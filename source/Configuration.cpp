#include "Configuration.h"

__CONF_T default_config[5] = {
  {"baudrate" , QSerialPort::Baud115200},
  {"parity" , QSerialPort::NoParity},
  {"stop_bits" , QSerialPort::OneStop},
  {"data_bits" , QSerialPort::Data8},
  {"flow_control" , QSerialPort::NoFlowControl},
};

Configuration::Configuration()
{
  if(fileExists())
  {

  }
  else
  {
    config.config = default_config;   
    config.count = 5;
  }
}
CONFIGURATION_T* Configuration::getConfiguration()
{
  return &config;
}
bool Configuration::fileExists()
{
  QString path = QDir::currentPath() + "/config.txt";
  if(QFile::exists(path))
  {
    return true;
  }
  else
  {
    return false;
  }
}
int Configuration::getValue(const QString &key)
{
  for(int i = 0; i < config.count; i++)
  {
    if(key == config.config[i].key) 
    {
      return config.config[i].data;
    }
  }
  return config.config[0].data;
}

