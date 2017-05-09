
#include <iostream>
#include "Sound_event.h"

void sound_event_test1(){
    std::string sound_path = "/home/darius/CLionProjects/tallerZ/z_sounds/acknowledge_08.wav";
    Sound_event sound(&sound_path[0],0);
    sound.play();
}
int main() {
    sound_event_test1();
    return 0;
}