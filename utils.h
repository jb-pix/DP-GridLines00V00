#ifndef UTILS_H
#define UTILS_H

#include <QWidget>
//#include <QString>


class Utils : public QWidget
{
  Q_OBJECT

public:
  Utils(QWidget *parent = 0);
  QString getCurrentDateTime();

  ~Utils();

};

#endif // UTILS_H
