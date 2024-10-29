#include<iostream>
using namespace std;

// Перегрузка оператора индексирования [], перегрузка оператора вызова функции ()

class MyArray
{
    int* ptr;
    int size;
public:
    MyArray()
    {
        ptr = nullptr;
        size = 0;
    }
    MyArray(int s)
    {
        size = s;
        ptr = new int[size] {0};
    }
    MyArray(const MyArray& obj)
    {
        size = obj.size;
        ptr = new int[size];
        for (int i = 0; i < size; i++)
        {
            ptr[i] = obj.ptr[i];
        }
    }
    // оператор =
    

    MyArray& operator=(const MyArray& obj) {
        if (this==&obj)
        {
            return *this;
        }
        if (ptr != nullptr)
        {
            delete[] ptr;
        }size = obj.size;
        ptr = new int[size];
        for (int i = 0; i < size; i++)
        {
            ptr[i] = obj.ptr[i];
        }
        return *this;
    }
    ~MyArray()
    {
        delete[] ptr;
    }

    int GetSize()
    {
        return size;
    }

    int operator[](int index)
    {
        if (index >= 0 && index < size)
            return ptr[index];
        return -1;
    }

    void operator() ()
    {
        for (int i = 0; i < size; i++)
        {
            ptr[i] = rand() % 41 - 20;
        }
    }
    void operator() (int a)
    {
        for (int i = 0; i < size; i++)
        {
            ptr[i] = a;
        }
    }
};

int main()
{
    MyArray obj(10);

    obj();

    for (int i = 0; i < obj.GetSize(); i++)
    {
        cout << obj[i] << "\t";
    }
    cout << endl;

    obj(10);

    for (int i = 0; i < obj.GetSize(); i++)
    {
        cout << obj[i] << "\t";
    }
    cout << endl;

}