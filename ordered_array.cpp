#include <iostream>
#include "ordered_array.hpp"

ordered_array::ordered_array(int cap)
{
    this->cap = cap;
    sz = 0;

    data = new int[cap];
}

ordered_array::~ordered_array()
{
    delete[] data;
}

int ordered_array::size()
{
    return sz;
}

int ordered_array::capacity()
{
    return cap;
}

void ordered_array::insert(int elem)
{
    // returns if the array is full
    if (sz == cap)
    {
        return;
    }

    // return if the elem is min value
    if (elem == -2147483648)
    {
        return;
    }

    // find pos where elem should be inserted
    int i = 0;
    while (i < sz && data[i] < elem)
    {
        i++;
    }

    //shift elem to the right
    for (int j = sz; j > i; j--) 
    {
        data[j] = data[j - 1];
    }


    // insert the new elem in correct position
    data[i] = elem;
    // increments the size of the array
    sz++;

}

void ordered_array::remove(int elem)
{
    // shifting
    // duplicates
    // check if elem exixts or if arr is empty
    if (!exists(elem) || sz == 0) {
        return;
    }

    // 1 check if elem exists
    // 2 find the first index of elem
    int i;
    for (i = 0; i < sz; ++i)
    {
        if (data[i] == elem)
        {
            break;
        }
    }


    // 4 shift the array down
    for (int j = i; j < sz - 1; j++) 
    {
        data[j] = data[j + 1];
    }

    // decrement sz of array
    sz--;

}

bool ordered_array::exists(int elem)
{
    for (int i = 0; i < sz; ++i)
    {
        if (data[i] == elem)
        {
            return true;
        }
    }
    return false;
}

int &ordered_array::at(int i)
{
    // i<=0, i <sz
   if (sz == 0) 
   {
       throw std::out_of_range("Index out of range");
   } else if (i >= 0 && i < cap) 
   {
       return data[i];
   } else 
   {
       throw std::out_of_range("Index out of range");
   }

}
