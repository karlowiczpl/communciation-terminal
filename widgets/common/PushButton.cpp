#include "PushButton.h"

PushButton::PushButton(int type) : type(type)
{
  setFocusPolicy(Qt::StrongFocus);
}
void PushButton::keyPressEvent(QKeyEvent* e)
{
  qDebug() << "test";
}
