#include "head.h"

int main()
{
    DList* plist;
    ListInit(&plist);
    ListPushBack(&plist,1);
    ListPushBack(&plist,2);
    ListPushBack(&plist,3);
    Print(&plist); 
   // ListPopBack(&plist);
  //ListDestory(&plist);
   // Print(&plist); 
   // ListPushFront(&plist,9);
   // ListPopFront(&plist);
   // Print(ListFind(&plist,2));
    printf("%d",ListFind(&plist,2)->data);
    ListInsert(&plist,2,8);
   // Print(&plist); 
    return 0;
}
