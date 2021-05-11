/****************************************************************************
Qt 5.7.1 Reference Documentation
Qt Widgets
Basic Drawing Example
painting/basicdrawing/window.cpp
****************************************************************************/
#include "renderarea.h"
#include "window.h"
#include "utils.h"


#include <QtWidgets>
#include <QDateTime>

const int IdRole = Qt::UserRole;

Window::Window()
{
  renderArea = new RenderArea;
  QGridLayout *mainLayout = new QGridLayout;


  /***********************************************
  //make a function to initialise the pen width
  //when either shape is called
  //thinks it nearly works now
  //extend to class - selectionCombo Box eg one named shape, other named grid
  shapeComboBox = new QComboBox;

//  shapeComboBox->addItem(tr("Ellipse"), RenderArea::Ellipse);
  shapeComboBox->addItem(tr("Dot"), RenderArea::Dot);
//  shapeComboBox->addItem(tr("Text"), RenderArea::Text);
//  shapeComboBox->addItem(tr("Pixmap"), RenderArea::Pixmap);
  
  shapeLabel = new QLabel(tr("&Shape:"));
  shapeLabel->setBuddy(shapeComboBox);

 // connect(shapeComboBox, SIGNAL(activated(int)),
 //         this, SLOT(shapeChanged()));

  mainLayout->addWidget(shapeLabel, 2, 0, Qt::AlignRight);
  mainLayout->addWidget(shapeComboBox, 2, 1);
 // shapeChanged();
  ***********************************************

  penWidthSpinBox = new QSpinBox;
  penWidthSpinBox->setRange(0, 6);
  penWidthSpinBox->setWrapping(true);
  penWidthSpinBox->setValue(2);

//  penWidthSpinBox->setRange(0, 20);
//  penWidthSpinBox->setSpecialValueText(tr("0 (cosmetic pen)"));

  penWidthLabel = new QLabel(tr("Pen &Width:"));
  penWidthLabel->setBuddy(penWidthSpinBox);
  ***********************************************/
  otherOptionsLabel = new QLabel(tr("Options:"));
  antialiasingCheckBox = new QCheckBox(tr("&Antialiasing"));

//  int dotDiameter = penWidthSpinBox->value();
  //  renderArea->setPen(QPen(Qt::blue, dotDiameter , Qt::SolidLine,  Qt::SquareCap, Qt::MiterJoin));
//  renderArea->setPen(QPen(Qt::blue, 3 , Qt::SolidLine,  Qt::SquareCap, Qt::MiterJoin));

//  connect(penWidthSpinBox, SIGNAL(valueChanged(int)),
//          this, SLOT(penChanged()));
  connect(antialiasingCheckBox, SIGNAL(toggled(bool)),
          renderArea, SLOT(setAntialiased(bool)));

  //QGridLayout *mainLayout = new QGridLayout;
  mainLayout->setColumnStretch(0, 1);
  mainLayout->setColumnStretch(3, 1);
  mainLayout->addWidget(renderArea, 0, 0, 1, 4);
//  mainLayout->addWidget(shapeLabel, 2, 0, Qt::AlignRight);
//  mainLayout->addWidget(shapeComboBox, 2, 1);
//  mainLayout->addWidget(penWidthLabel, 3, 0, Qt::AlignRight);
//  mainLayout->addWidget(penWidthSpinBox, 3, 1);

  mainLayout->addWidget(otherOptionsLabel, 5, 0, Qt::AlignRight);
  mainLayout->addWidget(antialiasingCheckBox, 5, 1, 1, 1, Qt::AlignRight);

  setLayout(mainLayout);
  
  //shapeChanged();
  antialiasingCheckBox->setChecked(true);

  Utils* utils = new Utils;
  QString dtsr = utils->getCurrentDateTime();
  QString titleText = "grid00 - " + dtsr;
  setWindowTitle(titleText);

  
//  setWindowTitle(tr("Basic Drawing"));
}

//void Window::shapeChanged()
//{
//  RenderArea::Shape shape = RenderArea::Shape(shapeComboBox->itemData(
//    shapeComboBox->currentIndex(), IdRole).toInt());
//  renderArea->setShape(shape);
//}


/*
void Window::penChanged()
{
 // int dotDiameter = penWidthSpinBox->value();//this should be a static const ie 3

  setPen(QPen(Qt::blue, 3 , Qt::SolidLine,  Qt::SquareCap, Qt::MiterJoin));
//  renderArea->setPen(QPen(Qt::blue, 3 , Qt::SolidLine,  Qt::SquareCap, Qt::MiterJoin));
}
*/
QSize Window::getDotSize() {
  QSize retval(penWidth, penWidth);
  return retval;
}
