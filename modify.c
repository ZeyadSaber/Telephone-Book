#include <stdlib.h>
#include <stdio.h>
#include "declare.h"
#include "string.h"



void modify(contact* x, int i)
{
    int k,choice=0;
    char s[20];
    printf("Enter last name of contact to be modified: ");
    scanf("%s",s);
    for(k=0; k<i; k++)
    {
        if(!strcasecmp(x[k].lname,s))
        {
            printf("%s %s",x[k].lname,x[k].fname);
            printf(", %d-%d-%d",x[k].bday.day,x[k].bday.month,x[k].bday.year);
            printf(", %s",x[k].add);
            printf(", %s",x[k].email);
            printf(", %s\n",x[k].num);
            printf("\nIs this the contact you want to modify?\n");
            printf("1- YES \t2- NO(look for another contact)\n");
            scanf("%d",&choice);
            while(choice!=1 && choice!=2)
            {
                printf("Unknown command\nPlease enter 1 to modify or 2 to search for another contact\n");
                scanf("%d",&choice);
            }
        }
        if(choice==1)
            break;
    }
    if(k<i)
    {
        int c=0;
        printf("Enter new last name: ");
        getchar();
        scanf("%[^\n]s",x[k].lname);
        printf("\nEnter new contact's first name: ");
        getchar();
        scanf("%[^\n]s",x[k].fname);
        printf("Do you want to modify birth date?\n1- Yes \t2- No\n");
        scanf("%d",&c);
        while(c!=1 && c!=2)
        {
            printf("Unknown command\nPlease enter 1 to delete or 2 to search for another contact\n");
            scanf("%d",&c);
        }
        if(c==1)
        {
            printf("\nEnter new contact's birth date: ");
            printf("\nDay: ");
            scanf("%d",&x[k].bday.day);
            while(x[k].bday.day > 31 || x[k].bday.day<1 )
            {
                printf("Invalid birth Day");
                printf("\nDay: ");
                scanf("%d",&x[k].bday.day);
            }
            printf("\nMonth: ");
            scanf("%d",&x[k].bday.month);
            while(x[k].bday.month>12||x[k].bday.month<1)
            {
                printf("Invalid birth month");
                printf("\nMonth: ");
                scanf("%d",&x[k].bday.month);
            }
            printf("\nYear: ");
            scanf("%d",&x[k].bday.year);
            while(x[k].bday.year>2012)
            {
                printf("Invalid birth year");
                printf("\nYear: ");
                scanf("%d",&x[k].bday.year);
            }
        }
        c=0;
        printf("\nEnter new contact's address: ");
        getchar(); // clear the buffer
        scanf("%[^\n]s",x[k].add);
        getchar(); // clear the buffer
        printf("Do you want to modify e-mail address?\n1- Yes \t2- No\n");
        scanf("%d",&c);
        while(c!=1 && c!=2)
        {
            printf("Unknown command\nPlease enter 1 to delete or 2 to search for another contact\n");
            scanf("%d",&c);
        }
        if(c==1)
        {
            printf("\nEnter new contact's email: ");
            scanf("%s",x[k].email);
            while(!isValid(x[k].email))
            {
                printf("Invalid Email");
                printf("\nEnter new contact's email: ");
                scanf("%s",x[k].email);
            }
        }
        c=0;
        getchar();
        printf("Do you want to modify Mobile Number?\n1- Yes \t2- No\n");
        scanf("%d",&c);
        while(c!=1 && c!=2)
        {
            printf("Unknown command\nPlease enter 1 to delete or 2 to search for another contact\n");
            scanf("%d",&c);
        }
        if(c==1)
        {
            printf("\nEnter new contact's number: ");
            scanf("%[^\n]s",x[k].num);
            while(!NumValid(x[k].num))
            {
                printf("Invalid Number");
                printf("\nEnter new contact's number: ");
                scanf("%s",x[k].num);
            }
        }
        printf("\n\nContact modified successfully !");
    }
    else
        printf("No Contact found\n");
}
