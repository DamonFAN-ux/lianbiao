#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ListNode {
    char code[8];
    struct ListNode *next;
};
struct ListNode *createlist(); 
int countcs( struct ListNode *head );
int main()
{
    struct ListNode  *head;
    head = createlist();
    printf("%d\n", countcs(head));
    free(head);
    return 0;
}
struct ListNode*createlist()
{
    struct ListNode*head=NULL,*Pt=head,*prePt=NULL;
    while(1)
  {
    Pt=(struct ListNode*)malloc(sizeof(struct ListNode));
    if(Pt==NULL)
    {
        printf("分配内存失败！\n");
        exit(1);
    }
    scanf("%s",Pt->code);
    if(Pt->code[0]=='#')
    {
        free(Pt);
        break;
    }
    Pt->next=NULL;
    if(head==NULL)
    {
        head=Pt;
        prePt=Pt;
    }
    else
    {
        prePt->next=Pt;
        prePt=Pt;
    }
  }
    return head;
}
int countcs( struct ListNode *head )
{
    struct ListNode*Pt=head;
    int cnt=0;
    while(Pt!=NULL)
    {
        if(Pt->code[1]=='0'&&Pt->code[2]=='2')
        {
            cnt++;
        }
        Pt=Pt->next;
    }
    return cnt;
}
