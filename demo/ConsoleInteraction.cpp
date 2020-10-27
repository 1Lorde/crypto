#include "ConsoleInteraction.h"
#include <string>
#include <iostream>
#include <Number.h>

using namespace std;

ConsoleInteraction::ColorsMap ConsoleInteraction::colorsMap_ = {
        {RED, "\x1B[31mTEXT\033[0m"},
        {GREEN, "\x1B[32mTEXT\033[0m"},
        {BLUE, "\x1B[34mTEXT\033[0m"},
        {YELLOW, "\x1B[93mTEXT\033[0m"},
        {DARK_YELLOW, "\x1B[33mTEXT\033[0m"},
        {GREY, "\033[3;47;30mTEXT\033[0m"},
};

void ConsoleInteraction::print(string text, Colors color){
	string colorStr = colorsMap_[color];
	string leftPart = colorStr.substr(0, colorStr.find("TEXT"));
	string rightPart = colorStr.substr(colorStr.find("TEXT")+4, colorStr.length()-1);

	printf("%s%s%s", leftPart.c_str(), text.c_str(), rightPart.c_str());
}

void ConsoleInteraction::print(string text){
    printf("%s",text.c_str());
}

void ConsoleInteraction::clearOutput() {
#ifdef _WIN64
    system("cls");
#endif

#ifdef linux
    system("clear");
#endif
}

void ConsoleInteraction::pause() {
#ifdef _WIN64
    print("\n\nPress <ENTER> to continue..");
    getch();
#endif

#ifdef linux
    print("\n\nPress <ENTER> to continue..");
    int ch = getchar();
    while (ch != '\n')
        ch = getchar();
#endif
}

int ConsoleInteraction::inputInteger(string varName) {
    string value;
    cout << "Enter " << varName << " = ";
    getline(cin, value);
    return stoi(value);
}

int ConsoleInteraction::inputInteger() {
    string value;
    print(">>> ", GREEN);
    getline(cin, value);
    return stoi(value);
}

long long ConsoleInteraction::inputBigInteger(string varName) {
    string value;
    cout << "Enter " << varName << " = ";
    getline(cin, value);
    return stoll(value);
}

Number ConsoleInteraction::inputNumber(string varName) {
    long long a, n;
    cout << varName << "{" << endl;
    cout << "\tEnter a = ";
    cin >> a;
    cout << "\tEnter n = ";
    cin >> n;
    cout << "}" << endl;
    return {a, n};
}

