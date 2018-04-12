#include <iostream>
#include "List.h"

int main() {
    List list;
    auto *v1=new ListItem;
    Init(list, 1);
    Report(list);
    int tmp[]={2,3,4,5};
    Init(list, tmp, 4);
    Prepend(list, 10);
    Append(list, 155);
    InsertAfter(list, list.Head->Next->Next, 12 );
    InsertBefore(list, list.Tail, 7);
    RemoveFirst(list);
    RemoveLast(list);       //bug
    Remove(list, 5);
    std::cout <<    SearchOneBeforeTheLast(list)    <<  std::endl;
    std::cout <<    "counter "  <<  Count(list)     <<  std::endl;
    std::cout <<    Contains(list, 4)               <<  std::endl;
    std::cout <<    Contains(list, 5)               <<  std::endl;
    ReportStructure(list);
    std::cout <<    SearchOneBeforeTheLast(list)    <<  std::endl;
    Report(list);
    Append(list, 3);
    Report(list);

    RemoveAll(list, 3);
    Report(list);

    Remove(list, list.Head);
    Report(list);
    RemoveLast(list);
    Report(list);
    Clear(list);
    ReportStructure(list);
    return 0;
}