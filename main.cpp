#include <iostream>

#include "includes/process_observer.h"
#include "includes/abstract_logger.h"
#include "includes/cli_logger.h"
#include "includes/remote_logger.h"

int main()
{
    // TODO: сраспараллелить блокирующие операции
    ProcessObserver po();

    AbstractLogger* log1 = new CliLogger();
    AbstractLogger* log2 = new RemoteLogger();

    po.addLogger(log1);
    po.addlogger(log2);

    po.run();

    std::cin.get();

    return 0;
};