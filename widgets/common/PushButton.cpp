#include "PushButton.h"

PushButton::PushButton(int type) : type(type) , connected(false)
{
  setFocusPolicy(Qt::StrongFocus);

  if(type)
  {
    setText("Send");
  }
}
void PushButton::mousePressEvent(QMouseEvent* e)
{
  if(!type)
  {
    connected = !connected;
    update();
  }
}
void PushButton::paintEvent(QPaintEvent* e)
{
  QPushButton::paintEvent(e);

  QPainter painter(this);
  if(type)
  {

  }
  else 
  {
    if(connected)
    {
      painter.setPen(Qt::red);
      painter.drawText(rect() , Qt::AlignCenter , "Disconnect");
    }
    else
    {
      painter.setPen(Qt::blue);
      painter.drawText(rect() , Qt::AlignCenter , "Connect");
    }
  }
}
