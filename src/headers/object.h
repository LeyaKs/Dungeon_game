#ifndef OBJECT_H
#define OBJECT_H

#include <string>

class Object {
    private:
        std::string name;
    public:
        Object() = default;
        Object(std::string _name): name(_name) {};
        void set_name(std::string);
        std::string get_name() const;
        virtual ~Object() = default;
};

#endif