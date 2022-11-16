#include "array.h"

void DynamicArray::createArray(int length)
{
    this->length = length;

    if (this->length != 0)
    {
        this->data = new int[this->length];
    }
    else
    {
        this->data = 0;
    }
}

void DynamicArray::deleteArray()
{
    delete[] data;
    length = 0;
}

void DynamicArray::resizeArray(int newLength)
{
    if (newLength > this->length)
    {
        int *newData = new int[newLength]; 
        for (int i = 0; i < this->length; ++i)
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
