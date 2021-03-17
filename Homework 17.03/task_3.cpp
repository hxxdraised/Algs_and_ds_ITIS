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

UniqSortedList *Union(UniqSortedList *a, UniqSortedList *b)
{
    UniqSortedList *uList = new UniqSortedList;
    for (int i = 0; i < a->size(); i++)
        uList->add(a->get(i));
    for (int i = 0; i < b->size(); i++)
        uList->add(b->get(i));
    return uList;
}

UniqSortedList *Intersect(UniqSortedList *a, UniqSortedList *b)
{
    UniqSortedList *uList = new UniqSortedList;
    UniqSortedList *dList = new UniqSortedList;
    for (int i = 0; i < a->size(); i++)
        uList->add(a->get(i));
    int size = uList->size();
    for (int i = 0; i < b->size(); i++)
    {
        uList->add(b->get(i));
        if (size == uList->size())
            dList->add(b->get(i));
        size = uList->size();
    }
    delete uList;
    return dList;
}

UniqSortedList *Difference(UniqSortedList *a, UniqSortedList *b)
{
    UniqSortedList *uList = new UniqSortedList;
    UniqSortedList *iList = new UniqSortedList;
    for (int i = 0; i < b->size(); i++)
        uList->add(b->get(i));
    int size = uList->size();
    for (int i = 0; i < a->size(); i++)
    {
        uList->add(a->get(i));
        if (size != uList->size())
            iList->add(a->get(i));
        size = uList->size();
    }
    delete uList;
    return iList;
}

int main()
{
    UniqSortedList *list1 = new UniqSortedList;
    list1->add(20);
    list1->add(10);
    list1->add(5);
    list1->add(25);
    list1->printAll();
    UniqSortedList *list2 = new UniqSortedList;
    list2->add(20);
    list2->add(10);
    list2->add(6);
    list2->add(26);
    list2->printAll();

    Union(list1, list2)->printAll();
    Intersect(list1, list2)->printAll();
    Difference(list1, list2)->printAll();

    delete list1, list2;
    return 0;
}