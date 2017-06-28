#include <iostream>

#include "includes/inotify.h"
#include "includes/process_observer.h"

int main()
{
    // Inotify fw = Inotify((char*)"./file");

    // while (1) {
    //     fw.watch();
    // } 

    ProcessObserver po(4326);

    std::cout << po.getProcessId();

    std::cin.get();

    return 0;
};