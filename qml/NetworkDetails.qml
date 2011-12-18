import QtQuick 1.0
import com.nokia.meego 1.0
import com.nokia.extras 1.0

Page {
    id: detailsPage
    tools: detailsTools

    TittleBar{
        id: tittleBar;
        tittle: "WiFi Pass Recovery";
        author: "By Iktwo";
        color: "green";
        //tittleLink: "http://store.ovi.mobi/content/213823";
        authorLink: "http://store.ovi.mobi/publisher/Iktwo/";
        z: 1;
    }

    Rectangle{
        id: savedContainer;
        color: "black"
        x: 0
        y: 72
        width: parent.width
        height: lblSaved.height;
        Label {
            id: lblSaved;
            text: networkName+" Properties:"
            font.pixelSize: 40
        }
        z:1;
    }

    ListView {
        id: listview
        y: savedContainer.y+savedContainer.height
        height: mainPage.height-72-savedContainer.height;
        width: mainPage.width
        model: networkPropertiesModel

        delegate: ListDelegate{

            Label {
                id: lblName;
                text: networkproperty
                font.pixelSize: 32
            }

            Label {
                anchors.top: lblName.bottom;
                text: value
                font.pixelSize: 27
            }

            onClicked: {
                wMain.getNetworkDetails(code)
                pageStack.push(networkDetails)
            }
        }
    }
    ScrollDecorator {
        flickableItem: listview
    }
}
