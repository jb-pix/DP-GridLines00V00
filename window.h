/****************************************************************************
Qt 5.7.1 Reference Documentation
Qt Widgets
Basic Drawing Example
painting/basicdrawing/window.h
****************************************************************************/
#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
class RenderArea;
class Utils;


class QCheckBox;
class QComboBox;
class QLabel;
class QSpinBox;



class Window : public QWidget
{
  Q_OBJECT
  
public:
  Window();
  QSize getDotSize();
  
private slots:
  //void shapeChanged();
  //void penChanged();
//  void brushChanged();
  
private:
  RenderArea *renderArea;
  QLabel *shapeLabel;
  QLabel *penWidthLabel;
  QLabel *otherOptionsLabel;
  QComboBox *shapeComboBox;
  QSpinBox *penWidthSpinBox;
  QComboBox *penJoinComboBox;
  QCheckBox *antialiasingCheckBox;
  int penWidth;
};

#endif // WINDOW_H
