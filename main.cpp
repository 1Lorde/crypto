//
// created by Vlad Savchuk on 22/09/20.
//

#include <iostream>
#include <ConsoleInteraction.h>
#include <Menu.h>

using namespace std;

void startDemo() {
    ConsoleInteraction::clearOutput();
    ConsoleInteraction::print("### This program developed by Vlad Savchuk.\n", ConsoleInteraction::BLUE);
    ConsoleInteraction::pause();
    Menu::handleInputInMainMenu();
}

int main() {
    startDemo();
    return 0;
}
