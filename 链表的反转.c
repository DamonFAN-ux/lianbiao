//运用尾插法和头插法
#include<stdio.h>
#include<stdlib.h>
#define N 5
typedef struct link{
    int data;
    struct link*next;
}LINK;
LINK*Hcreat();
LINK*Tcreat();
void Listsave(LINK*head);
void Listprint(LINK*head);
int E[N];
int main()
{
  LINK*head=NULL;
  head=Tcreat();
  if(head==NULL)
  {
    printf("创建链表为空：\n");
    return 0;
  }
  printf("链表创建成功，输出如下：\n");
  Listprint(head);
  Listsave(head);
  head=Hcreat();
  printf("链表反转成功，输出如下：\n");
  Listprint(head);
  return 0;
}
LINK*Tcreat()
{
 LINK*head=NULL,*Pt=head,*prePt=NULL;
 int i,n=N;
 for(i=0;i<n;i++)
 {
    Pt=(LINK*)malloc(sizeof(LINK));
    if(Pt==NULL)
    {
        printf("分配内存失败：\n");
        exit(1);
    }
    printf("请输入链表的值：\n");
    scanf("%d",&Pt->data);
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
void Listsave(LINK*head)
{
 LINK*Pt=head;
 int i,n=N;
    for(i=0;i<n;i++)
    {
        E[i]=Pt->data;
        Pt=Pt->next;
    }
}
LINK*Hcreat()
{
 LINK*head=NULL,*Pt=head,*prePt=NULL;
 int i,n=N;
 for(i=0;i<n;i++)
 {
    Pt=(LINK*)malloc(sizeof(LINK));
    if(Pt==NULL)
    {
        printf("分配内存失败：\n");
        exit(1);
    }
    Pt->data=E[i];
    Pt->next=head;
    head=Pt;
 }
return head;
}
void Listprint(LINK*head)
{
    LINK*Pt=head;
    while(Pt!=NULL)
    {
        printf("%d\n",Pt->data);
        Pt=Pt->next;
    }
}

