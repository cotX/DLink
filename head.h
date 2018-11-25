#ifndef __TEST__
#define __TEST__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct DListNode{
    struct DListNode* pNext;
    struct DListNode* pPre;
    DataType data;
}DListNode;

typedef struct DList{
    struct DListNode* pHead;
}DList;

void ListInit(DList* plist);
void Print(DList* plist);
void ListPushBack(DList* plist,DataType data);
DListNode* BuyDListNode(DataType data);
void ListDestory(DList* plist);
#endif
