//BY ZEESHAN KHAN Stack with ARRAY
#include <iostream>
using namespace std;
#define max 100
int push(int a[], int top)
{
    int data;
    if (top == max - 1)
    {
        cout << "stack is full" << endl
             << endl;
    }
    else
    {
        cout << "Enter Element" << endl;
        cin >> data;
        top++;
        a[top] = data;
    }
    return top;
}
int pop(int a[], int top)
{
    if (top == -1)
    {
        cout << "Stack is Empty" << endl
             << endl;
    }
    else
    {
        cout << "Poped elements" << a[top] << endl
             << endl;
        top--;
    }
    return top;
}
void display(int a[], int top)
{
    int i;
    cout << endl;
    if (top >= 0)

    {
        for (i = top; i >= 0; i--)

            cout << a[i] << endl;
    }
    else
    {
        cout << "stack is empty" << endl
             << endl;
    }
}
void peek(int a[], int top)
{
    int i = top;
    if (top == -1)
    {
        cout << "stack is empty" << endl
             << endl;
    }
    else
    {
        cout << "peek is " << a[i] << endl
             << endl;
    }
}
class stack
{
private:
    int a[max];
    static int top;

public:
    // void set_data(int )

    void create_stack_by_static()
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
                top = push(a, top);
                break;
            case 2:
                top = pop(a, top);
                break;
            case 3:
                display(a, top);
                break;
            case 4:
                peek(a, top);
                break;
            default:
            {
                cout << "THIS IS YOUR STATIC STACK ----END-------PROGRAM------" << endl;
            }
            }
        } while (ch <= 4);
    }
};
int stack::top = -1;
int main()
{
    stack ob1;
    ob1.create_stack_by_static();
}
