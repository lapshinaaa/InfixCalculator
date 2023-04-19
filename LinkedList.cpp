#include <iostream>

class List
{
public:
    List();
    ~List();

    // prototypes of all the necessary functions
    void insert(int data, int index);
    void removeAt(int index);
    void remove (int data);
    void pop_back();
    void print() const;
    void push_front(int data);
    void push_back(int data);
    void pop_front();
    void clear();
    int search(int data) const;
    int get_size() const {return size;}
    int& operator[] (int index);

private:

    // class "Node" for elements of the list
    class Node
    {
    public:
        Node *ptrNextNode; // pointer to the next node (address)
        int data;

        // constructor for the class "Node": (assigning default values)
        Node (int data = 0, Node *ptrNextNode = nullptr)
        {
            this->data = data;
            this->ptrNextNode = ptrNextNode;
        }
    };

    Node *head; // creating a pointer to an object of the Node type
    int size; // number of elements in a list

};



//separating constructors and destructors from the Class
List::List()
{
    this->size = 0;
    this->head = nullptr;
}

List::~List()
{
    clear();
}



// ADDING ELEMENTS TO THE END OF THE LIST
void List::push_back(int data)
{
    // first, checking if head is empty:
    if (head == nullptr)
    {
        head = new Node(data);
    }

    else  // if the element is not the first one
    {
        Node *currNode = this->head; // start at the head of the list
        while(currNode->ptrNextNode != nullptr) // traverse the list until the end
        {
            currNode = currNode->ptrNextNode; // moving to the next element
        }

        currNode->ptrNextNode = new Node(data); // pointer to the next node is a pointer to our newly-added node
    }

    size++;
}



// SEARCH FOR THE ELEMENT AT A PARTICULAR INDEX
int &List::operator[](const int index) // overloaded square bracket operator "List[5]"
{
    int counter = 0;
    Node *currNode = this->head;

    while (currNode != nullptr)
    {
        // if we're on the right element
        if (counter == index) return currNode->data;

        currNode = currNode->ptrNextNode;
        counter++;
    }

    throw std::out_of_range("Index out of range"); // throw an exception if the index is out of range
}


// DELETING THE FRONT ELEMENT
void List::pop_front()
{
    // checking if the list is empty:
    if (head == nullptr) return;

    Node *temp = head;
    head = head->ptrNextNode; // head is now the next element
    delete temp;
    size--;
}


// FREEING DYNAMICALLY ALLOCATED MEMORY
void List::clear()
{
    while(size) // while there are elements in our list
    {
        pop_front();
    }

}


// ADDING ELEMENTS TO THE BEGINNING OF THE LIST
void List::push_front(int data)
{
    head = new Node(data, head); // 'head' pointer is now pointing to our newly-added node
    size++;
}


// ADDING ELEMENT AT A PARTICULAR INDEX TO OUR LIST
void List::insert(int data, int index)
{
    try
    {
        if (index == 0) // if we want to add the element to the beginning
        {
            push_front(data);
        } else {
            Node *previousElem = this->head;

            for (int i = 0; i < index - 1; ++i) {
                if (previousElem == nullptr)
                    throw std::out_of_range("Index out of range");

                previousElem = previousElem->ptrNextNode; // accessing an object's field by using '->'
            }

            if (previousElem == nullptr)
                throw std::out_of_range("Index out of range");

            Node *newNode = new Node(data,
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
void List::print() const
{
    Node *currNode = head;
    while (currNode != nullptr)
    {
        std::cout<<currNode->data<<" ";
        currNode = currNode->ptrNextNode;
    }
    std::cout<<std::endl;
}


// REMOVING AN ELEMENT AT A PARTICULAR INDEX FROM THE LIST
void List::removeAt(int index)
{
    try
    {
        if (index == 0) {
            pop_front();
        } else {
            Node *previousElem = head;
            for (int i = 0; i < index - 1; ++i) {
                previousElem = previousElem->ptrNextNode;
            }

            Node *toDelete = previousElem->ptrNextNode; // getting the address of the node for deletion
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
void List::pop_back()
{
    if (head == nullptr) {return;} // if the list is empty
    removeAt(this->size - 1);
}


// REMOVING THE FIRST OCCURRENCE OF THE VALUE
void List::remove(int data)
{
    Node *currElem = head;
    Node *previousElem = nullptr;

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
int List::search(int data) const
{
    Node *currElem = head;
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
