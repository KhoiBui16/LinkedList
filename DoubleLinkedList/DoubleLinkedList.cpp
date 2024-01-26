#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

Node* MakeNode(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

int SizeLinkedList(Node* head)
{
    int element = 0;
    Node* currentNode = head;
    while(currentNode != nullptr)
    {
        element++;
        currentNode = currentNode->next;
    }
    return element;
}

void TraverseForward(Node*  head)
{
    Node* currentNode = head;
    if (currentNode == nullptr)
    {
        cout << "RONG!\n";
        return;
    }
    else
    {
        while(currentNode != nullptr)
        {
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }
}

void InsertAtHead(Node** head, int value)
{
    Node* newNode = MakeNode(value);
    if (*head == nullptr)
    {
        *head = newNode;
        return;
    }
    newNode->next = (*head);
    (*head)->prev = newNode;
    (*head) = newNode;
}

void InsertAtTail(Node** head, int value)
{
    Node* newNode = MakeNode(value);
    if (*head == nullptr)
    {
        InsertAtHead(head, value);
        return;
    }
    Node* currentNode = *head;
    while(currentNode->next != nullptr)
    {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
    newNode->prev = currentNode;
}

void InsertAtPos(Node** head, int value, int position)
{
    int size = SizeLinkedList(*head);
    if (position < 1 || position > size + 1)
    {
        cout << "Vi tri nhap khong hop le!\n";
        return;
    }
    if (position == 1)
    {
        InsertAtHead(head, value);
        return;
    }
    else if (position == size + 1)
    {
        InsertAtTail(head, value);
        return;
    }
    else
    {
        Node* currentNode = *head;
        for (int i = 1; i <= position - 1; i++)
        {
            currentNode = currentNode->next;
        }
        Node* newNode = MakeNode(value);
        newNode->next = currentNode;
        currentNode->prev->next = newNode;
        newNode->prev = currentNode->prev;
        currentNode->prev = newNode;
    }
}

void DeleteAtHead(Node** head)
{
    if (*head == nullptr)
    {
        cout << "Danh sach rong!\n";
        return;
    }
    Node* currentNode = *head;
    (*head) = (*head)->next;
    currentNode->next = nullptr;
}

void DeleteAtTail(Node** head)
{
    int size = SizeLinkedList(*head);
    if (*head == nullptr)
    {
        cout << "Danh sach rong!\n";
        return;
    }
    else if (size == 1)
    {
        DeleteAtHead(head);
        return;
    }
    else
    {
        Node* currentNode = *head;
        while(currentNode->next->next != nullptr)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = nullptr;
    }
}

void DeleteAtPos(Node** head, int position)
{
    int size = SizeLinkedList(*head);
    if (position < 1 || position > size)
    {
        cout << "Vi tri xoa khong hop le!\n";
        return;
    }
    if (*head == nullptr)
    {
        cout << "Danh sach rong!\n";
        return;
    }
    else if (position == 1)
    {
        DeleteAtHead(head);
        return;
    }
    else if (position == size)
    {
        DeleteAtTail(head);
        return;
    }
    else
    {
        Node* currentNode = *head;
        for (int i = 1; i <= position - 1; i++)
        {
            currentNode = currentNode->next;
        }
        currentNode->prev->next = currentNode->next;
        currentNode->next->prev = currentNode->prev;
        currentNode->next = nullptr;
        currentNode->prev = nullptr;
        delete currentNode;
    }
}

bool SearchNode(Node* head, int value)
{
    Node* currentNode = head;
    while(currentNode->next != nullptr)
    {
        if (currentNode->data == value)
            return true;
        currentNode = currentNode->next;
    }
    return false;
}   

int main()
{
    Node* head = nullptr;
    Node* tail = nullptr;
    while(1)
    {
        cout << "*--------------------------------DANH SACH LIEN KET DOI-------------------------*\n";
        cout << "|\t\t1. Kich thuoc cua danh sach.\t\t\t\t\t|\n";
        cout << "|\t\t2. In danh sach.\t\t\t\t\t\t|\n";
        cout << "|\t\t3. Them phan tu vao dau danh sach.\t\t\t\t|\n";
        cout << "|\t\t4. Them phan tu vao cuoi danh sach.\t\t\t\t|\n";
        cout << "|\t\t5. Them phan tu vao vi tri bat ki trong dach sach.\t\t|\n";
        cout << "|\t\t6. Xoa phan tu vi tri dau danh sach.\t\t\t\t|\n";
        cout << "|\t\t7. Xoa phan tu vi tri cuoi danh sach.\t\t\t\t|\n";
        cout << "|\t\t8. Xoa phan tu vi tri bat ki trong danh sach\t\t\t|\n";
        cout << "|\t\t9. Tim kiem phhan tu trong danh sach.\t\t\t\t|\n";
        cout << "|\t\t0. Ket thuc chuong trinh.\t\t\t\t\t|\n";
        cout << "*-------------------------------------------------------------------------------*\n";
        char executed_Statement;
        cout << "\nChon lenh: ";
        cin >> executed_Statement;
        cout << endl;
        if ((executed_Statement - '0') == 1)
        {
            // printing the size of the list
            cout << "Kich thuoc danh sach: " << SizeLinkedList(head) << endl;
        }
        else if ((executed_Statement - '0') == 2)
        {
            // printing the list
            cout << "Danh sach: ";
            TraverseForward(head);
        }
        else if ((executed_Statement - '0') == 3)
        {
            int value;
            cout << "Nhap gia tri can them: ";
            cin >> value;
            // inserting a node at the beginning in the list
            InsertAtHead(&head, value);
            cout << "Danh sach: ";
            TraverseForward(head);
        }
        else if ((executed_Statement - '0') == 4)
        {
            int value;
            cout << "Nhap gia tri can them: ";
            cin >> value;
            // inserting a node at the end in the list
            InsertAtTail(&head, value);
            cout << "Danh sach: ";
            TraverseForward(head);
        }
        else if ((executed_Statement - '0') == 5)
        {
            int value;
            cout << "Nhap gia tri can them: ";
            cin >> value;
            int position;
            cout << "Nhap vi tri can chen: ";
            cin >> position;
            // inserting a note at the specified position in the list
            InsertAtPos(&head, value, position);
            cout << "Danh sach: ";
            TraverseForward(head);
        }
        else if ((executed_Statement - '0') == 6)
        {
            // deleting a note at the beginning in the list
            DeleteAtHead(&head);
            cout << "Danh sach: ";
            TraverseForward(head);
        }
        else if ((executed_Statement - '0') == 7)
        {
            // deleting a note at the end in the list
            DeleteAtTail(&head);
            cout << "Danh sach: ";
            TraverseForward(head);
        }
        else if ((executed_Statement - '0') == 8)
        {
            int position;
            cout << "Nhap vi tri can xoa: ";
            cin >> position;
            // deleting a note at the specified position in the list
            DeleteAtPos(&head, position);
            cout << "Danh sach: ";
            TraverseForward(head);
        }
        else if ((executed_Statement - '0') == 9)
        {
            int value;
            cout << "Nhap gia tri can tim: ";
            cin >> value;
            // searching a note in the list
            if (SearchNode(head, value))
                cout << "Tim thay phan tu trong danh sach!" << endl;
            else
                cout << "Khong tim thay phan tu trong danh sach!" << endl;
        }
        else if ((executed_Statement - '0') == 0)
        {
            cout << "______________________\n";
            cout << "KET THUC CHUONG TRINH!\n";\
            break;
        }
        else
        {
            cout << "LENH NHAP KHONG HOP LE VUI LONG NHAP LAI!\n\n";
        }
    }

    return 0;
}


/*
    #include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Function to print the list
void printList(const Node* head) {
    const Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Function to insert at the beginning
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node{value, head, nullptr};
    if (head) {
        head->prev = newNode;
    }
    head = newNode;
}

// Function to insert at the end
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to insert at a specified position
void insertAtPosition(Node*& head, int value, int position) {
    if (position == 0) {
        insertAtBeginning(head, value);
    } else {
        Node* newNode = new Node{value, nullptr, nullptr};
        Node* current = head;
        for (int i = 0; i < position - 1 && current; ++i) {
            current = current->next;
        }
        if (!current) {
            std::cout << "Invalid position." << std::endl;
            return;
        }
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }
}

// Function to delete a node at a specified position
void deleteAtPosition(Node*& head, int position) {
    if (!head) {
        std::cout << "List is empty. Cannot delete." << std::endl;
        return;
    }

    Node* current = head;
    if (position == 0) {
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        delete current;
    } else {
        for (int i = 0; i < position && current; ++i) {
            current = current->next;
        }
        if (!current) {
            std::cout << "Invalid position. Cannot delete." << std::endl;
            return;
        }
        if (current->prev) {
            current->prev->next = current->next;
        }
        if (current->next) {
            current->next->prev = current->prev;
        }
        delete current;
    }
}

// Function to search for a value in the list
void searchValue(const Node* head, int value) {
    const Node* current = head;
    int position = 0;
    while (current) {
        if (current->data == value) {
            std::cout << "Value " << value << " found at position " << position << "." << std::endl;
            return;
        }
        current = current->next;
        position++;
    }
    std::cout << "Value " << value << " not found in the list." << std::endl;
}

int main() {
    Node* head = nullptr;

    while (1) {
        // Your menu goes here...

        char executed_Statement;
        std::cout << "\nChon lenh: ";
        std::cin >> executed_Statement;
        std::cout << std::endl;

        if (((executed_Statement - '0') == 1)) {
            // Print the list
            std::cout << "Danh sach: ";
            printList(head);
        } else if ((executed_Statement - '0') == 2) {
            // Insert at the beginning
            int value;
            std::cout << "Nhap gia tri can them: ";
            std::cin >> value;
            insertAtBeginning(head, value);
        } else if ((executed_Statement - '0') == 3) {
            // Insert at the end
            int value;
            std::cout << "Nhap gia tri can them: ";
            std::cin >> value;
            insertAtEnd(head, value);
        } else if ((executed_Statement - '0') == 4) {
            // Insert at a specified position
            int value, position;
            std::cout << "Nhap gia tri can them: ";
            std::cin >> value;
            std::cout << "Nhap vi tri can chen: ";
            std::cin >> position;
            insertAtPosition(head, value, position);
        } else if ((executed_Statement - '0') == 5) {
            // Delete at the beginning
            deleteAtPosition(head, 0);
        } else if ((executed_Statement - '0') == 6) {
            // Delete at the end
            deleteAtPosition(head, -1);
        } else if ((executed_Statement - '0') == 7) {
            // Delete at a specified position
            int position;
            std::cout << "Nhap vi tri can xoa: ";
            std::cin >> position;
            deleteAtPosition(head, position);
        } else if ((executed_Statement - '0') == 8) {
            // Search for a value in the list
            int value;
            std::cout << "Nhap gia tri can tim: ";
            std::cin >> value;
            searchValue(head, value);
        } else if ((executed_Statement - '0') == 0) {
            std::cout << "______________________\n";
            std::cout << "KET THUC CHUONG TRINH!\n";
            break;
        } else {
            std::cout << "LENH NHAP KHONG HOP LE VUI LONG NHAP LAI!\n\n";
        }
    }

    return 0;
}

*/