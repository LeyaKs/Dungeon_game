/**
     * \file
    * \brief Header file with description of functions of class armor and enum class type_of_armor
*/


#ifndef ARMOR_H
#define ARMOR_H

#include "object.h"


/**
    * \enum type_of_armor
    * \brief Enum class type_of_armor with available armor
*/

enum class type_of_armor{helmet, breastplate, gauntlet, pauldron, greaves,
                        sabaton};


/**
    * \class Armor
    * \brief Child class Armor from class Object
    * 
    * Contains the name, type of armor and protection value fields, constructors and functions
*/
class Armor: public Object {
    private:
        type_of_armor type;
        int protection;
    public:
        Armor() = default;
        Armor(std::string _name, type_of_armor _type, int _protection): 
            Object(_name), type(_type), protection(_protection) {};
        
        /**
            * \brief Setting type of armor
            * \param type of armor 
        */
        void set_type(type_of_armor);

        /**
            * \brief Setting protection
            * \param protection
        */
        void set_protection(int);


        /**
            * \brief Getting type_of armor
             * \return type of armor 
         */
        type_of_armor get_type() const;

        /**
             * \brief Getting protection
             * \return protection
        */
        int get_protection() const;
        ~Armor() = default;
};

#endif