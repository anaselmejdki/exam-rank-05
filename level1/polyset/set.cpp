#include "set.hpp"

set::set() : container(nullptr) {}

set::set(const set& other)
{
    if (other.container)
    {
        if (auto arr = dynamic_cast<searchable_array_bag *>(other.container))
            container = new searchable_array_bag(*arr);
        else if (auto tr = dynamic_cast<searchable_tree_bag *>(other.container))
            container = new searchable_tree_bag(*tr);
        else
            container = nullptr;
    }
    else
        container = nullptr;
}

set::set(searchable_bag& bag) : container(nullptr)
{
    if (auto arr = dynamic_cast<searchable_array_bag *>(&container))
        container = new searchable_array_bag(*arr);
    else if (auto tr = dynamic_cast<searchable_tree_bag *>(&container))
        container = new searchable_tree_bag(*tr);
}

set& set::operator=(const set& other)
{
    if (this != &other)
    {
        delete container;
        container = nullptr;
        if (other.container)
        {
            if (auto arr = dynamic_cast<searchable_array_bag *>(other.container))
                container = new searchable_array_bag(*arr);
            else if (auto tr = dynamic_cast<searchable_tree_bag *>(other.container))
                container = new searchable_tree_bag(*tr);
        }
    }
    return *this;
}

set::~set() {}

searchable_bag& set::get_bag() const
{
    if (!container)
    {
        std::cerr << "Error: no underlying bag set." << std::endl;
        std::exit(1);
    }
    return *container;
}

void set::set_container(searchable_bag* bag)
{
    delete container;
    container = bag;
}

void set::insert(int value)
{
    if (!container)
    {
        std::cerr << "Error, no underlying bag set." << std::endl;
        return;
    }
    if (!container->has(value))
        container->insert(value);
}

void set::insert(int *values, int count)
{
    if (!container)
    {
        std::cerr << "Error: no underlying bag set." << std::endl;
        return ;
    }
    for (int i = 0; i < count; i++)
    {
        if (!container->has(values[i]))
            container->insert(values[i]);
    }
}

bool set::has(int value) const
{
    if (!container)
        return false;
    return container->has(value);
}

void set::clear()
{
    if (container)
        container->clear();
}

void set::print() const
{
    if (container)
        container->print();
}
