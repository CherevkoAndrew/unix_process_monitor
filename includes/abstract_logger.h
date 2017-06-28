#pragma once

class AbstractLogger {
    public:
        virtual template<class Collection> void log(Collection& procList) = 0;
    private:
    /*
    * Helper comparators for sorting can be defined as:
    *-  bool sortByMemory(const Process* lhs,const Process* rhs) {
    *-    return lhs->vmSize < rhs->vmSize;
    *-  }
    */
}