/**
    * \file
    * \brief Header file with description of functions of class entity
*/
#ifndef ENTITY_H
#define ENTITY_H

#include "point.h"

/**
    * \class Enemy
    * \brief Abstract class Entity
    * 
    * Contains point, constructors and functions
*/
class Entity {
    private:
        Point point;
    public:
        Entity() = default;
        Entity(Point coords) : point(coords) {};



        /**
            * \brief Setting point
            * \param point
        */
        void set_point(Point);


        /**
            * \brief Getting point
            * \return point
        */
        Point get_point() const;
        virtual ~Entity() = default;
};

#endif