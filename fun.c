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
/*尾删*/
void ListPopBack(DList* plist)
{
    DListNode* pCur=plist->pHead;
    while(plist->pHead!=pCur->pNext->pNext)
    {
        pCur=pCur->pNext;
    }
    DListNode* pDel=pCur->pNext;
    pCur->pNext=plist->pHead;
    plist->pHead->pPre=pCur;
    free(pDel);
}
/*头插*/
void ListPushFront(DList* plist,DataType data)
{
    assert(plist!=NULL);
    DListNode* pCur=plist->pHead;
    DListNode* pNewNode=BuyDListNode(data);
    pNewNode->pNext=pCur->pNext;
    pCur->pNext->pPre=pNewNode;
    pCur->pNext=pNewNode;
    pNewNode->pPre=pCur;
}
/*头删*/
void ListPopFront(DList* plist)
{
    assert(plist!=NULL);
    DListNode* pCur=plist->pHead->pNext;
    pCur->pNext->pPre=plist->pHead;
    plist->pHead->pNext=pCur->pNext;
    free(pCur);
}
/*查找值为data的第一个节点*/
DListNode* ListFind(DList* plist,DataType data )
{
    assert(plist!=NULL);
    DListNode* pCur=plist->pHead->pNext;
    while(plist->pHead!=pCur)
    {
         if(data==pCur->data)
             return(pCur);
        pCur=pCur->pNext;
    }
    return NULL;
}
/*找出pos位置上的节点地址*/
DListNode* find_pos(DList* plist, int pos)
{
    DListNode* pCur=plist->pHead->pNext;
    while(--pos)
    {
        pCur=pCur->pNext;
    }
    return pCur;
}
/*在pos前面插入*/
void ListInsert(DList* plist,int pos, DataType data)
{
    DListNode* pCur=find_pos(plist,pos);
    DListNode* pNewNode=BuyDListNode(data);
    pNewNode->pNext=pCur;
    pNewNode->pPre=pCur->pPre;
    pCur->pPre->pNext=pNewNode;
    pCur->pPre=pNewNode;
}
