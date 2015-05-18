#include "Akinator.h"

using namespace std;
using namespace tree;
using namespace stack;
using namespace file;
using namespace game;

int main()
{
    FILE *filepointer = nullptr;
    Node *root = nullptr, *play = nullptr;
    char answer;

    do
    {
        system("clear");
        filepointer = fopen("DataBase.txt", "r");
        if(!filepointer)
        {
            cerr << "Cannot open the file." << endl;
            exit(EXIT_FAILURE);
        }
        readFromFile(filepointer, &root);
        fclose(filepointer);
        filepointer = nullptr;
        // -----
        play = playGame(root);

        cout << "Это " << play->data.str << ". Я угадала?" << endl << "Нажми y/n: ";
        cin >> answer;
        if(answer == 'y')
        cout << "Я победила!" << endl;
        else
        {
            cout << "Я проиграла! Помогите мне стать еще более умной и интересной!" << endl;
            addNewInformation(&root, play);
                filepointer = fopen("DataBase.txt", "w");
                if(!filepointer)
                {
                    clearTree(&root);
                    play = nullptr;
                    cerr << "Cannot open the file." << endl;
                    exit(EXIT_FAILURE);
                }
                writeToFile(filepointer, root);
                fclose(filepointer);
            }

        clearTree(&root);
        play = nullptr;

        cout << "Хочешь сыграть еще? y/n ";
        cin >> answer;
    }
    while(answer == 'y');

    return 0;
}

