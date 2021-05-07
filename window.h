/****************************************************************************

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
  
private slots:
  void gridChanged();

private:
  RenderArea *renderArea;
  QLabel* otherOptionsLabel;
  QCheckBox *antialiasingCheckBox;
  QLabel* gridLabel;
  QComboBox* gridComboBox;
  int penWidth;
};

#endif // WINDOW_H
