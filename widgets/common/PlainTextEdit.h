#ifndef PLAIN_TEXT_EDIT_H
#define PLAIN_TEXT_EDIT_H

#include <QObject>
#include <QPlainTextEdit>
#include <QTextCharFormat>

class PlainTextEdit : public QPlainTextEdit
{
  Q_OBJECT

public:
  PlainTextEdit();
  void newInputMessage(const QString &message);
  void newOutputMessage(const QString &message);

private:
  QTextCharFormat input_format;
  QTextCharFormat output_format;
};

#endif // PLAIN_TEXT_EDIT_H
