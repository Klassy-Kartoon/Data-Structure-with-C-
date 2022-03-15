// BY ZEESHAN KHAN Stack using LINKED LIST
#include <iostream>
using namespace std;
#define max 100
class node
{
public:
    node *next;
    int info;
};
node *push(node *top)
{
    int data;
    node *ptr = (node *)malloc(sizeof(node));
    cout << "enter element" << endl;
    cin >> data;
    ptr->info = data;
    ptr->next = top;
    top = ptr;
    return top;
}
node *pop(node *top)
{
    if (top == NULL)
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        node *ptr;
        ptr = top;
        top = top->next;
        free(ptr);
        ptr = NULL;
    }
    return top;
}
void display(node *top)
{
    node *ptr = top;
    if (ptr == NULL)
    {
        cout << "stack is emptpy" << endl;
    }
    else
    {
        while (ptr != NULL)
        {
            cout << ptr->info << " ";
            ptr = ptr->next;
        }
    }
    cout << endl
         << endl;
}
void peek(node *top)
{
    node *ptr = top;
    if (top == NULL)
    {
        cout << "STack is empty" << endl;
    }
    else
    {
        cout << "peek element is " << ptr->info << endl;
    }
}
class stack
{
private:
    static node *top;

public:
    void create_stack_by_using_linked_list()
    {
        int ch = 0;
        do
        {
            cout << "1. Push element " << endl;
            cout << "2. pop element" << endl;
            cout << "3. display element" << endl;
            cout << "4. peek of stack" << endl;

            cin >> ch;
            switch (ch)
            {
            case 1:
                top = push(top);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                display(top);
                break;
            case 4:
                peek(top);
                break;
            default:
            {
                cout << "THIS IS YOUR STATIC STACK ----END-------PROGRAM------" << endl;
            }
            }
        } while (ch <= 4);
    }
};
node *stack::top = NULL;

int main()
{
    stack ob1;

    ob1.create_stack_by_using_linked_list();
}
