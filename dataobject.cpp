#include <QDebug>
#include "dataobject.h"

DataObject::DataObject(QObject *parent)
    : QObject(parent)
{
}

DataObject::DataObject(const QString &name, const QString &security, const QString &code, QObject *parent)
    : QObject(parent), m_name(name), m_security(security), m_code(code)
{
}

QString DataObject::name() const
{
    return m_name;
}

void DataObject::setName(const QString &name)
{
    if (name != m_name) {
        m_name = name;
        emit nameChanged();
    }
}

QString DataObject::security() const
{
    return m_security;
}

void DataObject::setSecurity(const QString &security)
{
    if (security != m_security) {
        m_security = security;
        emit securityChanged();
    }
}

QString DataObject::code() const
{
    return m_code;
}

void DataObject::setCode(const QString &code)
{
    if (code != m_code) {
        m_code = code;
        emit codeChanged();
    }
}
