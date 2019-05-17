cmake_minimum_required(VERSION 3.12)
project(TrabalhoTP1)

add_executable(TesteDominEntidade test/Teste_Dominios.cpp source/Dominios.cpp include/Dominios.h source/Entidades.cpp include/Entidades.h include/Dominios.h test/Teste_Entidades.cpp)
add_executable(Qt main.cpp mainwindow.cpp mainwindow.h mainwindow.ui)


# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

set(Qt5Widgets_DIR /home/pedro/Programas/Qt/5.12.3/gcc_64/lib/cmake/Qt5Widgets)
set(Qt5Gui_DIR /home/pedro/Programas/Qt/5.12.3/gcc_64/lib/cmake/Qt5Gui)
set(Qt5Svg_DIR /home/pedro/Programas/Qt/5.12.3/gcc_64/lib/cmake/Qt5Svg)
# Find the QtWidgets library
find_package(Qt5Widgets CONFIG)
find_package(Qt5Gui)
find_package(Qt5Svg)
find_package(Qt5Core)
find_package(SQLite3)
# Populate a CMake variable with the sources
set(helloworld_SRCS
        mainwindow.ui
        mainwindow.cpp
        main.cpp
        source/Entidades.cpp
        source/Dominios.cpp
        source/Model.cpp
        )


# Tell CMake to create the helloworld executable
add_executable(helloworld WIN32 ${helloworld_SRCS})

# Use the Widgets module from Qt 5
target_link_libraries(helloworld Qt5::Widgets)
target_link_libraries(helloworld sqlite3)

get_target_property(QtCore_location Qt5::Core LOCATION)

find_package(Qt5Core)
set(CMAKE_CXX_FLAGS_COVERAGE "${CMAKE_CXX_FLAGS_RELEASE} -fprofile-arcs -ftest-coverage")

# set up a mapping so that the Release configuration for the Qt imported target is
# used in the COVERAGE CMake configuration.
set_target_properties(Qt5::Core PROPERTIES MAP_IMPORTED_CONFIG_COVERAGE "RELEASE")


foreach(plugin ${Qt5Network_PLUGINS})
    get_target_property(_loc ${plugin} LOCATION)
    message("Plugin ${plugin} is at location ${_loc}")
endforeach()

