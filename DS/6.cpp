#include <iostream>
#include <string>

using namespace std;

class Stack
{

private:
    int top;   // to hold the index position at the top of the stack
    int arr[5];

public:
    Stack()
    {
        top = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if (top == 4)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(int val)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        else
        {
            int val = arr[top];
            arr[top] = 0;
            top--;
            return val;
        }
    }

    int count()
    {
        return (top + 1);
    }

    int peek(int index)
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        else
        {
            int val = arr[index];
            return val;
        }
    }

    void change(int pos, int val)
    {
        arr[pos] = val;
        cout << "Item is changed at location" << pos << endl;
    }

    void display()
    {
        for (int i = 4; i >= 0; i--)
        {
            cout << "THE STACK" << endl;
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    Stack s1;
    int op, pos, val;

    do
    {
    cout << "THE STACK OPERATIONS" << endl;
    cout << "1. isEmpty()\n2. isFull()\n3. push()\n4. pop()\n5. count()\n6. peek()\n7. change()\n8. display()\n9. Exit" << endl;
    cin >> op;

    
         switch (op)
        {
        case 1:
            if (s1.isEmpty())
            {
                cout << "stack is empty" << endl;
            }
            else
            {
                cout << "stack isn't empty" << endl;
            }
            break;

        case 2:
            if (s1.isFull())
            {
                cout << "stack is full" << endl;
            }
            else
            {
                cout << "stack isn't full" << endl;
            }
            break;

        case 3:
            cout << "Enter any value : " << endl;
            cin >> val;
            s1.push(val);
            break;

        case 4:
            cout << s1.pop() << endl;
            break;

        case 5:
            cout << s1.count() << endl;
            break;

        case 6:
            cout << "Enter position : " << endl;
            cin >> pos;
            cout << s1.peek(pos) << endl;
            break;

        case 7:
            cout << "Enter position and value : " << endl;
            cin >> pos >> val;
            s1.change(pos, val);
            break;

        case 8:
            s1.display();
            break;

        case 9:
            exit(0);

        default:
            cout << "Invalid input";
            break;
        }
    } while (op != 0);
    
       
    return 0;
}
