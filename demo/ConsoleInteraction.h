#ifndef SAVCHUK_PRIMENUMBERGENERATOR_H
#define SAVCHUK_PRIMENUMBERGENERATOR_H

#include <map>
#include <string>
#include <Number.h>

/*
 *  Class that represents interactions with CLI.
 *
 *  created by Vlad Savchuk on 24/10/2020.
 */
class ConsoleInteraction{
public:
    enum Colors {RED, GREEN, BLUE, YELLOW, DARK_YELLOW, GREY};

    //dictionary with ASCII codes of colors
    typedef std::map<int, std::string> ColorsMap;
    static ColorsMap colorsMap_;

    //print colorized text
    static void print(std::string text, Colors color);

    //print regular text
    static void print(std::string text);

    //clear console
    static void clearOutput();

    //wait for user input
    static void pause();

    //handle 32 bit numbers input
    static int inputInteger(std::string varName);

    //handle 32 bit numbers input
    static int inputInteger();

    //handle 64 bit numbers input
    static long long int inputBigInteger(std::string varName);

    //handle Number object input
    static Number inputNumber(std::string varName);

};

#endif //SAVCHUK_PRIMENUMBERGENERATOR_H



