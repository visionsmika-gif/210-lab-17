#include <iostream>
using namespace std;

/* INSTRUCTIONS:
Refactor this code. The code currently is not modular at all; important code that could be reused is not contained in functions.

Rewrite the code such that it leverages functions to perform these linked list operations: adding a node to the front; adding a node to the tail;
deleting a node; inserting a node; and deleting the entire linked list.

Don't forget that the coding conventions for this course require using function prototypes. */

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);
Node* createLinkedList();
void deleteNode(Node* &head, int position);
void insertNode(Node* &head, int position, float newVal);
void deleteLinkedList(Node* &head);

// Add a node to the front
void addNodeToFront(Node* &head, float newVal) {
    Node* newNode = new Node;
    newNode->value = newVal;
    newNode->next = head;
    head = newNode;
}

// Add node to tail
void addNodeToTail(Node* &head, float newVal) {
    Node* newNode = new Node;
    newNode->value = newVal;

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    
}

int getUserEntry(const string& msg, Node* head) {
    int entry;
    cout << msg << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;
    return entry;
}

int main() {
    Node *head = nullptr;
    int count = 0;
    int entry;

    // Create a linked list of size SIZE with random numbers 0-99
    head = createLinkedList();
    output(head);

    // Ask the user which node to delete
    entry = getUserEntry("Which node to delete? ", head);
    
    // Delete the node
    deleteNode(head, entry);
    output(head);

    // Ask the user where to insert a node
    entry = getUserEntry("After which node to insert 10000? ", head);

    // Insert the node
    insertNode(head, entry, 1000);
    output(head);

    // Ask the user what value to add at the front of the linked list
    cout << "Enter a value to add to the front of the linked list --> ";
    cin >> entry;
    addNodeToFront(head, entry);
    output(head);

    cout << "Enter a value to add to the tail of the linked list --> ";
    cin >> entry;
    addNodeToTail(head, entry);
    output(head);

    // Delete the entire linked list
    deleteLinkedList(head);
    output(head);

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

Node* createLinkedList() {
    Node* head = nullptr;
    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node* newVal = new Node;

        // adds node at head
        if (!head) { // if this is the first node, it's the new head
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else { // its a second or subsequent node; place at the head
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
    return head;
}

void deleteNode(Node* &head, int position) {
    if (position == 1) { // Added an if branch to handle deleting the head
        Node* oldHead = head;
        head = head->next;
        delete oldHead;
        return;
    }
    Node* current = head;
    Node* prev = head;
    // traverse that many times and delete that node
    for (int i = 0; i < (position - 1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
}

void insertNode(Node* &head, int position, float newVal) {
    Node* current = head;
    Node* prev = head;
    for (int i = 0; i < (position); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node* newnode = new Node;
    newnode->value = newVal;
    newnode->next = current;
    prev->next = newnode;
}

void deleteLinkedList(Node* &head) {
    Node* current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
}