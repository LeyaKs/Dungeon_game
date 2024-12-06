#ifndef LOCK_PICKS_H
#define LOCK_PICKS_H

#include "object.h"

class LockPicks: public Object {
    private:
        int count;
    public:
        LockPicks() = default;
        LockPicks(std::string _name, int _count): Object(_name), count(_count) {};
        int get_count() const;
        void change_count(int);
        ~LockPicks() = default;
};

#endif