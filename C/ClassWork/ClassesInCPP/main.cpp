#include <iostream>

using namespace std;

/*
enum Sex {male, female};

class Persona
{
private: //не доступен никому
    char name[128];
    int age;
    Sex sex;
public: //доступен всем
    char *whatIsYourName() const;
    int howOldAreYou() const;
    void celebrateBirthday();
    Persona(char *name, int age, Sex sex); //конструктор
};

int main()
{
    Persona vasia("Vasia Ivanov", 22, male);
    cout << vasia.whatIsYourName();
    cout << vasia.whatIsYourName();
    vasia.celebrateBirthday();
    //cout << vasia.age; // нельзя
    //vasia.age = 49; // нельзя
    return 0;
}

//Инкапсуляция тесным образом связана с сокрытием данных. Сокрытие данных - запрещение модификации данных непосредственным (прямым) образом.
//Если нет сокрытия данных, то очень часто наши гарантии, что объект ведет себя определенным образом, могут быть нарушены (не всегда).
*/

/*
class A
{
public:
    int getX() const;
    void setX(int value);
private:
    int x;
};

int A::getX() const
{
    return x;
}

void A::setX(int value)
{
    x = value;
}

int main()
{
    A a;
    a.setX(5);
    cout << a.getX();
    return 0;
}

*/

/*
class A
{
public:
    int &x();
private:
    int x_;
};

int &A::x()
{
    return x_;
}

int main()
{
    A a;
    a.x() = 5;
    cout << a.x();
    return 0;
}
*/

class A
{
public:
    int x;
};

int main()
{
    A a;
    a.x = 5;
    cout << a.x;
    return 0;
}

// НИКОГДА НЕ ДЕЛАТЬ ДАННЫЕ ОТКРЫТЫМИ

//Конструктор - метод, который вызывается при рождении объекта. Обратный метод - деструктор (вызывается для разрушения объектов).
//Конструкторов бывает много разных видов, деструктор всегда один.
//В С++ любой конструктор обязан называться именем класса. При этом не должен возвращать значение. Может иметь различное число параметров (от 0 до ... дофига :)).
//Некоторые конструкторы с особенными параметрами имеют специальное название и роль (конструктор копирования и коснтруктор перемещения).
//В конструкторах и только в конструкторах разрешены списки инициализации.
//Деструктор называется так же, как и класс, только впереди идет ~ (например, ~Persona). Ничего не возвращает и ничего не получает.

//Методология RAII (resource acquisation is initialisation - доступ к ресурсу есть его инициализация) и ее реализации в С++:
//При доступе к ресурсу он инициализируется. По завершению работы с ним он уничтожается.
//По стандарту С++ конструктор можно вызвать только один единственный раз.
//Деструктор вызовется при любых обстоятельствах.
//Конструкторы, деструкторы и операторы присваивания по умолчанию: при определенных обстоятельствах, если мы не написали конструктор либо деструктор, либо один
//из операторов присваивания, то компилятор создаст их автоматически.
//Компилятор может создать коснтруктор без параметров (он ничего не делает), если не объявлено ни одного конструктора.
//Конструктор копирования делает побитовую копию объекта. Создается, если не создано ни одного пользовательского конструктора копирования.
//Оператор копирующего присваивания создает побитовую копию. Создается, если нет пользовательского оператора копирующего присваивания.
//Конструктор перемещения и оператор переместительного присвания создаются при довольно сложных условиях.
//Деструктор, который не делает нифига :) и является не виртуальным. Создается, когда нет собственного деструктора.