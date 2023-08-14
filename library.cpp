#include<iostream>
using namespace std;

#pragma pack(1)

struct node{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class SinglyLL{
    public:
    PNODE First;
    int iCount;


        SinglyLL();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPosition(int no ,int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int ipos);

        void Display();
};

class SinglyCL{
    public:
    PNODE first;
    PNODE last;
    int iCount;

    SinglyCL();
    void InsertFirst(int data);
    void InsertLast(int data);
    void InsertAtPos(int data,int ipos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos);
    void Display();
    
};

class DoublyLL
{
    public:
    PNODE First;
    
    int iCount;
    
        DoublyLL();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPosition(int no ,int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int ipos);

        void Display();

};

class Stack{
    public:
    PNODE first;
    int count;

    Stack();
    void Push(int data);
    void Pop();
    void StackDisplay();

};

class Queue{
    public:
    PNODE first;
    int icount=0;

    Queue();
    void Enqueue(int data);
    void Dequeue();
    void QueueDisplay();
};

SinglyLL :: SinglyLL()
{
    First = NULL;
    iCount = 0;
}

void SinglyLL :: InsertFirst(int no)
{
    // Step1 : Allocate memory for node
    PNODE newn = new NODE;

    // Step2 : Initialise node
    newn->data = no;
    newn->next =  NULL;

    // Step3 : Check if LL is empty or not
    if(First == NULL)   // if(iCount == 0)
    {
        First = newn;
        iCount++;
    }
    else    // If LL contains atleast one node
    {
        newn->next = First;
        First = newn;
        iCount++;
    }
}

void SinglyLL :: InsertLast(int no)
{
    // Step1 : Allocate memory for node
    PNODE newn = new NODE;

    // Step2 : Initialise node
    newn->data = no;
    newn->next =  NULL;

    // Step3 : Check if LL is empty or not
    if(First == NULL)   // if(iCount == 0)
    {
        First = newn;
        iCount++;
    }
    else    // If LL contains atleast one node
    {
        PNODE temp = First;

        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp->next = newn;
        iCount++;
    }
}

void SinglyLL :: InsertAtPosition(int no, int ipos)
{
    if((ipos < 1) || (ipos > iCount+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        PNODE newn = new NODE;

        newn->data = no;
        newn->next = NULL;

        PNODE temp = First;
        for(int iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

void SinglyLL :: DeleteFirst()
{
    if(First == NULL)   // if(iCount == 0)
    {
        return;
    }
    else if(First -> next == NULL) // else if(iCount == 1)
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        PNODE temp = First;
        First = First -> next;
        delete temp;
        iCount--;
    }
}

void SinglyLL :: DeleteLast()
{    
    if(First == NULL)   // if(iCount == 0)
    {
        return;
    }
    else if(First -> next == NULL) // else if(iCount == 1)
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        PNODE temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;

        iCount--;
    }
}

void SinglyLL :: DeleteAtPosition(int ipos)
{
    if((ipos < 1) || (ipos > iCount))
    {
        cout<<"Invalid position"<<"\n";
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

    }
}

void SinglyLL :: Display()
{
    cout<<"Elements of Linked List are : "<<"\n";
    PNODE temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}


Stack :: Stack(){
    first=NULL;
    count=0;
}

void Stack :: Push(int data){
    PNODE newn=(PNODE)malloc(sizeof(NODE));
    newn->data=data;
    newn->next=NULL;

    if((first)==NULL){
        first=newn;
    }else{
        newn->next=first;
        first=newn;
    }
}

void Stack :: Pop(){
    if((first->next) == NULL){
        delete first;
        first=NULL;
    }else{
        PNODE temp=first;
        first=first->next;
        delete temp;
    }
}

Queue :: Queue(){
    first=NULL;
    icount=0;
}

void Queue::Enqueue(int data){
    PNODE newn=new NODE;
    newn->data=data;
    newn->next=NULL;

    if(first==NULL){
        first=newn;
    }else{
        newn->next=first;
        first=newn;
    }
}

void Queue::Dequeue(){
    if(first==NULL){
        return;
    }else if ((first->next)==NULL)
    {
        free(first);
        first=NULL;
        /* code */
    }else{
        PNODE temp=first;

        while ((temp->next->next)!=NULL)
        {
            temp=temp->next;
            /* code */
        }

        delete temp->next;
        temp->next=NULL;
        
    }
    
}
void Queue::QueueDisplay(){
    PNODE temp=first;

    while (temp!=NULL)
    {
        cout<<temp->data<<"\n";
        temp=temp->next;

        /* code */
    }
    
}

SinglyCL::SinglyCL(){
    first=NULL;
    last=NULL;
    iCount=0;
}

void SinglyCL:: InsertFirst(int data){
    PNODE newn=(PNODE)malloc(sizeof(NODE));
    newn->data=data;
    newn->next=NULL;

    if((first)==NULL && (last)==NULL){
        (first)=(last)=newn;
    }else{
        (last)->next=newn;
        newn->next=(first);
        (first)=newn;
    }
    iCount++;
}

void SinglyCL::InsertLast(int data){

    PNODE newn=(PNODE)malloc(sizeof(NODE));
    newn->data=data;
    newn->next=NULL;

    if((first)==NULL && (last)==NULL){
        (first)=(last)=newn;
    }else{
        newn->next=(first);
        (last)->next=newn;
        (last)=newn;
    }
    iCount++;

}

void SinglyCL::InsertAtPos(int data,int ipos){
    PNODE newn=(PNODE)malloc(sizeof(NODE));
    newn->data=data;
    newn->next=NULL;

    if(ipos<0 || ipos>(iCount+1)){
        printf("invalid\n");
        return;
    }else if (ipos == 1)
    {
        InsertFirst(data);
        /* code */
    }else if (ipos==(iCount+1))
    {
        InsertLast(data);
        /* code */
    }else{
        PNODE temp=(first);

        for(int icnt=1;icnt<(ipos-1);icnt++){
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
        (last)->next=(first);
        
    }
}

void SinglyCL::DeleteFirst(){
    if((first)==NULL && (last)==NULL){
        return;
    }else if ((first)==(last))
    {
        free((first));
        (first)=NULL;
        (last)=NULL;
    }else{
        PNODE temp=(first);
        (first)=temp->next;
        (last)->next=(first);
        free(temp);
    }
}

void SinglyCL::DeleteLast(){
    if((first)==NULL && (last)==NULL){
        return;
    }else if ((first)==(last))
    {
        free((first));
        (first)=NULL;
        (last)=NULL;
    }else{
        PNODE temp=(last);
        while ((temp)->next!=(last))
        {
            temp=temp->next;
            /* code */
        }
        temp->next=(first);
        free(last);
        (last)=temp;
        (last)->next=(first);
    }
}

void SinglyCL::DeleteAtPos(int ipos){

    if(ipos<0 || ipos>(iCount+1)){
        printf("invalid\n");
        return;
    }else if (ipos == 1)
    {
        DeleteFirst();
        /* code */
    }else if (ipos==(iCount+1))
    {
        DeleteLast();
        /* code */
    }else{
        PNODE temp=(first);
        PNODE temp1=NULL;

        for(int icnt=1;icnt<(ipos-1);icnt++){
            temp=temp->next;
        }
        temp1=temp->next;
        temp->next=temp1->next;
        free(temp1);
        
    }
}

void SinglyCL::Display(){
    PNODE temp=first;
     do
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    } while ((temp) != last->next);
    
}

int main(){

    return 0;
}