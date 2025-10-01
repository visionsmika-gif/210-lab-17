// COMSC-210 | Lab 17 | Mika Aquino
// IDE used: Visual Studio 2022

#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

// Functions for linked list operations
Node* createLinkedList();
void insertNode(Node* &head, int position, float newVal);
void deleteNode(Node*& head, int position);
void addNodeToFront(Node* &head, float newVal);
void addNodeToTail(Node* &head, float newVal);
void deleteLinkedList(Node*& head);

// Functions for input and output
int getUserEntry(const string& msg, Node* head); // Prompts the user to select a node
void output(Node*); // Displays the linked list

int main() {
    Node *head = nullptr;
    int entry;

    // Create a linked list
    head = createLinkedList();
    output(head);

    // Delete a node
    entry = getUserEntry("Which node to delete? ", head);
    deleteNode(head, entry);
    output(head);

    // Insert a node
    entry = getUserEntry("After which node to insert 10000? ", head);
    insertNode(head, entry, 10000);
    output(head);

    // Add a node to the front
    cout << "Enter a value to add to the front of the linked list --> ";
    cin >> entry;
    addNodeToFront(head, entry);
    output(head);

    // Add a node to the tail
    cout << "Enter a value to add to the tail of the linked list --> ";
    cin >> entry;
    addNodeToTail(head, entry);
    output(head);

    // Delete the entire linked list
    deleteLinkedList(head);
    output(head);

    return 0;
}

// createLinkedList() creates a linked list of size SIZE with random numbers 0-99.
// args: none
// returns: a pointer to the linked list's head
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

// insertNode() inserts a node at a certain position in a linked list.
// args:
    // head - a pointer to the linked list's head
    // position - the position to insert the node at
    // newVal - the inserted node's value
// returns: void
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

// deleteNode() deletes a node at a certain position in a linked list.
// args:
    // head - a pointer to the linked list's head
    // position - the position of the node to delete
void deleteNode(Node*& head, int position) {
    if (position == 1) { // Added an if branch here to handle deleting the head
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

// addNodeToFront() adds a node to the front of a linked list.
// args:
    // head - a pointer to the linked list's head
    // newVal - the added node's value
// returns: void
void addNodeToFront(Node* &head, float newVal) {
    // Create a new node and make it the head of the linked list
    Node* newNode = new Node;
    newNode->value = newVal;
    newNode->next = head;
    head = newNode;
}

// addNodeToTail() adds a node to the tail of a linked list.
// args:
    // head - a pointer to the linked list's head
    // newVal - the added node's value
// returns: void
void addNodeToTail(Node* &head, float newVal) {
    // Create a new node
    Node* newNode = new Node;
    newNode->value = newVal;
    newNode->next = nullptr;

    // Traverse the linked list to the tail and add the node there
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

// deleteLinkedList() deletes an entire linked list.
// args:
    // head - a pointer to the linked list's head
// returns: void
void deleteLinkedList(Node*& head) {
    Node* current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
}

// getUserEntry() prompts the user to select a node from a displayed linked list.
// args:
    // msg - the message to display to the user
    // head - a pointer to the linked list's head
// returns: the integer entered by the user
int getUserEntry(const string& msg, Node* head) {
    int entry;
    cout << msg << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;
    return entry;
}

// output() displays a linked list to the user.
// args:
    // head - a pointer to the linked list's head
// returns: void
void output(Node* hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node* current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}