#pragma once

#include "searchable_bag.hpp"

class set {
    private:
        searchable_bag& bag_ref;
    public:
        set(searchable_bag& b);
        
        void insert(int value);
        void insert(int *ptr, int value);
        void print() const;
        void clear();
        bool has(int value) const;

        const searchable_bag& get_bag() const;
};