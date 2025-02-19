#ifndef COMBO_BOX_H
#define COMBO_BOX_H

#include <QObject>
#include <QComboBox>
#include <QSerialPort>
#include <QDebug>

typedef struct 
{
  QString label;
  int data;
}MAPPER;
typedef struct 
{
  int type;
  int size;
  MAPPER* mapper;
}TYPE_MAPPER;

class ComboBox : public QComboBox
{
public:
  ComboBox(int type);
  int value();

private:
  int type;

};

#endif // !COMBO_BOX_H
