#include "obsConn.h"
#include "wsDispatcher.h"

obsConn::obsConn() : m_open(false),m_done(false) {

	wsDispatcher wsDisp;

    // set up access channels to only log interesting things
    m_client.clear_access_channels(websocketpp::log::alevel::all);
    m_client.set_access_channels(websocketpp::log::alevel::connect);
    m_client.set_access_channels(websocketpp::log::alevel::disconnect);
    m_client.set_access_channels(websocketpp::log::alevel::app);

    // Initialize the Asio transport policy
    m_client.init_asio();

    // Bind the handlers we are using
    using websocketpp::lib::placeholders::_1;
    using websocketpp::lib::placeholders::_2;
    using websocketpp::lib::bind;
    m_client.set_open_handler(bind(&obsConn::on_open,this,_1));
    m_client.set_close_handler(bind(&obsConn::on_close,this,_1));
    m_client.set_fail_handler(bind(&obsConn::on_fail,this,_1));
	m_client.set_message_handler(bind(&obsConn::on_message,this,_1,_2,&wsDisp));
}

// This method will block until the connection is complete
void obsConn::run() {

	std::string uri = "ws://localhost:4455";

    // Create a new connection to the given URI
    websocketpp::lib::error_code ec;
    client::connection_ptr con = m_client.get_connection(uri, ec);
    if (ec) {
       m_client.get_alog().write(websocketpp::log::alevel::app,
               "Get Connection Error: "+ec.message());
       return;
   }

   // Grab a handle for this connection so we can talk to it in a thread
   // safe manor after the event loop starts.
   m_hdl = con->get_handle();

   // Queue the connection. No DNS queries or network connections will be
   // made until the io_service event loop is run.
   m_client.connect(con);

   // Create a thread to run the ASIO io_service event loop
   websocketpp::lib::thread asio_thread(&client::run, &m_client);

   asio_thread.detach();
}

// The open handler will signal that we are ready to start sending telemetry
void obsConn::on_open(websocketpp::connection_hdl) {
   m_client.get_alog().write(websocketpp::log::alevel::app,
            "OBS connection opened");

        scoped_lock guard(m_lock);
        m_open = true;
    }

    // The close handler will signal that we should stop sending telemetry
void obsConn::on_close(websocketpp::connection_hdl) {
        m_client.get_alog().write(websocketpp::log::alevel::app,
            "Connection closed, stopping telemetry!");

        scoped_lock guard(m_lock);
        m_done = true;
    }

    // The fail handler will signal that we should stop sending telemetry
void obsConn::on_fail(websocketpp::connection_hdl) {
        m_client.get_alog().write(websocketpp::log::alevel::app,
            "Connection failed, stopping telemetry!");

        scoped_lock guard(m_lock);
        m_done = true;
    }

void obsConn::on_message(websocketpp::connection_hdl hdl, message_ptr msg, wsDispatcher* wsDisp) {
    std::cout << "on_message called with hdl: " << hdl.lock().get()
              << " and message: " << msg->get_payload()
              << std::endl;


    websocketpp::lib::error_code ec;

    std::string outStr;
    wsDisp->exec(msg->get_payload(),outStr);
    if(outStr != "null") {
            m_client.send(hdl,outStr,websocketpp::frame::opcode::text,ec);
    }

    if (ec) {
        std::cout << "Echo failed because: " << ec.message() << std::endl;
    }
}

void obsConn::send(std::string& outStr) {

	websocketpp::lib::error_code ec;

	m_client.send(m_hdl,outStr,websocketpp::frame::opcode::text,ec);

	if (ec) {
        std::cout << "Send failed because: " << ec.message() << std::endl;
    }

}
