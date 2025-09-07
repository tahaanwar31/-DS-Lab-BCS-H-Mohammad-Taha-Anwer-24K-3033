#include <iostream>
#include <string>
using namespace std;

struct node{
    int data;
    node* next;
};

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

    bool flag=false;
    node* slow=head;
    node* fast=head;
    node* prev=nullptr;
    node* temp=nullptr;

    while(fast!=nullptr && fast->next!=nullptr){
        fast=fast->next->next;
        temp=slow->next;
        slow->next=prev;
        prev=slow;
        slow=temp;
    }

    if(fast!=nullptr){
        slow=slow->next;
    }

    node* secondhalf=slow;
    node* firsthalf=prev;

    while(secondhalf!=nullptr){
        if(firsthalf->data!=secondhalf->data){
            flag=false;
            break;
        }
        flag=true;
        firsthalf=firsthalf->next;
        secondhalf=secondhalf->next;
    }

    cout<<"========================================\n";
    if(flag==true){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    cout<<"========================================\n";

    while(head!=nullptr){
        node* temp=head;
        head=head->next;
        delete temp;
    }
}