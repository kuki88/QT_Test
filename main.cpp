#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("libgen");
    db.setUserName("root");
    db.setPassword("root");
    if(!db.open()){
        qDebug() << "Connection error!";
    }

    QPixmap pixmap("C:\\Users\\Jakov\\Pictures\\Slika.jpg");
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Testni_" + QLocale(locale).name();
        if (translator.load(":/18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    MainWindow w;
    w.show();
    return a.exec();
}
