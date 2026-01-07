#ifndef APP_H
#define APP_H
#include "StoryGenerator.h"

class App
{
public:
    App();
    void Run();

private:
    void showmenu();
    void handlechoice(int choice);
    bool mIsRunning;
    StoryGenerator generator;
};

#endif
