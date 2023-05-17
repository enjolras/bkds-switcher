#ifndef OBSCONN_H
#define OBSCONN_H

#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>
#include <websocketpp/common/thread.hpp>

class wsDispatcher;

class obsConn {
public:
    typedef websocketpp::client<websocketpp::config::asio_client> client;
    typedef websocketpp::lib::lock_guard<websocketpp::lib::mutex> scoped_lock;
	typedef websocketpp::config::asio_client::message_type::ptr message_ptr;
	obsConn();
    void run();
    void on_open(websocketpp::connection_hdl);
    void on_close(websocketpp::connection_hdl);
    void on_fail(websocketpp::connection_hdl);
	void on_message(websocketpp::connection_hdl, message_ptr, wsDispatcher*);
	void send(std::string&);

private:
    client m_client;
    websocketpp::connection_hdl m_hdl;
    websocketpp::lib::mutex m_lock;
    bool m_open;
    bool m_done;
};

#endif
