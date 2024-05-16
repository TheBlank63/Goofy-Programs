#include <iostream>
#include <cstring>

using namespace std;

// int sum(int arr[]);
// int summationall(int arr1[], int arr2[]);
// int getelementsnum(char [], int size);

struct node
{
    int data;
    node *next;
};

class linkedqueue
{
private:
    node *front;
    node *rear;

public:
    linkedqueue()
    {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void enqueue(int data)
    {
        node *temp = new node;
        temp->data = data;
        temp->next = nullptr;

        if (isEmpty())
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return -1;
        }

        node *temp = front;
        int data = temp->data;
        front = front->next;

        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp;
        return data;
    }
    int size()
    {
        int count = 0;
        node *temp = front;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int *storearray(string s, linkedqueue q, int max);
int convertint(string s, int, int);
int getmin(int size1, int size2);
int compareversion(int *arr1, int *arr2, int min);
int main()
{
    string ver;         // store the version numbers
    string s1, s2;      // store each of the version numbers
    linkedqueue q1, q2; // find the location of the dots in the string

    cout << "Enter the versions to compare: ";
    getline(cin, ver);

    int pipeloc = ver.find("|");

    if (pipeloc == -1)
    {
        cout << "Invalid input. Please enter the versions in the format: x.x|y.y" << endl;
        return 0;
    }
    else
    {
        int *arr1;

        for (int i = 0; i < pipeloc; i++)
        {
            s1 += ver[i];
            if (ver[i] == '.')
            {
                q1.enqueue(i);
            }
        }

        for (int i = pipeloc + 1; i < ver.length(); i++)
        {
            s2 += ver[i];
        }
        for (int i = 0; i < s2.length(); i++)
        {
            if (s2[i] == '.')
            {
                q2.enqueue(i);
            }
        }

        int size1 = q1.size() + 1, size2 = q2.size() + 1;

        int *ptr1 = storearray(s1, q1, pipeloc);
        int *ptr2 = storearray(s2, q2, s2.length());

        int min = getmin(size1, size2);

        cout << compareversion(ptr1, ptr2, min) << endl;
    }
}

int *storearray(string s, linkedqueue q, int max)
{
    int size = q.size() + 1;

    int *arr = new int[size];

    int start = 0;

    int end = q.dequeue();

    for (int i = 0; i < size; i++)
    {
        if (i < size - 1)
        {
            arr[i] = convertint(s, start, end);
            start = end + 1;
            if (!q.isEmpty())
            {
                end = q.dequeue();
            }
        }
        else
        {
            arr[i] = convertint(s, start, max);
        }
    }

    return arr;
}

int convertint(string s, int start, int end)
{
    int num = 0;
    for (int i = start; i < end; i++)
    {
        num = num * 10 + (s[i] - '0');
    }
    return num;
}

int getmin(int size1, int size2)
{
    if (size1 < size2)
    {
        return size1;
    }
    else
    {
        return size2;
    }
}

int compareversion(int *arr1, int *arr2, int min)
{
    for (int i = 0; i < min; i++)
    {
        if (arr1[i] > arr2[i])
        {
            return 1;
        }
        else if (arr1[i] < arr2[i])
        {
            return -1;
        }
    }
    return 0;
}