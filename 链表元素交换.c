#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int num;
    struct node*next;
}NODE;
NODE*Creat();
NODE*Creatsentinel();
NODE*Swap(NODE*head,int p1,int p2);
void Print(NODE*head);
int main()
{
    int p1,p2;
    NODE*head=NULL;
    head=Creat();
    if(head==NULL)
    {
        printf("创建失败！\n");
        return 0;
    }
    printf("创建链表成功，链表为：\n");
    Print(head);
    printf("请输入想要进行交换的两个结点值：\n");
    scanf("%d %d",&p1,&p2);
    head=Swap(head,p1,p2);
    printf("最终交换后的链表为：\n");
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
            printf("分配内存失败！\n");
            exit(1);
        }
        printf("请输入链表的各个值,各不相同并且到0结束:\n");
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
    // 分配内存并初始化哨兵节点
    NODE*sentinel = (NODE*)malloc(sizeof(NODE));
    if (sentinel==NULL) {
        printf("分配内存失败\n");
        exit(1);
    }
    sentinel->num = -1;  // 可以用一个特殊的值，如 -1，表示哨兵节点
    sentinel->next = NULL;
    return sentinel;
}
NODE*Swap(NODE*head, int p1, int p2)
{
    if (head == NULL || p1 == p2)//一种特殊情况：为空链表或者所需交换的两个值相同
        return head;
    NODE*sentinel=Creatsentinel();
    sentinel->next = head;
    NODE*Pt=NULL,*Ot=NULL,*prePt=NULL,*Cur=sentinel;//指向第一个值
    while (Cur->next != NULL)
    {
        if (Cur->next->num == p1 || Cur->next->num == p2)
        {
            if (Pt == NULL )
            {
                Pt = Cur->next;
                prePt = Cur;//更新prePt的位置
            }
            else
            {
                NODE*proOt = Cur->next->next;//指向第二个值的后一个节点
                Ot= Cur->next;
                prePt->next =Ot;
                if (Pt == Cur)//如果p1和p2相邻
                {
                    Ot->next = Pt;
                    Pt->next = proOt;
                }
                else
                {
                    Ot->next = Pt->next;
                    Pt->next = proOt;
                    Cur->next = Pt;
                }

            }
        }
        Cur = Cur->next;
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