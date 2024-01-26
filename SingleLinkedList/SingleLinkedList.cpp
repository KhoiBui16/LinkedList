#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

Node* MakeNode(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

int SizeLinkedList(Node* head)
{
    int size = 0;
    while(head != nullptr)
    {
        size++;
        head = head->next;
    }
    return size;
}

void TraverseLinkedList(Node* head)
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
}

void InsertNodeAtPos(Node** head, int value, int position)
{
    int size = SizeLinkedList(*head);
    if (position < 1 || position > size + 1)
    {
        cout << "Vi tri chen khong hop le!\n";
        return;
    }
    else if (position == 1)
    {
        InsertAtHead(head, value);
        return;
    }
    else if (position == size + 1)
    {
        InsertAtTail(head, value);
        return;
    }
    Node* newNode = MakeNode(value);
    Node* currentNode = *head;
    for (int i = 1; i <= position - 2; i++)
        currentNode = currentNode->next;
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    
}

void DeleteAtHead(Node** head)
{
    if (*head == nullptr)
    {
        cout << "Danh sach rong!\n";
        return;
    }
    Node* currentNode = *head;
    *head = currentNode->next;
    delete currentNode;
}

void DeleteAtTail(Node** head)
{
    if (*head == nullptr)
    {
        cout << "Danh sach rong!\n";
        return;
    }
    else if ((*head)->next = nullptr)
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
        Node* LastNode = currentNode->next;
        currentNode->next = nullptr;
        delete LastNode;
    }
}

void DeleteAtPos(Node** head, int position)
{
    if (*head == nullptr)
    {
        cout << "Danh sach rong!\n";
        return;
    }
    else if (position < 1 || position > SizeLinkedList(*head))
    {
        cout << "Vi tri xoa khong hop le!\n";
        return;
    }
    else if (position == 1)
    {
        DeleteAtHead(head);
        return;
    }
    else if (position == SizeLinkedList(*head))
    {
        DeleteAtTail(head);
        return;
    }
    Node* currentNode = *head;
    for (int i = 1; i <= position - 2; i++)
        currentNode = currentNode->next;
    Node* NodeDelete = currentNode->next;
    currentNode->next = NodeDelete->next;
    delete NodeDelete;
}

bool SearchNode(Node* head, int value)
{
    while(head != nullptr)
    {
        if (head->data == value)
            return true;
        head = head->next;
    }
    return false;
}

int MaxNode(Node* head)
{
    int result = -1e9;
    while(head != nullptr)
    {
        result = max(result, head->data);
        head = head->next;
    }
    return result;
}

void SortLinkedList(Node** head)
{
    // selection sort
    if (*head == nullptr || (*head)->next == nullptr)
        return;
    for (Node* i = *head; i != nullptr; i = i->next)
    {
        Node* min = i;
        for (Node* j = i->next; j != nullptr; j = j->next)
        {
            if (j->data < min->data)
                min = j;
        }
        swap(min->data, i->data);
    }
}

int main()
{
    Node* head = nullptr;
    while(1)
    {
        cout << "*--------------------------------DANH SACH LIEN KET DON-------------------------*\n";
        cout << "|\t\t1.  In danh sach.\t\t\t\t\t\t|\n";
        cout << "|\t\t2.  Kich thuoc cua danh sach.\t\t\t\t\t|\n";
        cout << "|\t\t3.  Them phan tu vao dau danh sach.\t\t\t\t|\n";
        cout << "|\t\t4.  Them phan tu vao cuoi danh sach.\t\t\t\t|\n";
        cout << "|\t\t5.  Them phan tu vao vi tri bat ki trong dach sach.\t\t|\n";
        cout << "|\t\t6.  Xoa phan tu vi tri dau danh sach.\t\t\t\t|\n";
        cout << "|\t\t7.  Xoa phan tu vi tri cuoi danh sach.\t\t\t\t|\n";
        cout << "|\t\t8.  Xoa phan tu vi tri bat ki trong danh sach\t\t\t|\n";
        cout << "|\t\t9.  Tim kiem phhan tu trong danh sach.\t\t\t\t|\n";
        cout << "|\t\t10. Tim Kiem phan tu co gia tri lon nhat trong danh sach:\t|\n";
        cout << "|\t\t11. Sap xep danh sach tang dan\t\t\t\t\t|\n";
        cout << "|\t\t0. Ket thuc chuong trinh.\t\t\t\t\t|\n";
        cout << "*-------------------------------------------------------------------------------*\n";
        int executed_Statement;
        cout << "\nChon lenh: ";
        cin >> executed_Statement;
        cout << endl;
        if (executed_Statement == 1)
        {
            // printing the list
            cout << "Danh sach: ";
            TraverseLinkedList(head);
        }
        else if (executed_Statement == 2)
        {
            // printing the size of the list
            cout << "Kich thuoc danh sach: " << SizeLinkedList(head) << endl;
        }
        else if (executed_Statement == 3)
        {
            int value;
            cout << "Nhap gia tri can them: ";
            cin >> value;
            // inserting a node at the beginning in the list
            InsertAtHead(&head, value);
            cout << "Danh sach: ";
            TraverseLinkedList(head);
        }
        else if (executed_Statement == 4)
        {
            int value;
            cout << "Nhap gia tri can them: ";
            cin >> value;
            // inserting a node at the end in the list
            InsertAtTail(&head, value);
            cout << "Danh sach: ";
            TraverseLinkedList(head);
        }
        else if (executed_Statement == 5)
        {
            int value;
            cout << "Nhap gia tri can them: ";
            cin >> value;
            int position;
            cout << "Nhap vi tri can chen: ";
            cin >> position;
            // inserting a note at the specified position in the list
            InsertNodeAtPos(&head, value, position);
            cout << "Danh sach: ";
            TraverseLinkedList(head);
        }
        else if (executed_Statement == 6)
        {
            // deleting a note at the beginning in the list
            DeleteAtHead(&head);
            cout << "Danh sach: ";
            TraverseLinkedList(head);
        }
        else if (executed_Statement == 7)
        {
            // deleting a note at the end in the list
            DeleteAtTail(&head);
            cout << "Danh sach: ";
            TraverseLinkedList(head);
        }
        else if (executed_Statement == 8)
        {
            int position;
            cout << "Nhap vi tri can xoa: ";
            cin >> position;
            // deleting a note at the specified position in the list
            DeleteAtPos(&head, position);
            cout << "Danh sach: ";
            TraverseLinkedList(head);
        }
        else if (executed_Statement == 9)
        {
            int value;
            cout << "Nhap gia tri can tim: ";
            cin >> value;
            // searching a note in the list
            if (SearchNode(head, value))
                cout << "Gia tri " << value << " co trong danh sach.\n";
            else
                cout << "Gia tri " << value << " khong co trong danh sach.\n";
        }
        else if (executed_Statement == 10)
        {
            // finding the maximun value in the list
            int result = 0;
            result = MaxNode(head);
            cout << "Gia tri lon nhat trong danh sach: " << result << endl;
        }
        else if (executed_Statement == 11)
        {
            // sorting the list
            SortLinkedList(&head);
            cout << "Danh sach: ";
            TraverseLinkedList(head);
        }
        else if (executed_Statement == 0)
        {
            cout << "______________________\n";
            cout << "KET THUC CHUONG TRINH!\n";\
            break;
        }
    }

    return 0;
}
