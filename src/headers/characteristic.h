/**
    * \file
    * \brief Header file with description of functions of class characteristic
*/


#ifndef CHARACTERISTIC_H
#define CHARACTERISTIC_H

#include <string>


/**
    * \enum type_of_characteristic
    * \brief Enum class type_of_characteristic with available characteristic
*/

enum class type_of_characteristic{strength, agility, endurance,
                                    max_health, curr_health};


/**
    * \class Characteristic
    * \brief Class Characteristic with functions
    * 
    * Contains the type of characteristic and value fields, constructors and functions
*/
class Characteristic {
    private:
        type_of_characteristic type;
        int value = 0;
    public:
        Characteristic() = default;

        /**
            * \brief Setting type of characteristic
            * \param type of characteristic
        */
        void set_type(type_of_characteristic);


        /**
            * \brief Changing value of characteristic
            * \param value
        */      
        void change_value(int);


        /**
            * \brief Getting type of characteristic
            * \return type of characteristic
        */
        type_of_characteristic get_type() const;


        /**
            * \brief Getting value of characteristic
            * \param value
        */ 
        int get_value() const;
        ~Characteristic() = default;
};

#endif