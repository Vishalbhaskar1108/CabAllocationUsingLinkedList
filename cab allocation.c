#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
struct node
{
    char cabtype[20];
    int status;
    struct node *down;
    struct node *side;
};
struct node *head=NULL;
void admin()
{int a1,a3=1,a4=1;
    printf("what do you want to do??(1.insert-2.delete-3.display):    ");
    scanf("%d",&a1);
    if(a1==1)
        while(a3==1)
        {
            insert();
            printf("\ndo you wish to add more??(0/1):   ");
            scanf("%d",&a3);
        }
    else if(a1==2)
        while(a4==1)
        {
            del();
            printf("\n do you want to delete more??(0/1):   ");
            scanf("%d",&a4);
        }
    else if(a1==3)
        display();
    else
    {
        printf("\noption incorrect");
        admin();
    }
    printf("\n");
    mainmenu();
}
void insert()
{int a2;
    struct node *newnode,*temp;
    char tp[10];
    printf("\nIs this type of cab already present??(0/1):   ");
    scanf("%d",&a2);
    if(a2==0)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the type of cab:    ");
        scanf("%s",&newnode->cabtype);
        newnode->status=1;
        newnode->down=NULL;
        newnode->side=NULL;
        if(head==NULL)
        {
            head=newnode;
        }
        else
        {
            temp=head;
            while(temp->down!=NULL)
            {
                temp=temp->down;
            }
            temp->down=newnode;
        }
    }
    else
    {
        printf("\nEnter the cab type:   ");
        scanf("%s",&tp);
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the number of cab of type %s:    ",tp);
        scanf("%s",&newnode->cabtype);
        newnode->status=1;
        newnode->down=NULL;
        newnode->side=NULL;
        temp=head;
        while(strcmp(temp->cabtype,tp)&&temp->down!=NULL)
        {
            temp=temp->down;
        }
        if(strcmp(tp,temp->cabtype))
        {
            printf("\n-x-x-x-x--- cab type not found ---x-x-x-x");
            insert();
        }
        while(temp->side!=NULL)
        {
            temp=temp->side;
        }
        temp->side=newnode;
        }
}
void del()
{
    int a5,a6;
    char a7[20],a8[20];
    struct node *temp1,*temp2,*prev;
    printf("\ndo you wish to delete a single cab or whole cab type:??(1.single cab/2.whole cab type):   ");
    scanf("%d",&a5);
    if(a5==1)
    {
        printf("\nenter the cab type from which you wish to delete:    ");
        scanf("%s",&a8);
        if(head==NULL)
        {
            printf("\n the list is empty!!");
        }
        temp1=head;
        while((strcmp(temp1->cabtype,a8))&&temp1->down!=NULL)
        {
            temp1=temp1->down;
        }
        if(strcmp(temp1->cabtype,a8))
            {printf("\n xxxx cab type not found xxxx");
            del();}
        printf("\nenter the cab no. you wish to delete:    ");
        scanf("%s",&a7);
        temp2=temp1;
        prev=temp1;
        while((strcmp(temp2->cabtype,a7))&&temp2->side!=NULL)
        {
            prev=temp2;
            temp2=temp2->side;
        }
        if(strcmp(temp2->cabtype,a7))
            {printf("\n -x-x- cab not found -x-x-");
            del();}
        else
        {
            prev->side=temp2->side;
            printf("\nthe deleted cab is %s-%s",a8,temp2->cabtype);
        }

    }
    else if(a5==2)
    {
        printf("enter the cabtype you wish to delete??:    ");
        scanf("%s",&a7);
        if(head==NULL)
            printf("\nthe list is empty!!");
        temp1=head;
        prev=head;
        if(!strcmp(a7,head->cabtype))
        {
            printf("\nthe deleted cab type is %s",head->cabtype);
            head=head->down;
            free(temp1);
            return;
        }
        else
        {
            while((strcmp(temp1->cabtype,a7))&&temp1!=NULL)
            {
                prev=temp1;
                temp1=temp1->down;
            }
            prev->down=temp1->down;
            printf("the deleted cab type is %s",temp1->cabtype);
            free(temp1);
        }
    }
}
void display()
{
    struct node *temp2,*temp3;
    temp2=head;
    temp3=head;
    while(temp2!=NULL)
    {
        printf("\n--%s--",temp2->cabtype);
        temp3=temp2->side;
        while(temp2->side!=NULL && temp3!=NULL)
        {
            printf("\t-->%s-(status=%d)",temp3->cabtype,temp3->status);
            temp3=temp3->side;
        }
        temp2=temp2->down;
    }
}
void driver()
{
    int a9,a10=1;
    char carno[20],cabtyp[20];
    struct node *temp5;
    printf("\n-----welcome driver-----");
    printf("\nenter your cab type:");
    scanf("%s",&cabtyp);
    printf("enter your car no.:");
    scanf("%s",&carno);
    temp5=head;
        while(strcmp(cabtyp,temp5->cabtype))
        {
            temp5=temp5->down;
        }
        while(strcmp(carno,temp5->cabtype))
        {
            temp5=temp5->side;
        }
    while(a10>0)
    {printf("\n Are you coming back or leaving??(1.coming back   2.leaving):");
    scanf("%d",&a9);
    if(a9==1)
    {
        temp5->status=1;
        a10=0;
    }
    else if(a9==2)
    {
        temp5->status=0;
        a10=0;
    }
    else
    {
        printf("\n wrong choice");
    }}
    mainmenu();
}
void customer()
{
    char name[20],choice[20];
    int z=1,z1=1,ans1;
    struct node *temp6,*temp7;
    printf("\nenter your name:");
    scanf("%s",&name);
    /*printf("\ncabtype and availabilty:");
    display();*/
    while(z!=0)
    {while(z1!=0)
    {printf("\nenter the cabtype you want to book:");
    scanf("%s",&choice);
    temp6=temp7=head;
    while(strcmp(choice,temp6->cabtype)&&temp6->down!=NULL)
    {
        temp6=temp6->down;
    }
    if(strcmp(choice,temp6->cabtype))
    {
        printf("\n Sorry,cabtype not available!!");
    }
    else
        z1=0;
    }
    temp6=temp6->side;
    while(temp6->status!=1&&temp6->side!=NULL)
    {
        temp6=temp6->side;
    }
    if(temp6->status!=1)
    {
        printf("\nsorry cab not available. Please insert another choice:");
    }
    else
        z=0;
    }
    printf("\nDo you wish to confirm booking?(1.To confirm/0.To exit):");
    scanf("%d",&ans1);
    if(ans1==1)
    {
        temp6->status=0;
        printf("\n-----Booking Confirmed-----");
    }
    mainmenu();


}
void mainmenu()
{int a,w;
char pswd[10];
    printf("\nAre you admin or a driver or a customer(1.admin, 2.driver, 3.customer,4.exit): ");
    scanf("%d",&a);
    switch(a)
    {
    case 1:
        do
        {
            printf("enter password:    ");
            scanf("%s",&pswd);
            if(!strcmp(pswd,"apple"))
            {
                w=1;
                printf("\n-------------Welcome Admin---------------\n\n");
                admin();
            }
            else
            {
                w=0;
                printf("password incorrect(try again)!!");
            }
        }while(w!=1);
        break;
    case 2:
        driver();
        break;
    case 3:
        customer();
        break;
    case 4:
        exit(0);
}
}
main()
{
    mainmenu();
}
