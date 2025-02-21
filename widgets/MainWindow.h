#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>

#include "PortComboBox.h"
#include "windowWidgets.h"
#include "common/PushButton.h"
#include "common/ComboBox.h"
#include "common/LineEdit.h"
#include "common/PlainTextEdit.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT
  
public:
  MainWindow();

private:
  QVBoxLayout* createWindow();
  void createWidgets();
  void addItemsToMainLayout(QVBoxLayout* main_layout);
  void addItemsToSettingsLayout(QGridLayout* settings_layout);

private:
  WINDOW_WIDGETS_T window_widgets;
  PortComboBox* port_box;
};

#endif // !MAIN_WINDOW_H
