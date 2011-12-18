#ifndef DATAOBJECT_H
#define DATAOBJECT_H

#include <QObject>

//![0]
class DataObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString security READ security WRITE setSecurity NOTIFY securityChanged)
    Q_PROPERTY(QString code READ code WRITE setCode NOTIFY codeChanged)
//![0]

public:
    DataObject(QObject *parent=0);
    DataObject(const QString &name, const QString &security, const QString &code, QObject *parent=0);

    QString name() const;
    void setName(const QString &name);

    QString security() const;
    void setSecurity(const QString &security);

    QString code() const;
    void setCode(const QString &code);

signals:
    void nameChanged();
    void securityChanged();
    void codeChanged();

private:
    QString m_name;
    QString m_security;
    QString m_code;
//![1]
};
//![1]

#endif // DATAOBJECT_H
