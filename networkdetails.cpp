#include <QDebug>
#include "networkdetails.h"

NetworkDetails::NetworkDetails(QObject *parent)
    : QObject(parent)
{
}

NetworkDetails::NetworkDetails(const QString &networkproperty, const QString &value, QObject *parent)
    : QObject(parent), m_networkproperty(networkproperty), m_value(value)
{
}

QString NetworkDetails::networkproperty() const
{
    return m_networkproperty;
}

void NetworkDetails::setNetworkproperty(const QString &networkproperty)
{
    if (networkproperty != m_networkproperty) {
        m_networkproperty = networkproperty;
        emit networkpropertyChanged();
    }
}

QString NetworkDetails::value() const
{
    return m_value;
}

void NetworkDetails::setValue(const QString &value)
{
    if (value != m_value) {
        m_value = value;
        emit valueChanged();
    }
}
