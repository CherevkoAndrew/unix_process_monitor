# unix_process_monitor

uses unix inotify api to observe `/proc` directory,
stores statistics about active processes,
logs changes simultaneously via different `AbstractLogger` class implementations
