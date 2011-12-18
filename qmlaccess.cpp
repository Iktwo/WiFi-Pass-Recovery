#include "qmlaccess.h"
#include <QDebug>
#include <QStringList>
#include "dataobject.h"
#include "networkdetails.h"

QMLAccess::QMLAccess(QWidget *parent) :
    QDeclarativeView(parent)
{   
    m_context = rootContext();
    m_context->setContextProperty("wMain", this);
    QList<QObject*> dataList;
    QStringList networkNameList;
    QStringList networkSecurityList;
    QStringList networkCodeList;

    /***SET THE ROUTE TO WHERE NETWORKS ARE STORED***/

    routeToNetworking = "/system/osso/connectivity/IAP";

    /***CREATE A GCONFITEM TO ACCESS NETWORKS***/

    GConfItem networkingDir(routeToNetworking);

    /***CREATE A LIST WITH ALL THE SAVED NETWORKS***/

    QStringList networkList = networkingDir.listDirs();

    /***SEARCH IN THE ***/
    for (int var = 0; var < networkList.count(); ++var) {
        GConfItem network(networkList.at(var));
        QStringList networkProperties = network.listEntries();

        GConfItem wlan_security(network.key()+"/wlan_security");
        debug("KEY:"+wlan_security.key()+" VALUE:"+wlan_security.value().toString());
        if (wlan_security.value().toString()!="NONE"){
            if (networkProperties.contains(networkList.at(var)+"/wlan_ssid")){
                networkCodeList.append(networkList.at(var));
                for (int p = 0; p < networkProperties.count(); ++p) {
                    GConfItem networkProperty(networkProperties.at(p));
                    if(networkProperty.key().contains("name")){
                        networkNameList.append(networkProperty.value().toString());
                    }
                    if(networkProperty.key().contains("wlan_security")){
                        networkSecurityList.append(networkProperty.value().toString());
                    }
                    /*else{
                        debug("Key"+networkProperty.key()+" VALUE: "+networkProperty.value().toString());
                    }*/
                }
            }
        }

    }

    if (networkNameList.count()==networkSecurityList.count()){
        for (int var = 0; var < networkNameList.count(); ++var) {
            dataList.append(new DataObject(networkNameList.at(var),networkSecurityList.at(var),networkCodeList.at(var)));
        }
    }

    m_context->setContextProperty("networkListModel", QVariant::fromValue(dataList));

    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);
    setSource(QUrl("qrc:/qml/main.qml"));
}

void QMLAccess::debug(QString msg){
    qDebug() << msg;
}

void QMLAccess::getNetworkDetails(QString network){

    QList<QObject*> detailsList;
    GConfItem networkingDetails(network);
    QStringList networkProperties = networkingDetails.listEntries();

    for (int var = 0; var < networkProperties.count(); ++var) {
        GConfItem networkProperty(networkProperties.at(var));
        if (networkProperty.key().contains("name")){
            m_context->setContextProperty("networkName", networkProperty.value().toString());
        }else if (
                  !networkProperty.key().contains("proxy_rtsp") &&
                  !networkProperty.key().contains("EAP_wpa2_only_mode") &&
                  !networkProperty.key().contains("proxy") &&
                  !networkProperty.key().contains("type") &&
                  !networkProperty.key().contains("dns") &&
                  !networkProperty.key().contains("ipv4") &&
                  !networkProperty.key().contains("wlan_hidden") &&
                  !networkProperty.key().contains("autoconnect") &&
                  !networkProperty.key().contains("wlan_ssid") &&
                  !networkProperty.key().contains("url") &&
                  !networkProperty.key().contains("wlan_wepdefkey")
                  ){
            QString key = networkProperty.key();
            key = key.mid(key.lastIndexOf("/")+1);
            detailsList.append(new NetworkDetails(key,networkProperty.value().toString()));
        }
    }

    m_context->setContextProperty("networkPropertiesModel", QVariant::fromValue(detailsList));
}
