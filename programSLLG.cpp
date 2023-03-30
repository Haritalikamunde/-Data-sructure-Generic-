#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
};

template<class T>
class SinglyLL
{
    public:
    struct node<T> *Head;
    int Count;

    SinglyLL();
    void Insertfirst(T);
    void InsertLast(T);
    void Display();
    int CountNode();
    void InsertAtPosition(T,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPosition(int);
};

template<class T>
SinglyLL<T>::SinglyLL()
{
    Head=NULL;
    Count=0;
}

template<class T>
void SinglyLL<T>::Insertfirst(T no)
{
    struct node<T> *newn=NULL;
    newn = new node<T>;

    newn->data=no;
    newn->next=NULL;

    if(Head==NULL)
    {
        Head=newn;
    }
    else
    {
        newn->next=Head;
        Head=newn;
    }
    Count++;

}

template<class T>
void SinglyLL<T> ::InsertLast(T no)
{
    struct node<T> *newn=NULL;
    newn = new node<T>;

    newn->data=no;
    newn->next=NULL;

    if(Head==NULL)
    {
        Head=newn;
    }
    else
    {
        struct node<T> *temp=Head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }

        temp->next=newn;
        
    }
    Count++;

}

template<class T>
void SinglyLL<T>::Display()
{
    cout<<"Elements from linked list are:"<<endl;
    struct node<T>*temp=Head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

template<class T>
void SinglyLL<T>::InsertAtPosition(T no, int pos)
{
    struct node<T> *newn=NULL;
    newn = new node<T>;

    newn->data=no;
    newn->next=NULL;

    if((pos < 1) || (pos > Count+1))
    {
        return;
    }
    if(pos==1)
    {
        Insertfirst(no);
    }
    else if(pos==(Count+1))
    {
        InsertLast(no);
    }
    else
    {
        struct node<T> *newn=NULL;
        newn = new node<T>;

        newn->data=no;
        newn->next=NULL;

        struct node<T> *temp=Head;

        for(int i=1; i<=(pos-2);i++)
        {
            temp=temp->next;
        }

        newn->next=temp->next;
        temp->next=newn;
    }
    Count++;
}

template<class T>
void SinglyLL<T>::DeleteFirst()
{
    struct node<T> *temp=Head;

    if(Head==NULL)
    {
        return ;
    }
    else
    {
        Head=Head->next;
        free(temp);
    }
    Count--;
}

template<class T>
void SinglyLL<T>::DeleteLast()
{
    struct node<T> *temp=Head;

    if(Head==NULL)
    {
        return ;
    }
    else if(Head->next==NULL)
    {
        delete Head;
        Head =NULL;
    }
    else
    {
        struct node<T> *temp1=Head;
        struct node<T> *temp2=NULL;

        while(temp1->next->next!=NULL)
        {
            temp1=temp1->next;
        }

        temp2=temp1->next;
        temp1->next=NULL;
        free(temp2);
    }
    Count--;
}

template<class T>
void SinglyLL<T>::DeleteAtPosition(int pos)
{

    if((Head==NULL)||(pos>Count)||(pos<=0))
    {
        return ;
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
        struct node<T> *temp1=Head;
        struct node<T> *temp2=NULL;

        for(int i=1;i<=(pos-2);i++)
        {
            temp1=temp1->next;
            ++i;
        }
        temp2=temp1->next;
        temp1->next=temp2->next;

        delete temp2;
    }
    Count--;
}

template<class T>
int SinglyLL<T>::CountNode()
{
    return Count;
}

int main()
{
    SinglyLL<int>obj1;
    SinglyLL<float>obj2;
    SinglyLL<char>obj3;

    obj1.Insertfirst(21);
    obj1.Insertfirst(11);
    obj1.Insertfirst(51);
    obj1.Insertfirst(101);
    obj1.Display();
    cout<<"NUmber of nodes are :"<<obj1.CountNode()<<endl;

    obj1.InsertLast(121);
    obj1.InsertLast(111);
    obj1.InsertLast(101);
    obj1.InsertLast(151);
    obj1.Display();
    cout<<"NUmber of nodes are :"<<obj1.CountNode()<<endl;
    

    obj1.InsertAtPosition(75,3);
    obj1.Display();
    cout<<"NUmber of nodes are :"<<obj1.CountNode()<<endl;

    obj1.DeleteFirst();
    obj1.Display();
    cout<<"NUmber of nodes are :"<<obj1.CountNode()<<endl;

    obj1.DeleteLast();
    obj1.Display();
    cout<<"NUmber of nodes are :"<<obj1.CountNode()<<endl;

    obj1.DeleteAtPosition(2);
    obj1.Display();

    cout<<"NUmber of nodes are :"<<obj1.CountNode()<<endl;

    
    return 0;
}