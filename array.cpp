#include "array.h"
#include <ncurses.h>

void DynamicArray::createArray(int length)
{
    this->length = length;

    if (this->length != 0)
    {
        this->data = new int[this->length];
    }
    else
    {
        this->data = NULL;
    }

    for (int i = 0; i < length; ++i)
    {
        this->data[i] = 0;
    }
}

void DynamicArray::deleteArray()
{
    length = 0;
    delete data;
}

void DynamicArray::resizeArray(int newLength)
{
    if (newLength > length)
    {
        int *newData = new int[newLength]; 
        for (int i = 0; i < length; ++i)
        {
            newData[i] = data[i];
        }
        delete data;
        data = newData;
    }
    length = newLength;
}

void DynamicArray::readArray()
{
    for (int i = 0; i < length; ++i)
    {
        std::cin >> data[i];
    }
}

void DynamicArray::printArray()
{
    for (int i = 0; i < length; ++i)
    {
        std::cout << data[i] << std::endl;
    }
}

void DynamicArray::sortArray(SORT_TYPE type)
{
    switch (type)
    {
        case SORT_MAX:
            for (int i = 0; i < length; i++) 
            {
                for (int j = 0; j < length - 1; j++) 
                {
                    if (data[j] > data[j + 1]) 
                    {
                        int temp = data[j]; 
                        data[j] = data[j + 1]; 
                        data[j + 1] = temp; 
                    }
                }
            }       
            break;

        case SORT_MIN:
            for (int i = 0; i < length; i++) 
            {
                for (int j = 0; j < length - 1; j++) 
                {
                    if (data[j] < data[j + 1]) 
                    {
                        int temp = data[j]; 
                        data[j] = data[j + 1]; 
                        data[j + 1] = temp; 
                    }
                }
            }       
            break;
    }
}

int DynamicArray::maxArray()
{
    int max = INT32_MIN;
    for (int i = 0; i < this->length; ++i)
    {
        if (data[i] > max)
        {
            max = data[i];
        }
    }

    return max;
}

int DynamicArray::get(int i)
{
    if (data[i] != 0)
        return data[i];
    else
        return 0;
}

int DynamicArray::getLength()
{
    return length;
}

void DynamicArray::readEl(int index, int el)
{
    data[index] = el;
}
