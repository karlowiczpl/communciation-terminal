#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QString>
#include <QSerialPort>
#include <QFile>
#include <QDir>
#include <QDebug>

typedef struct 
{
  QString key;
  int data;
}__CONF_T;
typedef struct
{
  int count;
  __CONF_T* config;
}CONFIGURATION_T;

class Configuration
{
public:
  Configuration();
  CONFIGURATION_T* getConfiguration();
  int getValue(const QString &label);

private:
  bool fileExists();

private:
  CONFIGURATION_T config;
};

#endif // !CONFIGURATION_H
