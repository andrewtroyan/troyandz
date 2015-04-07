#include "saddlePoint.h"

using namespace std;
using namespace array;
using namespace saddlePoint;

int main()
{
    srand(time(NULL));
    int **array = nullptr, rows, cols, rowMin, colMax;

    cout << "Enter amount of rows: ";
    cin >> rows;
    array = new int*[rows];

    cout << "Enter amount of columns: ";
    cin >> cols;
    for(int i = 0; i < rows; ++i)
    {
        array[i] = nullptr;
        array[i] = new int[cols];
        generateRandomNumbersInArray(array[i], cols, 0, 99);
    }

    outputMultiArray(array, rows, cols);

    bool noSaddlePoints = true;

    for(int i = 0; i < rows; ++i)
    {
        rowMin = minOfArray(array[i], cols);
        for(int j = 0; j < cols; ++j)
        {
            if(array[i][j] == rowMin)
            {
                colMax = maxInCol((const int **)array, rows, j);
                if(array[i][j] == array[colMax][j])
                {
                    noSaddlePoints = false;
                    cout << "The saddle point is " << array[i][j] << " [" << i << "][" << j << "]." << endl;
                }
            }
        }
    }

    if(noSaddlePoints)
        cout << "There's no saddle points." << endl;

    for(int i = 0; i < rows; ++i)
    {
        delete [] array[i];
        array[i] = nullptr;
    }
    delete [] array;
    array = nullptr;
    return 0;
}
