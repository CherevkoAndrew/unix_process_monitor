#include "../includes/inotify.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/inotify.h>

#define EVENT_SIZE  ( sizeof (struct inotify_event) )
#define BUF_LEN     ( 1024 * ( EVENT_SIZE + 16 ) )

Inotify::Inotify(std::string filename) {
    this->filename = filename;
    this->fd = inotify_init();
};

Inotify::Inotify(char* filename) {
    this->filename = filename;
    this->fd = inotify_init();
}

Inotify::~Inotify () {
    inotify_rm_watch( fd, wd );
    close( fd );
}

void Inotify::watch () {
    int length, i = 0;
    char buffer[BUF_LEN];

    if ( this->fd < 0 ) {
        perror( "inotify_init" );
    }

    this->wd = inotify_add_watch( this->fd, this->filename.c_str(), 
                            IN_MODIFY | IN_CREATE | IN_DELETE );
    length = read( this->fd, buffer, BUF_LEN );  

    if ( length < 0 ) {
        perror( "read" );
    }
    while ( i < length ) {
        struct inotify_event *event = ( struct inotify_event * ) &buffer[ i ];
        handleChange(event);

        i += EVENT_SIZE + event->len;
    }
}

void Inotify::handleChange(struct inotify_event* event) {
    // TODO: call listener and pass process id as parameter
    if ( event->mask & IN_CREATE ) {
        if ( event->mask & IN_ISDIR ) {
          printf( "The directory %s was created.\n", event->name );       
        }
        else {
          printf( "The file %s was created.\n", event->name );
        }
    }
    else if ( event->mask & IN_DELETE ) {
        if ( event->mask & IN_ISDIR ) {
          printf( "The directory %s was deleted.\n", event->name );       
        }
        else {
          printf( "The file %s was deleted.\n", event->name );
        }
      }
      else if ( event->mask & IN_MODIFY ) {
        if ( event->mask & IN_ISDIR ) {
          printf( "The directory %s was modified.\n", event->name );
        }
        else {
          printf( "The file %s was modified.\n", event->name );
        }
    }
};

void setListener(void (*f)(int pid)) {
    // Как-то так, пока не проверял
    this->callback = f;
}