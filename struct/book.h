#include <QtDBus>

class Book
{
    friend QDBusArgument &operator<<(QDBusArgument &argument, const Book &book);

    friend const QDBusArgument &operator>>(const QDBusArgument &argument, Book &book);

    static void registerMetaType();

public:
    QString name;
    qlonglong page;
    QString author;
};

Q_DECLARE_METATYPE(Book)