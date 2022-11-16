#include <iostream>

class DynamicArray
{
    private:
        int *data;
        int length;

    public:
        typedef enum sort_type {SORT_MAX, SORT_MIN} SORT_TYPE;
        void createArray(int length);
        void deleteArray();
        void resizeArray(int newLength);
        void readArray();
        void printArray();
        void sortArray(SORT_TYPE type);
        int maxArray();
};
