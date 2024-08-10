#include<stdio.h>
#include<stdlib.h>
typedef struct student{
    int num;
    int score;
    struct student*next;
}stu;
stu*Creat();
stu*Insert(stu*head,stu*p);
stu*Sort(stu*head);
stu*Combine(stu*head1,stu*head2);
void Print(stu*head);
int main()
{
    stu*head1=NULL,*head2=NULL;
    head1=Creat();
    printf("创建成功,a链表为:\n");
    Print(head1);
    head2=Creat();
    printf("创建成功,b链表为:\n");
    Print(head2);
    head1=Combine(head1,head2);
    printf("合并成功,合并后的链表为:\n");
    Print(head1);
    head1=Sort(head1);
    printf("最终排序后的合并链表为:\n");
    Print(head1);
    return 0;
}
stu*Creat()
{
    stu*head=NULL,*Pt=head,*prePt=NULL;
    while(1)
    {
        Pt=(stu*)malloc(sizeof(stu));
        if(Pt==NULL)
        {
            printf("分配内存失败!\n");
            exit(1);
        }
        printf("请输入学生的学号和成绩,当输入0结束:\n");
        scanf("%d %d",&Pt->num,&Pt->score);
        if(Pt->num==0&&Pt->score==0)
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
stu*Insert(stu*head,stu*p)
{
    stu*Pt=head,*prePt=NULL;
    if(head==NULL||p->num<=head->num)
    {
        p->next=head;
        head=p;
        return head;
    }
    while(Pt!=NULL&&p->num>Pt->num)
    {
        prePt=Pt;
        Pt=Pt->next;
    }
    prePt->next=p;
    p->next=Pt;
    if(Pt!=NULL&&p->num==Pt->num)
    {
        if(p->score>Pt->score)
        {
            stu*proPt=Pt->next;
            Pt->next=p;
            p->next=proPt;
        }
    }
    return head;
}
stu*Sort(stu*head)
{
    stu*Pt=head,*tmp=NULL,*head1=NULL;
    while(Pt!=NULL)
    {
        tmp=Pt->next;
        head1=Insert(head1,Pt);
        Pt=tmp;
    }
    return head1;
}
stu*Combine(stu*head1,stu*head2)
{
    stu*Pt=head1;
    if(head1==NULL)
    return head2;
    while(Pt->next!=NULL)
    {
        Pt=Pt->next;
    }
    Pt->next=head2;
    return head1;
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
