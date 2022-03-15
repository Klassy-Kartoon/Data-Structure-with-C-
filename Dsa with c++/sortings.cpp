//Zeeshan Khan (sorting)
#include <iostream>
using namespace std;
#define max 1000
void bubble_sort(int a[], int n)
{
    int i; // round or passes
    int j; // represent index of value of array
    int temp = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
void selection_sort(int a[], int n)
{
    int i;
    int j;
    int temp;
    int pos;
    int min;
    for (i = 0; i < n; i++)
    {
        min = a[i];
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (min > a[j])
            {
                min = a[j];
                pos = j;
            }
            if (pos != i)
            {
                a[pos] = a[i];
                a[i] = min;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
void insertion_sort(int a[], int n)
{
    cout << "inseertion sort" << endl;
    int i;
    int j;
    int key;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && key < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
void quick_sort(int a[], int lb, int ub)
{
    int i = lb;
    int j = ub;
    int n = ub;
    int key = a[lb];
    int t = 0;
    if (lb >= ub)
    {
        return;
    }
    else
    {
        while (i < j)
        {
            while (key >= a[i] && i < j)
            {
                i++;
            }
            while (key <  a[j])
            {
                j--;
            }
            if (i < j)
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    a[lb] = a[j];
    a[j] = key;
    quick_sort(a, lb, j - 1);
    quick_sort(a, j + 1, ub);
}
class sorting
{
private:
    int a[max];
    static int n; // number of elements
    int i;

public:
    void array_create()
    {
        cout << "Enter number of elements" << endl;
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cout << "element " << i + 1 << " =";
            cin >> a[i];
        }
    }
    void sort()
    {
        int ch = 0;
        do
        {
            cout << "1. Bubble Sort" << endl;
            cout << "2. Selection Sort" << endl;
            cout << "3. Insertion Sort" << endl;
            cout << "4. Quick Sort" << endl;
            cout << "5. Merge Sort" << endl;
            cin >> ch;
            switch (ch)
            {
            case 1:
                bubble_sort(a, n);
                break;
            case 2:
                selection_sort(a, n);
                break;
            case 3:
                insertion_sort(a, n);
                break;
            case 4:
            {
                int lb = 0;
                int ub = n - 1;
                quick_sort(a, lb, ub);
                for (i = 0; i < n; i++)
                {
                    cout << a[i] << " ";
                }
            }
            break;

            default:
            {
                cout << "end program" << endl;
            }
            }

        } while (ch <= 3);
    }
};
int sorting::n;
int main()
{
    sorting ob1;
    ob1.array_create();
    ob1.sort();
}
