#pragma once

#include "searchable_bag.hpp"

class set {
    private:
        searchable_bag& bag;
    public:
        set(searchable_bag& bag);

        void insert(int value);
        void insert(int *value, int count);
        void print() const;
        void clear();
        bool has(int value) const;

        const searchable_bag& get_bag() const;
};