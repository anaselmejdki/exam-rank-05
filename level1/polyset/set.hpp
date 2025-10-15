#pragma once

#include "searchable_bag.hpp"
#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"

class set {
    private:
        searchable_bag* container;
    public:
        set();
        set(const set& other);
        set(searchable_bag& bag);
        set& operator=(const set& other);
        ~set();

        searchable_bag& get_bag() const;
        void set_container(searchable_bag* bag);
        void insert(int value);
        void insert(int *values, int count);
        bool has(int value) const;
        void clear();
        void print() const;
};