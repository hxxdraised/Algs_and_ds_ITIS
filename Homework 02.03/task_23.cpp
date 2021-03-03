#include <iostream>
using namespace std;

struct Node
{
    int item;
    Node *next;
};

struct LinkedList
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
            temp->next = node;
        }
    }

    int size()
    {
        int size = 0;
        Node *temp = pHead;
        while (temp){
            temp = temp->next;
            size++;
        }
        return size;
    }

    int get(int id)
    {
        Node *temp = pHead;
        for (int i = 0; i < id; i++)
            temp = temp->next;
        if (!temp)
            throw 1;
        return temp->item;
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
    LinkedList *list = new LinkedList;

    list->add(10);
    list->add(20);
    list->add(30);

    cout << "size: " << list->size() << endl;
    cout << list->get(1) << endl;
    list->printAll();

    delete list;
    return 0;
}