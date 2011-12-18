import QtQuick 1.0
import com.nokia.meego 1.0

QueryDialog {
    id: aboutDialog

    titleText: "WiFi Password Recovery by Iktwo " + "1.0.0"
    icon: "qrc:/images/iktwo.png"
    message: qsTr("See the password of previously connected WiFi Networks. <br><br> &copy; Iktwo 2011<br><br>Bugs/Comments <br> Send me an <a href=\"mailto:elmaildeliktwo@gmail.com\"> email</a>")
}
