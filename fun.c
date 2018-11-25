#include "head.h"

/*建立新节点*/
DListNode* BuyDListNode(DataType data)
{
    DListNode* pNewNode=(DListNode*)malloc(sizeof(DListNode));
    if(pNewNode==NULL)
    {
        exit(1);
    }
    pNewNode->pNext=NULL;
    pNewNode->pPre=NULL;
    pNewNode->data=data;
    return pNewNode;
}
/*打印链表*/
void Print(DList* plist)
{
    assert(plist!=NULL);
    DListNode* pCur=plist->pHead->pNext;
    while(pCur!=plist->pHead)
    {
         printf("%d->",pCur->data);
         pCur=pCur->pNext;
    }
    printf("NULLL\n");
}
/*初始化*/
void ListInit(DList* plist)
{
    assert(plist);
    plist->pHead=BuyDListNode(0);
    plist->pHead->pNext=plist->pHead;
    plist->pHead->pPre=plist->pHead;
}
/*尾插*/    
void ListPushBack(DList* plist,DataType data)
{
    assert(plist!=NULL);
    DListNode* pCur=plist->pHead->pNext;
    DListNode* pNewNode=BuyDListNode(data);
    while(pCur->pNext!=plist->pHead)
    {
        pCur=pCur->pNext;
    }
    pCur->pNext=pNewNode;
    pNewNode->pNext=plist->pHead;
    pNewNode->pPre=pCur;
    plist->pHead->pPre=pNewNode;
}
/*销毁链表*/
void ListDestory(DList* plist)
{
    DListNode* pDel=plist->pHead->pNext;
    while(pDel!=plist->pHead)
    {
        plist->pHead->pNext=pDel->pNext;
        free(pDel);
        pDel=plist->pHead->pNext;
    }
    free(plist->pHead);
}
