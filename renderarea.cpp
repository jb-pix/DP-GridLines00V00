/****************************************************************************
Qt 5.7.1 Reference Documentation
Qt Widgets
Basic Drawing Example
painting/basicdrawing/renderarea.cpp
****************************************************************************/
#include "renderarea.h"

//#include <QRect>
#include <QPainter>
#include <QDebug>

RenderArea::RenderArea(QWidget *parent): QWidget(parent){
  shape = Dot;
  antialiased = false;
//  pixmap.load("/home/janebo/apps/qtexamples/drawDotsV000/images/Qt-logo.png");

  setBackgroundRole(QPalette::Base);
  setAutoFillBackground(true);
}

QSize RenderArea::minimumSizeHint() const
{
  return QSize(wdPix, htPix);
}

QSize RenderArea::sizeHint() const
{
  return QSize(wdPix, htPix);
}

//void RenderArea::setShape(Shape shape)
//{
//  this->shape = shape;
//  update();
//}

//void RenderArea::setPen(const QPen &pen)
//{
//  this->pen = pen;
//  update();
//}

//void RenderArea::setBrush(const QBrush &brush)
//{
//  this->brush = brush;
//  update();
//}

void RenderArea::setAntialiased(bool antialiased)
{
  this->antialiased = antialiased;
  update();
}

bool RenderArea::grid2(int i, int j, int scale){
  // qDebug() <<"START grid2";
  qDebug() <<"scale: " << scale;
  bool retval = false;
 // qDebug() <<"(i , j): (" << i << " , " << j << ")";
  bool isXCoordDrawn = (i)%scale;
  bool isYCoordDrawn = (j)%scale;
  //retval = (isXCoordDrawn||isYCoordDrawn);
  retval = (isXCoordDrawn&&isYCoordDrawn);
 // qDebug() <<"END grid2 returns: " << retval;
  return !retval;
}
void RenderArea::paintEvent(QPaintEvent * /* event */)
{
//  QRect rect(10, 20, 80, 60);//for ellipse
  QPainter painter(this);
  painter.setPen(pen);
//  painter.setBrush(brush);
  if (antialiased)
    painter.setRenderHint(QPainter::Antialiasing, true);
  painter.save();
  for (int x = 0; x < width(); x += 10) {
    for (int y = 0; y < height(); y += 10) {
        painter.drawPoint(x, y );
    }
  }
  painter.restore();
}

