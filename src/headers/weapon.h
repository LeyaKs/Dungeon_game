/**
    * \file
    * \brief Header file with description of functions of class weapon
*/
#ifndef WEAPON_H
#define WEAPON_H

#include <memory>
#include "object.h"

/**
    * \enum type_value
    * \brief Enum class type_value with available types
*/
enum class type_value{ordinary, valuable};

class Enemy;


/**
    * \class Weapon
    * \brief Child class Weapon from class Object
    * 
    * Contains value type, damage, constructors and functions
*/
class Weapon: public Object {
    private:
        int damage;
        type_value value;
    public:
        Weapon() = default;
        Weapon(std::string _name, int _damage, type_value _value): Object(_name),
            damage(_damage), value(_value) {};

        /**
            * \brief Setting damage
            * \param damage
        */                   
        void set_damage(int);



        /**
            * \brief Setting value type
            * \param value type
        */  
        void set_value(type_value);


        /**
            * \brief Getting damage
            * \return damage
        */     
        int get_damage() const;


        /**
            * \brief Getting value type
            * \return value type
        */        
        type_value get_type() const;


        /**
            * \brief generating damage
            * \param enemy
            * \return damage
        */  
        virtual int generate_damage(const std::shared_ptr<Enemy>& = nullptr);
        virtual ~Weapon() = default; 
};

#endif