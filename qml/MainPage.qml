import QtQuick 1.1
import com.nokia.meego 1.0
import com.nokia.extras 1.0

Page {
    id: mainPage

    tools: commonTools

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
            text: "Saved WiFi Networks:"
            font.pixelSize: 40
        }
        z:1;
    }

    ListView {
        id: listview
        y: savedContainer.y+savedContainer.height
        height: mainPage.height-72-savedContainer.height;
        width: mainPage.width
        model: networkListModel

        delegate: ListDelegate{

            Label {
                id: lblName;
                text: name
                font.pixelSize: 32
            }

            Image {
                source: "image://theme/icon-m-common-drilldown-arrow" + (theme.inverted ? "-inverse" : "")
                anchors.right: parent.right;
                anchors.verticalCenter: parent.verticalCenter
            }

            Label {
                anchors.top: lblName.bottom;
                text: security
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

    NetworkDetails{
        id: networkDetails;
        anchors.fill: parent
    }
}
