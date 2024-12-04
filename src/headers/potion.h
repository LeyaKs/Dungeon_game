#ifndef POTION_H
#define POTION_H

#include <vector>
#include "object.h"
#include "characteristics.h"

class Potion: public Object {
    private:
        Characteristics characteristics;
        std::vector<int> values;
    public:
        Potion() = default;
        Potion(std::string _name, Characteristics _characteristics, 
            std::vector<int> _values): Object(_name),
            characteristics(_characteristics), values(_values) {};
        
        void set_characteristics(Characteristics);
        void set_values(std::vector<int>);
        void set_name(std::string);

        Characteristics get_characteristics() const;
        std::vector<int> get_values() const;
        std::string get_name() const;

        bool operator==(const std::shared_ptr<Potion> other) const {
            return this->get_name() == other->get_name();
        }
        ~Potion() = default;
};
#endif