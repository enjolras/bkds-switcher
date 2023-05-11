#include <errno.h>
#include <fcntl.h>
#include <cstring>
#include <termios.h>
#include <unistd.h>
#include <cstdio>
#include <cstdbool>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <sstream>

#include "connectionHandler.h"
#include "obsConn.h"

using namespace std;

connectionHandler::connectionHandler(obsConn* obs) : obs_(obs) {
	connect();
}

void connectionHandler::sendToObs(std::string& outStr) {

	std::cout << "SEND TO OBS: " << outStr << std::endl;
	obs_->send(outStr);
}

int connectionHandler::setInterfaceAttribs(int speed, int parity) {
        struct termios tty;
        if (tcgetattr (fd, &tty) != 0)
        {
                //perror("error %d from tcgetattr", errno);
				perror("tcgetattr");
                return -1;
        }

        cfsetospeed (&tty, speed);
        cfsetispeed (&tty, speed);

        tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
        // disable IGNBRK for mismatched speed tests; otherwise receive break
        // as \000 chars
        tty.c_iflag &= ~IGNBRK;         // disable break processing
        tty.c_lflag = 0;                // no signaling chars, no echo,
                                        // no canonical processing
        tty.c_oflag = 0;                // no remapping, no delays
        tty.c_cc[VMIN]  = 0;            // read doesn't block
        tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout

        tty.c_iflag &= ~(IXON | IXOFF | IXANY); // shut off xon/xoff ctrl

        tty.c_cflag |= (CLOCAL | CREAD);// ignore modem controls,
                                        // enable reading
        tty.c_cflag &= ~(PARENB | PARODD);      // shut off parity
        tty.c_cflag |= parity;
        tty.c_cflag &= ~CSTOPB;
        tty.c_cflag &= ~CRTSCTS;

        if (tcsetattr (fd, TCSANOW, &tty) != 0)
        {
                perror("tcsetattr");
               // printf("error %d from tcsetattr"\n, errno);
                return -1;
        }
        return 0;
}

void connectionHandler::setBlocking(int should_block) {
        struct termios tty;
        memset (&tty, 0, sizeof tty);
        if (tcgetattr (fd, &tty) != 0)
        {
               // printf("error %d from tggetattr", errno);
                perror("tggetattr");
                return;
        }

        tty.c_cc[VMIN]  = should_block ? 1 : 0;
        tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout

        if (tcsetattr (fd, TCSANOW, &tty) != 0) {
                perror("tcsetsttr");
            }
               // printf("error %d setting term attributes", errno);
}

void connectionHandler::sendAck() {
    unsigned char ack = 0x84;
    write(fd, &ack, 1);
}

void connectionHandler::connect() {

    fd = open ("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_SYNC);
    if (fd < 0)
    {
        //error_message ("error %d opening %s: %s", errno, portname, strerror (errno));
        //return -1;
    }

    setInterfaceAttribs(B38400, PARODD | PARENB); // 38400 8O1
    setBlocking(1);                // set blocking

	bool break_received = false;

    printf("Waiting for connection...\n");
    while(true) {
        unsigned int n = read (fd, readBuf, 1);
        if(n==1) {
            printf("Bytes read: %d %02x\n",n,readBuf[0]);
            if(readBuf[0] == 0x30 && break_received) {
				break_received = false;
                sendAck();
                printf("Connected!\n") ;
                break ;
            } else if(readBuf[0] == 0x00) {
				break_received = true;
				continue;
			}
        }
    }
}

unsigned char* connectionHandler::getNextCommand() {

	bool break_received = false;

    while(true) {
        unsigned int bytes_read = read (fd, readBuf, 1);

        if(readBuf[0] == 0x30 && break_received) {
			break_received = false;
            printf("Connection reset!\n") ;
            sendAck();
            continue;
        } else if(readBuf[0] == 0x00) {
			break_received = true;
            continue;
        }

		bytes_read = 0;
        unsigned int n = read(fd,&readBuf[1],readBuf[0]) ;
        if(n!=readBuf[0]) {
			while(true) {
				bytes_read += n;
				printf("Reading more (requested %d - read %d - to go: %d)...\n",readBuf[0],bytes_read,readBuf[0]-bytes_read);
				n = read(fd,&readBuf[bytes_read+1],readBuf[0]-bytes_read);
				if(readBuf[0] == bytes_read + n) break;
			}
//            printf("READ DATA MISMATCH - BTR: %d - ACTUALLY: %d\n",readBuf[0],n);
        }
        if(readBuf[2]>=0x80) {
            sendAck();
        }

		return readBuf;
	}
}

void connectionHandler::addResponse(response &resp) {

	responses.push(resp);

}

void connectionHandler::commitResponses() {

	while(!responses.empty()) {
		response tmpResp = responses.front();
		write(fd,tmpResp.getData(),tmpResp.getData()[0]+1);
		responses.pop();
	}
}

response::response() {

	memset(resp_,0,sizeof(resp_));

}

void response::addByte(unsigned char byte) {

	resp_[0]++;
	resp_[resp_[0]] = byte;

}

unsigned char* response::getData() {
	return resp_;
}

void response::debugResponse() {
	printf("RESPONSE: ");
	for(int i=0;i<=getData()[0];i++) {
		printf("%02x ",getData()[i]);
	}
	printf("\n");
}
