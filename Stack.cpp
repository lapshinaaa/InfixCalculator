#include "LinkedList.cpp"

class Stack
{
public:

    Stack(); //конструктор
    // Прототипы используемых функций:
    void push (int value);
    int pop();
    int size() const;
    int top() const;
    bool empty() const;

private: //чтобы пользователь не видел работу листа
    LinkedList<int> list;
};


Stack::Stack() {  //выделяем память под объект класса
}

void Stack::push(int value) {
    list.pushFront(value);
}

// смотрим размер стека
int Stack::size() const
{
    return list.getSize();
}

int Stack::pop() {
    int data = list[0]; //нашли по индексу и вытаскиваем верхний элемент (последний сверху)
    list.removeAt(0);//удаляем из стека выбранный элемент
    return data; //возвращаем элемент
}

int Stack::top() const { //const - не изменяет лист, top- показывает чему равен самый верхний элемент
    return list[0]; //
}
bool Stack::empty() const { //проверка стека на пустоту
    return list.getSize() == 0; //считаем количество элементов и сравнивает с 0 (false - если не пустой)
}
