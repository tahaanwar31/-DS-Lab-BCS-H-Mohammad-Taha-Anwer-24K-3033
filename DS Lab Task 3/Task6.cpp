#include <iostream>
#include <stack>
using namespace std;

struct node {
    int data;
    node* next;
    node* child;
};

int main() {
    node* head = nullptr;
    node* tail = nullptr;
    int main_size = 3;
    int main_values[] = {1, 2, 3};

    for (int i = 0; i < main_size; i++) {
        node* newnode = new node;
        newnode->data = main_values[i];
        newnode->next = nullptr;
        newnode->child = nullptr;
        if (head == nullptr) {
            head = newnode;
            tail = newnode;
        }
        else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    node* child_head = nullptr;
    node* child_tail = nullptr;
    int child_size = 2;
    int child_values[] = {4, 5};

    for (int i = 0; i < child_size; i++) {
        node* newnode = new node;
        newnode->data = child_values[i];
        newnode->next = nullptr;
        newnode->child = nullptr;
        if (child_head == nullptr) {
            child_head = newnode;
            child_tail = newnode;
        }
        else {
            child_tail->next = newnode;
            child_tail = newnode;
        }
    }

    head->next->child = child_head;

    bool flag = true;
    node* slow = head;
    node* fast = nullptr;
    node* prev = nullptr;
    node* temp = nullptr;
    stack<node*> st;

    while (slow != nullptr) {
        if (slow->child != nullptr) {
            if (slow->next != nullptr) {
                st.push(slow->next);
            }
            slow->next = slow->child;
            slow->child = nullptr;
        }
        else if (slow->next == nullptr && !st.empty()) {
            slow->next = st.top();
            st.pop();
        }
        slow = slow->next;
    }

    cout << "========================================\n";
    temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
    cout << "========================================\n";

    while (head != nullptr) {
        node* temp = head;
        head = head->next;
        delete temp;
    }
}
