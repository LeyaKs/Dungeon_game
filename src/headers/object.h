/**
    * \file
    * \brief Header file with description of functions of class Object
*/
#ifndef OBJECT_H
#define OBJECT_H

#include <string>


/**
    * \class Object
    * \brief Class Object
    * 
    * Contains name, constructors and functions
*/
class Object {
    private:
        std::string name;
    public:
        Object() = default;
        Object(std::string _name): name(_name) {};

        /**
            * \brief Setting name
            * \param nane
        */                
        void set_name(std::string);

        /**
            * \brief Getting name
            * \return name
        */
        std::string get_name() const;
        virtual ~Object() = default;
};

#endif
