#ifndef NETWORKDETAILS_H
#define NETWORKDETAILS_H

#include <QObject>

class NetworkDetails : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString networkproperty READ networkproperty WRITE setNetworkproperty NOTIFY networkpropertyChanged)
    Q_PROPERTY(QString value READ value WRITE setValue NOTIFY valueChanged)

public:
    NetworkDetails(QObject *parent=0);
    NetworkDetails(const QString &networkproperty, const QString &value, QObject *parent=0);

    QString networkproperty() const;
    void setNetworkproperty(const QString &networkproperty);

    QString value() const;
    void setValue(const QString &value);

signals:
    void networkpropertyChanged();
    void valueChanged();

private:
    QString m_networkproperty;
    QString m_value;
};

#endif // NETWORKDETAILS_H
