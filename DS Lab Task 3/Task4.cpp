#include <iostream>
#include <string>
using namespace std;

struct node{
    int data;
    node* next;
};

int main(){
    int n;
    cout<<"enter number of people: "<<endl;
    cin>>n;
    int k;
    cout<<"enter elimination interval k: "<<endl;
    cin>>k;

    node* head=nullptr;
    node* tail=nullptr;

    for(int i=0;i<n;i++){
        node* newnode=new node;
        newnode->data=i+1;
        newnode->next=nullptr;
        if(head==nullptr){
            head=newnode;
            tail=newnode;
            tail->next=head;
        }
        else{
            tail->next=newnode;
            tail=newnode;
            tail->next=head;
        }
    }


    node* current=head;
    int count=n;

    while(count>1){
        for(int i=1;i<k-1;i++){
            current=current->next;
        }
        node* temp=current->next;
        current->next=temp->next;
        if(temp==head){
            head=temp->next;
        }
        if(temp==tail){
            tail=current;
        }
        delete temp;
        current=current->next;
        count--;
    }

    cout<<"========================================\n";
    cout<<"Survivor position is "<<current->data<<endl;
    cout<<"========================================\n";

    while(head!=nullptr){
        node* temp=head;
        head=head->next;
        if(head==temp){
            head=nullptr;
        }
        delete temp;
    }
}