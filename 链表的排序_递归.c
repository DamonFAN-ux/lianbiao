//归并排序（分治算法）
#include<stdio.h>
#include<stdlib.h>
typedef struct list{
    int val;
    struct list*next;
}ListNode;
ListNode*Creat();
ListNode*sortList(ListNode* head);
ListNode*mergeTwoLists(ListNode*l1,ListNode*l2);
void Print(ListNode*head);
int main()
{
    ListNode*head=NULL;
    head=Creat();
    if(head==NULL)
    {
        printf("空链表！\n");
        return 0;
    }
    printf("链表创建成功，输出如下：\n");
    Print(head);
    head=sortList(head);
    printf("运用归并算法后，链表排序成功，结果如下：\n");
    Print(head);
    return 0;
}
ListNode*Creat()
{
    ListNode*head=NULL,*Pt=head,*prePt=NULL;
    while(1)
    {
        Pt=(ListNode*)malloc(sizeof(ListNode));
        if(Pt==NULL)
        {
            printf("内存分配失败！\n");
            exit(1);
        }
        printf("请输入链表的值,输入0结束:\n");
        scanf("%d",&Pt->val);
        if(Pt->val==0)
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
ListNode* sortList(ListNode* head) 
{
    if (head == NULL || head->next == NULL) 
    return head;
    ListNode* slow = head, *fast = head, *prev = NULL;
    while (fast != NULL && fast->next != NULL) 
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL; // 断开链表
    ListNode* l1 = sortList(head);
    ListNode* l2 = sortList(slow);
    return mergeTwoLists(l1, l2);
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    if (l1->val < l2->val) 
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } 
    else 
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}
void Print(ListNode*head)
{
    ListNode*Pt=head;
    while(Pt!=NULL)
    {
        printf("%d\n",Pt->val);
        Pt=Pt->next;
    }
}
