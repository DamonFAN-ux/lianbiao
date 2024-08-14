#include<stdio.h>
#include<stdlib.h>
#define N 5
typedef struct node{
    int data;
    struct node*next;
}NODE;
NODE*Creat();
NODE*Circle(NODE*head,int k);
void Print(NODE*head);
int main()
{
    NODE*head=NULL;
    int k;
    head=Creat();
    if(head==NULL)
    {
        printf("空链表!\n");
        return 0;
    }
    printf("链表创建成功，其值如下：\n");
    Print(head);
    printf("请输入需要循环右移的位数：\n");
    scanf("%d",&k);
    head=Circle(head,k);
    printf("旋转成功，其值如下：\n");
    Print(head);
    return 0;
}
NODE*Creat()
{
    NODE*head=NULL,*Pt=head,*prePt=NULL;
    int n=N,i,j=1;
    for(i=0;i<N;i++,j++)
    {
        Pt=(NODE*)malloc(sizeof(NODE));
        if(Pt==NULL)
        {
            printf("分配内存失败!\n");
            exit(1);
        }
        Pt->data=j;
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
NODE*Circle(NODE*head,int k)
{
    if (head == NULL || head->next == NULL || k == 0)
    return head;
    NODE* old_tail = head;
    int n;
    for (n = 1; old_tail->next != NULL; n++)
    old_tail = old_tail->next;
    old_tail->next = head; // 成环
    NODE* new_tail = head;
    for (int i = 0; i < n - k % n - 1; i++)
    new_tail = new_tail->next;
    NODE* new_head = new_tail->next;
    new_tail->next = NULL;
    return new_head;
}
void Print(NODE*head)
{
    NODE*Pt=head;
    while(Pt!=NULL)
    {
        printf("%d\n",Pt->data);
        Pt=Pt->next;
    }
}