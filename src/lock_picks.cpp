#include "headers/lock_picks.h"

void LockPicks::change_count(int _count) {
    count += _count;
}

int LockPicks::get_count() const {
    return count;
}
