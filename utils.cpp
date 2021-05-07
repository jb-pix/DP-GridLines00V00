#include "utils.h"

#include <QString>
#include <QDateTime>
#include <QDebug>


Utils::Utils(QWidget *parent)
  : QWidget(parent){
}

QString Utils::getCurrentDateTime(){
  QDateTime dt = QDateTime::currentDateTime();

  qDebug() << "dt: " << dt;

  //hh:mm:ss.zzz
  //14:13:09.042
  QString formatStr = "yyMMdd::hh:mm:ss";
  QString dtStr = dt.toString(formatStr);
  qDebug() << "dtStr: " << dtStr;
  return dtStr;
}

Utils::~Utils(){
}
