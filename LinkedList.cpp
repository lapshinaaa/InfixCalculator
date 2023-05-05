#include <iostream>

template <typename T>
class List
{
public:
    List<T>();
    ~List<T>();

    // prototypes of all the necessary functions
    void insert(T data, int index);
    void removeAt(int index);
    void remove(T data);
    void pop_back();
    void print() const;
    void push_front(T data);
    void push_back(T data);
    void pop_front();
    void clear();
    int search(T data) const;
    int get_size() const {return size;}
    T& operator[] (int index) const;


private:

    // class "Node" for elements of the list
    template <typename U>
    class Node
    {
    public:
        Node<U> *ptrNextNode; // pointer to the next node (address)
        U data;

        // constructor for the class "Node": (assigning default values)
        Node (U data = 0, Node<U> *ptrNextNode = nullptr)
        {
            this->data = data;
            this->ptrNextNode = ptrNextNode;
        }
    };

    Node<T> *head; // creating a pointer to an object of the Node type
    int size; // number of elements in a list

};



//separating constructors and destructors from the Class
template <typename T>
List<T>::List()
{
    this->size = 0;
    this->head = nullptr;
}

template <typename T>
List<T>::~List()
{
    clear();
}


// ADDING ELEMENTS TO THE END OF THE LIST
template <typename T>
void List<T>::push_back(T data)
{
    // first, checking if head is empty:
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }

    else  // if the element is not the first one
    {
        Node<T> *currNode = this->head; // start at the head of the list
        while(currNode->ptrNextNode != nullptr) // traverse the list until the end
        {
            currNode = currNode->ptrNextNode; // moving to the next element
        }

        currNode->ptrNextNode = new Node<T>(data); // pointer to the next node is a pointer to our newly-added node
    }

    size++;
}



// SEARCH FOR THE ELEMENT AT A PARTICULAR INDEX
template <typename T>
T& List<T>::operator[](const int index) const // overloaded square bracket operator "List[5]"
{
    int counter = 0;
    Node<T> *currNode = this->head;

    while (currNode != nullptr)
    {
        // if we're on the right element
        if (counter == index) return currNode->data;

        currNode = currNode->ptrNextNode;
        counter++;
    }
}


// DELETING THE FRONT ELEMENT
template <typename T>
void List<T>::pop_front()
{
    // checking if the list is empty:
    if (head == nullptr) return;

    Node<T> *temp = head;
    head = head->ptrNextNode; // head is now the next element
    delete temp;
    size--;
}


// FREEING DYNAMICALLY ALLOCATED MEMORY
template <typename T>
void List<T>::clear()
{
    while(size) // while there are elements in our list
    {
        pop_front();
    }

}


// ADDING ELEMENTS TO THE BEGINNING OF THE LIST
template <typename T>
void List<T>::push_front(T data)
{
    head = new Node<T>(data, head); // 'head' pointer is now pointing to our newly-added node
    size++;
}


// ADDING ELEMENT AT A PARTICULAR INDEX TO OUR LIST
template <typename T>
void List<T>::insert(T data, int index)
{
    try
    {
        if (index == 0) // if we want to add the element to the beginning
        {
            push_front(data);
        } else {
            Node<T> *previousElem = this->head;

            for (int i = 0; i < index - 1; ++i) {
                if (previousElem == nullptr)
                    throw std::out_of_range("Index out of range");

                previousElem = previousElem->ptrNextNode; // accessing an object's field by using '->'
            }

            if (previousElem == nullptr)
                throw std::out_of_range("Index out of range");

            Node<T> *newNode = new Node<T>(data,
                                     previousElem->ptrNextNode); // newly-added node will now point to the next element
            previousElem->ptrNextNode = newNode;
            size++;
        }
    }
    catch (std::out_of_range& e)
    {
        std::cout << "Error occurred while inserting an element: " << e.what() << std::endl;
    }
}


// FUNCTION TO PRINT OUT ALL THE ELEMENTS OF THE LINKED LIST
template <typename T>
void List<T>::print() const
{
    Node<T> *currNode = head;
    while (currNode != nullptr)
    {
        std::cout<<currNode->data<<" ";
        currNode = currNode->ptrNextNode;
    }
    std::cout<<std::endl;
}


// REMOVING AN ELEMENT AT A PARTICULAR INDEX FROM THE LIST
template <typename T>
void List<T>::removeAt(int index)
{
    try
    {
        if (index == 0) {
            pop_front();
        } else {
            Node<T> *previousElem = head;
            for (int i = 0; i < index - 1; ++i) {
                previousElem = previousElem->ptrNextNode;
            }

            Node<T> *toDelete = previousElem->ptrNextNode; // getting the address of the node for deletion
            previousElem->ptrNextNode = toDelete->ptrNextNode; // pointing to the node next after the one for deletion

            delete toDelete;
            size--;
        }
    }

    catch (std::exception& e)
    {
        std::cout<<"Error occurred while removing an element at index. Index out of range."<<e.what()<<std::endl;
    }
}


// FUNCTION FOR DELETING THE LAST ELEMENT OF THE LIST
template <typename T>
void List<T>::pop_back()
{
    if (head == nullptr) {return;} // if the list is empty
    removeAt(this->size - 1);
}


// REMOVING THE FIRST OCCURRENCE OF THE VALUE
template <typename T>
void List<T>::remove(T data)
{
    Node<T> *currElem = head;
    Node<T> *previousElem = nullptr;

    // traversing the list to find the required value:
    while(currElem != nullptr)
    {
        // checking if this is the value we're looking for:
        if (currElem->data == data)
        {
            if (previousElem == nullptr) // if the element we want to remove is 'head'
            {
                head = currElem->ptrNextNode;
            }

            else
            {
                previousElem->ptrNextNode = currElem->ptrNextNode;
            }

            delete currElem;
            size--;
            return;

        }

        previousElem = currElem;
        currElem = currElem->ptrNextNode;

    }
}


// RETURNING THE INDEX OF THE FIRST OCCURRENCE OF THE GIVEN VALUE
template <typename T>
int List<T>::search(T data) const
{
    Node<T> *currElem = head;
    int index = 0;

    // traversing the list looking for the given element
    while(currElem != nullptr)
    {
        if (currElem->data == data)
        {
            return index;
        }

        currElem = currElem->ptrNextNode;
        index++;

    }

    return -1; // if the element not found
}
