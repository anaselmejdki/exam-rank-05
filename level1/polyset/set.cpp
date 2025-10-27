#include "set.hpp"

set::set(searchable_bag& b) : bag_ref(b) {}

void set::insert(int value)
{
    if (!bag_ref.has(value))
        bag_ref.insert(value);
}

void set::insert(int *ptr, int value)
{
    for (int i = 0; i < value; ++i)
    {
        insert(ptr[i]);
    }
}

void set::print() const
{
    bag_ref.print();
}

void set::clear()
{
    bag_ref.clear();
}

bool set::has(int value) const
{
    return bag_ref.has(value);
}

const searchable_bag& set::get_bag() const
{
    return bag_ref;
}