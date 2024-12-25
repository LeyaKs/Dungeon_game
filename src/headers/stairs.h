/**
     * \file
    * \brief Header file with description of functions of class stairs and enum class type_of_stairs
*/

#ifndef STAIRS_H
#define STAIRS_H

#include "construction.h"

/**
    * \enum type_of_stairs
    * \brief Enum class type_of_stairs with available type
*/
enum class type_of_stairs{up, down};



/**
    * \class Stairs
    * \brief Child class Stairs from class Construction
    * 
    * Contains type of stairs, constructors and functions
*/
class Stairs: public Construction {
    private:
        type_of_stairs type;
    public:
        Stairs() = default;
        Stairs(Point _point, type_of_stairs _type): Construction(_point), type(_type) {};

        /**
            * \brief Setting type of stairs
            * \param type of stairs
        */
        void set_type(type_of_stairs);

        /**
            * \brief Getting type of armor
            * \return type of stairs 
        */
        type_of_stairs get_type() const;

        virtual ~Stairs() = default;
};

#endif