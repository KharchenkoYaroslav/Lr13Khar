#include <iostream>
using namespace std;

#define SIZE 2

template <class T>
class DataStruct
{
protected:
    T stck[SIZE];
    int tos;

public:
    DataStruct() : tos(0) {}
    virtual void push(T obj) = 0;
    virtual T pop() = 0;
};

template <class T>
class Stack : public DataStruct<T>
{
public:
    void push(T obj) override;
    T pop() override;
};

template <class T>
void Stack<T>::push(T obj)
{
    if (this->tos == SIZE)
    {
        cout << "Stack is full\n";
        throw 0;
    }
    this->stck[this->tos++] = obj;
}

template <class T>
T Stack<T>::pop()
{
    if (this->tos == 0)
    {
        cout << "Stack is empty\n";
        throw 0;
    }
    return this->stck[--this->tos];
}

template <class T>
class Queue : public DataStruct<T>
{
    int bos;

public:
    Queue() : bos(0) {}
    void push(T obj) override;
    T pop() override;
};

template <class T>
void Queue<T>::push(T obj)
{
    if (this->tos == SIZE)
    {
        cout << "Queue is full\n";
        throw 0;
    }
    this->stck[this->tos++] = obj;
}

template <class T>
T Queue<T>::pop()
{
    if (bos == this->tos)
    {
        cout << "Queue is empty\n";
        throw 0;
    }
    return this->stck[bos++];
}

template <class T>
DataStruct<T>* DataStructFactory(char what)
{
    if (what == 's')
    {
        return new Stack<T>;
    }
    else // Нема сенсу обробляти варіант коли користувач вибрав ні те ні інше, тому за дефолтний варіант будемо вважати чергу
    {
        return new Queue<T>;
    }
}

int main()
{
    DataStruct<int>* s = DataStructFactory<int>('s');
    DataStruct<char>* q = DataStructFactory<char>('q');

    try
    {
        s->push(1);
        s->push(2);
        s->push(3);
    }
    catch (int)
    {
    }

    try
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "S pop: " << s->pop() << endl;
        }
    }
    catch (int)
    {
    }

    try
    {
        q->push('a');
        q->push('b');
        q->push('c');
    }
    catch (int)
    {
    }

    try
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "Q pop: " << q->pop() << endl;
        }
    }
    catch (int)
    {
    }

    delete s; 
    delete q;

    return 0;
}