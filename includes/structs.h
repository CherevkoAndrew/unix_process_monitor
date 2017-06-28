#pragma once

#include <string>

struct proc_shot {
    int pid;
    std::string comm;
    char state;
    int ppid;
    int pgrp;
    int session;
    int tty_nr;
    int tpgid;
    unsigned int flags;
    long unsigned int cminflt;
    long unsigned int majflt;
    long unsigned int utime;
    long unsigned int stime;
    long int cutime;
    long int cstime;
    long priority;
    long int nice;
    long int num_threads;
    long int itervalue;
    unsigned long long int starttime;
    unsigned long int vsize;
};