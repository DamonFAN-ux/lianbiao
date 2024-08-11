//这个方法与合并数组方法相同，优点在于用了哨兵位，简化算法
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int num;
    struct node*next;
}NODE;
NODE*Creat();
NODE*Creatsentinel();
NODE*Combine(NODE*head1,NODE*head2);
void Print(NODE*head);
int main()
{
    NODE*head1=NULL,*head2=NULL,*head=NULL;
    head1=Creat();
    if (head1 == NULL) //避免为空链表；
   {
    printf("链表为空!\n");
    return 0;
   }
    printf("创建成功,a链表为:\n");
    Print(head1);
    head2=Creat();
       if (head2 == NULL) //避免为空链表；
   {
    printf("链表为空!\n");
    return 0;
   }
    printf("创建成功,b链表为:\n");
    Print(head2);
    head=Combine(head1,head2);
    printf("合并成功,合并后的链表为:\n");
    Print(head);
    return 0;
}
NODE*Creat()
{
    NODE*head=NULL,*Pt=head,*prePt=NULL;
    while(1)
    {
        Pt=(NODE*)malloc(sizeof(NODE));
        if(Pt==NULL)
        {
            printf("分配内存失败!\n");
            exit(1);
        }
        printf("请输入链表中的值,当输入0结束:\n");
        scanf("%d",&Pt->num);
        if(Pt->num==0)
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
NODE*Creatsentinel()
{
    NODE*sentinel=(NODE*)malloc(sizeof(NODE));
      if (sentinel==NULL) {
        printf("分配内存失败\n");
        exit(1);
    }
    sentinel->num = -1;  // 可以用一个特殊的值，如 -1，表示哨兵节点
    sentinel->next = NULL;
    return sentinel;
}
NODE*Combine(NODE*head1, NODE*head2)
{
    NODE*head=(NODE*)malloc(sizeof(NODE));
    if(head1== NULL) return head2;
    if(head2== NULL) return head1;
    NODE*sentinel=Creatsentinel();
    sentinel->next = head;
    NODE* Cur = sentinel;
    while(head1!=NULL&& head2!=NULL)//讨论两者都不为空链表的情况
    {
        if(head1->num < head2->num)
        {
            Cur->next = head1;
            head1= head1->next;
            Cur= Cur->next;
        }
        else
        {
            Cur->next = head2;
            head2 = head2->next;
            Cur= Cur->next;
        }
    }
    if(head1!=NULL)
    {
        Cur->next = head1;
    }
    if(head2!=NULL)
    {
        Cur->next = head2;
    }
    NODE*newhead=sentinel->next;
    free(sentinel);
    return newhead;
}
void Print(NODE*head)
{
    NODE*Pt=head;
    while(Pt!=NULL)
    {
        printf("%d\n",Pt->num);
        Pt=Pt->next;
    }
}

   
