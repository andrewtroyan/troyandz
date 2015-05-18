#include <iostream>
#include <iomanip>

//int main()
//{
//    std::cout << "Hello world!" << std::endl; //endl - перевод строки //cout - класс
//    return 0;
//}

struct Persona
{
    int age;
};

using namespace std;
//using std::cout;

int main()
{
    cout << "Hello world!" << endl << endl;

    cout << "Hello world!\n";
    cout << 'A' << endl;
    cout << 23 << endl << 2.35 << endl << endl;

    cout << hex << 27 << endl;
    cout << oct << 27 << endl;
    cout << dec;
    cout << true << endl;
    cout << boolalpha << true << endl << endl;

    cout.width(5); //включать каждый раз перед выводом
    cout << 2345 << endl << endl;

    cout.width(5);
    cout.fill('*');
    cout << 1 << endl << endl;

    cout.precision(5); //точность по кол-ву ВСЕХ цифр в числе
    cout << 200.555 << endl << endl;

    cout << setw(5) << setfill('*') << 23 << endl << endl; //iomanip

    int a;
    cout << "Enter the number: ";
    cin >> a;
    cout << a << endl << endl;

    //cerr << "Error" << endl << endl;

    //Сигнатура функции - имя функции и последовательность типов, которые она получает в качестве параметров.
    //Компилятор С++ различает функции по СИГНАТУРАМ.

    //Перегрузка:
    //void zuzu(int a, int b, char c);
    //void zuzu(int a);
    //На С++ скомпилируется, на С - нет.

    //Параметры по умолчанию.
    //void foo(int a, int b = 5); - можно передать и один, и два параметра.
    //void foo(int c) - нельзя (перегрузка не сработает).

    //Параметр умолчания можно написать ТОЛЬКО один раз!!! (обычно пишется в заголовочном файле).

    //Ссылки.
    //Ссылка - синтаксический сахар, введенный для передачи по указателю.
    //Ссылку нельзя передвинуть :(
    //Ссылка должна быть сразу инициализирована (переприсваивать нельзя).
    //В новом стандарте есть ПРАВАЯ ссылка.

    int x, &y = x;
    x = 5;
    y = 7;
    cout << x;

    //struct без typedef
    Persona Vasya, *Petya;

    //Выделение и удаление памяти: new, delete
    int *array = nullptr;
    //array = new int[5]; //просто массив интов с мусором
    array = new int[5](); //массив интов с нулями :)
    delete [] array;
    array = nullptr;

    int *p = nullptr;
    p = new int;
    delete p;
    p = nullptr;

    return 0;
}


//namespace zuzu //создаем пространство имен в заголовочном файле
//{
//    функции
//}


