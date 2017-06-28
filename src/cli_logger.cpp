#include "../includes/cli_logger.h"
#include "../includes/structs.h"

#include <iostream>
#include <unistd.h>
#include <term.h>

void clearScreen();
std::string format(Process* p);

void CliLogger::log(Collection& procList) {
    /*
    *   procList->sort(this->sortByMemory);
    */
    // Not the best way, bacause iteration through linked list will be nonn-optimal 
    for(int i = 0; i < procList.length; ++i) {
        std::cout << format(procList);
    }
}


void clearScreen() {
    if (!cur_term){
        int result;
        setupterm( NULL, STDOUT_FILENO, &result );
        if (result <= 0) return;
    }

    putp( tigetstr( "clear" ) );
}

std::string format(Process* p) {
    std::string ret = "";
    proc_shot* ps = p->getState();

    ret += ps->id + ' ' + ps->vsize;
};