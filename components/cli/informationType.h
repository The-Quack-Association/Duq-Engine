#include "coloredText.h"
#include <iostream>
#include <string>

using namespace std;

void simple(string text = "Simple Text") {

    cout << text << endl;

}

void info(string text = "Info") {
    cout << BOLDCYAN << "INFO: " << WHITE << text << endl;
}

void error(string text = "An error has occurred") {
    cout << BOLDRED << "ERROR: " << WHITE << text << endl;
}

void warning(string text = "Something may have happened") {
    cout << BOLDYELLOW << "WARNING: " << WHITE << text << endl;
}

void user(string text = "User") {
    cout << BOLDBLUE << "USER: " << WHITE << text << endl;
}

void debug(string text = "Debug") {
    cout << BOLDGREEN << "DEBUG: " << WHITE << text << endl;
}

void extra(string type, string text = "Extra information and text") {
    cout << BOLDMAGENTA << type << ": " << WHITE << text << endl;
}