#include "MainWindow.h"

MainWindow::MainWindow()
{
  QVBoxLayout* main_layout = createWindow();
  createWidgets();
  addItemsToMainLayout(main_layout);
}
void MainWindow::addItemsToMainLayout(QVBoxLayout* main_layout)
{
  auto* settings_layout = new QGridLayout; 
  main_layout->addLayout(settings_layout);
  addItemsToSettingsLayout(settings_layout);

}
void MainWindow::addItemsToSettingsLayout(QGridLayout* settings_layout)
{
  settings_layout->addWidget(port_box , 1 , 1);
  settings_layout->addWidget(window_widgets.baud_rate_box , 1 , 2);
  settings_layout->addWidget(window_widgets.data_bits_box , 2 , 1);
  settings_layout->addWidget(window_widgets.stop_bits_box , 2 , 2);
  settings_layout->addWidget(window_widgets.parity_box , 3 , 1);
  settings_layout->addWidget(window_widgets.flow_control_box , 3 , 2);
  settings_layout->addWidget(window_widgets.connect_button , 4 , 2);
}
void MainWindow::createWidgets()
{
  window_widgets.connect_button = new PushButton(0);
  window_widgets.send_button = new PushButton(1);
  window_widgets.input_line = new LineEdit;
  window_widgets.output_box = new PlainTextEdit;
  port_box = new PortComboBox();
  window_widgets.baud_rate_box = new ComboBox(1);
  window_widgets.data_bits_box = new ComboBox(2);
  window_widgets.stop_bits_box = new ComboBox(3);
  window_widgets.parity_box = new ComboBox(4);
  window_widgets.flow_control_box = new ComboBox(5);
}
QVBoxLayout* MainWindow::createWindow()
{
  resize(1000 , 1000);
  show();

  auto* central_widget = new QWidget;
  auto* main_layout = new QVBoxLayout;

  setCentralWidget(central_widget);
  central_widget->setLayout(main_layout);

  return main_layout;
}
