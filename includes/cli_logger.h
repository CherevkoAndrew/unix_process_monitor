#pragma once

#include "abstract_logger.h"

class CliLogger : AbstractLogger {
    public:
        virtual template<class Collection> void log(Collection& procList);
}