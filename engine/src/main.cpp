#include <iostream>

#include <core/window.hpp>
#include <core/types.hpp>

int main() {

    Duq::Window mainWindow(Duq::Resolution{400, 500}, "Duq Engine");

    mainWindow.initWindow();

    mainWindow.update();

    mainWindow.closeWindow();

    return 0;

}