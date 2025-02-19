#include "PortComboBox.h"

PortComboBox::PortComboBox()
{
  scan();
  serial_port = new QSerialPort;
}
void PortComboBox::scan()
{
  QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
  available_ports.clear();
  clear();

  for(const QSerialPortInfo &port : ports)
  {
    if(!port.isBusy() && !port.isNull() && port.manufacturer() != "")
    {
      available_ports.append(port);
    }
  }

  for(const QSerialPortInfo &port : available_ports)
  {
    addItem(port.portName());
  }
}
void PortComboBox::mousePressEvent(QMouseEvent* e)
{
  scan();
  showPopup();
}
void PortComboBox::connectionButtonClicked()
{
  serial_port->setBaudRate(window_widgets->baud_rate_box->value());
  qDebug() << "value: " << window_widgets->baud_rate_box->value();
}
