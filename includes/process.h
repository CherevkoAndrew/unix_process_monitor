#pragma once

class Process {
    public:
        ProcessObserver(int id);

        int getProcessId();
        void update();

    private:
        int pid;
        struct proc_shot* shot;
};