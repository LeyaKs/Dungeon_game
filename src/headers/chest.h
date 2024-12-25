/**
    * \file
    * \brief Header file with description of functions of class chest
*/


#ifndef CHEST_H
#define CHEST_H

#include "object.h"
#include "entity.h"
#include <memory>




/**
    * \class Chest
    * \brief Child class Chest from class Entity
    * 
    * Contains the level of padlock and pointer to object, constructors and functions
*/
class Chest: public Entity {
    private:
        int level_padlock;
        std::shared_ptr<Object> object;
    public:
        Chest() = default;
        Chest(Point _entity, int _level_padlock, const std::shared_ptr<Object>& _object):
                Entity(_entity), level_padlock(_level_padlock), object(_object) {};

        /**
            * \brief Setting level of padlock
            * \param value of level
        */
        void set_level_padlock(int);


        /**
            * \brief Setting object
            * \param const pointer to object
        */
        void set_object(const std::shared_ptr<Object>&);
 
 
         /**
            * \brief Getting level of padlock
            * \return value of level
        */
        int get_level_padlock() const;



        /**
            * \brief Trying to open chest
            * \param value of agility
            * \return pointer to object if it was sucсessful and nullptr if not
        */
        std::shared_ptr<Object> try_open(int);
        ~Chest() = default;
};

#endif