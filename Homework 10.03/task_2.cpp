#include <iostream>
using namespace std;

struct Node
{
    int item;
    Node *next;
};

struct Queue
{
    Node *pHead;

    void enqueue(int item)
    {
        Node *node = new Node;
        node->item = item;
        node->next = pHead;
        pHead = node;
    }

    int dequeue()
    {
        if (!pHead)
            throw 1;

        Node *temp = pHead;
        while (temp->next->next)
            temp = temp->next;
        Node *nextNode = temp->next;
        temp->next = NULL;
        int x = nextNode->item;
        delete nextNode;
        return x;
    }

    void printAll()
    {
        for (Node *temp = pHead; temp; temp = temp->next)
            cout << temp->item << " ";
        cout << endl;
    }
};

int main()
{
    Queue *queue = new Queue;

    queue->enqueue(10);
    queue->enqueue(20);
    queue->enqueue(30);
    queue->printAll();

    cout << endl
         << queue->dequeue() << endl;
         
    cout << queue->dequeue() << endl;
    queue->printAll();

    delete queue;
    return 0;
}
