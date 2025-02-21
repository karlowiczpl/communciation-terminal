#ifndef PORT_COMBO_BOX_H
#define PORT_COMBO_BOX_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QObject>
#include <QComboBox>
#include <QList>
#include <QMouseEvent>
#include <QDebug>
#include <QWidget>
#include <QThread>

#include "windowWidgets.h"
#include "common/PushButton.h"
#include "../source/Configuration.h"

class PortComboBox : public QComboBox
{
  Q_OBJECT

public:
  PortComboBox(WINDOW_WIDGETS_T* window_widgets);
  void connect();

private:
  void scan();
  void setParameters();

private slots:
  void newMessage();

protected:
  virtual void mousePressEvent(QMouseEvent* e) override;

private:
  QList<QSerialPortInfo> available_ports;
  WINDOW_WIDGETS_T* window_widgets;
  QSerialPort* serial_port;
};

#endif // !PORT_COMBO_BOX_H
