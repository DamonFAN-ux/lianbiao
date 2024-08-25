#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist();
struct ListNode *deleteeven( struct ListNode *head );
void printlist( struct ListNode *head )
{
     struct ListNode *p = head;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode *head;

    head = createlist();
    head = deleteeven(head);
    printlist(head);

    return 0;
}
struct ListNode *createlist()
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
        scanf("%d",&Pt->data);
        if(Pt->data==-1)
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
struct ListNode *deleteeven( struct ListNode *head )
{
    struct ListNode*head1=NULL,*Pt=head;
    struct ListNode*Ot=head1,*preOt=NULL;
    if(head==NULL)
        return head;
    while(Pt!=NULL)
    {
        int num=Pt->data;
        if(num%2==0)
        {
           Ot=(struct ListNode*)malloc(sizeof(struct ListNode));
           Ot->data=num;
           Ot->next=NULL;
           if(head1==NULL)
           {
               head1=Ot;
               preOt=Ot;
           }
            else
            {
                preOt->next=Ot;
                preOt=Ot;
            }
        }
        Pt=Pt->next;
    }
    return head1;
}