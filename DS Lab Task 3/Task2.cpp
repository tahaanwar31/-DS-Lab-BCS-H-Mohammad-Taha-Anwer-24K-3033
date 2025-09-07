#include <iostream>
#include <string>
using namespace std;

struct node{
    int data;
    node* next;
};

int main(){
    int size1;
    cout<<"enter the number of integers for list 1: "<<endl;
    cin>>size1;
    node* head1=nullptr;
    node* tail1=nullptr;

    for(int i=0;i<size1;i++){
        cout<<"enter integer"<<i+1<<" for list 1"<<endl;
        int value;
        cin>>value;
        node* newnode=new node;
        newnode->data=value;
        newnode->next=nullptr;
        if(head1==nullptr){
            head1=newnode;
            tail1=newnode;
        }
        else{
            tail1->next=newnode;
            tail1=newnode;
        }
    }

    int size2;
    cout<<"enter the number of integers for list 2: "<<endl;
    cin>>size2;
    node* head2=nullptr;
    node* tail2=nullptr;

    for(int i=0;i<size2;i++){
         cout<<"enter integer"<<i+1<<" for list 2"<<endl;
        int value;
        cin>>value;
        node* newnode=new node;
        newnode->data=value;
        newnode->next=nullptr;
        if(head2==nullptr){
            head2=newnode;
            tail2=newnode;
        }
        else{
            tail2->next=newnode;
            tail2=newnode;
        }
    }

    cout<<"================\n";
    cout<<"MERGED LISTS\n";
    cout<<"================\n";
    node* current1=head1;
    node* current2=head2;
    node* prev=nullptr;

    while(current1!=nullptr && current2!=nullptr){
        if(current1->data<=current2->data){
            if(prev==nullptr){
                head1=current1;
                prev=current1;
                current1=current1->next;
            }
            else{
                prev->next=current1;
                prev=current1;
                current1=current1->next;
            }
        }
        else{
            if(prev==nullptr){
                head1=current2;
                prev=current2;
                current2=current2->next;
            }
            else{
                prev->next=current2;
                prev=current2;
                current2=current2->next;
            }
        }
    }

    if(current1!=nullptr){
        prev->next=current1;
    }
    if(current2!=nullptr){
        prev->next=current2;
    }

    node* current=head1;
    while(current!=nullptr){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<endl;

    while(head1!=nullptr){
        node* temp=head1;
        head1=head1->next;
        delete temp;
    }
    while(head2!=nullptr){
        node* temp=head2;
        head2=head2->next;
        delete temp;
    }
}