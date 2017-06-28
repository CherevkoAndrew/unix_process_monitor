#pragma once

#include "process.h"
#include "abstract_logger.h"
#include "inotify.h"

class ProcessObserver {
    public:
        ProcessObserver();
        ~ProcessObserver();

        void update(int pid);
        void addLogger(AbstractLogger* logger);
        void run();
    private:
        void log();//notify loggers

        std::vector<Process*> plist;

        std::list<AbstractLogger*> loggers;

        Inotify* watcher;
}