#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QMessageBox>

/**
 * Multithread server
 */
// Use ThreadPool interface to create request executor
// Use separate thread to accept connections from client
// Use sockets to work with network (Qt Sockets, boost::asio etc.), but not WinAPI if possible
// Implement the below scenario:
// - Server is started on default endpoint (0.0.0.0) and provided port to accept connections from client
// - Client connects to server IP and port
// - Client sends some string to server, server adds some prefix to this string and sends it back (some kind of echo server)
// - Server closes the connection
class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(unsigned int port);
    void messageToClient(QTcpSocket *socket, const std::string& clientString);

private slots:
    void clientDisconnect();
    void clientConnection();
    void getMessage();


private:
    QTcpServer *tcpserver;
};

#endif // SERVER_H
