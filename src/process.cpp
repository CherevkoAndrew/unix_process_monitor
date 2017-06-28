#include "../includes/structs.h"

#include <iostream>
#include <fstream>
#include <string>

#define PROC "/proc/"
#define STAT "/stat"

/*
* helper function that accepts ifstream of /proc/*pid/stat file
* and returns proc_shot structure
*/ 
struct proc_shot* parseStat(std::ifstream& stat) {
    struct proc_shot* ret = new proc_shot;
    
    stat >> ret->pid >> ret->comm >> ret->state >> ret->ppid >>ret->pgrp;
    stat >> ret->session >> ret->tty_nr >> ret->tpgid >> ret->flags >> ret->cminflt;
    stat >> ret->majflt >> ret->utime >> ret->stime >> ret->cutime >> ret->cstime;
    stat >> ret->nice >> ret->num_threads >> ret->itervalue >> ret->starttime >> ret->vsize; 
    
    return ret;
};

Process::Process(int id) {
    this->pid = id;
    std::string proc(PROC);

    std::ifstream procFile(proc + std::to_string(id) + "/stat");

    if (procFile) {
        this->shot = parseStat(procFile);
        procFile.close();
    } else {
        // error
        std::cout << "warning: cant find folder";
    }

}

int Process::getProcessId() {
    return this->pid;
}

void Process::update() {

}