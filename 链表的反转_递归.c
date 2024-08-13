#include<stdio.h>
#include<stdlib.h>
#define N 5
typedef struct link{
    int data;
    struct link*next;
}LINK;
LINK*Creat();
LINK*Creatsentinel();
LINK*ReverseList(LINK*head);
void Print(LINK*head);
int main()
{
 LINK*head;
 head=Creat(head);
 printf("创建链表成功，输出如下：\n");
 Print(head);
 head=ReverseList(head);
 printf("反转成功，输出如下：\n");
 Print(head);
 return 0;
}
LINK*Creat()
{
    LINK*head=NULL,*Pt=head,*prePt=NULL;
    int n=N,i;
    for(i=0;i<N;i++)
    {
        Pt=(LINK*)malloc(sizeof(LINK));
        if(Pt==NULL)
        {
            printf("分配内存失败！\n");
            exit(1);
        }
        printf("请输入链表的值：\n");
        scanf("%d",&Pt->data);
         Pt->next=NULL;
        if(head==0)
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
LINK*ReverseList(LINK* head) 
{
    LINK* prev = NULL;
    LINK* curr = head;
    while (curr != NULL) {
        LINK* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}
void Print(LINK*head)
{
    LINK*Pt=head;
    while(Pt!=NULL)
    {
        printf("%d\n",Pt->data);
        Pt=Pt->next;
    }
}
