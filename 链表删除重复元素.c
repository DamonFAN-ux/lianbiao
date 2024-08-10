#include<stdio.h>
typedef struct student{
    int num;
    char name[10];
    struct student*next;
}stu;
stu*Del(stu*x,stu*y);
void Print(stu*x);
int main()
{
    stu a[4]={{101,"Wang"},{102,"Li"},{105,"Zhang"},{106,"Wei"}}; 
    stu b[5]={{103,"Zhang"},{104,"Ma"},{105,"Chen"},{107,"Guo"},{108,"lui"}};
    printf("List a:\n");
    int i;
    stu*head1=NULL,*Pt1;
    head1=&a[0];
    Pt1=head1;
    for(i=0;i<3;i++)
    {
     Pt1->next=&a[i+1];
     if(i<=2)
     {
     Pt1=Pt1->next;
     }
    }
    Pt1->next=NULL;
    Print(head1);
    printf("List b:\n");
    int j;
    stu*head2=NULL,*Pt2;
    head2=&b[0];
    Pt2=head2;
    for(j=0;j<4;j++)
    {
     Pt2->next=&b[j+1];
     if(j<=3)
     {
     Pt2=Pt2->next;
     }
    }
    Pt2->next=NULL;
    Print(head2);
    head1=Del(head1,head2);
    printf("The result is:\n");
    Print(head1);
    return 0;
}
stu*Del(stu*x,stu*y)
{
    stu*Pt=x,*prePt=NULL;
    stu*Ot=y,*preOt=NULL;
    while(Pt!=NULL)
    {   
        Ot=y;
        while(Ot!=NULL)
        {
            if(Pt->num==Ot->num)
            break;
            Ot=Ot->next;
        }
        if(Ot!=NULL&&Pt->num==Ot->num)
        {
            if(Pt==x)
            {
            x=Pt->next;
            Pt=x;
            }
            else
            {
                prePt->next=Pt->next;
                Pt=Pt->next;
            }

        }
        else
        {
            prePt=Pt;
            Pt=Pt->next;
        }
    }
    return x;
}
void Print(stu*x)
{
    stu*Pt=x;
    while(Pt!=NULL)
    {
        printf("%d %s\n",Pt->num,Pt->name);
        Pt=Pt->next;
    }
}
