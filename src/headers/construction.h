/**
    * \file
    * \brief Header file with description of functions of class construction
*/


#ifndef CONSTRUCTION_H
#define CONSTRUCTION_H

#include <string>
#include "entity.h"



/**
    * \class Construction
    * \brief Child abstract class Construction from class Entity and parent class for Door, Stairs and Floor
    *
    * Contains constructors
*/
class Construction: public Entity {
    public:
        Construction() = default;
        Construction(Point _entity): Entity(_entity) {};
        virtual ~Construction() = default;
};

#endif