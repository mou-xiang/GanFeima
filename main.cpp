#include "fm_finder.h"
#include "audiomgr.h"
#include "./assets/gfms.h"
#include <SDL2/SDL.h>
#include <SDL_mixer.h>
#include <cstring>
#include <iostream>

int main(int argc, char *argv[]) {
  // std::cout << "Hello world!" << '\n';



  if (argc == 1) {
    std::cout << "Usage: \n";
    std::cout << "    gfma -Str [String]\n";
    std::cout << "    gfma -File [File Path]\n";
    std::cout << "    gfma -Desktop\n";
    return 1;
  }

  A_Mgr g_mgr;
  g_mgr.init();
  // g_mgr.loadMusic("/home/sun/Projects/GanFeima/assets/gfms.mp3");
  g_mgr.loadMusicFromArray(__assets_gfms_mp3, __assets_gfms_mp3_len);

  // Mix_Music *music_gfm = Mix_LoadMUS("/home/sun/Projects/GanFeima/assets/gfms.mp3");

  Fm_Finder g_finder;

  if (!strcmp(argv[1], "-Str")) {
    g_finder.loadString(argv[2]);
  } else if (!strcmp(argv[1], "-File")) {
    g_finder.loadFile(argv[2]);
  }
  std::cout << "buffer:" << g_finder.get_buffer() << std::endl;

  g_mgr.playMusic();

  // 释放资源
  g_mgr.free();


  return 0;
}
