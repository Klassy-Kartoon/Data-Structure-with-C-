// by zeeshan khan (singly linked list)
#include <iostream>
using namespace std;
class node
{
public:
    int info;
    node *link;
};
node *add_first(node *head, int data)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->info = data;
    ptr->link = NULL;
    head = ptr;
    return head;
}
node *add_at_end(node *head, int data)
{
    node *ptr = (node *)malloc(sizeof(node));
    node *ptr2 = head;
    ptr->info = data;
    ptr->link = NULL;
    while (ptr2->link != NULL)
    {
        ptr2 = ptr2->link;
    }
    ptr2->link = ptr;
    return head;
}
node *print_linked_list1(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->info << " ";
        ptr = ptr->link;
    }
    return head;
}
node *add_at_beg(node *head)
{
    int data;
    cout << "enter element you want to insert at first" << endl;
    cin >> data;
    node *ptr = (node *)malloc(sizeof(node));
    ptr->info = data;
    ptr->link = NULL;
    ptr->link = head;
    head = ptr;
    return head;
}
node *add_at_last(node *head)
{
    int data;
    cout << "enter element you want to insert at end" << endl;
    cin >> data;
    node *ptr = (node *)malloc(sizeof(node));
    ptr->info = data;
    ptr->link = NULL;
    node *ptr2 = head;
    while (ptr2->link != NULL)
    {
        ptr2 = ptr2->link;
    }
    ptr2->link = ptr;
    return head;
}
node *add_at_middle(node *head)
{
    int data;
    cout << "enter the element you want insert at any positin (rest 1 and last" << endl;
    cin >> data;
    node *ptr = (node *)malloc(sizeof(node));
    ptr->info = data;
    ptr->link = NULL;
    int pos;
    cout << "enter the position " << endl;
    cin >> pos;
    node *tp = head;
    node *tp2;
    while (pos != 1)
    {
        tp2 = tp;
        tp = tp->link;
        pos--;
    }
    tp2->link = ptr;
    ptr->link = tp;

    return head;
}
node *del_at_beg(node *head)
{
    if (head == NULL)
    {
        cout << "LInked list is empty" << endl;
    }
    else if (head->link == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        node *temp;
        temp = head;
        head = head->link;
        free(temp);
        temp = NULL;
    }
    return head;
}
node *del_at_last(node *head)
{
    if (head == NULL)
    {
        cout << "LInked list is empty" << endl;
        return head;
    }
    else if (head->link == NULL)
    {
        free(head);
        head = NULL;
        return head;
    }
    else
    {
        node *temp, *temp2;
        temp = head;
        while (temp->link != NULL)
        {
            temp2 = temp;
            temp = temp->link;
        }
        free(temp);
        temp = NULL;
        temp2->link = NULL;
        return head;
    }
}
node *del_at_middle(node *head)
{
    int pos;
    if (head == NULL)
    {
        cout << "linked list is empty" << endl;
    }
    else if (head->link == NULL)
    {
        free(head);
        head = NULL;
    }
    else if (head->link->link == NULL)
    {
        node *ptr = head;
        ptr = ptr->link->link;
        free(ptr);
        ptr = NULL;
        head->link = NULL;
    }
    else
    {
        cout << "enter the position number whuc you want to delete" << endl;
        cin >> pos;
        node *temp, *temp2, *temp3;
        temp = head;
        while (pos != 1)
        {
            temp2 = temp;
            temp = temp->link;
            pos--;
        }
        temp3 = temp->link;
        temp2->link = temp3;
        free(temp);
        temp = NULL;
    }
    return head;
}
node *display(node *head)
{
    node *ptr = head;
    if (ptr == NULL)
    {
        cout << "taddddddaaaa linked list is empty" << endl;
    }

    else
    {
        while (ptr != NULL)
        {
            cout << ptr->info << " ";
            ptr = ptr->link;
        }
    }
    return head;
}
class singly_linked_list
{
private:
    node *head;
    int data;

public:
    void create_list()
    {
        int n;
        cout << "enter number of nodes" << endl;
        cin >> n;
        cout << "enter 1 element" << endl;
        cin >> data;
        head = add_first(head, data);
        for (int i = 2; i <= n; i++)
        {
            cout << "enter " << i << " element" << endl;
            cin >> data;
            head = add_at_end(head, data);
        }
        head = print_linked_list1(head);
        cout << endl
             << endl
             << endl;
    }
    void function_in_singly_linked_list()
    {
        int ch = 0;
        do
        {
            cout << endl
                 << "1. Add At Begning" << endl;
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
                cout << " SINGLE LINKED LIST BY ZEESHAN 😄" << endl;
            }
            }
        } while (ch <= 7);
    }
};
int main()
{
    singly_linked_list ob;
    ob.create_list();
    ob.function_in_singly_linked_list();
}