/****************************************************************************
Qt 5.7.1 Reference Documentation
Qt Widgets
Basic Drawing Example
painting/basicdrawing/renderarea.h
****************************************************************************/
#ifndef RENDERAREA_H
#define RENDERAREA_H

#include "window.h"

#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>

class RenderArea : public QWidget
{
  Q_OBJECT

public:
  enum Shape { Ellipse, Dot, Text, Pixmap };
  RenderArea(QWidget *parent = 0);
//  Window myWindow();

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

public slots:
  //void setShape(Shape shape);
  //void setPen(const QPen &pen);
  //void setBrush(const QBrush &brush);
  void setAntialiased(bool antialiased);

protected:
  void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
  const static int wdPix = 500;
  const static int htPix = 350;
  //const static int wdPix = 500;
  //const static int htPix = 350;
  const static int dotDiameter = 3;

  bool grid2(int i, int j, int scale);

  Shape shape;
  QPen pen;
  QBrush brush;
  bool antialiased;
  QPixmap pixmap;
};

#endif // RENDERAREA_H
