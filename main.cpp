#include "fm_finder.h"
#include "audiomgr.h"
#include "./assets/gfms.h"
#include <SDL2/SDL.h>
#include <SDL_mixer.h>
#include <cstring>
#include <iostream>

int main(int argc, char *argv[]) {
  // std::cout << "Hello world!" << '\n';


  std::cout << "输入含有飞马的文本开始干飞马" << std::endl;



  if (argc == 1) {
    std::cout << "Usage: \n";
    std::cout << "    gfma -Str [String]\n";
    std::cout << "    gfma -File [File Path]\n";
    std::cout << "    gfma -Interactive\n";
    std::cout << "    gfma -Desktop\n";

    return 1;
  }

  A_Mgr g_mgr;
  g_mgr.init();
  g_mgr.load_music_from_array(__assets_gfms_mp3, __assets_gfms_mp3_len);


  Fm_Finder g_finder;

  if (!strcmp(argv[1], "-Str")) {
    g_finder.load_string(argv[2]);
  } else if (!strcmp(argv[1], "-File")) {
    g_finder.load_file(argv[2]);
  }
  // std::cout << "buffer:" << g_finder.get_buffer() << std::endl;

  if (g_finder.find_feima()) {
    g_mgr.play_music();
  }

  // 释放资源
  g_mgr.free();


  return 0;
}
