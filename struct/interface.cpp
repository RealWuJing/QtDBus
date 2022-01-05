#include <QCoreApplication>
#include <QDBusMessage>
#include <QDBusConnection>
#include <QDBusReply>
#include <QDBusInterface>
#include <QDebug>

#include "book.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qRegisterMetaType<Book>("Book");
    qDBusRegisterMetaType<Book>();

    // 创建QDBusInterface接口
    QDBusInterface interface("com.scorpio.test", "/test/objects",
                             "com.scorpio.test.value",
                             QDBusConnection::sessionBus());
    QDBusPendingReply<Book> reply = interface.call("book");
    reply.waitForFinished();
    if (reply.isValid())
    {
        Book book = reply.value();
        qDebug() << QString("book.name = %1, book.page = %2, book.author = %3").arg(book.name).arg(book.page).arg(book.author);
    }

    return a.exec();
}