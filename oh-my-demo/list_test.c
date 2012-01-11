#include <stdio.h>
#include "list.h"

declareList(myList, int);

int main()
{
    int a = 9;
    int b = 10;
    int c = 11;

    initList(myList);
    initListInterface(myList);
    getListInterfaceType(myList)* listInterface = getListInterface(myList);

    listInterface->getRoot()->value = a;
    listType(myList)* item = newItem(myList);
    item->value = b;
    appendItem(myList, getRootItem(myList), item);
    item = newItem(myList);
    item->value = c;
    insertItem(myList, getRootItem(myList)->nextItem, item);
    listType(myList)* rootItem = getRootItem(myList);
    printf("%d\n", rootItem->value);
    item = getNextItem(myList, rootItem);
    printf("%d\n", item->value);
    item = getNextItem(myList, item);
    printf("%d\n", item->value);
    item = getNextItem(myList, item);
    printf("%d\n", item->value);
    item = getNextItem(myList, item);
    printf("%d\n", item->value);
    item = getNextItem(myList, item);
    printf("%d\n", item->value);
    freeList(myList);

    return 0;
}

