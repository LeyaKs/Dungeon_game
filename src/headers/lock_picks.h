/**
    * \file
    * \brief Header file with description of functions of class lock picks
*/
#ifndef LOCK_PICKS_H
#define LOCK_PICKS_H

#include "object.h"


/**
    * \class LockPicks
    * \brief Child class LockPicks from class Object
    * 
    * Contains count of lock picks, constructors and functions
*/
class LockPicks: public Object {
    private:
        int count = 0;
    public:
        LockPicks() = default;
        LockPicks(std::string _name, int _count): Object(_name), count(_count) {};


        /**
            * \brief Getting count
            * \return count
        */
        int get_count() const;


        /**
            * \brief Changing count
            * \param count
        */
        void change_count(int);
        ~LockPicks() = default;
};

#endif