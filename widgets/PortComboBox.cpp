#include "PortComboBox.h"

PortComboBox::PortComboBox(WINDOW_WIDGETS_T* window_widgets) : window_widgets(window_widgets) 
{
  scan();
  serial_port = new QSerialPort;

  QPushButton::connect(window_widgets->connect_button , &QPushButton::clicked , this , &PortComboBox::connect);
  QSerialPort::connect(serial_port , &QSerialPort::readyRead , this , &PortComboBox::newMessage);

  Configuration cf;
  qDebug() << cf.getValue("parity");
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
  QComboBox::mousePressEvent(e);
}
void PortComboBox::connect()
{
  setParameters();
  if(serial_port->isOpen())
  {
    serial_port->close();
  }
  else
  {
    serial_port->open(QIODevice::ReadWrite);
    QThread::msleep(100);
    serial_port->clear(QSerialPort::AllDirections);
  }
  window_widgets->connect_button->connected(serial_port->isOpen());
}
void PortComboBox::setParameters()
{
  serial_port->setBaudRate(window_widgets->baud_rate_box->value());
  serial_port->setDataBits(QSerialPort::DataBits(window_widgets->data_bits_box->value()));
  serial_port->setFlowControl(QSerialPort::FlowControl(window_widgets->flow_control_box->value()));
  serial_port->setParity(QSerialPort::Parity(window_widgets->parity_box->value()));
  serial_port->setStopBits(QSerialPort::StopBits(window_widgets->stop_bits_box->value()));
  if(currentText() != "")
  {
    serial_port->setPort(QSerialPortInfo(currentText()));
  }
}
void PortComboBox::newMessage()
{
  QByteArray data = serial_port->readAll();
  QString message = QString::fromUtf8(data);

  window_widgets->output_box->newInputMessage(message.trimmed());
}

