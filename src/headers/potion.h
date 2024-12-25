/**
     * \file
    * \brief Header file with description of functions of class potion
*/

#ifndef POTION_H
#define POTION_H

#include <vector>
#include "object.h"
#include "characteristics.h"

/**
    * \class Potion
    * \brief Child class Potion from class Object
    * 
    * Contains vector of characteristics and their values
*/
class Potion: public Object {
    private:
        Characteristics characteristics;
        std::vector<int> values;
    public:
        Potion() = default;
        Potion(std::string _name, const Characteristics& _characteristics, 
            const std::vector<int>& _values): Object(_name),
            characteristics(_characteristics), values(_values) {};
        
         /**
            * \brief Setting characteristics
            * \param characteristics
        */       
        void set_characteristics(const Characteristics&);

        /**
            * \brief Setting values
            * \param values
        */
        void set_values(const std::vector<int>&);

        /**
            * \brief Setting name
            * \param name
        */
        void set_name(std::string);

        /**
            * \brief Getting characteristics
            * \return characteristics
        */
        Characteristics get_characteristics() const;


        /**
            * \brief Getting values
            * \return values
        */
        std::vector<int> get_values() const;

        /**
            * \brief Getting name
            * \return name
        */
        std::string get_name() const;
        ~Potion() = default;
};
#endif