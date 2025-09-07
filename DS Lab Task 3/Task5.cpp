#include <iostream>
using namespace std;

struct singly_node {
    int data;
    singly_node* next;
};

struct doubly_node {
    int data;
    doubly_node* prev;
    doubly_node* next;
};

doubly_node* convert_to_doubly(singly_node* shead) {
    if (shead == nullptr) {
        return nullptr;
    }
    doubly_node* dhead = new doubly_node;
    dhead->data = shead->data;
    dhead->prev = nullptr;
    dhead->next = nullptr;
    doubly_node* current = dhead;
    singly_node* scurrent = shead->next;
    while (scurrent != nullptr) {
        doubly_node* newnode = new doubly_node;
        newnode->data = scurrent->data;
        newnode->prev = current;
        newnode->next = nullptr;
        current->next = newnode;
        current = newnode;
        scurrent = scurrent->next;
    }
    return dhead;
}

singly_node* convert_to_circular(singly_node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    singly_node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    tail->next = head;
    return head;
}

int main() {
    int n;
    cout << "enter number of elements for list: " << endl;
    cin >> n;
    singly_node* shead = nullptr;
    singly_node* stail = nullptr;
    cout << "enter the elements: " << endl;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        singly_node* newnode = new singly_node;
        newnode->data = val;
        newnode->next = nullptr;
        if (shead == nullptr) {
            shead = newnode;
            stail = newnode;
        }
        else {
            stail->next = newnode;
            stail = newnode;
        }
    }
    cout << "original list: ";
    singly_node* temp = shead;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    doubly_node* dhead = convert_to_doubly(shead);
    cout << "doubly list forward: ";
    doubly_node* dtemp = dhead;
    while (dtemp != nullptr) {
        cout << dtemp->data << " ";
        dtemp = dtemp->next;
    }
    cout << endl;

    cout << "doubly list backward: ";
    dtemp = dhead;
    while (dtemp->next != nullptr) {
        dtemp = dtemp->next;
    }
    while (dtemp != nullptr) {
        cout << dtemp->data << " ";
        dtemp = dtemp->prev;
    }
    cout << endl;

    while (shead != nullptr) {
        singly_node* temp = shead;
        shead = shead->next;
        delete temp;
    }
    while (dhead != nullptr) {
        doubly_node* temp = dhead;
        dhead = dhead->next;
        delete temp;
    }

    cout << "enter number of elements for circular list: " << endl;
    cin >> n;
    shead = nullptr;
    stail = nullptr;
    cout << "enter the elements: " << endl;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        singly_node* newnode = new singly_node;
        newnode->data = val;
        newnode->next = nullptr;
        if (shead == nullptr) {
            shead = newnode;
            stail = newnode;
        }
        else {
            stail->next = newnode;
            stail = newnode;
        }
    }
    cout << "original list: ";
    temp = shead;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    shead = convert_to_circular(shead);
    cout << "circular list printing some to show cycle: ";
    temp = shead;
    int count = 0;
    while (temp != nullptr && count < n + 2) {
        cout << temp->data << " ";
        temp = temp->next;
        count++;
    }
    cout << endl;

    stail->next = nullptr;
    while (shead != nullptr) {
        singly_node* temp = shead;
        shead = shead->next;
        delete temp;
    }
    return 0;
}
