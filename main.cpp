#include "array.h"

int main()
{
    DynamicArray array;

    std::cout << "Введите длину массива" << std::endl;
    int n;
    std::cin >> n;
    array.createArray(n);
    array.readArray();
    array.printArray();
    array.resizeArray(n + 1);
    array.readArray();
    array.printArray();

    
    return 0;
}
