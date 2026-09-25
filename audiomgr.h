#pragma once

#include <SDL_mixer.h>

class A_Mgr {
public:
  A_Mgr();
  ~A_Mgr();

  bool init();
  bool free();
  void playMusic();
  bool loadMusic(const char* music_path);
  bool loadMusicFromArray(unsigned char data[], unsigned int& size);

private:
    Mix_Music* fm_music;
};
