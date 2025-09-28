//----------------------------------------------------------------------------------------------------------------------------------//
//        Project Title : Generalized Data Structures Library
//        Technology    : C++ Programming
//        Description   : # This project is considered as a library which contains generic implementations of all major types of 
//                         data structures.
//                                              
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

///////////////////////////////////////////////////////////////////////
//
//  Class :         SinglyLL
//  Description :   Generic implementation of Singly Linked List
//  Author :        Amol R. Mane
//
///////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////
//
//  Class :         SinglyCL
//  Description :   Generic implementation of Singly Circular Linked List
//  Author :        Amol R. Mane
//
///////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////
//
//  Class :         DoublyLL
//  Description :   Generic implementation of Doubly Linked List
//  Author :        Amol R. Mane
//
///////////////////////////////////////////////////////////////////////

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


///////////////////////////////////////////////////////////////////////
//
//  Class :         DoublyCL
//  Description :   Generic implementation of Doubly Circular Linked List
//  Author :        Amol R. Mane
//
///////////////////////////////////////////////////////////////////////

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



///////////////////////////////////////////////////////////////////////
//
//  Class :         Stack
//  Description :   Generic implementation of Stack
//  Author :        Amol R. Mane
//
///////////////////////////////////////////////////////////////////////

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



///////////////////////////////////////////////////////////////////////
//
//  Class :         Queue
//  Description :   Generic implementation of Queue
//  Author :        Amol R. Mane
//
///////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////
//
//  Class :         BinarySearchTree
//  Description :   Generic implementation of Binary Search Tree
//  Author :        Amol R. Mane
//
///////////////////////////////////////////////////////////////////////

template<class T>
struct nodeBST
{
    T data;
    nodeBST<T> *lchild;
    nodeBST<T> *rchild;
};

template<class T>
class BinarySearchTree
{
    private:
        nodeBST<T> * head;

        // private helper for recursion
        void InorderR(nodeBST<T>* temp);
        void PreorderR(nodeBST<T>* temp);
        void PostorderR(nodeBST<T>* temp);
        bool SearchR(nodeBST<T>* temp, T no);
        int CountNodesR(nodeBST<T>* temp);
        int CountParentNodesR(nodeBST<T>* temp);
        int CountLeafNodesR(nodeBST<T>* temp);

    public:
        BinarySearchTree();
        void Insert(T no);
        void Inorder();
        void Preorder();
        void Postorder();
        bool Search(T no);
        int CountNodes();
        int CountParentNodes();
        int CountLeafNodes();
};

// constructor
template<class T>
BinarySearchTree<T>::BinarySearchTree()
{
    cout<<"Insdie constructor of BST\n";
    this->head = NULL;
}

// insert function
template<class T>
void BinarySearchTree<T>::Insert(T no)
{
    nodeBST<T> * newn = NULL;
    nodeBST<T> * temp = NULL;

    newn = new nodeBST<T>;
    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(head == NULL)   // Tree is empty
    {
        head = newn;
        return;
    }
    else    // Tree contains at least one node
    {
        temp = head;

        while(1)
        {
            if(no > temp->data) // Greater
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else if(no < temp->data)    // Smaller
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
            else if(no == temp->data)   // Identical
            {
                cout<<"Unable to insert as element is duplicate\n";
                delete newn;
                break;
            }
        }
    }
}

// Public wrappers
template<class T>
void BinarySearchTree<T>::Inorder()   { InorderR(head); cout<<"\n"; }

template<class T>
void BinarySearchTree<T>::Preorder()  { PreorderR(head); cout<<"\n"; }

template<class T>
void BinarySearchTree<T>::Postorder() { PostorderR(head); cout<<"\n"; }

template<class T>
bool BinarySearchTree<T>::Search(T no) { return SearchR(head,no); }

template<class T>
int BinarySearchTree<T>::CountNodes() { return CountNodesR(head); }

template<class T>
int BinarySearchTree<T>::CountParentNodes() { return CountParentNodesR(head); }

template<class T>
int BinarySearchTree<T>::CountLeafNodes() { return CountLeafNodesR(head); }

// private helpers
template <class T>
void BinarySearchTree<T>::InorderR(nodeBST<T>* temp)
{
    if(temp != NULL)
    {
        InorderR(temp->lchild);
        cout<<temp->data<<" ";
        InorderR(temp->rchild);
    }
}

template <class T>
void BinarySearchTree<T>::PreorderR(nodeBST<T>* temp)
{
    if(temp != NULL)
    {
        cout<<temp->data<<" ";
        PreorderR(temp->lchild);
        PreorderR(temp->rchild);
    }
}

template <class T>
void BinarySearchTree<T>::PostorderR(nodeBST<T>* temp)
{
    if(temp != NULL)
    {
        PostorderR(temp->lchild);
        PostorderR(temp->rchild);
        cout<<temp->data<<" ";
    }
}

template <class T>
bool BinarySearchTree<T>::SearchR(nodeBST<T>* temp, T no)
{
    bool bFlag = false;

    while(temp != NULL)
    {
        if(no == temp->data)
        {
            bFlag = true;
            break;
        }
        else if(no > temp->data)
        {
            temp = temp->rchild;
        }
        else if(no < temp->data)
        {
            temp = temp->lchild;
        }
    }
    return bFlag;
}

template <class T>
int BinarySearchTree<T>::CountNodesR(nodeBST<T>* temp)
{
    if(temp == NULL)
        return 0;

    return 1 + CountNodesR(temp->lchild) + CountNodesR(temp->rchild);
}

template <class T>
int BinarySearchTree<T>::CountParentNodesR(nodeBST<T>* temp)
{
   if(temp == NULL)
        return 0;

    int count = 0;
    if(temp->lchild != NULL || temp->rchild != NULL) // only parent nodes
        count = 1;

    return count + CountParentNodesR(temp->lchild) + CountParentNodesR(temp->rchild); 
}

template <class T>
int BinarySearchTree<T>::CountLeafNodesR(nodeBST<T>* temp)
{
    if(temp == NULL)
        return 0;
    if(temp->lchild == NULL && temp->rchild == NULL)
        return 1;
    return CountLeafNodesR(temp->lchild) + CountLeafNodesR(temp->rchild);
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         SearchingAlgorithems
//  Description :   Generic implementation of -
//                                            Linear Search
//                                            Linear Bidirectional Search
//                                            Binary Search
//  Author :        Amol R. Mane
//
///////////////////////////////////////////////////////////////////////

template <class T>
class SearchingAlgorithems
{
    private:
        T* Arr;
        int size;

    public:
        SearchingAlgorithems(int n);
        ~SearchingAlgorithems();
        void Accept();
        void Display();
        bool LinearSearch(T iNo);
        bool LinearSearchBidirectional(T Value);
        bool BinarySearch(T iNo);
};

// constructor
template <class T>
SearchingAlgorithems<T>::SearchingAlgorithems(int n)
{
    size = n;
    Arr = new T[size];
}

template<class T>
SearchingAlgorithems<T>::~SearchingAlgorithems()
{
    delete[] Arr;    
}

template<class T>
void SearchingAlgorithems<T>::Accept()
{
    int i = 0;
    cout<<"Enter the elements : \n";
    for( i = 0; i < size; i++)
    {
        cin>>Arr[i];            
    }
}

template<class T>
void SearchingAlgorithems<T>::Display()
{
    int i = 0;
    cout<<"Elements of the array are : \n";
    for( i = 0; i < size; i++)
    {
        cout<<Arr[i]<<" ";            
    }
    cout<<"\n";
}
//----------------------------------------------------------------------------------------------------------------------------------//
//             Linear Search 
//----------------------------------------------------------------------------------------------------------------------------------//
template <class T>
bool SearchingAlgorithems<T>::LinearSearch(T iNo)
{
    for (int i = 0; i < size; i++)
    {
        if (Arr[i] == iNo)
            return true; // Element found
    }
    return false; // Not found
}

//----------------------------------------------------------------------------------------------------------------------------------//
//             Linear Search Bidirectional 
//----------------------------------------------------------------------------------------------------------------------------------//
template <class T>
bool SearchingAlgorithems<T>::LinearSearchBidirectional(T Value)
{
    int iStart = 0, iEnd = size - 1;
    while (iStart <= iEnd)
    {
        if (Arr[iStart] == Value || Arr[iEnd] == Value)
            return true; // Element found
        iStart++;
        iEnd--;
    }
    return false; // Not found
}

//----------------------------------------------------------------------------------------------------------------------------------//
//                 Binary Search 
//----------------------------------------------------------------------------------------------------------------------------------//
template <class T>
bool SearchingAlgorithems<T>::BinarySearch(T iNo)
{
    int iStart = 0, iEnd = size - 1;
    while (iStart <= iEnd)
    {
        int iMid = iStart + (iEnd - iStart) / 2;

        if (Arr[iMid] == iNo)
            return true; // Found
        else if (iNo > Arr[iMid])
            iStart = iMid + 1; // Right half
        else
            iEnd = iMid - 1;   // Left half
    }
    return false; // Not found
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         SortingAlgorithems
//  Description :   Generic implementation of -
//                                            Bubble Sort
//                                            Selection Sort
//                                            Insertion Search
//  Author :        Amol R. Mane
//
///////////////////////////////////////////////////////////////////////

template<class T>
class SortingAlgorithems
{
    private:
        T* Arr;
        int size;

    public:
        SortingAlgorithems(int n);
        ~SortingAlgorithems();
        void Accept();
        void Display();
        void BubbleSort();
        void SelectionSort();
        void InsertionSort();
};

// Constructor
template<class T>
SortingAlgorithems<T>::SortingAlgorithems(int n)
{
    size = n;
    Arr = new T[size];
}

// Destructor
template<class T>
SortingAlgorithems<T>::~SortingAlgorithems()
{
    delete[] Arr;
}

template<class T>
void SortingAlgorithems<T>::Accept()
{
    int i = 0;
    cout<<"Enter the elements : \n";
    for(i = 0; i < size; i++)
    {
        cin>>Arr[i];            
    }
}

template<class T>
void SortingAlgorithems<T>::Display()
{
    int i = 0;
    cout<<"Elements of the array are : \n";
    for(i = 0; i < size; i++)
    {
        cout<<Arr[i]<<" ";
    }
    cout<<"\n";
}

//----------------------------------------------------------------------------------------------------------------------------------//
//              Bubble Sort
//----------------------------------------------------------------------------------------------------------------------------------//

template<class T>
void SortingAlgorithems<T> :: BubbleSort()
{
    int i = 0, j = 0;
    T temp;

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size - i - 1; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
            }
        }
    }
}

//----------------------------------------------------------------------------------------------------------------------------------//
//              Selection Sort
//----------------------------------------------------------------------------------------------------------------------------------//

template <class T>
void SortingAlgorithems<T> :: SelectionSort()
{
    int i = 0, j = 0, min_index = 0;
    T temp;

    for(i = 0; i < size; i++)
    {
        min_index = i;
        
        for(j = i+1; j < size; j++)
        {
            if(Arr[min_index] > Arr[j])
            {
                min_index = j;
            }
        }
        if(i != min_index)
        {
            temp = Arr[i];
            Arr[i] = Arr[min_index];
            Arr[min_index] = temp;
        }
    }
}

//----------------------------------------------------------------------------------------------------------------------------------//
//              Insertion Sort
//----------------------------------------------------------------------------------------------------------------------------------//

template<class T>
void SortingAlgorithems<T> :: InsertionSort()
{
    int i = 0, j = 0;
    T selected;

    for(i = 1; i < size; i++)
    {
        for(j = i-1, selected = Arr[i]; ((j >= 0) && (Arr[j] > selected)); j--)
        {
            Arr[j + 1] = Arr[j];
        }   
        Arr[j + 1] = selected;
    } 
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         MiddleElement
//  Description :   Generic implementation of Middle Element
//
//  Author :        Amol R. Mane
//
///////////////////////////////////////////////////////////////////////


//----------------------------------------------------------------------------------------------------------------------------------//
//              Middle Element
//----------------------------------------------------------------------------------------------------------------------------------//

// Generic Middle Element 
template <class T>
class MiddleElement
{
    private:
        T* Arr;
        int size;

    public:
        MiddleElement(int n);
        ~MiddleElement();

        void Accept();
        void Display();
        void MidElement();
};

template<class T>
MiddleElement<T> :: MiddleElement(int n)
{
    size = n;
    Arr = new T[size];
}

template<class T>
MiddleElement<T> :: ~MiddleElement()
{
    delete []Arr;
}

template<class T>
void MiddleElement<T> :: Accept()
{
    int i = 0;
    cout<<"Enter the elements of array : \n";
    for(i = 0; i < size; i++)
    {
        cin>>Arr[i];
    }
}

template<class T>
void MiddleElement<T> :: Display()
{
    int i = 0;
    cout<<"Elements of the array are : \n";
    for(i = 0; i < size; i++)
    {
        cout<<Arr[i]<<" ";
    }
    cout<<"\n";
}

template<class T>
void MiddleElement<T> :: MidElement()
{
    if(size <= 0)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    
    int Mid = size/2;
    
    cout<<"Middle element is : "<<Arr[Mid]<<endl;
}

////////////////////////////////////////////////////////////////////////
//
//  Function :      main()
//  Description :   Entry point function
//  Author :        Amol R. Mane
//
///////////////////////////////////////////////////////////////////////

int main()
{
    // SinglyLL
    SinglyLL<int> sobj;
    sobj.InsertFirst(11);
    sobj.InsertLast(51);
    sobj.InsertAtPos(21,2);
    sobj.Display();
    cout<<"Number of elements : "<<sobj.Count()<<endl;

    sobj.DeleteAtPos(2);
    sobj.Display();
    cout<<"Number of elements : "<<sobj.Count()<<endl;

    // Stack
    Stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.Display();  // shows 30 -> 20 -> 10

    s.pop();      // Removes 30

    s.Display();  // show 20 -> 10

    cout << "Stack Count: " << s.Count() << "\n\n";

    // Queue
    Queue<int> qobj;

    qobj.enqueue(100);
    qobj.enqueue(200);
    qobj.enqueue(300);

    qobj.Display();  // show 100 -> 200 -> 300
    cout<<"\n";

    qobj.dequeue();  // Removes 100

    qobj.Display();  // show 200 -> 300

    cout << "Queue Count: " << qobj.Count() << "\n";


    // BST
    BinarySearchTree<int> bobj;

    bobj.Insert(10);
    bobj.Insert(50);
    bobj.Insert(30);
    bobj.Insert(25);
    bobj.Insert(75);
    bobj.Insert(60);

    bobj.Inorder();
    bobj.Preorder();
    bobj.Postorder();

    if(bobj.Search(30)) cout<<"Found\n";
    else  cout<<"Not found\n";

    if(bobj.Search(100)) cout<<"Found\n";
    else cout<<"Not Found\n";

    cout<<bobj.CountLeafNodes()<<"\n";
    cout<<bobj.CountNodes()<<endl;
    cout<<bobj.CountParentNodes()<<endl;

    // sorting algorithems
    int n = 0;
    cin>>n;

    SortingAlgorithems<int> obj(n);
    obj.Accept();
    obj.Display();

    obj.BubbleSort();
    obj.Display();

    obj.Accept();
    obj.SelectionSort();
    obj.Display();

    return 0;
}

//----------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------//
