//
// Created by darius on 09/05/17.
//

#include "../../z_sounds/Sound_event.h"
#include "gtest/gtest.h"

class Sound_Tests : public ::testing::Test {
public:
    Sound_event * sound;
    std::string audio_path = "/home/darius/CLionProjects/tallerZ/z_sounds/acknowledge_08.wav";

    Sound_Tests() : Test() {
        sound = new Sound_event(&audio_path[0],0);
    }

    ~Sound_Tests(){
        delete sound;
    }
};


TEST_F(Sound_Tests, test1){
    sound->play();
    ::sleep(1);
    EXPECT_EQ(1,1);
}