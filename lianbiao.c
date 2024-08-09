#include<stdio.h>
#include<stdlib.h>
typedef struct student{
  int num;
  int score;
  struct student*next;
}stu;
stu*Creat();
stu*Insert(stu*head, stu*p);
stu*Sort(stu*head);
stu*Del(stu*head);
void Print(stu*head);
int main()
{
  stu*head=NULL,*Pt,*prePt=NULL;
  Pt=head;
  head=Creat();
  if (head == NULL) 
  {
   printf("链表为空!\n");
   return 0;
  }
  head=Sort(head);
  head=Del(head);
  Print(head);
  return 0;
}
stu*Creat()
{
 stu*head=NULL,*Pt,*prePt;
 Pt=prePt=NULL;
 while(1)
 {
  Pt=(stu*)malloc(sizeof(stu));
  if(Pt==NULL)
  {
    printf("分配内存失败!\n");
    exit(1);
  }
  scanf("%d %d",&Pt->num,&Pt->score);
  if(Pt->num==0&&Pt->score==0)
  break;
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
 Pt->next=NULL;
 return head;
}
stu*Insert(stu*head, stu*p)
{
  stu*Pt,*prePt;
  Pt=head;
  prePt=NULL;
  if(head==NULL||p->num<head->num)
  {
    p->next=head;
    head=p;
    return head;
  }
  while(Pt!=NULL&&Pt->num < p->num)
  {
    prePt=Pt;
    Pt=Pt->next;
  }
  prePt->next=p;
  p->next=Pt;
  return head;
}
stu*Sort(stu*head)
{
  stu*Pt,*tmp;
  stu*head1=NULL;
  Pt=head;
  while(Pt!=NULL)
  {
      tmp=Pt->next;
      head1=Insert(head1,Pt);   
      Pt=tmp;
  }
  return head1;
}
void Print(stu*head)
{
  stu*Pt,*prePt;
  Pt=head;
  while(Pt!=NULL)
  {
    printf("%d %d\n",Pt->num,Pt->score);
    Pt=Pt->next;
  }
}
stu*Del(stu*head)
{
  stu*Pt,*prePt=NULL;
  Pt=head;
  if(head==NULL)
  {
    return NULL;
  }
  while(Pt!=NULL&&Pt->next!=NULL)
  {
    stu*tmp=Pt->next;
  if(Pt->num==tmp->num)
  {
    if(Pt->score>=tmp->score)
    {
      Pt->next=tmp->next;
      free(tmp);
    }
    else
    {
      if(prePt==NULL)
      {
        head=tmp;
      }
      else
      {
        prePt->next=tmp;
      }
      free(Pt);
      Pt=tmp;
    }
  }
  else
  {
    prePt=Pt;
    Pt=Pt->next;
  }
  }
  return head;
  }
