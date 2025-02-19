#include "ComboBox.h"

#define COMBO_BOX_TYPES_COUNT 5

TYPE_MAPPER* getMapper(int type);

MAPPER all_baud_rates[] = {
  {"1200" , QSerialPort::Baud1200},
  {"2400" , QSerialPort::Baud2400},
  {"4800" , QSerialPort::Baud4800},
  {"9600" , QSerialPort::Baud9600},
  {"19200" , QSerialPort::Baud19200},
  {"38400" , QSerialPort::Baud38400},
  {"57600" , QSerialPort::Baud57600},
  {"115200" , QSerialPort::Baud115200},
};
MAPPER all_parity[] = {
  {"No parity" , QSerialPort::NoParity},
  {"Even parity" , QSerialPort::EvenParity},
  {"Odd parity" , QSerialPort::OddParity},
  {"Space parity" , QSerialPort::SpaceParity},
  {"Mark parity" , QSerialPort::MarkParity},
};
MAPPER all_stop_bits[] = {
  {"One stop" , QSerialPort::OneStop},
  {"One and half stop" , QSerialPort::OneAndHalfStop},
  {"Two stop" , QSerialPort::TwoStop},
};
MAPPER all_data_bits[] = {
  {"5" , QSerialPort::Data5},
  {"6" , QSerialPort::Data6},
  {"7" , QSerialPort::Data7},
  {"7" , QSerialPort::Data7},
};
MAPPER all_flow_control[] = {
  {"No flow control" , QSerialPort::NoFlowControl},
  {"Hardware control" , QSerialPort::HardwareControl},
  {"Software control" , QSerialPort::SoftwareControl},
};
TYPE_MAPPER type_mapper[] = {
  {1 , 8 , all_baud_rates},
  {2 , 4 , all_data_bits},
  {3 , 3 , all_stop_bits},
  {4 , 5 , all_parity},
  {5 , 3 , all_flow_control},
};
ComboBox::ComboBox(int type) : type(type)
{
  if(type != 0)
  {
    TYPE_MAPPER* mapper = getMapper(type);
    for(int i = 0; i < mapper->size; i++)
    {
      addItem(mapper->mapper[i].label);
    }
  }
}
TYPE_MAPPER* getMapper(int type)
{
  for(int i = 0; i < COMBO_BOX_TYPES_COUNT; i++)
  {
    if(type_mapper[i].type == type)
    {
      return &type_mapper[i];
    }
  }
  return &type_mapper[0];
}
int ComboBox::value()
{
  TYPE_MAPPER* mapper = getMapper(type);
  for(int i = 0; i < mapper->size; i++)
  {
    if(mapper->mapper[i].label == currentText())
    {
      return mapper->mapper[i].data;
    }
  }
  return mapper->mapper[0].data;
}
