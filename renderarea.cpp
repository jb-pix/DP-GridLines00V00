/****************************************************************************
Qt 5.7.1 Reference Documentation
Qt Widgets
Basic Drawing Example
painting/basicdrawing/renderarea.cpp
****************************************************************************/
#include "renderarea.h"

#include <QPainter>
#include <QDebug>

RenderArea::RenderArea(QWidget *parent): QWidget(parent){
  //shape = Dot;
  antialiased = false;

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

void RenderArea::setAntialiased(bool antialiased)
{
  this->antialiased = antialiased;
  update();
}

bool RenderArea::grid2(int i, int j, int scale){
  // qDebug() <<"START grid2";
  qDebug() <<"scale: " << scale;
  bool retval = false;
  bool isXCoordDrawn = (i)%scale;
  bool isYCoordDrawn = (j)%scale;
  //retval = (isXCoordDrawn||isYCoordDrawn);
  retval = (isXCoordDrawn&&isYCoordDrawn);
 // qDebug() <<"END grid2 returns: " << retval;
  return !retval;
}
void RenderArea::paintEvent(QPaintEvent * /* event */)
{
//  void QPainter::drawEllipse(const QPointF &center, qreal rx, qreal ry)
//  This is an overloaded function.
//  Draws the ellipse positioned at center with radii rx and ry.

  QPainter painter(this);
  painter.setPen(pen);
  if (antialiased)
    painter.setRenderHint(QPainter::Antialiasing, true);
  painter.save();
  qreal scale = 0.01;
  for (int x = 0; x < width()*100; x += 100) {
  //for (int x = 0; x < width()*99; x += 10) {
    for (int y = 0; y < height() - 0.1/scale; y += 100) {
      //for (int y = 0; y < height() - 0.4/scale; y += 100) {
      //for (int y = 0; y < height(); y += 100) {
        qreal xx = x*scale;
        qreal yy = y;
        qreal r = 0.5;
        //qreal r = 1.2;

        QPointF ptf;
        ptf.setX(xx);
        ptf.setY(yy);
        painter.drawEllipse(ptf, r, r);//circle
        //painter.drawPoint(x, y );
      }
    }

  //  for (int x = 0; x < width(); x += 10) {
  //    for (int y = 0; y < height(); y += 10) {
  //      painter.drawPoint(x, y );
  //      //painter.drawPoint(x, y );
  //    }
  //  }

  painter.restore();
}

