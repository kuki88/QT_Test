#ifndef CONNECTION_H
#define CONNECTION_H

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QSqlDatabase>
#include <QMessageBox>
#include <string.h>
#include <vector>

#endif // CONNECTION_H

class Connection{

    private:

        Connection(){}

    public:

        static bool mySqlConnection(QSqlDatabase db){

            if(db.open()){
                return true;
            }

            return false;

        }

};
