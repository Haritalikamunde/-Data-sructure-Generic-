#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
};

template<class T>
class SinglyCL
{
    public:
    struct node<T> *Head;
    struct node<T> *Tail;
    int Count;

    SinglyCL();
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
SinglyCL<T>::SinglyCL()
{
    Head=NULL;
    Tail=NULL;
    Count=0;
}

template<class T>
void SinglyCL<T>::Insertfirst(T no)
{
    struct node<T> *newn=NULL;
    newn = new node<T>;

    newn->data=no;
    newn->next=NULL;

    if((Head == NULL) && (Tail == NULL))    
    {
        Head = newn;
        Tail = newn;
    }
    else       
    {
        newn -> next = Head;
        Head = newn;
    }
    Tail -> next = Head;
    Count++;
}

template<class T>
void SinglyCL<T> ::InsertLast(T no)
{
    struct node<T> *newn=NULL;
    newn = new node<T>;

    newn->data=no;
    newn->next=NULL;

    if((Head == NULL) && (Tail == NULL))   
    {
        Head = newn;
        Tail = newn;
    }
    else      
    {
        Tail -> next = newn;
        Tail = newn;
    }
    Tail -> next = Head;
    Count++;

}

template<class T>
void SinglyCL<T>::InsertAtPosition(T no, int pos)
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
        int iCnt = 0;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp -> next;
        temp->next = newn;
    }
    Count++;
}

template<class T>
void SinglyCL<T>::DeleteFirst()
{

    if(Head == NULL && Tail ==  NULL)      
    {
        return;
    }
    else if(Head == Tail)       
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else    
    {
        Head = Head -> next;
        delete Tail->next;

        Tail->next = Head;
    }
    Count--;
}

template<class T>
void SinglyCL<T>::DeleteLast()
{
    if(Head == NULL && Tail ==  NULL)       
    {
        return;
    }
    else if(Head == Tail)     
    {
        delete Tail;
        Head = NULL;
        Tail = NULL;
    }
    else   
    {
        struct node<T> *temp=Head;

        while(temp->next != Tail)
        {
            temp = temp->next;
        }

        delete Tail;
        Tail = temp;

        Tail->next = Head;
    }
    Count--;
}

template<class T>
void SinglyCL<T>::DeleteAtPosition(int pos)
{

    if((pos < 1) || (pos > Count))
    {
        return ;
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
        struct node<T> *temp2=NULL;
        int iCnt = 0;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp= temp->next;
        }

        temp2 = temp->next;

        temp->next = temp2->next;
        delete temp2;
    }
    Count--;
}


template<class T>
void SinglyCL<T>::Display()
{
    cout<<"Elements from linked list are:"<<endl;
    struct node<T>*temp=Head;

    if((Head == NULL) && (Tail == NULL))
    {
        return ;
    }

    do
    {
        cout<<temp->data<<" ";
        temp = temp -> next;
    }while(temp != Head);

    cout<<endl;
}

template<class T>
int SinglyCL<T>::CountNode()
{
    return Count;
}

int main()
{
    SinglyCL<int>obj1;

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