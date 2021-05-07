/****************************************************************************
Qt 5.7.1 Reference Documentation
Qt Widgets
Basic Drawing Example
painting/basicdrawing/main.cpp
****************************************************************************/

#include "window.h"

#include <QApplication>

int main(int argc, char *argv[]){  
  QApplication app(argc, argv);
  Window window;
  window.show();
  return app.exec();
}
