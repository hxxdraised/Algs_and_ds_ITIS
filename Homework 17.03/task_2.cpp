#include <iostream>
using namespace std;

struct Node
{
    int item;
    Node *next;
};

struct UniqSortedList
{
    Node *pHead = new Node;

    void add(int item)
    {
        Node *node = new Node;
        node->item = item;
        Node *temp = pHead;
        while (temp->next && (temp->next->item < item))
            temp = temp->next;
        if (!(temp->next) or (temp->next->item != item))
        {
            node->next = temp->next;
            temp->next = node;
        }
    }

    int size()
    {
        int size = 0;
        Node *temp = pHead->next;
        while (temp)
        {
            temp = temp->next;
            size++;
        }
        return size;
    }

    int get(int id)
    {
        Node *temp = pHead->next;
        for (int i = 0; i < id; i++)
            temp = temp->next;
        if (!temp)
            throw 1;
        return temp->item;
    }

    void remove(int id)
    {
        Node *temp = pHead;
        for (int i = 0; i < id; i++)
        {
            temp = temp->next;
            if (!temp)
                throw 1;
        }
        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    void printAll()
    {
        Node *temp = pHead->next;
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
    UniqSortedList *list = new UniqSortedList;

    list->add(20);
    list->add(10);
    list->add(5);
    list->add(25);
    list->add(25);

    list->printAll();
    cout << "size: " << list->size() << endl;
    cout << list->get(1) << endl;
    list->remove(0);
    list->printAll();

    delete list;
    return 0;
}