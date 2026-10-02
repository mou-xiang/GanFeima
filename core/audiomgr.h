#pragma once

#include <SDL_mixer.h>

class A_Mgr {
public:
  A_Mgr();
  ~A_Mgr();

  bool init();
  bool free();
  void play_music();
  bool load_music(const char* music_path);
  bool load_music_from_array(unsigned char data[], unsigned int& size);

private:
    Mix_Music* fm_music;
};
