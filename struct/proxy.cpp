#include <QCoreApplication>
#include <QDBusMessage>
#include <QDBusConnection>
#include <QDBusReply>
#include <QDBusInterface>
#include <QDebug>
#include "testInterface.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qRegisterMetaType<Book>("Book");
    qDBusRegisterMetaType<Book>();

    // 初始化自动生成的Proxy类com::scorpio::test::value
    com::scorpio::test::value test("com.scorpio.test",
                                   "/test/objects",
                                   QDBusConnection::sessionBus());
    // 调用value方法
    QDBusPendingReply<Book> reply = test.book();
    //qdbusxml2cpp生成的Proxy类是采用异步的方式来传递Message，
    //所以需要调用waitForFinished来等到Message执行完成
    reply.waitForFinished();
    if (reply.isValid())
    {
        Book book = reply.value();
        qDebug() << QString("book.name = %1, book.page = %2, book.author = %3").arg(book.name).arg(book.page).arg(book.author);
    }
    else
    {
        qDebug() << "value method called failed!";
    }

    return a.exec();
}
