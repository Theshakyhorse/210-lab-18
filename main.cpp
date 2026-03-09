//COMSC-210 | Lab 18 | Alexander Sierra
#include <iostream>
using namespace std;

struct Node {
    float rating;
    string comment;
    Node *next;
};

void frontN(Node *&, Node *);
void tailN(Node *&, Node *);
void output(Node *);

int main() {
    int choice = 0;
    cout << "[1] new nodes are added to the head of linked list" << endl;
    cout << "[2] new nodes are added to the tail of linked list" << endl;
    cin >> choice;
    return 0;
}

void frontN(Node *&head, Node *newnode) {
    if(!head) {
        head = newnode;
        newnode->next=nullptr;
    }
    else {
        newnode->next=head;
        head = newnode;
    }
}

void tailN(Node *&head, Node *newnode) {
    if(!head) {
        head = newnode;
        newnode->next=nullptr;
    }
    else{
        Node *current=head;
        while (current) {
            if ((current->next)==nullptr) {
                current->next=newnode;
                newnode->next=nullptr;
            }
            current = current->next;
        }
    }
}