/**
    * \file
    * \brief Header file with description of functions of struct point
*/
#ifndef POINT_H
#define POINT_H


/**
    * \struct Point
    * 
    * Contains coordinates and constructors
*/
struct Point {
    int x;
    int y;
    Point() = default;
    Point(int _x, int _y) : x(_x), y(_y) {};
};

#endif