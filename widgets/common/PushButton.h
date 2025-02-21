#ifndef PUSH_BUTTON_H
#define PUSH_BUTTON_H

#include <QObject>
#include <QPushButton>
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
#include <QWidget>

class PushButton : public QPushButton
{
  Q_OBJECT
public:
  PushButton(int type);
  void connected(bool en);

protected:
  virtual void paintEvent(QPaintEvent* e) override;

private:
  int type;
  bool isConnected;

  /*PortComboBox* port_box;*/
};

#endif // PUSH_BUTTON_H
