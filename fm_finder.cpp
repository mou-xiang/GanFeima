#include "fm_finder.h"
#include <fstream>
#include <iostream>
#include <iterator>

Fm_Finder::Fm_Finder() {
    buffer.clear();
}

Fm_Finder::~Fm_Finder() {

}

bool Fm_Finder::loadString(const char* str) {
    buffer = str;

    return !buffer.empty();
}

bool Fm_Finder::loadFile(const char* path) {
    file.open(path);
    if (!file) return 0;

    buffer.assign(
        std::istreambuf_iterator<char>(file),
        std::istreambuf_iterator<char>()
    );
    // std::cout << buffer;
    return 1;
}

std::string Fm_Finder::get_buffer() {
    return buffer;
}
