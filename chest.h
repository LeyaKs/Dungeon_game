#ifndef CHEST_H
#define CHEST_H

#include "object.h"
#include "entity.h"

class Chest: public Entity {
    private:
        int level_padlock;
        Object *object;
    public:
        Chest() = default;
        void set_level_padlock(int);
        void set_object(Object *);
        int get_level_padlock() const;
        Object *get_object() const;
        void try_open();
        ~Chest() = default;
};

#endif