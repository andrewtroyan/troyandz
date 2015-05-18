#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
    int width, height;
    cout << "Enter the width (>= 1): " << endl;
    cin >> width;
    cout << "Enter the height (>= 1): " << endl;
    cin >> height;
    system("clear");
    for(int i = 0; i < height; ++i)
        cout << setw(width) << setfill('*') << '*' << endl;
    return 0;
}
