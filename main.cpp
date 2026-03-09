//COMSC-210 | Lab 18 | Alexander Sierra
#include <iostream>
using namespace std;

struct Node {
    double rating;
    string comment;
    Node *next;
};

void frontN(Node *&, Node *);
void tailN(Node *&, Node *);
void output(Node *);
void deleteL(Node *&);

int main() {
    //declarations
    Node *head = nullptr;
    int choice = 0;
    string sentence;
    double rate;

    //giving choice of adding to head or tail
    cout << "Select which linked list method should be used:" << endl;
    cout << "[1] New nodes are added to the head of linked list" << endl;
    cout << "[2] New nodes are added to the tail of linked list" << endl;
    cin >> choice;

    //code for head
    Node *newnode = nullptr;
    while (choice == 1) {
        cout << "Enter review rating 0.0-5.0:" << endl;
        cin >> rate;
        newnode->rating = rate;
        cout << "Enter review comment:" << endl;
        cin.ignore();
        getline(cin, sentence);
        newnode->comment = sentence;
        frontN(head, newnode);
        cout << "Enter another review? (Y=1/N=0)" << endl;
        cin >> choice;
        deleteL(newnode);
    }

    //code for tail
    while (choice == 2) {
        cout << "Enter review rating 0.0-5.0:" << endl;
        cin >> rate;
        newnode->rating = rate;
        cout << "Enter review comment:" << endl;
        cin.ignore();
        getline(cin, sentence);
        newnode->comment = sentence;
        tailN(head, newnode);
        cout << "Enter another review? (Y=2/N=0)" << endl;
        cin >> choice;
        deleteL(newnode);
    }

    cout << "Outputting all reviews: " << endl;
    output(head);
    deleteL(head);

    return 0;
}

//adds node to head
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

//adds node to tail
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

//outputs linked list
void output(Node *hd) {
    if (!hd) {
        cout << "empty list.\n";
        return;
    }

    int count = 1;
    double sum = 0;
    Node *current = hd;
    while (current) {
        cout << " > Review #" << count++ << ": ";
        cout << current->rating << ": " << current ->comment << endl;
        sum += current->rating;
    }
    cout << " > Average: " << sum/count << endl;
}

//deletes a linked list
void deleteL(Node *&n) {
    Node *current = n;
    while (current) {
        n = current ->next;
        delete current;
        current = n;
    }
    n = nullptr;
}