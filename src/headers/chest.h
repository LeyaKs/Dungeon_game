#ifndef CHEST_H
#define CHEST_H

#include "object.h"
#include "entity.h"
#include <memory>

class Chest: public Entity {
    private:
        int level_padlock;
        std::shared_ptr<Object> object;
    public:
        Chest() = default;
        void set_level_padlock(int);
        void set_object(std::shared_ptr<Object>);
        int get_level_padlock() const;

        std::shared_ptr<Object> try_open(int);
        ~Chest() = default;
};

#endif