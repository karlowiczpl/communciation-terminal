#include "PlainTextEdit.h"

PlainTextEdit::PlainTextEdit()
{
  setReadOnly(true);

  input_format.setForeground(Qt::blue);
  output_format.setForeground(Qt::green);
}
void PlainTextEdit::newInputMessage(const QString &message)
{
  QTextCursor cursor = textCursor();
  cursor.movePosition(QTextCursor::End);

  cursor.setCharFormat(input_format);
  cursor.insertText(message + "\n");
}
void PlainTextEdit::newOutputMessage(const QString &message)
{

}
