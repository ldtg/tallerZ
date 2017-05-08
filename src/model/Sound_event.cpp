//
// Created by darius on 05/05/17.
//

#include "Sound_event.h"

Sound_event::Sound_event(char *sound_file_path, unsigned int replays) {
    SDL_Init(SDL_INIT_AUDIO);
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
    sound = Mix_LoadWAV(sound_file_path);
    if (sound == NULL){
        std::cout << "null\n";
    }
    this->replays = replays;
}

void Sound_event::play() {
    char c = '\0';
    while (c != 'q'){
        if (Mix_PlayChannel(-1,sound,replays) == ERROR){
            //throw exception
            std::cout << "Error en play de Sound_event.h\n";
        };
        std::cin.get(c);
    }
}

Sound_event::~Sound_event() {
    Mix_FreeChunk(sound);
    Mix_CloseAudio();
}
