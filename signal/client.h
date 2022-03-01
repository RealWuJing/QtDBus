#ifndef CLIENT_H
#define CLIENT_H
#include <QtCore/QObject>
#include <QTextStream>
#include <QCoreApplication>
#include <QtDBus>
#include <QDebug>
#include <thread>

class Client: public QObject
{
    Q_OBJECT
public:
    Client();
public slots:
    void client_get(void);
signals:
    void send_to_service(QString st);
};

#endif // CLIENT_H