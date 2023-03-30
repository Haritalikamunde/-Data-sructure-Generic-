#include<iostream>
using namespace std;

template<class T>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

template<class T>
class DoublyCLL
{
    public:

    struct node<T> *Head;
    struct node<T> *Tail;
    int Count;

    DoublyCLL();
    void InsertFirst(T);
    void InsertLast(T);
    void Display();
    int CountNode();
    void InsertAtPos(T,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template<class T>
DoublyCLL<T>::DoublyCLL()
{
    Head=NULL;
    Tail=NULL;
    Count=0;
}

template<class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    struct node<T> *newn=NULL;
    newn=new node<T>;

    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if((Head==NULL)&&(Tail==NULL))
    {
        Head=newn;
        Tail=newn;
    }
    else
    {
        newn->next=Head;
        Head->prev=newn;
        Head=newn;
    }

    Head->prev = Tail;
    Tail->next = Head;

    Count++;
}

template<class T>
void DoublyCLL<T>::InsertLast(T no)
{
    struct node<T> *newn=NULL;
    newn=new node<T>;

    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if((Head==NULL)&&(Tail==NULL))
    {
        Head=newn;
        Tail=newn;
    }
    else
    {
        Tail->next = newn;
        newn->prev = Tail;

        Tail = newn;
    }

    Head->prev = Tail;
    Tail->next = Head;

    Count++;
}

template<class T>
void DoublyCLL<T>::InsertAtPos(T no,int pos)
{
if((pos < 1) || (pos > Count+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == Count+1)
    {
        InsertLast(no);
    }
    else
    {
        struct node<T> *newn=NULL;
        newn=new node<T>;

        newn->data=no;
        newn->next=NULL;
        newn->prev=NULL;

        struct node<T> *temp=Head;

        for(int i = 1; i<pos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        Count++;
    
    }
}

template<class T>
void DoublyCLL<T>::DeleteFirst()
{
    if(Count == 0)
    {
        return;
    }
    else if(Count== 1)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head->next;
        delete Tail->next;          
    }

    Tail->next = Head;
    Head->prev = Tail;
    Count--;
}

template<class T>
void DoublyCLL<T>::DeleteLast()
{
    if(Count == 0)
    {
        return;
    }
    else if(Count== 1)
    {
        delete Tail;
        Head = NULL;
        Tail = NULL;
    }
     else
    {
        Tail = Tail->prev;
        delete Tail->next;         
    }

    Tail->next = Head;
    Head->prev = Tail;
    Count--;
}

template<class T>
void DoublyCLL<T>::DeleteAtPos(int pos)
{
    if((pos < 1) || (pos > Count))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == Count)
    {
        DeleteLast();
    }
    else
    {
        struct node<T> *temp=Head;

        for(int i = 1; i<pos-1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        Count--;
    }
}

template<class T>
void DoublyCLL<T>::Display()
{
    struct node<T> *temp=Head;
   
    for(int i = 1; i<= Count; i++)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"\n";
}

template<class T>
int DoublyCLL<T>::CountNode()
{
    return Count;
}

int main()
{
    DoublyCLL<int>obj;

    obj.InsertFirst(11);
    obj.InsertFirst(21);
    obj.InsertFirst(51);
    obj.InsertFirst(101);
    obj.Display();
    cout<<"number of nodes are :"<<obj.CountNode()<<endl;

    obj.InsertLast(111);
    obj.InsertLast(121);
    obj.InsertLast(151);
    obj.InsertLast(161);
    obj.Display();
    cout<<"number of nodes are :"<<obj.CountNode()<<endl;

    obj.InsertAtPos(75,2);
    obj.InsertAtPos(71,1);
    obj.Display();
    cout<<"number of nodes are :"<<obj.CountNode()<<endl;

    obj.DeleteFirst();
    obj.DeleteLast();
    obj.Display();
    cout<<"number of nodes are :"<<obj.CountNode()<<endl;

    obj.DeleteAtPos(5);
    obj.Display();
    cout<<"number of nodes are :"<<obj.CountNode()<<endl;
}