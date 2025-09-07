#include <iostream>
#include <string>
using namespace std;

struct node{
    int data;
    node* next;
};

node* reversegroup(node* head,int k){
    node* current=head;
    node* prev=nullptr;
    node* next=nullptr;
    int count=0;

    while(current!=nullptr && count<k){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        count++;
    }

    if(next!=nullptr){
        head->next=reversegroup(next,k);
    }

    return prev;
}

int main(){
    int size;
    cout<<"enter the number of integers: "<<endl;
    cin>>size;
    node* head=nullptr;
    node* tail=nullptr;

    for(int i=0;i<size;i++){
        cout<<"enter integer:"<<i+1<<endl;
        int value;
        cin>>value;
        node* newnode=new node;
        newnode->data=value;
        newnode->next=nullptr;
        if(head==nullptr){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }

    int k;
    cout<<"enter group size k: "<<endl;
    cin>>k;



    head=reversegroup(head,k);

    node* current=head;
    while(current!=nullptr){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<endl;

   

    while(head!=nullptr){
        node* temp=head;
        head=head->next;
        delete temp;
    }
}