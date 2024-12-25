/**
    * \file
    * \brief Header file with description of functions of class characteristics
*/



#ifndef CHARACTERISTICS_H
#define CHARACTERISTICS_H


#include "characteristic.h"
#include <vector>
#include <algorithm>
#include <memory>





/**
    * \class Characteristics
    * \brief Class Characteristics with functions
    * 
    * Contains vector of characteristics, constructors and functions
*/
class Characteristics {
    private:
        std::vector<std::shared_ptr<Characteristic>> characteristics;
    public:
        Characteristics() = default;
        Characteristics(const std::vector<std::shared_ptr<Characteristic>>&);
        

        /**
            * \brief Changing value of characteristic
            * \param type of characteristic, value to increase
        */      
        void change_value_characteristic(type_of_characteristic, int);



        /**
            * \brief Finding characteristic
            * \param type of characteristic
            * \return index or -1 if it wasn't found
        */      
        int find_characteristic(type_of_characteristic) const;


        /**
            * \brief Adding characteristic
            * \param type of characteristic, value
        */   
        void add_characteristic(type_of_characteristic, int);


        /**
            * \brief Gettinging count of characteristics
            * \return count
        */      
        int get_count() const;


        /**
            * \brief Getting vector of characteristics
            * \return vector of characteristics
        */      
        std::vector<std::shared_ptr<Characteristic>> get_characteristics() const;


        /**
            * \brief Getting value of characteristic
            * \param type of characteristic
            * \return value
        */      
        int get_characteristic(type_of_characteristic) const;
        
        ~Characteristics() = default;
};

#endif