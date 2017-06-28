#pragma once

#include "abstract_logger.h"

class RemoteLogger : AbstractLogger {
    public:
        virtual template<class Collection> void log(Collection& procList);
}