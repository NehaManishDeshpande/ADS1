#include<iostream>
using namespace std;

//front and rear points to same index when only one element is left
//when dequeuing increase the front by one so that it should point to next front element after removing previous
//the rear value get increase when we enqueue 

class Queue
{

private:
    int front;
    int rear;
    int arr[4];
    
public:
    Queue()
    {
        front = -1;
        rear = -1;

        for (int i = 0; i < 4; i++)
        {
            arr[i] = 0;
        }
        
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
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
        if (rear == 3)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
    void enqueue(int val)
    {
        if (isFull())   
        {
            cout << "Queue is full"<< endl;
            return;
        }
        else if (isEmpty()) 
        {
            rear = front = 0;
            arr[rear] = val;
        }
        else
        {
            rear++;
            arr[rear] = val; 
        }
        
    }
    int dequeue()
    {
        int x = 0;
        if (isEmpty())
        {
            cout <<"Queue is Empty"<< endl;
            return 0 ;
        }
        else if (front == rear)
        {
            x = arr[front];
            rear = -1;
            front = -1;
            arr[front] = 0;
        }
        else 
        { 
            x = arr[front];
            arr[front] = 0;
            front++;
        }
        return x;
    }
    int count()
    {
        return (rear-front+1); 
    }
    void display()
    {
        for (int i = 0; i < 4; i++)
        {
            cout << arr[i] << " ";
        }
        
    }
};

int main()
{
    Queue q1;
    int op, val;
    do
    {
        cout << "\n\nMake a Choice  : "<< endl;
        cout << "1. isEmpty()\n2. isFull()\n3. enqueue()\n4.dequeue()\n5. count\n6. display()\n7. Exit\nEnter" << endl;
        cin >> op;

        switch (op)
        {
        case 1:
            if (q1.isEmpty())
            {
                cout << "Queue is empty" << endl;
            }
            else
            {
                cout << "Queue isn't empty" << endl;
            }
            
            break;

        case 2:
            if (q1.isFull())
            {
                cout << "Queue is full" << endl;
            }
            else
            {
                cout << "Queue isn't full" << endl;
            }
            break;

        case 3:
            cout <<"Enqueue : " << endl;
            cin >> val;
            q1.enqueue(val);
            break;

        case 4:
            cout << "Dequeue : " << endl;
            q1.dequeue();
            break;
        
        case 5:
            cout << "The count is  : " << q1.count() << endl;
            break;
        
        case 6:
            cout << "The Queue : " << endl;
            q1.display();
            break;
        
        case 7:
            exit(0);
        
        
        default:
            cout << "Invalid entry" << endl;
            break;
        }
    } while (op != 0);
    
    return 0;
}