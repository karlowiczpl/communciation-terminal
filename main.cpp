#include <QApplication>
#include <QDebug>

#include "widgets/MainWindow.h"

int main(int argc , char* argv[])
{
  QApplication a(argc , argv);

  MainWindow m1;

  return QApplication::exec();
}
