#include<iostream>
#include<string.h>
using namespace std;
struct node{
    long int value;
    node*next;
}*Hashtable[10];

class hashing
{
    public:
    hashing()
    {
        for(int i=0;i<10;i++)
        {
            Hashtable[i]=NULL;
        }
    }

    int hashfunction(long int value)
    {
        return(value%10);
    }
    node*creat_node(double x)
    {
        node*temp=new node;
        temp->next=NULL;
        temp->value=x;
        return temp;
    }

    void display()
    {
        for(int i=0;i<10;i++)
        {
            node*temp=new node;
            temp=Hashtable[i];
            cout<<"a["<<i<<"] : ";
            while(temp!=NULL)
            {
                cout<<"->"<<temp->value;
                temp=temp->next;
            }
            cout<<"\n";
        }
    }

    int search(double value)
    {
        bool flag;
        int hash_val=hashfunction(value);
        node*entry=Hashtable[hash_val];
        cout<<"\n phone no. found at : ";
        while(entry!=NULL)
        {
            if(entry->value==value){
            cout<<hash_val<<" : "<<entry->value<<endl;
            flag=true;
            }
            entry=entry->next;
        }

        if (!flag)
            return -1;
    }

    void del(double value)
    {
        int hash_val=hashfunction(value);
        node*entry=Hashtable[hash_val];
        if(entry==NULL)
        {
            cout<<"phone no. not found";
            return;
        }
        if(entry->value==value)
        {
            Hashtable[hash_val]=entry->next;
            return;
        }
        while((entry->next)->value!=value)
        {
            entry=entry->next;
        }
        entry->next=(entry->next)->next;

    }

    void insert(long int value)
    {
        int hash_val=hashfunction(value);
        node*temp=new node;
        node*head=new node;
        head=creat_node(value);
        temp=Hashtable[hash_val];
        if (temp==NULL)
        {
            Hashtable[hash_val]=head;
        }
        else{
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=head;
        }


    }


};

int main()
{
    int ch;
    double data,searching,dele;
    hashing h;
    do
    {
        cout<<"\ttelephone Book\n1. Insert\n2. display\n3. search\n4. delete\n5. Exit\n\nENTER YOUR CHOICE : ";
        cin>>ch;
        switch(ch)
        {
            case 1:cout<<"Enter ph. no. to be Insert : ";
                    cin>>data;
                    h.insert(data);
                    break;

            case 2:h.display();
                    break;

            case 3:cout<<"Enter ph. no. to be Search : ";
                    cin>>searching;
                    if(h.search(searching)==-1)
                    {
                        cout<<"Phone no. not found"<<endl;
                        continue;
                    }
                    break;

            case 4:cout<<"Enter ph. no. want delete : " ;
                    cin>>dele;
                    h.del(dele);
                    cout<<"Phone no. deleted"<<endl;
                    break;
        }

    }
    while(ch!=5);
        return 0;
}
