#include "set.hpp"

set::set(searchable_bag& bag) : bag(bag) {}

void set::insert(int value)
{
    if (!bag.has(value))
        bag.insert(value);
}

void set::insert(int *value, int count)
{
    for (int i = 0; i < count; i++)
        insert(value[i]);
}

void set::print() const
{
    bag.print();
}

void set::clear()
{
    bag.clear();
}

bool set::has(int value) const
{
    return bag.has(value);
}

const searchable_bag& set::get_bag() const
{
    return bag;
}