// ZEESHAN KHAN ----------- 
#include <iostream>
using namespace std;
class node
{
public:
    int info;
    node *next;
    node *prev;
};
node *add_first(node *head, int data) // Creating first node
{

    node *ptr = head;
    ptr = (node *)malloc(sizeof(node));

    ptr->info = data;
    ptr->prev = NULL;
    ptr->next = NULL;
    return ptr;
}
node *add_at_end(node *head, int data) // Creating second and further node
{
    node *ptr = NULL;
    ptr = (node *)malloc(sizeof(node));
    ptr->info = data;
    ptr->prev = NULL;
    ptr->next = NULL;
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
    ptr->prev = temp;
    return head;
}
node *print_doublylinkedlist_1(node *head) // printing elements after creating list
{
    node *ptr = head;
    cout << "printing double linked list 1 " << endl;
    while (ptr != NULL)
    {
        cout << ptr->info << " ";
        ptr = ptr->next;
    }
    return head;
}

node *add_at_beg(node *head) // adding at begning of linked listafter creating that list
{
    int data;
    node *ptr = (node *)malloc(sizeof(node));
    cout << "Enter the elememt you want to add at begning " << endl;
    cin >> data;
    ptr->info = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    head->prev = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

node *add_at_last(node *head) // adding at last of linked list after creating that list

{
    node *ptr = (node *)malloc(sizeof(node));
    int data;
    cout << "Enter the element you want to add at END" << endl;
    cin >> data;
    ptr->info = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
    ptr->prev = temp;
    return head;
}

node *add_at_middle(node *head) // adding at any postion of linked list after creating that list(except first and last)
{
    int data;
    int pos; // position at which you want to insert the node
    node *ptr = (node *)malloc(sizeof(node));
    cout << "Enter the elements " << endl;
    cin >> data;
    cout << "Enter the position ( any position rest first and last)" << endl;
    cin >> pos;
    ptr->info = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    node *tp = head;
    node *tp2;
    while (pos != 1)
    {
        tp = tp->next;
        pos--;
    }
    tp2 = tp->prev;
    tp2->next = ptr;
    tp->prev = ptr;
    ptr->prev = tp2;
    ptr->next = tp;
    return head;
}
node *del_at_beg(node *head) // deleting at begning of linked list after creating that list
{
    node *ptr = head;
    cout << "Deleting First Node" << endl;
    head = head->next;
    free(ptr);
    ptr = NULL;
    head->prev = NULL;
    return head;
}

node *del_at_last(node *head) // deleting at last of linked list after creating that list
{
    node *tp, *tp2;
    tp = head;
    while (tp->next != NULL)
    {
        tp = tp->next;
    }
    tp2 = tp->prev;
    tp2->next = NULL;
    free(tp);
    tp = NULL;
    return head;
}
node *del_at_middle(node *head) // delelting at any position of linked list after creating that list(except first and last)
{
    node *ptr, *tp;
    ptr = head;
    int pos;
    cout << "enter the position where u want to delete" << endl;
    cin >> pos;
    while (pos != 1)
    {
        ptr = ptr->next;
        pos--;
    }
    tp = ptr->prev;
    tp->next = ptr->next;
    ptr->next->prev = tp;
    free(ptr);
    ptr = NULL;
    return head;
}

node *display(node *head) // display the linked list after creating that list
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->info << " ";
        ptr = ptr->next;
    }
    cout << endl
         << endl;
    return head;
}

class doubly_linked_list
{
private:
    node *head;
    int data;

public:
    void create_list1()
    {
        int n;
        cout << "enter number of nodes\n";
        cin >> n;
        // node * head = (node*)malloc(sizeof(node));
        cout << "enter element in 1 node= " << endl;
        cin >> data;
        head = add_first(head, data);
        for (int i = 2; i <= n; i++) // int n --- head---
        {
            cout << "enter element in node " << i << endl;
            cin >> data;
            head = add_at_end(head, data);
        }
        head = print_doublylinkedlist_1(head);
        cout << endl;
    }
    void function_in_doubly_linked_list()
    {
        int ch = 0;
        do
        {
            cout << "1. Add At Begning" << endl;
            cout << "2. Add At Last" << endl;
            cout << "3. Add At Middle" << endl;
            cout << "4. Delete At Begning" << endl;
            cout << "5. Delete At Last" << endl;
            cout << "6. Delete At Middle" << endl;
            cout << "7. Display Doubly LINKED LIST" << endl;
            cout << "8. end program" << endl;
            cin >> ch;
            switch (ch)
            {
            case 1:
                head = add_at_beg(head);
                break;
            case 2:
                head = add_at_last(head);
                break;
            case 3:
                head = add_at_middle(head);
                break;
            case 4:
                head = del_at_beg(head);
                break;
            case 5:
                head = del_at_last(head);
                break;
            case 6:
                head = del_at_middle(head);
            case 7:
                head = display(head);
                break;
            default:
            {
                cout << " DOUBLE LINKED LIST BY ZEESHAN 😄" << endl;
            }
            }
        } while (ch <= 7);
    }
};
// int doubly_linked_list ::*head;

// CREATING SINGLE LINKED LIST

int main()
{
    doubly_linked_list ob;
    ob.create_list1(); // whole creating a doubly linked list
                       // ob.rest();
    ob.function_in_doubly_linked_list();
}
