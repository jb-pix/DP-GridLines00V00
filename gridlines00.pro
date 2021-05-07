#Qt 5.7.1 Reference Documentation
#Basic Drawing Example
#painting/basicdrawing/basicdrawing.pro 

  QT       += core gui

  greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

  TARGET = DrawDotsV000
  TEMPLATE = app

  HEADERS       = window.h \
                  renderarea.h \
    utils.h \
    gridline.h
  SOURCES       = main.cpp \
                  renderarea.cpp \
                  window.cpp \
    utils.cpp \
    gridline.cpp

  # install
  #target.path = $$[QT_INSTALL_EXAMPLES]/widgets/painting/basicdrawing
  #INSTALLS += target
