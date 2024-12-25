/**
    * \file
    * \brief Header file with description of functions of class cell
*/

#ifndef CELL_H
#define CELL_H

#include "entity.h"
#include <memory>


/**
    * \class Cell
    * \brief Class Cell with functions
    * 
    * Contains the fields of the point and the pointer to the entity
*/

class Cell {
    private:
        Point point;
        std::shared_ptr<Entity> entity;
    public:
        Cell() = default;
        Cell(Point _point, const std::shared_ptr<Entity>& _entity):
            point(_point), entity(_entity) {};

        /**
            * \brief Setting point
            * \param struct point
        */
        void set_point(Point);

        /**
             * \brief Setting entity
             * \param pointer to the entity
        */
        void set_entity(const std::shared_ptr<Entity>&);


        /**
             * \brief Getting point
             * \return point
        */
        Point get_point() const;


        /**
             * \brief Getting entity
             * \return pointer to the entity
        */
        std::shared_ptr<Entity> get_entity() const;


        ~Cell() = default;
};

#endif