import QtQuick 1.0
import com.nokia.meego 1.0

Column {

        property alias tittle: mainPageTitleText.text;
        property alias author: mainPageAuthorText.text;
        property alias color: mainPageTitle.color;
        property alias tittleLink: tittleLink.text;
        property alias authorLink: authorLink.text;

        id: mainPageColumn
        width: parent.width
        height: 72
        anchors.bottomMargin: 567
        anchors.fill: parent

        Rectangle {
            id: mainPageTitle
            width: parent.width
            height: 72

            Label {
                id: mainPageTitleText
                anchors.left: parent.left
                anchors.leftMargin: 15
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 35
                color:  "white"
                MouseArea {
                    id: mouse_area_tittle
                    anchors.fill: parent
                    onClicked: Qt.openUrlExternally(tittleLink.text);
                }
            }

            Label {
                id: mainPageAuthorText
                x: mainPageTitle.width-10-mainPageAuthorText.width
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 30
                color:  "white"
                MouseArea {
                    id: mouse_area_author
                    anchors.fill: parent
                    onClicked: Qt.openUrlExternally(authorLink.text);
                }
            }

            Text {
                id: authorLink
                opacity: 0
            }

            Text {
                id: tittleLink
                opacity: 0
            }
        }
    }
