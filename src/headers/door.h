/**
    * \file
    * \brief Header file with description of functions of class door
*/

#ifndef DOOR_H
#define DOOR_H


#include "construction.h"

/**
    * \enum type_of_door
    * \brief Enum class type_of_door with available door status
*/
enum class type_of_door{opened, closed};



/**
    * \class Door
    * \brief Child class Door from class Construction
    * 
    * Contains level of padlock and door type fields, constructors and functions
*/
class Door: public Construction {
    private:
        int level_padlock = 0;
        type_of_door type;
    public:
        Door(): type(type_of_door::closed) {};
        // Door (type_of_door _type, int _lvl): type(_type), level_padlock(_lvl) {};
        Door(Point _point, type_of_door _type, int _lvl): Construction(_point), type(_type), level_padlock(_lvl) {};

        /**
            * \brief Setting type of door
            * \param door type
        */        
        void set_type(type_of_door);


        /**
            * \brief Getting type of door
            * \return door type
        */
        type_of_door get_type() const;


        /**
            * \brief Getting level of padlock
            * \return value of level
        */
        int get_level_padlock() const;
        ~Door() = default;
};

#endif