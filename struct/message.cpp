#include <QCoreApplication>
#include <QDBusMessage>
#include <QDBusConnection>
#include <QDebug>
#include <QtDBus>

#include "book.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //构造一个method_call消息，服务名称为：com.scorpio.test，对象路径为：/test/objects
    //接口名称为com.scorpio.test.value，method名称为value
    QDBusMessage message = QDBusMessage::createMethodCall("com.scorpio.test",
                                                          "/test/objects",
                                                          "com.scorpio.test.value",
                                                          "book");
    //发送消息
    QDBusMessage response = QDBusConnection::sessionBus().call(message);
    qInfo() << response;
    //判断method是否被正确返回
    if (response.type() == QDBusMessage::ReplyMessage)
    {
        //从返回参数获取返回值
        // QDBusMessage的arguments不仅可以用来存储发送的参数，也用来存储返回值
        QList<QVariant> outArgs = response.arguments();
        QVariant data = outArgs.at(0);
        const QDBusArgument dbusArgs = data.value<QDBusArgument>();
        qInfo() << "QDBusArgument current type is" << dbusArgs.currentType();
        Book book;
        dbusArgs.beginStructure();
        dbusArgs >> book.name >> book.page >> book.author;
        dbusArgs.endStructure();
        qDebug() << QString("book.name = %1, book.page = %2, book.author = %3").arg(book.name).arg(book.page).arg(book.author);
    }
    else
    {
        qDebug() << "value method called failed!";
    }

    return a.exec();
}