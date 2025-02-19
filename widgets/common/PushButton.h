#ifndef PUSH_BUTTON_H
#define PUSH_BUTTON_H

#include <QObject>
#include <QPushButton>
#include <QMouseEvent>
#include <QDebug>

class PushButton : public QPushButton
{
  Q_OBJECT
public:
  PushButton(int type);

protected:
  virtual void keyPressEvent(QKeyEvent* e) override;

private:
  int type;

};

#endif // PUSH_BUTTON_H
