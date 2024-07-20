#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL; 
    }
};
void traverseLinkedList(Node* head)
{
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
}
bool searchLinkedList(Node* head, int target)
{
    while (head != nullptr) {
        if (head->data == target) {
            return true; 
        }
        head = head->next;
    }
    return false;
}
int findLength(Node* head)
{
    int length = 0;
    Node* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}
Node* insertAtBeginning(Node* head, int value)
{
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    return head;
}
void insertAtEnd(Node** head, int value)
{
    Node* newNode = new Node(value);
    if (*head == nullptr) {
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}
void insertPos(Node** current, int pos, int data)
{
    int size = findLength(*current);
    if (pos < 1 || pos > size + 1)
        cout << "Invalid position!" << endl;
    else {
        while (pos--) {
            if (pos == 0) {
                Node* temp = new Node(data);
                temp->next = *current;
                *current = temp;
            }
            else
                current = &(*current)->next;
        }
        size++;
    }
}
Node* removeFirstNode(struct Node* head)
{
    if (head == NULL)
        return NULL;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
Node* removeLastNode(struct Node* head)
{
    if (head == NULL)
        return NULL; 
    if (head->next == NULL) {
        delete head;
        return NULL;
    } 
    Node* second_last = head;
    while (second_last->next->next != NULL)
        second_last = second_last->next; 
    delete (second_last->next); 
    second_last->next = NULL; 
    return head;
}
void deleteAtPosition(Node** head, int position)
{
    if (*head == nullptr || position < 1) {
        return;
    }
    if (position == 1) {
        Node* temp = *head;
        *head = (*head)->next;
        delete temp;
        return;
    }
    Node* current = *head;
    for (int i = 1; i < position - 1 && current != NULL;
         i++) {
        current = current->next;
    }
    if (current == NULL || current->next == NULL) {
        return;
    }
    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
}
void reverselinkedlist(Node*& head)
{
    Node* temp = head;
    Node* prev = NULL;
    while (temp != NULL)
    {
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
}
Node* findMiddle(Node* head)
{
    if (head == NULL)
        return NULL;
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}
Node* merge(Node* left, Node* right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;    
    Node* result = NULL;    
    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }    
    return result;
}

Node* mergeSort(Node* head)
{
    if (head == NULL || head->next == NULL)
        return head;    
    Node* slow = head;
    Node* fast = head->next;    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }    
    Node* mid = slow->next;
    slow->next = NULL;    
    Node* left = mergeSort(head);
    Node* right = mergeSort(mid);    
    return merge(left, right);
}

void removeDuplicates(Node* head)
{
    Node* current = head;
    while (current != NULL && current->next != NULL) {
        Node* runner = current;
        while (runner->next != NULL) {
            if (current->data == runner->next->data) {
                Node* temp = runner->next;
                runner->next = runner->next->next;
                delete temp;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

bool detectCycle(Node* head)
{
    Node* slow=head;
    Node* fast=head;

    while(fast!=nullptr and fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
    }

    return false;
}
int main()
{
    Node* head = NULL;

    insertAtEnd(&head, 30);
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 25);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 25);

    // Traverse the linked list
    cout << "Linked List after insertion at end: ";
    traverseLinkedList(head);

    cout<<endl;

    // Loop Detection
    if (detectCycle(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    // Insert node at the beginning
    head = insertAtBeginning(head, 5);
    cout << "Linked List after insertion at beginning: ";
    traverseLinkedList(head);
    cout<<endl;

    // Insert node at a specific position
    insertPos(&head, 3, 15);
    cout << "Linked List after insertion at position 3: ";
    traverseLinkedList(head);
    cout<<endl;

    // Search in the linked list
    int target = 20;
    bool found = searchLinkedList(head, target);
    cout << "Element " << target << (found ? " is found" : " is not found") << " in the linked list." << endl;
    cout<<endl;

    // Find the length of the linked list
    int length = findLength(head);
    cout << "Length of the linked list: " << length << endl;
    cout<<endl;

    // Remove the first node
    head = removeFirstNode(head);
    cout << "Linked List after removing the first node: ";
    traverseLinkedList(head);
    cout<<endl;

    // Remove the last node
    head = removeLastNode(head);
    cout << "Linked List after removing the last node: ";
    traverseLinkedList(head);
    cout<<endl;

    // Delete a node at a specific position
    deleteAtPosition(&head, 2);
    cout << "Linked List after deletion at position 2: ";
    traverseLinkedList(head);
    cout<<endl;

     // Find the middle of the linked list
    Node* middle = findMiddle(head);
    if (middle != NULL)
    cout << "Middle of the linked list: " << middle->data;
    cout<<endl;

    // Sort the linked list
    head = mergeSort(head);
    cout<<"Sorted Linked List: ";
    traverseLinkedList(head);
    cout<<endl;

    // Reverse the linkedlist 
    reverselinkedlist(head);
    cout << "Linked List after reversal: ";
    traverseLinkedList(head);
    cout<<endl;

    //  Remove the duplicates\.
    removeDuplicates(head);
    cout<<"After removal of duplicates from linkedlist: ";
    traverseLinkedList(head);
    cout<<endl;
    

    return 0;
}
