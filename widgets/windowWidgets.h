#ifndef WINDOW_WIDGETS_H
#define WINDOW_WIDGETS_H

#include "common/PushButton.h"
#include "common/ComboBox.h"
#include "common/LineEdit.h"
#include "common/PlainTextEdit.h"

typedef struct 
{
  PushButton* connect_button;
  PushButton* send_button;
  LineEdit* input_line;
  PlainTextEdit* output_box;
  ComboBox* baud_rate_box;
  ComboBox* data_bits_box;
  ComboBox* stop_bits_box;
  ComboBox* parity_box;
  ComboBox* flow_control_box;
}WINDOW_WIDGETS_T;

#endif // !WINDOW_WIDGETS_H
