cmake_minimum_required(VERSION 3.27)
project(serial-terminal)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        SerialPort
        SerialBus
        REQUIRED)

set(source
)

set(widgets
  widgets/MainWindow.cpp
  widgets/MainWindow.h
  widgets/PortComboBox.cpp
  widgets/PortComboBox.h
)

set(common
  widgets/common/ComboBox.cpp
  widgets/common/ComboBox.h
  widgets/common/LineEdit.cpp
  widgets/common/LineEdit.h
  widgets/common/PlainTextEdit.cpp
  widgets/common/PlainTextEdit.h
  widgets/common/PushButton.cpp
  widgets/common/PushButton.h
)

add_executable(${PROJECT_NAME} main.cpp ${source}  ${widgets} ${common})

target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::SerialPort
        Qt5::SerialBus
)
