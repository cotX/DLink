#include "head.h"

int main()
{
    DList* plist;
    ListInit(&plist);
    ListPushBack(&plist,1);
    ListPushBack(&plist,2);
    ListPushBack(&plist,3);
    Print(&plist); 
    ListDestory(&plist);
    Print(&plist); 
    return 0;
}
