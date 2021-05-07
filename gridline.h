#ifndef GRIDLINE_H
#define GRIDLINE_H

#include <QWidget>
#include <QWidget>

class GridLine : public QWidget {
  Q_OBJECT
public:
  GridLine(QString gridType, QWidget *parent = 0);
  GridLine(QWidget *parent = 0);
  ~GridLine();
signals:

public slots:
};

#endif // GRIDLINE_H
