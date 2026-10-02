#include "audiomgr.h"
#include <SDL2/SDL.h>
#include <SDL_mixer.h>
#include <SDL_rwops.h>
#include <iostream>

A_Mgr::A_Mgr() {}
A_Mgr::~A_Mgr() {}

bool A_Mgr::init() {
  ;
  ;

  if (SDL_Init(SDL_INIT_AUDIO)) {
    std::cerr << "ERROR:SDL初始化失败！" << '\n';
    std::cerr << "  " << SDL_GetError() << std::endl;
    return 0;
  }

  if (!Mix_Init(MIX_INIT_MP3)) {
    std::cerr << "ERROR:Mixer初始化失败！" << '\n';
    std::cerr << "  " << Mix_GetError() << std::endl;
    return 0;
  }

  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
    std::cerr << "ERROR:打开音频设备失败！" << '\n';
    std::cerr << "  " << Mix_GetError() << std::endl;
    return 0;
  }

  return 1;
}

bool A_Mgr::free() {
  Mix_FreeMusic(fm_music);
  Mix_CloseAudio();
  SDL_Quit();
  return 1;
}

void A_Mgr::play_music() {
  Mix_PlayMusic(fm_music, 0);
  while (Mix_PlayingMusic()) {
    SDL_Delay(10);
  }
}

bool A_Mgr::load_music(const char *music_path) {
  fm_music = Mix_LoadMUS(music_path);
  if (!fm_music) {
    std::cerr << "ERROR:加载音频失败！" << '\n';
    std::cerr << "  " << Mix_GetError() << std::endl;
    return 0;
  }
  return 1;
}

bool A_Mgr::load_music_from_array(unsigned char data[], unsigned int &size) {
  SDL_RWops *rw_music = SDL_RWFromConstMem(data, size);
  if (!rw_music) {
    return 0;
  }

  fm_music = Mix_LoadMUS_RW(rw_music, 1);
  if (!fm_music) {
    SDL_RWclose(rw_music);
    return 0;
  }

  return 1;
}
