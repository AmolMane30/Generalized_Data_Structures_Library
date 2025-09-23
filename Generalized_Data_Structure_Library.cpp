//----------------------------------------------------------------------------------------------------------------------------------//
//        Project Title : Generalized Data Structures Library
//        Technology    : C++ Programming
//        Description   : # This project is considered as a library which contains generic implementations of all major types of 
//                         data structures such as -
//                                               1] Singly Linked List
//                                               2] Singly Circular Linked List
//                                               3] Doubly Linked List
//                                               4] Doubly Circular Linked List
//                                               5] Stack
//                                               6] Queue
//                       # It provides the readymade implementations of all fundamental operations as well as advanced operations on 
//                         linear, non linear data structures in an object oriented way.
//                              
//                       # It provides the generic way of implementation so we can use the functionality for any type of data types
//                         such as - INT, CHAR, FLOAT, DOUBLE
//                  
//                       # All the object oriented design policies are used in this project.
//                       # Supports generic data types and dynamic memory allocation.
//
//        Author       : Amol R. Mane
//        Date         : 7 August 2025
//----------------------------------------------------------------------------------------------------------------------------------//


//----------------------------------------------------------------------------------------------------------------------------------//
//                                        [ GENERALIZED DATA STRUCTURES LIBRARY ]
//----------------------------------------------------------------------------------------------------------------------------------//

#include <iostream>
using namespace std;

// Supports generic data types and dynamic memory allocation

//----------------------------------------------------------------------------------------------------------------------------------//
//                  Singly Linear Linked List
//----------------------------------------------------------------------------------------------------------------------------------//

template <class T>
struct nodeSL 
{
    T data;
    struct nodeSL * next;
};

// Generic Singly Linear Linked List class
template <class T>
class SinglyLL
{
    public:
        struct nodeSL<T> * head;
        int iCount;

        SinglyLL();

        void InsertFirst(T no);
        
        void InsertLast(T no);
        
        void InsertAtPos(T no, int ipos);
       
        void DeleteFirst();
    
        void DeleteLast();
       
        void DeleteAtPos(int ipos);

        void Display();
        
        int Count();

};

template <class T>
SinglyLL<T> :: SinglyLL()
{
    iCount = 0;
    head = NULL;
}

template <class T>
void SinglyLL<T> :: InsertFirst(T no)
{
    struct nodeSL<T> * newn = NULL;
    newn = new struct nodeSL<T>;

    newn->data = no;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        newn->next = head;
        head = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T> :: InsertLast(T no)
{
    struct nodeSL<T> * newn = NULL;
    struct nodeSL<T> * temp = NULL;
    newn = new struct nodeSL<T>;

    newn->data = no;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T> :: InsertAtPos(T no, int ipos)
{
    struct nodeSL<T> * newn = NULL;
    struct nodeSL<T> * temp = NULL;

    if(ipos < 1 || ipos > iCount+1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new nodeSL<T>;
        newn->data = no;
        newn->next = NULL;

        temp = head;
        for(int i = 1; i < ipos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyLL<T> :: DeleteFirst()
{
    struct nodeSL<T> * temp = NULL;
    if(head == NULL)
    {
        return;
    }
    else if(head ->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        temp = head;
        head = head ->next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T> :: DeleteLast()
{
    struct nodeSL<T> * temp = NULL;

    if(head == NULL)
    {
        return;
    }
    else if(head -> next == NULL)
    {
        delete head;
        head = NULL;
    }
    else 
    {
        temp = head;
        while(temp ->next ->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;

        iCount--;
    }
}

template <class T>
void SinglyLL<T> :: DeleteAtPos(int ipos)
{
    struct nodeSL<T> * temp = NULL;
    struct nodeSL<T> * target = NULL;

    if(ipos < 1 || ipos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = head;
        for(int i = 1; i < ipos-1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target -> next;
        delete target;

        iCount--;
    }
}

template <class T>
void SinglyLL<T> :: Display()
{
    struct nodeSL<T> * temp = NULL;
    temp = head;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
int SinglyLL<T> :: Count()
{
    return iCount;
}



//----------------------------------------------------------------------------------------------------------------------------------//
//                          Singly Circular Linked List
//----------------------------------------------------------------------------------------------------------------------------------//

template <class T>
struct nodeSC 
{
    T data;
    struct nodeSC * next;
};

// Generic Singly Circular Linked List class
template <class T>
class SinglyCL
{
    public:
        struct nodeSC<T> * head;
        struct nodeSC<T> * tail;
        int iCount;

        SinglyCL();

        void InsertFirst(T no);
        
        void InsertLast(T no);
        
        void InsertAtPos(T no, int ipos);
       
        void DeleteFirst();
    
        void DeleteLast();
       
        void DeleteAtPos(int ipos);

        void Display();
        
        int Count();

};

template <class T>
SinglyCL<T> :: SinglyCL()
{
    iCount = 0;
    head = NULL;
    tail = NULL;
}

template <class T>
void SinglyCL<T> :: InsertFirst(T no)
{
    struct nodeSC<T> * newn = NULL;
    newn = new struct nodeSC<T>;

    newn->data = no;
    newn->next = NULL;

    if(head == NULL && tail == NULL)
    {
        head = newn;
        tail = newn;
        tail->next = head;
    }
    else
    {
        newn->next = head;
        head = newn;
        tail->next = head;
    }
    iCount++;
}

template <class T>
void SinglyCL<T> :: InsertLast(T no)
{
    struct nodeSC<T> * newn = NULL;
    struct nodeSC<T> * temp = NULL;
    newn = new struct nodeSC<T>;

    newn->data = no;
    newn->next = NULL;

    if(head == NULL && tail == NULL)
    {
        head = newn;
        tail = newn;
        tail->next = head;
    }
    else
    {
        tail->next = newn;
        tail = tail->next;
        tail->next = head;
    }
    iCount++;
}

template <class T>
void SinglyCL<T> :: InsertAtPos(T no, int ipos)
{
    struct nodeSC<T> * newn = NULL;
    struct nodeSC<T> * temp = NULL;

    if(ipos < 1 || ipos > iCount+1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        temp = head;

        for(int i = 0; i < ipos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyCL<T> :: DeleteFirst()
{
    struct nodeSC<T> * temp = NULL;
    if(head == NULL && tail == NULL)
    {
        return;
    }
    else if(head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        head = head->next;
        delete (tail->next);
        tail->next = head;
    }
    iCount--;
}

template <class T>
void SinglyCL<T> :: DeleteLast()
{
    struct nodeSC<T> * temp = NULL;

    if(head == NULL && tail == NULL)
    {
        return;
    }
    else if(head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else 
    {
        temp = head;
        while(temp->next->next != head)
        {
            temp = temp->next;
        }
        delete temp ->next;
        tail = temp;
        temp->next = head;
    }
    iCount--;
}

template <class T>
void SinglyCL<T> :: DeleteAtPos(int ipos)
{
    struct nodeSC<T> * temp = NULL;
    struct nodeSC<T> * target = NULL;

    if(ipos < 1 || ipos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = head;
        for(int i = 1; i < ipos -1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;
        iCount--;
    }
}

template <class T>
void SinglyCL<T> :: Display()
{
    struct nodeSC<T> * temp = NULL;
    temp = head;

    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }while(temp != tail->next);

    cout<<"\n";
}

template <class T>
int SinglyCL<T> :: Count()
{
    return iCount;
}



//----------------------------------------------------------------------------------------------------------------------------------//
//              Doubly Linear Linked List
//----------------------------------------------------------------------------------------------------------------------------------//

template <class T>
struct nodeDL
{
    T data;
    struct nodeDL * next;
    struct nodeDL * prev;
};

// Generic Doubly Linear Linked List class
template <class T>
class DoublyLL
{
    public:
        struct nodeDL<T> * head;
        int iCount;

        DoublyLL();
      
        void InsertFirst(T no);
       
        void InsertLast(T no);
        
        void InsertAtPos(T no, int ipos);
       
        void DeleteFirst();
       
        void DeleteLast();
       
        void DeleteAtPos(int ipos);
        
        void Display();
       
        int Count();  
};

template <class T>
DoublyLL<T> :: DoublyLL()
{
    head = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T> :: InsertFirst(T no)
{
    struct nodeDL<T> * newn = NULL;
    newn = new struct nodeDL<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        newn->next = head;
        head->prev = newn;
        head = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T> :: InsertLast(T no)
{
    struct nodeDL<T> * newn = NULL;
    struct nodeDL<T> * temp = NULL;
    newn = new struct nodeDL<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

template <class T>
void DoublyLL<T> :: InsertAtPos(T no, int ipos)
{
    struct nodeDL<T> * temp = NULL;
    struct nodeDL<T> * newn = NULL;

    if(ipos < 1 || ipos > iCount+1)
    {
        cout<<"Invalid Position\n";
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        temp = head;
        newn = new struct nodeDL<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(int i = 1; i < ipos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

template <class T>
void DoublyLL<T> :: DeleteFirst()
{
    if(head == NULL)
    {
        return;
    }
    else if(head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        head = head->next;
        delete head->prev;
        head->prev = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T> :: DeleteLast()
{
    struct nodeDL<T> * temp = NULL;

    if(head == NULL)
    {
        return;
    }
    else if(head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        temp = head;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete (temp->next);
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T> :: DeleteAtPos(int ipos)
{
    struct nodeDL<T> * temp = NULL;
    struct nodeDL<T> * target = NULL;

    if(ipos < 1 || ipos > iCount)
    {
        cout<<"Invalid Position\n";
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = head;

        for(int i = 1; i < ipos-1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = temp->next->next;
        target->prev = temp;
        delete (target);
    }
    iCount--;
}

template <class T>
void DoublyLL<T> :: Display()
{
    struct nodeDL<T> * temp = NULL;
    temp = head;

    cout<<"NULL <=> ";
    do
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }while(temp != NULL);

    cout<<"NULL \n";
}

template <class T>
int DoublyLL<T> :: Count()
{
    return iCount;
}


//----------------------------------------------------------------------------------------------------------------------------------//
//              Doubly Circular Linked List
//----------------------------------------------------------------------------------------------------------------------------------//

template <class T>
struct nodeDC
{
    T data;
    struct nodeDC * next;
    struct nodeDC * prev;
};

// Generic Doubly Circular Linked List class
template <class T>
class DoublyCL
{
    public:
        struct nodeDC<T> * head;
        struct nodeDC<T> * tail;
        int iCount;

        DoublyCL();
      
        void InsertFirst(T no);
       
        void InsertLast(T no);
        
        void InsertAtPos(T no, int ipos);
       
        void DeleteFirst();
       
        void DeleteLast();
       
        void DeleteAtPos(int ipos);
        
        void Display();
       
        int Count();  
};

template <class T>
DoublyCL<T> :: DoublyCL()
{
    head = NULL;
    tail = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T> :: InsertFirst(T no)
{
    struct nodeDC<T> * newn = NULL;
    newn = new struct nodeDC<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(head == NULL && tail == NULL)
    {
        head = newn;
        tail = newn;
        tail->next = head;
        head->prev = tail;
    }
    else
    {
       newn->next = head;
       head->prev = newn;
       tail->next = newn;
       newn->prev = tail;
       head = newn;
    }
    iCount++;
}

template <class T>
void DoublyCL<T> :: InsertLast(T no)
{
    struct nodeDC<T> * newn = NULL;
    struct nodeDC<T> * temp = NULL;
    newn = new struct nodeDC<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(head == NULL && tail == NULL)
    {
        head = newn;
        tail = newn;
        tail->next = head;
        head->prev = tail;
    }
    else
    {
        tail->next = newn;
        newn->prev = tail;
        tail = tail->next;
        tail->next = head;
        head->prev = tail;
    }
    iCount++;
}

template <class T>
void DoublyCL<T> :: InsertAtPos(T no, int ipos)
{
    struct nodeDC<T> * temp = NULL;
    struct nodeDC<T> * newn = NULL;

    if(ipos < 1 || ipos > iCount+1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        temp = head;
        newn = new struct nodeDC<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(int i = 1; i < ipos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        temp->next->prev = temp;
    }
    iCount++;
}

template <class T>
void DoublyCL<T> :: DeleteFirst()
{
    if(head == NULL && tail == NULL)
    {
        return;
    }
    else if(head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        head = head->next;
        delete head->prev;
        head->prev = tail;
        tail->next = head;
    }
    iCount--;
}

template <class T>
void DoublyCL<T> :: DeleteLast()
{
    if(head == NULL && tail == NULL)
    {
        return;
    }
    else if(head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = head;
        head->prev = tail;
    }
    iCount--;
}

template <class T>
void DoublyCL<T> :: DeleteAtPos(int ipos)
{
    struct nodeDC<T> * temp = NULL;

    if(ipos < 1 || ipos > iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = head;

        for(int i = 1; i < ipos-1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete (temp->next->prev);
        temp->next->prev = temp;
    }
    iCount--;
}

template <class T>
void DoublyCL<T> :: Display()
{
    struct nodeDC<T> * temp = NULL;
    temp = head;

    if(head == NULL && tail == NULL)
    {
        cout<<"Linked list is empty\n";
        return;
    }

    do
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }while(temp != head);

    cout<<"\n";
}

template <class T>
int DoublyCL <T> :: Count()
{
    return iCount;
}



//----------------------------------------------------------------------------------------------------------------------------------//
//                           STACK 
//----------------------------------------------------------------------------------------------------------------------------------//

template <class T>
struct nodeStack 
{
    T data;
    struct nodeStack * next;
};

// Generic Stack class
template <class T>
class Stack 
{
    public:
        struct nodeStack<T> * head;
        int iCount;

        Stack();

        void push(T no);  // InsertFirst()
       
        void pop();  // DeleteFirst()
        
        void Display();

        int Count();

};

template <class T>
Stack<T> :: Stack()
{
    head = NULL;
    iCount = 0;
}

template <class T>
void Stack<T> :: push(T no)   // InsertFirst()
{
    struct nodeStack<T> * newn = NULL;
    newn = new struct nodeStack<T>;

    newn->data = no;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        newn->next = head;
        head = newn;
    }
    iCount++;
}

template <class T>
void Stack<T> :: pop()  // DeleteFirst()
{
    struct nodeStack<T> * temp = NULL;
    if(head == NULL)
    {
        return;
    }
    else if(head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    iCount--;
}

template <class T>
void Stack<T> :: Display()
{
    struct nodeStack<T> * temp = NULL;
    temp = head;
    
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |"<<endl;
        temp = temp->next;
    }
    cout<<"\n";
}

template <class T>
int Stack<T> :: Count()
{
    return iCount;
}



//----------------------------------------------------------------------------------------------------------------------------------//
//                      QUEUE
//----------------------------------------------------------------------------------------------------------------------------------//

template <class T>
struct nodeQueue
{
    T data;
    struct nodeQueue * next;
};

// Generic QUEUE class
template <class T>
class Queue
{
    public:
        struct nodeQueue<T> * head;
        int iCount;

        Queue();
        
        void enqueue(T no);    // InsertLast()

        void dequeue();  // DeleteFirst()
       
        void Display();
       
        int Count();
};

template <class T>
Queue<T> :: Queue()
{
    head = NULL;
    iCount = 0;
}

template <class T>
void Queue<T> :: enqueue(T no)    // InsertLast()
{
    struct nodeQueue<T> * newn = NULL;
    struct nodeQueue<T> * temp = NULL;
    newn = new struct nodeQueue<T>;

    newn->data = no;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else 
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void Queue<T> :: dequeue()  // DeleteFirst()
{
    struct nodeQueue<T> * temp = NULL;

    if(head == NULL)
    {
        return;
    }
    else if(head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    iCount--;
}

template <class T>
void Queue<T> :: Display()
{
    struct nodeQueue<T> * temp = NULL;
    temp = head;
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | "<<"\n";
        temp = temp->next;
    }
}

template <class T>
int Queue<T> :: Count()
{
    return iCount;
}

//----------------------------------------------------------------------------------------------------------------------------------//
//              Linear Search Algorithem
//----------------------------------------------------------------------------------------------------------------------------------//

template <class T>
bool LinearSearch(T Brr[], int size, T iNo)
{
    bool Flag = false;
    int i = 0;

    for(i = 0; i < size; i++)
    {
        if(iNo == Brr[i])
        {
            Flag = true;    // Element found 
            break;
        }
    }
    
    return Flag;    // Element not found
}

//----------------------------------------------------------------------------------------------------------------------------------//
//              Middle Element
//----------------------------------------------------------------------------------------------------------------------------------//

// Generic Middle Element 
template <class T>
void MiddleElement(T Brr[], int Size)
{
    if(Size <= 0)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    
    int Mid = Size/2;
    
    cout<<"Middle element is : "<<Brr[Mid]<<endl;
}

//----------------------------------------------------------------------------------------------------------------------------------//
//              Main Function
//----------------------------------------------------------------------------------------------------------------------------------//

int main()
{
    SinglyLL<int> sobj;
    sobj.InsertFirst(11);
    sobj.InsertLast(51);
    sobj.InsertAtPos(21,2);
    sobj.Display();
    cout<<"Number of elements : "<<sobj.Count()<<endl;

    sobj.DeleteAtPos(2);
    sobj.Display();
    cout<<"Number of elements : "<<sobj.Count()<<endl;

    Stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.Display();  // shows 30 -> 20 -> 10

    s.pop();      // Removes 30

    s.Display();  // show 20 -> 10

    cout << "Stack Count: " << s.Count() << "\n\n";

    Queue<int> qobj;

    qobj.enqueue(100);
    qobj.enqueue(200);
    qobj.enqueue(300);

    qobj.Display();  // show 100 -> 200 -> 300
    cout<<"\n";

    qobj.dequeue();  // Removes 100

    qobj.Display();  // show 200 -> 300

    cout << "Queue Count: " << qobj.Count() << "\n";

    return 0;
}

//----------------------------------------------------------------------------------------------------------------------------------//

//----------------------------------------------------------------------------------------------------------------------------------//

