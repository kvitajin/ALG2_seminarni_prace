#include "List.h"

void Init(List& L)
{
    L.Head = nullptr;
    L.Tail = nullptr;
}

void Init(List& L, const int InitValue)
{
    InternalCreateSingleElementList(L, InitValue);
}

void Init(List& L, const int InitValues[], const int N)
{
    Init(L);
    for (int i = 0; i < N; i++)
    {
        Append(L, InitValues[i]);
    }
}

void Init(List& L, const List& Other)
{
    Init(L);
    for (ListItem* p = Other.Head; p != nullptr; p = p->Next)
    {
        Append(L, p->Value);
    }
}

void Prepend(List& L, const int NewValue)
{
    if (IsEmpty(L))
    {
        InternalCreateSingleElementList(L, NewValue);
    }
    else
    {
                                                                     //po sem asi beze zmeny

        auto* NewItem = new ListItem;
        NewItem->Value = NewValue;
        NewItem->Next = L.Head;
        L.Head->Prev = NewItem;
        L.Head = NewItem;
    }
}

void Append(List& L, const int NewValue)
{
    if (IsEmpty(L))
    {
        InternalCreateSingleElementList(L, NewValue);
    }
    else
    {
        auto* NewItem = new ListItem;
        NewItem->Value = NewValue;
        NewItem->Next = nullptr;
        L.Tail->Next = NewItem;             //todo zde byl odmazan radek, pokud nebude fungovat, vratit
        L.Tail = NewItem;
    }
}

void InsertBefore(List& L, ListItem* CurrentItem, const int NewValue)
{
    if (CurrentItem != nullptr)
    {
        if (CurrentItem == L.Head)
        {
            Prepend(L, NewValue);
        }
        else
        {
            auto* NewItem = new ListItem;
            NewItem->Value = NewValue;
            NewItem->Next=CurrentItem;
            ListItem* P=SearchOneBefore(L, CurrentItem->Value);
            P->Next=NewItem;
        }
    }
}

void InsertAfter(List& L, ListItem* CurrentItem, const int NewValue)
{
    if (CurrentItem != nullptr)
    {
        if (CurrentItem == L.Tail)
        {
            Append(L, NewValue);
        }
        else
        {
            auto* NewItem = new ListItem;
            NewItem->Value = NewValue;
            NewItem->Next = CurrentItem->Next;
            CurrentItem->Next = NewItem;
        }
    }
}

void RemoveFirst(List& L)
{
    if (!IsEmpty(L))
    {
        InternalRemove(L, L.Head);
    }
}

void RemoveLast(List& L)
{
    if (!IsEmpty(L))
    {
        InternalRemove(L, L.Tail);
    }
}

void Remove(List& L, const int ValueToRemove)
{
    ListItem* p = Search(L, ValueToRemove);
    if (p != nullptr)
    {
        InternalRemove(L, p);
    }
}

void RemoveAll(List& L, const int ValueToRemove)
{
    ListItem* p;
    while ((p = Search(L, ValueToRemove)) != nullptr)
    {
        InternalRemove(L, p);
    }
}


void Remove(List& L, const ListItem* ItemToRemove)
{
    if (ItemToRemove != nullptr)
    {
        InternalRemove(L, ItemToRemove);
    }
}

void Clear(List& L)
{
    while (!IsEmpty(L))
    {
        InternalRemove(L, L.Head);
    }
}

ListItem* Search(const List& L, const int Value)
{
    for (ListItem* p = L.Head; p != nullptr; p = p->Next)
    {
        if (p->Value == Value)
        {
            return p;
        }
    }
    return nullptr;
}
ListItem* SearchOneBefore(const List& L, const int Value){
    ListItem* q;
    q->Next= nullptr;
    for (ListItem* p = L.Head; p != nullptr; p = p->Next)
    {
        if (p->Value == Value)
        {
            return q;
        }
        q=p;
    }
    return nullptr;
}
ListItem* SearchOneBeforeTheLast(const List& L){
    ListItem* q;
    q->Next= nullptr;
    for (ListItem* p = L.Head; p != nullptr; p = p->Next){
        q=p;
    }
    return q;

}

bool Contains(const List& L, const int Value)
{
    return Search(L, Value) != nullptr;
}

bool IsEmpty(const List& L)
{
    return L.Head == nullptr;
}

int Count(const List& L)
{
    int counter = 0;
    for (ListItem* p = L.Head; p != nullptr; p = p->Next)
    {
        counter += 1;
    }
    return counter;
}

void Report(const List& L)
{
    for (ListItem* p = L.Head; p != nullptr; p = p->Next)
    {
        cout << p->Value << "\t";
    }
    cout << endl;
}

void ReportStructure(const List& L)
{
    cout << "L.Head: " << L.Head << endl;
    cout << "L.Tail: " << L.Tail << endl;
    for (ListItem* p = L.Head; p != nullptr; p = p->Next)
    {
        cout << "Item address: " << p << endl;
        cout << "Value: " << p->Value << endl;
        cout << "Next: " << p->Next << endl;
        cout << endl;
    }
}

void InternalCreateSingleElementList(List& L, const int NewValue)
{
    L.Head = L.Tail = new ListItem;
    L.Head->Value = NewValue;
    L.Head->Next = nullptr;
}

void InternalRemove(List& L, const ListItem* ItemToDelete)
{
    if (ItemToDelete == L.Head && ItemToDelete == L.Tail)
    {
        L.Head = nullptr;
        L.Tail = nullptr;
    }
    else
    {
        if (ItemToDelete == L.Head)
        {
            L.Head = L.Head->Next;
        }
        else
        {
            if (ItemToDelete == L.Tail)
            {
                L.Tail=SearchOneBeforeTheLast(L);                                //todo napojeni predesleho// asi done??? otestovat
                L.Tail->Next = nullptr;
            }
            else
            {
                ListItem* N= ItemToDelete->Next; //todo

                /*ListItem* P = ItemToDelete->Prev;
                ListItem* N = ItemToDelete->Next;
                P->Next = N;
                N->Prev = P;*/
            }
        }
    }
    delete ItemToDelete;
}
