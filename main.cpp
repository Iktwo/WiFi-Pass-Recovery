#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include "qmlaccess.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QCoreApplication::setOrganizationName("Iktwo Corp.");
    QCoreApplication::setOrganizationDomain("iktwo.com");
    QCoreApplication::setApplicationName("WiFiPassRetriever");

    QMLAccess qmlAccess;
    qmlAccess.showFullScreen();
    //qmlAccess.setOrientation(QMLAccess::ScreenOrientationLockPortrait);

    return app.exec();
}
