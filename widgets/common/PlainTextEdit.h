#ifndef PLAIN_TEXT_EDIT_H
#define PLAIN_TEXT_EDIT_H

#include <QObject>
#include <QPlainTextEdit>

class PlainTextEdit : public QPlainTextEdit
{
  Q_OBJECT

public:
  PlainTextEdit();
};

#endif // PLAIN_TEXT_EDIT_H
