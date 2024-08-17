#include<stdio.h>
#include<stdlib.h>
typedef struct students{
    int num;
    int score;
    struct students*next;
}stu;
stu*Creat();
stu*Insert(stu*head,stu*p,int num);
stu*Del(stu*head,int num);
stu*Search(stu*head,int num);
stu*Change(stu*head,stu*p,int num);
void Print(stu*head);
int main()
{
    stu*head=NULL,*Pt=head;
    stu*p=NULL,*q=NULL;
    int m,n,i,j;
    head=Creat();
    if(head==0)
    {
        printf("创建失败！\n");
        return 0;
    }
    printf("创建链表成功，其值如下：\n");
    Print(head);
    p = (stu*)malloc(sizeof(stu));  // 分配内存
    if (p == NULL)
     {
        printf("内存分配失败\n");
        return 1;
    }
    printf("请输入需要插入的结点内容：\n");
    scanf("%d %d",&p->num,&p->score);
    printf("请输入需要插入的位置（学号）：\n");
    scanf("%d",&n);
    head=Insert(head,p,n);
    if(head==NULL)
    {
        printf("此结点不存在：\n");
    }
    else
    {
        printf("插入后的链表的值为：\n");
        Print(head);
    }
    printf("请输入想要删除的结点学号：\n");
    scanf("%d",&m);
    head=Del(head,m);
    if(head==NULL)
    {
        printf("此结点不存在：\n");
    }
    else
    {
    printf("删除后的链表的值为：\n");
    Print(head);
    }
     q = (stu*)malloc(sizeof(stu));  // 分配内存
    if (q == NULL) 
    {
        printf("内存分配失败\n");
        return 1;
    }
    printf("请输入需要修改的结点的学号：\n");
    scanf("%d",&i);
    printf("请输入需要修改的结点的值：\n");
    scanf("%d %d",&q->num,&q->score);
    head=Change(head,q,i);
    if(head==NULL)
    {
        printf("此结点不存在：\n");
    }
    else
    {
    printf("修改后链表的值为：\n");
    Print(head);
    }
    printf("请输入需要查找的结点学号：\n");
    scanf("%d",&j);
    Pt=Search(head,j);
    if(Pt==NULL)
    {
        printf("此结点不存在：\n");
    }
    else
    {
    printf("查找的值为：\n");
    printf("%d %d\n",Pt->num,Pt->score);
    }
    return 0;
}
stu*Creat()
{
    stu*head=NULL,*Pt=head,*prePt=NULL;
    char ch;
    while(1)
    {
        Pt=(stu*)malloc(sizeof(stu));
        if(Pt==NULL)
        {
            printf("分配内存失败：\n");
            exit(1);
        }
        printf("请输入学号和成绩：\n");
        scanf("%d %d",&Pt->num,&Pt->score);
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
        printf("输入字符Y继续创建,否则停止创建：\n");
        getchar();
        scanf("%c",&ch);
        if(ch!='Y')
        {
         printf("创建结束：\n");
         break;
        }
    }
    return head;
}
stu* Search(stu*head,int num)
{
 stu*Pt=head;
 while(Pt!=NULL)
 {
    if(num==Pt->num)
    {
        printf("该结点查找成功！\n");
        break;
    }
    Pt=Pt->next;
 }
    return Pt;
}

stu*Insert(stu*head,stu*p,int num)
{
    stu*Pt=head,*prePt=NULL,*proPt=NULL;
    Pt=Search(head,num);
    if(num==-1)
    {
        p->next=head;
        head=p;
        return head;
    }
    if(Pt==NULL)
    return NULL;
    else
    {
     proPt=Pt->next;
     Pt->next=p;
     p->next=proPt;
    }
    return head;
}
stu*Del(stu*head,int num)
{
    stu*Pt=head,*prePt=NULL;
    while(Pt!=NULL)
    {
        if(num==Pt->num)
        {
         break;
        }
        prePt=Pt;
        Pt=Pt->next;
    }
    if(Pt==NULL)
    return NULL;
    else
    {
        if(Pt==head)
        {
            head=Pt->next;
            free(Pt);
        }
        else
        {
            prePt->next=Pt->next;
            free(Pt);
        }
    }
    return head;
}
stu*Change(stu*head,stu*p,int num)
{
    stu*Pt=head,*prePt=NULL;
    Pt=Search(head,num);
    if(Pt==NULL)
    return NULL;
    else
    {
        Pt->num=p->num;
        Pt->score=p->score;
    }
    return head;
}
void Print(stu*head)
{
    stu*Pt=head;
    while(Pt!=NULL)
    {
        printf("%d %d\n",Pt->num,Pt->score);
        Pt=Pt->next;
    }
}
