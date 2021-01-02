#include "coloredText.h"
#include <iostream>
#include <string>

using namespace std;

void info(std::string text) {
    cout << BOLDCYAN << "INFO: " << WHITE << text << "\n";
}

void error(std::string text) {
    cout << BOLDRED << "ERROR: " << WHITE << text << "\n";
}

void warning(std::string text) {
    cout << BOLDYELLOW << "WARNING: " << WHITE << text << "\n";
}

void user(std::string text) {
    cout << BOLDBLUE << "USER: " << WHITE << text << "\n";
}

void extra(std::string type, std::string text) {
    cout << BOLDMAGENTA << type << ": " << WHITE << text << "\n";
}