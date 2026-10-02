#pragma once
#include <fstream>
#include <string>

class Fm_Finder {
public:
  Fm_Finder();
  ~Fm_Finder();

  bool load_string(const char *str);
  bool load_file(const char *path);

  bool find_feima();

  std::string get_buffer();

private:
  std::ifstream file;
  std::string buffer;
};
