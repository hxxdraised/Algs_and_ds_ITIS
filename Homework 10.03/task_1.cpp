#include <iostream>
using namespace std;

struct Node
{
    int item;
    Node *next;
    Node *prev;
};

struct DoublyLinkedList
{
    Node *pHead;

    void add(int item)
    {
        Node *node = new Node;
        node->item = item;
        if (!pHead)
            pHead = node;
        else
        {
            Node *temp = pHead;
            while (temp->next)
                temp = temp->next;
            node->prev = temp;
            temp->next = node;
        }
    }

    int size()
    {
        int size = 0;
        Node *temp = pHead;
        while (temp)
        {
            temp = temp->next;
            size++;
        }
        return size;
    }

    int get(int id)
    {
        Node *temp = pHead;
        for (int i = 0; i < id; i++)
        {
            temp = temp->next;
            if (!temp)
                throw 1;
        }
        return temp->item;
    }

    void insertAt(int item, int id)
    {
        Node *node = new Node;
        node->item = item;
        if ((!pHead) && (id == 0))
            pHead = node;
        else if (pHead)
        {
            Node *temp = pHead;
            for (int i = 0; i < (id - 1); i++)
            {
                temp = temp->next;
                if (!temp)
                    throw 1;
            }
            node->next = temp->next;
            node->prev = temp;
            temp->next = node;
        }
        else
            throw 1;
    }

    void removeAt(int id)
    {
        Node *temp = pHead;
        for (int i = 0; i < id; i++)
        {
            temp = temp->next;
            if (!temp)
                throw 1;
        }
        Node *prevNode = temp->prev;
        Node *nextNode = temp->next;
        delete temp;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void printAll()
    {
        Node *temp = pHead;
        while (temp)
        {
            cout << temp->item << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList *list = new DoublyLinkedList;

    list->add(10);
    list->add(20);
    list->add(30);
    list->add(20);
    list->insertAt(25, 2);

    list->printAll();
    cout << "size: " << list->size() << endl
         << endl;

    list->removeAt(2);
    list->printAll();
    cout << "size: " << list->size() << endl;

    delete list;
    return 0;
}