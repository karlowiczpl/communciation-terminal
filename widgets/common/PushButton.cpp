#include "PushButton.h"

PushButton::PushButton(int type) : type(type) , isConnected(false)
{
  setFocusPolicy(Qt::StrongFocus);

  if(type)
  {
    setText("Send");
  }
}
void PushButton::connected(bool con)
{
  if(!type)
  {
    isConnected = con;
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
    if(isConnected)
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
