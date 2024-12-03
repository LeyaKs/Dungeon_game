#ifndef LOCK_PICKS_H
#define LOCK_PICKS_H

#include "object.h"

class LockPicks: public Object {
    private:
        int count;
    public:
        LockPicks() = default;
        LockPicks(int _count): Object(), count(_count) {};
        void set_count(int);
        int get_count() const;
        ~LockPicks() = default;
};

#endif