#ifndef QMLACCESS_H
#define QMLACCESS_H
#include <gconfitem.h>

#include <QDeclarativeView>
#include <QDeclarativeEngine>
#include <QDeclarativeView>
#include <QDeclarativeContext>
#include <QSettings>
#include <QDebug>

class QMLAccess : public QDeclarativeView
{
	Q_OBJECT
public:
    explicit QMLAccess(QWidget *parent = 0);
	enum ScreenOrientation {
        ScreenOrientationLockPortrait,
        ScreenOrientationLockLandscape,
        ScreenOrientationAuto
    };
    void setOrientation(ScreenOrientation orientation);
	
public slots:
    void debug(QString msg);
    void getNetworkDetails(QString network);

private:
    QDeclarativeContext *m_context;
    QSettings *settings;
    QString routeToNetworking;
};

#endif // QMLACCESS_H
