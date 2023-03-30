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
class DoublyLL
{
    public:
    struct node<T> *Head;
    int Count;

    DoublyLL();
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
DoublyLL<T>::DoublyLL()
{
    Head=NULL;
    Count=0;
}

template<class T>
void DoublyLL<T>::InsertFirst(T no)
{
    struct node<T> *newn=NULL;
    newn= new node<T>;

    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if(Head==NULL)
    {
        Head=newn;
    }
    else
    {
        Head->prev=newn;
        newn->next=Head;
        Head=newn;
    }
    Count++;
}

template<class T>
void DoublyLL<T>::InsertLast(T no)
{
    struct node<T> *newn=NULL;
    newn= new node<T>;

    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if(Head==NULL)
    {
        Head=newn;
    }
    else
    {
        struct node<T> *temp=Head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
        newn->prev=temp;
    }
    Count++;
}

template<class T>
void DoublyLL<T>::InsertAtPos(T no,int pos)
{
    if((Head==NULL)||(pos>Count+1)||(pos<=0))
    {
        return;
    }
    if(pos==1)
    {
        InsertFirst(no);
    }
    else if(pos==Count+1)
    {
        InsertLast(no);
    }
    else
    {
        struct node<T> *newn=NULL;
        newn= new node<T>;

        newn->data=no;
        newn->next=NULL;
        newn->prev=NULL;

        struct node<T> *temp=Head;
        for(int i=1;i<=(pos-2);i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;
        newn->prev=temp;
        temp->next=newn;
        Count++;
    }
    
}

template<class T>
void DoublyLL<T>::DeleteFirst()
{
    struct node<T> *temp=Head;
    if(Head==NULL)
    {
        return;
    }
    else
    {
        Head=Head->next;
        Head->prev=NULL;

        delete temp;
        Count--;
    }
}

template<class T>
void DoublyLL<T>::DeleteLast()
{
    struct node<T> *temp=Head;
    if(Head==NULL)
    {
        return;
    }
    else if(Head->next==NULL)
    {
        delete Head;
        Head=NULL;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->prev->next=NULL;
        delete temp;
        Count--;
    }
}

template<class T>
void DoublyLL<T>::DeleteAtPos(int pos)
{
    if((Head==NULL)||(pos>Count+1)||(pos<=0))
    {
        return;
    }
    else if(pos==1)
    {
        DeleteFirst();
    }
    else if(pos==Count)
    {
        DeleteLast();
    }
    else
    {
        struct node<T> *temp=Head;

        for(int i=1;i<=(pos-2);i++)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;
        delete temp->next->prev;
        temp->next->prev=temp;
        Count--;
    }

}

template<class T>
void DoublyLL<T>::Display()
{
    struct node<T> *temp=Head;

    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL\n"<<endl;
}

template<class T>
int DoublyLL<T>::CountNode()
{
    return Count;
}

int main()
{
    DoublyLL<int>obj;

    obj.InsertFirst(11);
    obj.InsertFirst(21);
    obj.InsertFirst(51);
    obj.InsertFirst(101);

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