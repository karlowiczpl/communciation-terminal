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

#include "windowWidgets.h"

class PortComboBox : public QComboBox
{
  Q_OBJECT

public:
  PortComboBox();
  void connect();

private:
  void scan();

protected:
  virtual void mousePressEvent(QMouseEvent* e) override;

private:
  QList<QSerialPortInfo> available_ports;
  WINDOW_WIDGETS_T* window_widgets;
  QSerialPort* serial_port;
};

#endif // !PORT_COMBO_BOX_H
