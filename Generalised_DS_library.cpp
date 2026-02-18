#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////
//
// Code of Singly Linear
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template <class T>
class SinglyLL
{
    private:
        struct nodeSL<T> * First;
        int iCount;

    public:
        SinglyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    cout<<"Inside Constructor\n";
    First = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
    struct nodeSL<T> * temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"|-> ";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct nodeSL<T> * newn = NULL;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct nodeSL<T> * newn = NULL;
    struct nodeSL<T> * temp = First;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeSL<T> * newn = NULL;
    int i = 0;
    struct nodeSL<T> * temp;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else 
    {
        temp = First;
        
        newn = new nodeSL<T>;
        newn->data = No;
        newn->next = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp -> next = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First -> next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp ->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSL<T> * temp1;
    struct nodeSL<T> * temp2;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else 
    {
        temp1 = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }    
}

/////////////////////////////////////////////////////////////
//
// Code of Doubly Circular
//
/////////////////////////////////////////////////////////////
template <class T>
struct nodeDC
{
    T data;
    struct nodeDC *next;
    struct nodeDC *prev;
};

template <class T>
class DoublyCL
{
    private:
        struct nodeDC<T> * First;
        struct nodeDC<T> * Last;
        int iCount;

    public:
        DoublyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
DoublyCL<T>:: DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
    if(First == NULL && Last == NULL)
    {
        cout<<"Linked List is emprty\n";
        return;
    }

    cout<<"<=> ";
    do
    {
        cout<<"| "<<First->data <<"| <=> ";
        First = First -> next;
    }while(Last -> next != First);

    cout<<"\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last ->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;    
}

template <class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDC<T> * temp = NULL;
    struct nodeDC<T> * newn = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeDC<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one node
    {
        First = First -> next;
        delete Last->next;
        First -> prev = Last;
        Last -> next = First;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one node
    {
        Last = Last -> prev;
        delete First -> prev;

        Last -> next = First;
        First -> prev = Last;
    }
    iCount--;    
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    struct nodeDC<T> * temp = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }    
}

/////////////////////////////////////////////////////////////
//
// Code of Doubly Liear
//
/////////////////////////////////////////////////////////////
template <class T>
struct nodeDl
{
    T data;
    struct nodeDl<T> *next;
    struct nodeDl<T> *prev;
};

template <class T>
class DoublyLL
{
private:
   struct nodeDl<T> * First;
    int iCount;

public:
    DoublyLL();

    void Display();
    int Count();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T>::Display()
{
   struct nodeDl<T> * temp = NULL;

    temp = First;
    cout << "\nNULL<=>";
    while (temp != NULL)
    {
        cout << "|" << temp->data << "|<=>";
        temp = temp->next;
    }
    cout << "NULL\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    cout << "\n";
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T No)
{
   struct nodeDl<T> * newn = NULL;

    newn = new nodeDl<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;

        First = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertLast(T No)
{
   struct nodeDl<T> *newn = NULL;
   struct nodeDl<T> * temp = NULL;

    newn = new nodeDl<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T No, int iPos)
{
 struct nodeDl<T> * newn = NULL;
 struct nodeDl<T> * temp = NULL;
    int i = 0;

    newn = new nodeDl<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if ((iPos < 1) || (iPos > iCount + 1))
    {
        return;
    }
    if (iPos == 1)
    {
        InsertFirst(No);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        temp = First;

        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if (First == NULL)
    {
        return;
    }
    else if (First->next == NULL)
    {
        free(First);
        First = NULL;
    }
    else
    {
        First = First->next;
        free(First->prev);
        First->prev = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    struct nodeDl<T> * temp = NULL;

    if (First == NULL)
    {
        return;
    }
    else if (First->next == NULL)
    {
        free(First);
        First = NULL;
    }
    else
    {
        temp = First;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    struct nodeDl<T> * newn = NULL;
    struct nodeDl<T> * temp = NULL;
    int i = 0;

    if ((iPos < 1) || (iPos > iCount))
    {
        return;
    }
    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;

        free(temp->next->prev);

        temp->next->prev = NULL;

        iCount--;
    }
}

/////////////////////////////////////////////////////////////
//
// Code of Singly Circular
//
/////////////////////////////////////////////////////////////

  template <class T>
struct nodeSC
{
    T data;
    struct nodeSC *next;
};

template <class T>
class SinglyCL
{
private:
   struct nodeSC<T> * First;
   struct nodeSC<T> * Last;
    int iCount;

public:
    SinglyCL();

    void Display();
    int Count();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};

template <class T>
SinglyCL<T>::SinglyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
int SinglyCL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyCL<T>::Display()
{
    if ((First == NULL) && (Last == NULL))
    {
        return;
    }
    do
    {
        cout << First->data << "|->";
        First = First->next;
    } while (First != Last->next);

    cout << "\n";
}

template <class T>
void SinglyCL<T>::InsertFirst(T No)
{
   struct nodeSC<T> * newn = NULL;

    newn = new nodeSC<T>;

    newn->data = No;
    newn->next = NULL;

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    Last->next = First;
    iCount++;
}

template <class T>
void SinglyCL<T>::InsertLast(T No)
{
  struct nodeSC<T> * newn = NULL;

    newn = new nodeSC<T>;

    newn->data = No;
    newn->next = NULL;

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        Last = newn;
    }
    Last->next = First;
    iCount++;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T No, int iPos)
{
    int i = 0;
   struct nodeSC<T> * newn = NULL;
   struct nodeSC<T> * temp = NULL;

    if ((iPos < 1) || (iPos > iCount + 1))
    {
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(No);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeSC<T>;

        newn->data = No;
        newn->next = NULL;

        temp = First;

        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }

    Last->next = First;
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if ((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if (First == Last)
    {
        delete (First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete (Last->next);
    }
    Last->next = First;
    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
   struct nodeSC<T> * temp = NULL;

    if ((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if (First == Last)
    {
        delete (First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        temp = First;
        while (temp->next != Last)
        {
            temp = temp->next;
        }
        delete (Last);
        Last = temp;
    }
    Last->next = First;
    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
   struct nodeSC<T> * temp1 = NULL;
   struct nodeSC<T> * temp2 = NULL;

    if ((iPos < 1) || (iPos > iCount))
    {
        return;
    }
    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for (i = 1; i < iPos - 1; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;

        temp1->next = temp2->next;

        delete(temp2);
         Last->next = First;
          iCount--;
    }
}
/////////////////////////////////////////////////////////////
//
// Code of Stack
//
/////////////////////////////////////////////////////////////

   
template <class T>
struct nodeS
{
    T data;
    struct nodeS * next;
};

template <class T>
class Stack
{
    private:
      struct  nodeS<T>* First;
        int iCount;

    public:
        Stack();
        void Display();
        int Count();
        void Push(T No);
        T Pop();
};

template <class T>
Stack<T>::Stack()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void Stack<T>::Display()
{
    cout << "Elements of stack are : \n";
   struct nodeS<T>* temp = First;

    while(temp != NULL)
    {
        cout << temp->data << "\n";
        temp = temp->next;
    }
    cout << "\n";
}

template <class T>
int Stack<T>::Count()
{
    return iCount;
}

template <class T>
void Stack<T>::Push(T No)
{
  struct  nodeS<T>* newn = new nodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
T Stack<T>::Pop()
{
    if(First == NULL)
    {
        cout << "Stack is empty\n";
        return T();
    }

   struct nodeS<T>* temp = First;
    T iValue = temp->data;

    First = First->next;
    delete temp;
    iCount--;

    return iValue;
}

/////////////////////////////////////////////////////////////
//
// Code of Queue
//
/////////////////////////////////////////////////////////////

   
template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class Queue
{
    private:
        struct node<T> *First;
        int iCount;

    public:
        Queue();
        void Display();
        int Count();
        void EnQueue(T No);  // InsertLast()
        T DeQueue();   // DeleteFirst()
};

template <class T>
Queue<T> :: Queue()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void Queue<T> ::Display()
{
    cout<<"Elements of Queue are : \n";
   struct node<T> * temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp -> next;
    }
    cout<<"\n";
}

template <class T>
int Queue<T> ::Count()
{
    return iCount;
}

template <class T>
void Queue<T> ::EnQueue(T No)
{
    struct node<T> * newn = NULL;
    struct node<T> * temp = NULL;

    newn = new node<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while(temp ->next != NULL)
        {
            temp = temp -> next;
        }

        temp->next = newn;
    }
    iCount++;
}

template <class T>
T Queue<T> ::DeQueue()
{
    T iValue;
    struct node<T> * temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to remove the element as queue is empty\n";
        return -1;
    }
    else
    {
        temp = First;

        iValue = First -> data;
        First = First -> next;
        delete temp;
        
        iCount--;
    }

    return iValue;
}

int main()
{
    // LL of integer
           cout<<"----------- Implementaion Singly LinkdList of Integers -----------\n";

    cout<<"-------------- Singly LinkdList of Integers --------------\n";

    SinglyLL<int> *iobj = new SinglyLL<int>();
    int iRet = 0;

    iobj->InsertFirst(51);
    iobj->InsertFirst(21);
    iobj->InsertFirst(11);

    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iobj->InsertLast(101);
    iobj->InsertLast(111);
    iobj->InsertLast(121);
    
    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iobj->InsertAtPos(105,5);

    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iobj->DeleteAtPos(5);
    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    // LL of character
    cout<<"-------------- Singly LinkdList of Chracters --------------\n";

    SinglyLL<char> *cobj = new SinglyLL<char>();

    cobj->InsertFirst('D');
    cobj->InsertFirst('F');
    cobj->InsertFirst('R');

    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cobj->InsertLast('E');
    cobj->InsertLast('Y');
    cobj->InsertLast('U');
    
    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cobj->InsertAtPos('W',5);

    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cobj->DeleteAtPos(5);
    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    // LL of float
    cout<<"-------------- Singly LinkdList of Floats --------------\n";

    SinglyLL<float> *fobj = new SinglyLL<float>();

    fobj->InsertFirst(90.78f);
    fobj->InsertFirst(78.99f);
    fobj->InsertFirst(67.99f);

    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fobj->InsertLast(45.67f);
    fobj->InsertLast(54.78f);
    fobj->InsertLast(77.89f);
    
    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fobj->InsertAtPos(88.56,5);

    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fobj->DeleteAtPos(5);
    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    // LL of double

    cout<<"-------------- Singly LinkdList of Doubles --------------\n";

    SinglyLL<double> *dobj = new SinglyLL<double>();

    dobj->InsertFirst(90.78978);
    dobj->InsertFirst(78.99645);
    dobj->InsertFirst(67.9934);

    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dobj->InsertLast(45.67867);
    dobj->InsertLast(54.78534);
    dobj->InsertLast(77.89324);
    
    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dobj->InsertAtPos(88.56987,5);

    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dobj->DeleteAtPos(5);
    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

     // Singly Circular Linkedlist 
     cout<<"-------------- Singly Circular Linkedlist --------------\n";

 cout<<"-------------- Singly Circular Linkedlist of Integers --------------\n";
     SinglyCL<int> *SCiobj = new SinglyCL<int>() ;
    // int iRet = 0;

    cout <<"InsertFirst   :\n";
    SCiobj->InsertFirst(101);
    SCiobj->InsertFirst(51);
    SCiobj->InsertFirst(21);
    SCiobj->InsertFirst(11);

    SCiobj->Display();
    iRet = SCiobj->Count();

    cout <<"Number of elements are: " << iRet << " \n";

     cout <<"InsertLast   :\n";
    SCiobj->InsertLast(111);
    SCiobj->InsertLast(121);
    SCiobj->InsertLast(151);
    SCiobj->InsertLast(201);

     SCiobj->Display();
     iRet = SCiobj->Count();
     cout << "Number of elements are:" << iRet <<" \n ";
     cout <<"Innsert At Pos   :\n";
    SCiobj->InsertAtPos(10, 5);

     SCiobj->Display();
    iRet = SCiobj->Count();

    cout << "Number of elements are:  " << iRet <<"\n";
    
     cout<<"DeleteFirst   : \n";
    SCiobj->DeleteFirst();
    SCiobj->Display();
    iRet = SCiobj->Count();

       cout<<"DeleteLast   : \n";
    SCiobj->DeleteLast();

    SCiobj->Display();
    iRet = SCiobj->Count();

       cout<<"Delete At Pos   :\n";
    SCiobj->DeleteAtPos(5);

    SCiobj->Display();
    iRet = SCiobj->Count();

    cout << "Number of elements are:  " << iRet << "\n";

    // SinglyCl of float
     cout<<"-------------- Singly Circular Linkedlist of Float --------------\n";

     SinglyCL<float> *SCfobj = new SinglyCL<float>() ;

    cout <<"InsertFirst   :\n";
    SCfobj->InsertFirst(101.83f);
    SCfobj->InsertFirst(51.28f);
    SCfobj->InsertFirst(21.88f);
    SCfobj->InsertFirst(11.683f);

    SCfobj->Display();
    iRet = SCfobj->Count();

    cout <<"Number of elements are: " << iRet << " \n";

     cout <<"InsertLast   :\n";
    SCfobj->InsertLast(111.18f);
    SCfobj->InsertLast(121.583f);
    SCfobj->InsertLast(151.58f);
    SCfobj->InsertLast(201.589f);

     SCfobj->Display();
     iRet = SCfobj->Count();
    cout << "Number of elements are:" << iRet <<" \n ";

    cout <<"Innsert At Pos   :\n";
    SCfobj->InsertAtPos(10.38f,5);

     SCfobj->Display();
    iRet = SCfobj->Count();

    cout << "Number of elements are:  " << iRet <<"\n";
    
     cout<<"DeleteFirst   : \n";
    SCfobj->DeleteFirst();
    SCfobj->Display();
    iRet = SCfobj->Count();

       cout<<"DeleteLast   : \n";
    SCfobj->DeleteLast();

    SCfobj->Display();
    iRet = SCfobj->Count();

       cout<<"Delete At Pos   :\n";
    SCfobj->DeleteAtPos(5);

    SCfobj->Display();
    iRet = SCfobj->Count();

      cout << "Number of elements are:  " << iRet << "\n" ;

          // SinglyCl of Double
     cout<<"-------------- Singly Circular Linkedlist of Double --------------\n";

     SinglyCL<double> *SCdobj = new SinglyCL<double>() ;

    cout <<"InsertFirst   :\n";
    SCdobj->InsertFirst(101.523);
    SCdobj->InsertFirst(51.2378);
    SCdobj->InsertFirst(21.87654);
    SCdobj->InsertFirst(11.6782);

    SCdobj->Display();
    iRet = SCdobj->Count();

    cout <<"Number of elements are: " << iRet << " \n";

     cout <<"InsertLast   :\n";
    SCdobj->InsertLast(111.12323);
    SCdobj->InsertLast(121.5652);
    SCdobj->InsertLast(151.53267);
    SCdobj->InsertLast(201.53987);

     SCdobj->Display();
     iRet = SCdobj->Count();
    cout << "Number of elements are:" << iRet <<" \n ";

    cout <<"Innsert At Pos   :\n";
    SCdobj->InsertAtPos(10.3987, 5);

     SCdobj->Display();
    iRet = SCdobj->Count();

    cout << "Number of elements are:  " << iRet <<"\n";
    
     cout<<"DeleteFirst   : \n";
    SCdobj->DeleteFirst();
    SCdobj->Display();
    iRet = SCdobj->Count();

       cout<<"DeleteLast   : \n";
    SCdobj->DeleteLast();

    SCdobj->Display();
    iRet = SCdobj->Count();

       cout<<"Delete At Pos   :\n";
    SCdobj->DeleteAtPos(5);

    SCdobj->Display();
    iRet = SCdobj->Count();

      cout << "Number of elements are:  " << iRet << "\n" ;

                // SinglyCl of Character
     cout<<"-------------- Singly Circular Linkedlist of Character --------------\n";

     SinglyCL<char> *SCcobj = new SinglyCL<char>() ;

    cout <<"InsertFirst   :\n";
    SCcobj->InsertFirst('A');
    SCcobj->InsertFirst('B');
    SCcobj->InsertFirst('V');
    SCcobj->InsertFirst('N');

    SCcobj->Display();
    iRet = SCcobj->Count();

    cout <<"Number of elements are: " << iRet << " \n";

     cout <<"InsertLast   :\n";
    SCcobj->InsertLast('U');
    SCcobj->InsertLast('P');
    SCcobj->InsertLast('O');
    SCcobj->InsertLast('I');

     SCcobj->Display();
     iRet = SCcobj->Count();
    cout << "Number of elements are:" << iRet <<" \n ";

    cout <<"Innsert At Pos   :\n";
    SCcobj->InsertAtPos('S', 5);

     SCcobj->Display();
    iRet = SCcobj->Count();

    cout << "Number of elements are:  " << iRet <<"\n";
    
     cout<<"DeleteFirst   : \n";
    SCcobj->DeleteFirst();
    SCcobj->Display();
    iRet = SCcobj->Count();

       cout<<"DeleteLast   : \n";
    SCcobj->DeleteLast();

    SCcobj->Display();
    iRet = SCcobj->Count();

       cout<<"Delete At Pos   :\n";
    SCcobj->DeleteAtPos(5);

    SCcobj->Display();
    iRet = SCcobj->Count();

      cout << "Number of elements are:  " << iRet << "\n" ;

       // DoubleLL of Integer

       cout<<"--------------Implementaion Doubly Liner Linkedlist --------------\n";

    cout<<"-------------- Doubly linear LinkdList of Integers --------------\n";
    int iret = 0;
    DoublyLL<int> *Dliobj = new DoublyLL<int>();
    cout<<"\nInsert First ";
    Dliobj->InsertFirst(101);
    Dliobj->InsertFirst(51);
    Dliobj->InsertFirst(21);
    Dliobj->InsertFirst(11);

     Dliobj->Display();
    iret = Dliobj->Count();

    cout << "number of elements in linklist is : " << iret;

    cout<<"\nInsert Last ";
    Dliobj->InsertLast(111);
    Dliobj->InsertLast(121);
    Dliobj->InsertLast(151);
    Dliobj->InsertLast(201);

     Dliobj->Display();
    iret = Dliobj->Count();

    cout << "number of elements in linklist is : " << iret;

    cout<<"\nInsert At Pos ";
    Dliobj->InsertAtPos(105, 5);

     Dliobj->Display();
    iret = Dliobj->Count();

    cout << "number of elements in linklist is : " << iret;

    cout<<"\nDelete First ";
    Dliobj->DeleteFirst();

     Dliobj->Display();
    iret = Dliobj->Count();

    cout << "number of elements in linklist is : " << iret;

    cout<<"\nDelete last ";
    Dliobj->DeleteLast();

     Dliobj->Display();
    iret = Dliobj->Count();

    cout << "number of elements in linklist is : " << iret;

    cout<<"\nDelete At Pos ";
    Dliobj->DeleteAtPos(5);

    Dliobj->Display();
    iret = Dliobj->Count();

    cout << "number of elements in linklist is : " << iret;

    // DoublyLL of Float
        cout<<"\n-------------- Doubly linear LinkdList of Float --------------\n";
// int iret = 0;
    DoublyLL<float> *Dlfobj = new DoublyLL<float>();
    cout<<"\nInsert First ";
    Dlfobj->InsertFirst(101.34f);
    Dlfobj->InsertFirst(51.3f);
    Dlfobj->InsertFirst(21.93f);
    Dlfobj->InsertFirst(11.09f);

     Dlfobj->Display();
    iret = Dlfobj->Count();

    cout << "number of elements in linklist is : " << iret;

    cout<<"\nInsert Last ";
    Dlfobj->InsertLast(111.12f);
    Dlfobj->InsertLast(121.65f);
    Dlfobj->InsertLast(151.983f);
    Dlfobj->InsertLast(201.23f);

     Dlfobj->Display();
    iret = Dlfobj->Count();

    cout << "number of elements in linklist is : " << iret;

    cout<<"\nInsert At Pos ";
    Dlfobj->InsertAtPos(105.098f, 5);

     Dlfobj->Display();
    iret = Dlfobj->Count();

    cout << "number of elements in linklist is : " << iret;

    cout<<"\nDelete First ";
    Dlfobj->DeleteFirst();

     Dlfobj->Display();
    iret = Dlfobj->Count();

    cout << "number of elements in linklist is : " << iret;

    cout<<"\nDelete last ";
    Dlfobj->DeleteLast();

     Dlfobj->Display();
    iret = Dlfobj->Count();

    cout << "number of elements in linklist is : " << iret;

    cout<<"\nDelete At Pos ";
    Dlfobj->DeleteAtPos(5);

    Dlfobj->Display();
    iret = Dlfobj->Count();

    cout << "number of elements in linklist is : " << iret;

      // DoublyLL of Double
        cout<<"\n-------------- Doubly linear LinkdList of Double --------------\n";
  DoublyLL<double> *Dldobj = new DoublyLL<double>();
    cout<<"\nInsert First ";
    Dldobj->InsertFirst(101.342);
    Dldobj->InsertFirst(51.3976);
    Dldobj->InsertFirst(21.9356);
    Dldobj->InsertFirst(11.093679);

     Dldobj->Display();
    iret = Dldobj->Count();

    cout << "number of elements in linklist is : " << iret;

    cout<<"\nInsert Last ";
    Dldobj->InsertLast(111.129);
    Dldobj->InsertLast(121.65238);
    Dldobj->InsertLast(151.9839);
    Dldobj->InsertLast(201.23239098);

     Dldobj->Display();
    iret = Dldobj->Count();

    cout << "number of elements in linklist is : " << iret;

    cout<<"\nInsert At Pos ";
    Dldobj->InsertAtPos(105.098239, 5);

     Dldobj->Display();
    iret = Dldobj->Count();

    cout << "number of elements in linklist is : " << iret;

    cout<<"\nDelete First ";
    Dldobj->DeleteFirst();

     Dldobj->Display();
    iret = Dldobj->Count();

    cout << "number of elements in linklist is : " << iret;

    cout<<"\nDelete last ";
    Dldobj->DeleteLast();

     Dldobj->Display();
    iret = Dldobj->Count();

    cout << "number of elements in linklist is : " << iret;

    cout<<"\nDelete At Pos ";
    Dldobj->DeleteAtPos(5);

    Dldobj->Display();
    iret = Dldobj->Count();

    cout << "number of elements in linklist is : " << iret;

 // DoublyLL of char
        cout<<"\n-------------- Doubly linear LinkdList of Character --------------\n";

          DoublyLL<char> *Dlcobj = new DoublyLL<char>();
    cout<<"\nInsert First ";
    Dlcobj->InsertFirst('A');
    Dlcobj->InsertFirst('M');
    Dlcobj->InsertFirst('U');
    Dlcobj->InsertFirst('P');

     Dlcobj->Display();
    iret = Dlcobj->Count();

    cout << "number of elements in linklist is : " << iret;

    cout<<"\nInsert Last ";
    Dlcobj->InsertLast('B');
    Dlcobj->InsertLast('R');
    Dlcobj->InsertLast('U');
    Dlcobj->InsertLast('D');

     Dlcobj->Display();
    iret = Dlcobj->Count();

    cout << "number of elements in linklist is : " << iret;

    cout<<"\nInsert At Pos ";
    Dlcobj->InsertAtPos('Y', 5);

     Dlcobj->Display();
    iret = Dlcobj->Count();

    cout << "number of elements in linklist is : " << iret;

    cout<<"\nDelete First ";
    Dlcobj->DeleteFirst();

     Dlcobj->Display();
    iret = Dlcobj->Count();

    cout << "number of elements in linklist is : " << iret;

    cout<<"\nDelete last ";
    Dlcobj->DeleteLast();

     Dlcobj->Display();
    iret = Dlcobj->Count();

    cout << "number of elements in linklist is : " << iret;

    cout<<"\nDelete At Pos ";
    Dlcobj->DeleteAtPos(5);

    Dlcobj->Display();
    iret = Dlcobj->Count();

    cout << "number of elements in linklist is : " << iret;

// DoublyCL LinkdList
       cout<<"\n--------------Implementaion DoublyCircular Linkedlist --------------\n";

    cout<<"-------------- DoublyCircular LinkdList of Integers --------------\n";

DoublyCL<int> *dciobj = new DoublyCL<int>();
    // int iRet = 0;
      dciobj->InsertFirst(51);
    dciobj->InsertFirst(21);
    dciobj->InsertFirst(11);

    dciobj->Display();
    iRet = dciobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dciobj->InsertLast(101);
    dciobj->InsertLast(111);
    dciobj->InsertLast(121);
    
    dciobj->Display();
    iRet = dciobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dciobj->InsertAtPos(105,5);

    dciobj->Display();
    iRet = dciobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dciobj->DeleteAtPos(5);
    dciobj->Display();
    iRet = dciobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    // DoublyCL of character
    cout<<"-------------- DoublyCircular LinkdList of Chracters --------------\n";
  DoublyCL<char> *dccobj = new DoublyCL<char>();

    dccobj->InsertFirst('D');
    dccobj->InsertFirst('F');
    dccobj->InsertFirst('R');

    dccobj->Display();
    iRet = dccobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dccobj->InsertLast('E');
    dccobj->InsertLast('Y');
    dccobj->InsertLast('U');
    
    dccobj->Display();
    iRet = dccobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dccobj->InsertAtPos('W',5);

    dccobj->Display();
    iRet = dccobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dccobj->DeleteAtPos(5);
    dccobj->Display();
    iRet = dccobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

      // DoublyCL of float
    cout<<"-------------- DoublyCL LinkdList of Floats --------------\n";
    DoublyCL<float> *dcfobj = new DoublyCL<float>();

    dcfobj->InsertFirst(90.78f);
    dcfobj->InsertFirst(78.99f);
    dcfobj->InsertFirst(67.99f);

    dcfobj->Display();
    iRet = dcfobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dcfobj->InsertLast(45.67f);
    dcfobj->InsertLast(54.78f);
    dcfobj->InsertLast(77.89f);
    
    dcfobj->Display();
    iRet = dcfobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dcfobj->InsertAtPos(88.56,5);

    dcfobj->Display();
    iRet = dcfobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dcfobj->DeleteAtPos(5);
    dcfobj->Display();
    iRet = dcfobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    // DoublyCL of double
    cout<<"-------------- DoublyCL LinkdList of Double --------------\n";
      DoublyCL <double> *dcdobj = new DoublyCL <double>();

    dcdobj->InsertFirst(90.78978);
    dcdobj->InsertFirst(78.99645);
    dcdobj->InsertFirst(67.9934);

    dcdobj->Display();
    iRet = dcdobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dcdobj->InsertLast(45.67867);
    dcdobj->InsertLast(54.78534);
    dcdobj->InsertLast(77.89324);
    
    dcdobj->Display();
    iRet = dcdobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dcdobj->InsertAtPos(88.56987,5);

    dcdobj->Display();
    iRet = dcdobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dcdobj->DeleteAtPos(5);
    dcdobj->Display();
    iRet = dcdobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

       cout<<"----------- Implementaion of Queue -----------\n";
       // Queue of integer
    cout<<"-------------- Queue of Integers --------------\n";
    Queue<int> *qiobj = new Queue<int>();
               int iNo;
                qiobj->EnQueue(11);
                 qiobj->EnQueue(21);
                  qiobj->EnQueue(51);
                  qiobj->EnQueue(101);

                   qiobj->Display();
                   iNo = qiobj->Count();
                cout<<"Number of elements in Queue are : "<<iNo<<"\n";

                iNo = qiobj->DeQueue();
                if(iNo != -1)
                {
                    cout<<"Removed element from Queue is : "<<iNo<<"\n";
                }
         
                qiobj->Display();
        
                iNo = qiobj->Count();
                cout<<"Number of elements in Queue are : "<<iNo<<"\n";

                       // Queue of Folat
    cout<<"-------------- Queue of Float --------------\n";
           
   Queue<float> *qfobj = new Queue<float>();
            //    int iNo;
               float ret = 0.0f;
                qfobj->EnQueue(11.2f);
                 qfobj->EnQueue(21.58f);
                  qfobj->EnQueue(51.67f);
                  qfobj->EnQueue(101.3f);

                   qfobj->Display();
                   iNo = qfobj->Count();
                cout<<"Number of elements in Queue are : "<<iNo<<"\n";

                ret = qfobj->DeQueue();
                if(ret != -1)
                {
                    cout<<"Removed element from Queue is : "<<ret<<"\n";
                }
         
                qfobj->Display();
        
                iNo = qfobj->Count();
                cout<<"Number of elements in Queue are : "<<iNo<<"\n";

                                      // Queue of Double
    cout<<"-------------- Queue of Double --------------\n";

      Queue<double> *qdobj = new Queue<double>();
            //    int iNo;
               double dret = 0.00000;
                qdobj->EnQueue(11.5412);
                 qdobj->EnQueue(21.58225);
                  qdobj->EnQueue(51.6754);
                  qdobj->EnQueue(101.39741);

                   qdobj->Display();
                   iNo = qdobj->Count();
                cout<<"Number of elements in Queue are : "<<iNo<<"\n";

                dret = qdobj->DeQueue();
                if(ret != -1)
                {
                    cout<<"Removed element from Queue is : "<<dret<<"\n";
                }
         
                qdobj->Display();
        
                iNo = qdobj->Count();
                cout<<"Number of elements in Queue are : "<<iNo<<"\n";

                                      // Queue of Character
    cout<<"-------------- Queue of Character --------------\n";

      Queue<char> *cdobj = new Queue<char>();
            //    int iNo;
               char cret = '\0';
                cdobj->EnQueue('A');
                 cdobj->EnQueue('E');
                  cdobj->EnQueue('I');
                  cdobj->EnQueue('O');

                   cdobj->Display();
                   iNo = cdobj->Count();
                cout<<"Number of elements in Queue are : "<<iNo<<"\n";

                cret = cdobj->DeQueue();
                if(ret != -1)
                {
                    cout<<"Removed element from Queue is : "<<cret<<"\n";
                }
         
                cdobj->Display();
        
                iNo = cdobj->Count();
                cout<<"Number of elements in Queue are : "<<iNo<<"\n";

                    cout<<"----------- Implementaion of Stack -----------\n";
   // stack of integer
       cout<<"-------------- stack of Integers --------------\n";

    Stack<int> *siobj = new Stack<int>();  

    // int iRet = 0;

    siobj->Push(10);
    siobj->Push(20);
    siobj->Push(30);
    siobj->Push(40);

    siobj->Display();

    iRet = siobj->Count();
    cout << "Number of elements in stack: " << iRet << "\n";

    iRet = siobj->Pop();
    cout << "Popped element is: " << iRet << "\n";

    siobj->Display();

     // stack of Float
       cout<<"-------------- stack of Float --------------\n";

  Stack<float> *sfobj = new Stack<float>();  

    float fRet = 0.0f;

    sfobj->Push(10.53f);
    sfobj->Push(20.563f);
    sfobj->Push(30.35f);
    sfobj->Push(40.963f);

    sfobj->Display();

    iRet = sfobj->Count();
    cout << "Number of elements in stack: " << iRet << "\n";

    fRet = sfobj->Pop();
    cout << "Popped element is: " << fRet << "\n";

    sfobj->Display();

    // stack of Double
       cout<<"-------------- stack of Double --------------\n";
 Stack<double> *sdobj = new Stack<double>();  

    double dRet = 0.0;

    sdobj->Push(10.53543);
    sdobj->Push(20.56343);
    sdobj->Push(30.35543);
    sdobj->Push(40.96356);

    sdobj->Display();

    iRet = sdobj->Count();
    cout << "Number of elements in stack: " << iRet << "\n";

    dRet = sdobj->Pop();
    cout << "Popped element is: " << dRet << "\n";

    sdobj->Display();

       // stack of Character
       cout<<"-------------- stack of Characters --------------\n";
        Stack<char> *scobj = new Stack<char>();  

    char cRet = '\0';

    scobj->Push('A');
    scobj->Push('V');
    scobj->Push('G');
    scobj->Push('R');

    scobj->Display();

    iRet = scobj->Count();
    cout << "Number of elements in stack: " << iRet << "\n";

    cRet = scobj->Pop();
    cout << "Popped element is: " << cRet << "\n";

    scobj->Display();

                cout<<"-------Thank you for using our application-------\n";

    return 0;
}