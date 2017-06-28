#include <iostream>

#include "includes/inotify.h"

int main()
{
    Inotify fw = Inotify((char*)"./file");

    while (1) {
        fw.watch();
    } 

    std::cin.get();

    return 0;
};