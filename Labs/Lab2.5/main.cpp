//Done by student: Vitaliy Syniak
//Group: 121-1
//Lab 2.5

#include <iostream>

struct Node {
    int data; 
    Node* next; 
    Node* prev;
};

void addToFront(Node** head, int value); 
void reverseList(Node** head); 
void addToEnd(Node** head, int value); 
void removeFromEnd(Node** head); 
void printList(Node* head); 
Node* searchElement(Node* head, int value); 
void sortList(Node** head); 
void clearList(Node** head); 

int main() {
    Node* head = nullptr;

    addToFront(&head, 10);
    addToFront(&head, 20);
    addToFront(&head, 30);

    std::cout << "List with elements: ";
    printList(head);

    int searchValue = 20;
    Node* foundNode = searchElement(head, searchValue);
    if (foundNode) {
        std::cout << "Element " << searchValue << " found" << std::endl;
    } else {
        std::cout << "Element " << searchValue << " not found" << std::endl;
    }

    removeFromEnd(&head);
    std::cout << "List after removing last element: ";
    printList(head);

    reverseList(&head);
    std::cout << "Reversed list: ";
    printList(head);

    sortList(&head);
    std::cout << "Sorted list: ";
    printList(head);

    clearList(&head);
    std::cout << "Cleared list: ";
    printList(head);

    return 0;
}

void addToFront(Node** head, int value) {
    Node* newNode = new Node{value, *head, nullptr};
    if (*head != nullptr) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// #1
void addToEnd(Node** head, int value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (*head == nullptr) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// #2
void removeFromEnd(Node** head) {
    if (*head == nullptr) return;
    if ((*head)->next == nullptr) {
        delete *head;
        *head = nullptr;
    } else {
        Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        delete temp;
    }
}

// #3
void printList(Node* head) {
    if (head == nullptr) {
        std::cout << "null" << std::endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "null" << std::endl;
}

// #4
Node* searchElement(Node* head, int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) return current;
        current = current->next;
    }
    return nullptr;
}

// #5
void reverseList(Node** head) {
    Node* current = *head;
    Node* temp = nullptr;
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != nullptr) {
        *head = temp->prev;
    }
}

// #6
void sortList(Node** head) {
    if (*head == nullptr) return;
    bool swapped;
    do {
        swapped = false;
        Node* current = *head;
        while (current->next != nullptr) {
            if (current->data > current->next->data) {
                std::swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

// #7
void clearList(Node** head) {
    Node* current = *head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    *head = nullptr;
}
