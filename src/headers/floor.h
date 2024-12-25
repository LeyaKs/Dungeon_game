/**
    * \file
    * \brief Header file with description of functions of class floor
*/
#ifndef FLOOR_H
#define FLOOR_H

#include "construction.h"


/**
    * \class Floor
    * \brief Child class Floor from class Construction
*/
class Floor: public Construction {
    public:
        Floor() = default;
        //Floor(int _x, int _y) : Construction(Point(_x, _y)) {};
        virtual ~Floor() = default;
};

#endif