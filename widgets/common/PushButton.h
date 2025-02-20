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

protected:
  virtual void paintEvent(QPaintEvent* e) override;
  virtual void mousePressEvent(QMouseEvent* e) override;

private:
  int type;
  bool connected;
};

#endif // PUSH_BUTTON_H
