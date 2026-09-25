#include "fm_finder.h"
#include <fstream>
#include <iostream>
#include <iterator>

Fm_Finder::Fm_Finder() {
    buffer.clear();
}

Fm_Finder::~Fm_Finder() {

}

bool Fm_Finder::load_string(const char* str) {
    buffer = str;

    return !buffer.empty();
}

bool Fm_Finder::load_file(const char* path) {
    file.open(path);
    if (!file) return 0;

    buffer.assign(
        std::istreambuf_iterator<char>(file),
        std::istreambuf_iterator<char>()
    );
    // std::cout << buffer;
    return 1;
}

bool Fm_Finder::find_feima() {
    if (buffer.empty()) {
        std::cerr << "buffer is empty!" << std::endl;
        return 0;
    }

    if (buffer.find("飞马") != std::string::npos) {
        return 1;
    } else {
        return 0;
    }

    return 0;

}

std::string Fm_Finder::get_buffer() {
    return buffer;
}
