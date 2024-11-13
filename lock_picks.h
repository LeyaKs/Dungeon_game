#ifndef LOCK_PICKS_H
#define LOCK_PICKS_H

#include "object.h"

class LockPicks: public Object {
    private:
        int count;
    public:
        LockPicks() = default;
        void set_count(int);
        int get_count() const;
        ~LockPicks() = default;
};

#endif