#ifndef OBJECT_H
#define OBJECT_H

#include <string>

class Object {
    private:
        std::string name;
    public:
        Object() = default;
        void set_name(std::string);
        std::string get_name() const;
        ~Object() = default;
};

#endif