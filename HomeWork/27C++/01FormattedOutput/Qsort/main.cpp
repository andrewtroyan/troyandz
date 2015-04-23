#include "QsortDetails.h"

using namespace std;
using namespace array;

int main()
{
    int size, *array = nullptr;
    cout << "Enter the size of array: ";
    cin >> size;
    array = new int [size] ();

    int a, b;
    cout << "Enter the range of numbers: " << endl;
    cin >> a >> b;

    srand(time(NULL));
    generateRandomNumbersInArray(array, size, a, b);
    system("clear");
    cout << "Your array: " << endl;
    outputArray(array, size);

    int way;
    cout << endl << "Enter the way to sort your array: " << endl << "1. Ascending" << endl << "2. Descending" << endl;
    cin >> way;

    if(way == 1)
        qsort(array, size, sizeof(int), ascending);
    else if(way == 2)
        qsort(array, size, sizeof(int), descending);

    system("clear");
    cout << "Your array: " << endl;
    outputArray(array, size);

    delete [] array;
    return 0;
}
