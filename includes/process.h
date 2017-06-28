#pragma once

class Process {
    public:
        Process(int id);
        ~Process();

        const int getProcessId();
        void update();

    private:
        int pid;
        struct proc_shot* shot;
};