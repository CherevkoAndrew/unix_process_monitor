#include "../includes/process_observer.h"

#include "process.h"
#include "abstract_logger.h"
#include "inotify.h"

ProcessObserver::ProcessObserver() {
    watcher = new Inotify("/proc");

    watcher.
}

ProcessObserver::ProcessObserver() {
    // delete* this->plist
    // delete* this->loggers
    delete this->watcher;
}

void ProcessObserver::update(int pid) {
    if (this->plist[pid]) {
        this->plist[pid].update();
    }

    this->log();
}

void ProcessObserver::run() {
    this->watcher->watch();
}

void ProcessObserver::log() {
    for (std::list<int>::iterator it=this->loggers.begin(); it != mylist.end(); ++it) {
        it->log();
    }
}
 