/*************************************************************
Project:    DrawingProject. GUI for an integrated drawing package
Module:     GridLines00
File:       window.cpp
File Path:  ~/apps/qtexamples/DrawingProject/gridlines00/
Author:     Jane Booth
Date:       06/05/2021
Note:       This module generates grids of co.ordinates
*************************************************************/
#include "renderarea.h"
#include "window.h"
#include "utils.h"


#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QCheckBox>
#include <QComboBox>
#include <QDateTime>
#include <QDebug>

Window::Window()
{
  renderArea = new RenderArea;
  QGridLayout *mainLayout = new QGridLayout;

  /***********************************************/
   gridComboBox = new QComboBox;
   gridComboBox->addItem("grid1");
   gridComboBox->addItem("grid2");

   //gridLabel = new QLabel("Grids:");
   gridLabel = new QLabel("Grids:");
   gridLabel->setBuddy(gridComboBox);

   connect(gridComboBox, SIGNAL(activated(int)),
           this, SLOT(gridChanged()));

   /***********************************************/
   QLabel* dummy = new QLabel("                 ");


  otherOptionsLabel = new QLabel(tr("                  Options:"));
  antialiasingCheckBox = new QCheckBox(tr("&Antialiasing"));
  connect(antialiasingCheckBox, SIGNAL(toggled(bool)),
          renderArea, SLOT(setAntialiased(bool)));

  mainLayout->setColumnStretch(0, 1);
  mainLayout->setColumnStretch(3, 1);
  mainLayout->addWidget(renderArea, 0, 0, 1, 5);

  mainLayout->addWidget(gridLabel, 5, 0, Qt::AlignLeft);
  mainLayout->addWidget(gridComboBox, 5, 1, Qt::AlignLeft);
  mainLayout->addWidget(dummy, 5, 2, Qt::AlignLeft);
  mainLayout->addWidget(otherOptionsLabel, 5, 3, Qt::AlignRight);
  mainLayout->addWidget(antialiasingCheckBox, 5, 4, 1, 1, Qt::AlignRight);

  setLayout(mainLayout);
  
  gridChanged();
  antialiasingCheckBox->setChecked(true);

  Utils* utils = new Utils;
  QString dtsr = utils->getCurrentDateTime();
  QString titleText = "grid01 - " + dtsr;
  setWindowTitle(titleText);
}

void Window::gridChanged(){
  qDebug() << "START  gridChanged";
  qDebug() << "END    gridChanged";
}


