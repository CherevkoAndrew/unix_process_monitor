#pragma once

#include <string>

class Inotify {
    public:
        Inotify(std::string filename);
        Inotify(char* filename);
        ~Inotify();

        void watch();
        void setListener(void (*f)(int pid));
    private:
        // notify listener
        void handleChange(struct inotify_event*);
  
        std::string filename;
        int fd;
        int wd;

        void (*callback)(int pid)
};