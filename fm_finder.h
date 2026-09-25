#pragma once
#include <fstream>
#include <string>

class Fm_Finder {
public:
  Fm_Finder();
  ~Fm_Finder();

  bool loadString(const char *str);
  bool loadFile(const char *path);

  std::string get_buffer();

private:
  std::ifstream file;
  std::string buffer;
};
