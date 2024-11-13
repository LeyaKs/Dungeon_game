#ifndef ENTITY_H
#define ENTITY_H

struct Point {
    int x;
    int y;
    Point() = default;
};

class Entity {
    private:
        Point point;
    public:
        Entity() = default;
        void set_point(Point);
        Point get_point() const;
        ~Entity() = default;
};

#endif