#pragma once

#include <string>

class Inotify {
    public:
        Inotify(std::string filename);
        Inotify(char* filename);
        ~Inotify();
        
        void watch();
    private:
        void handleChange(struct inotify_event*);
  
        std::string filename;
        int fd;
        int wd;
};