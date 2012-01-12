// Linked list by noark
#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdio.h>

#define swap(a, b) {typeof(a) __tmp = b; b = a; a = __tmp}

#define declareList(__name__, __type__) \
    typedef struct __##__name__##List{ \
        __type__ value; \
        struct __##__name__##List* nextItem; \
        struct __##__name__##List* prevItem; \
    } __name__##List; \
    __name__##List* __name__##RootItem; \
    \
    typedef struct __##__name__##ListInterface { \
        __name__##List* (*getRoot) (); \
    } __name__##ListInterface; \
    __name__##ListInterface __##__name__##interface; \
    \
    __name__##List* init##__name__##List() \
    { \
        __name__##List* __name__##Item = (__name__##List*) malloc(sizeof(__name__##List)); \
        __name__##RootItem = __name__##Item; \
        __name__##RootItem->value = NULL; \
        __name__##RootItem->nextItem = __name__##RootItem; \
        __name__##RootItem->prevItem = __name__##RootItem; \
        return __name__##Item; \
    } \
    void free##__name__##List() \
    { \
        __name__##List* curItem = __name__##RootItem; \
        if (NULL == curItem) \
        { \
            return; \
        } \
        do \
        { \
            __name__##List* nextItem = (__name__##List*) curItem->nextItem; \
            free(curItem); \
            curItem = NULL; \
            curItem = nextItem; \
        } \
        while(NULL == curItem); \
    } \
    \
    __name__##List* getNext##__name__##Item(__name__##List* item) \
    { \
        return (__name__##List*) item->nextItem; \
    } \
    \
    __name__##List* get##__name__##RootItem() \
    { \
        return (__name__##List*) __name__##RootItem; \
    } \
    \
    __name__##List* getPrev##__name__##Item(__name__##List* item) \
    { \
        return (__name__##List*) item->prevItem; \
    } \
    \
    void insert##__name__##Item(__name__##List* item, __name__##List* itemToInsert) \
    { \
        itemToInsert->nextItem = item; \
        itemToInsert->prevItem = item->prevItem; \
        item->prevItem->nextItem = itemToInsert; \
        item->prevItem = itemToInsert; \
    } \
    \
    void append##__name__##Item(__name__##List* item, __name__##List* itemToAppend) \
    { \
        itemToAppend->nextItem = item->nextItem; \
        itemToAppend->prevItem = item; \
        item->nextItem->prevItem = itemToAppend; \
        item->nextItem = itemToAppend; \
    } \
    \
    void remove##__name__##Item(__name__##List* item) \
    { \
        item->prevItem->nextItem = item->nextItem->nextItem; \
        item->nextItem->prevItem = item->prevItem; \
        free(item); \
    } \
    \
    void swap##__name__##Item(__name__##List* a, __name__##List* b) \
    { \
        __name__##List* aNext = a->nextItem; \
        __name__##List* aPrev = a->prevItem; \
        void* aValue = a->value; \
        a->nextItem = b->nextItem; \
        a->prevItem = b->prevItem; \
        a->value = b->value; \
        b->nextItem = aNext; \
        b->prevItem = aPrev; \
        b->value = aValue; \
    } \
    \
    __name__##List* new##__name__##Item() \
    { \
        return (__name__##List*) malloc(sizeof(__name__##List)); \
    } \
    \
    void init##__name__##ListInterface() \
    { \
        __##__name__##interface.getRoot = &(get##__name__##RootItem); \
    } \


#define initList(__name__) init##__name__##List()

#define initListInterface(__name__) init##__name__##ListInterface()

#define freeList(__name__) free##__name__##List()

#define insertItem(__name__, item, itemToInsert) insert##__name__##Item(item, itemToInsert)

#define appendItem(__name__, item, itemToAppend) append##__name__##Item(item, itemToAppend)

#define swapItem(__name__, a, b) swap##__name__##Item(a, b)

#define removeItem(__name__, item) remove##__name__##Item(item)

#define newItem(__name__) new##__name__##Item()

#define listType(__name__) __name__##List

#define getRootItem(__name__) get##__name__##RootItem()

#define getNextItem(__name__, item) getNext##__name__##Item(item)

#define getPrevItem(__name__, item) getPrev##__name__##Item(item)

#define getListInterfaceType(__name__) __name__##ListInterface

#define getListInterface(__name__) &(__##__name__##interface)

#endif

