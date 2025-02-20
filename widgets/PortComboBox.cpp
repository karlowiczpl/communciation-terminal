#include "PortComboBox.h"

PortComboBox::PortComboBox()
{
  scan();
  serial_port = new QSerialPort;

  qDebug() << window_widgets->connect_button;
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
bool PortComboBox::connect()
{
  serial_port->setBaudRate(window_widgets->baud_rate_box->value());
  serial_port->setDataBits(QSerialPort::DataBits(window_widgets->data_bits_box->value()));
  serial_port->setFlowControl(QSerialPort::FlowControl(window_widgets->flow_control_box->value()));
  serial_port->setParity(QSerialPort::Parity(window_widgets->parity_box->value()));
  serial_port->setStopBits(QSerialPort::StopBits(window_widgets->stop_bits_box->value()));

  if(currentText() != "")
  {
    serial_port->setPort(QSerialPortInfo(currentText()));
    /*window_widgets->*/
  }
}
