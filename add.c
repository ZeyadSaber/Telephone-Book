#include <stdlib.h>
#include <stdio.h>
#include "declare.h"
#include "string.h"

int NumValid(char *n)
{
    int i;
    for(i=0; n[i]; i++)
    {
        if(n[i]>57 || n[i]<48) //check if the entered element in the string is number (ASCII code of numbers 0~9 is 48~57)
            return 0;
    }
    return 1;
}
int isValid (char s[])
{
    char *p1,*p,p2[15],p3[10];
    int i,j,k;
    for(p1=s; *p1; p1++)
    {
        if(*p1=='@')
        {
            i=p1-s;
            break;
        }
    }
    if(!i)
        return 0;
    for(j=0,k=0; *(p1+1); j++)
    {
        p2[j]=*(p1+1);
        p1++;
        if(p2[j]=='.')
            p=&p2[j];
    }
    p2[j]='\0';
    if(!strcasecmp(p2,".com"))
        return 0;
    for(k=0; *p; k++)
    {
        p3[k]=*p;
        p++;
    }
    p3[k]='\0';
    if(strcasecmp(p3,".com"))
        return 0;
    return 1;
}

void ADD( contact* x,int i)
{

    printf("Enter new contact's last name: ");
    scanf("%s",x[i].lname);
    getchar();
    printf("\nEnter new contact's first name: ");
    scanf("%[^\n]s",x[i].fname);
    printf("\nEnter new contact's birth date: ");
    printf("\nDay: ");
    scanf("%d",&x[i].bday.day);
    while(x[i].bday.day > 31 || x[i].bday.day<1 )
    {
        printf("Invalid birth Day");
        printf("\nDay: ");
        scanf("%d",&x[i].bday.day);
    }
    printf("\nMonth: ");
    scanf("%d",&x[i].bday.month);
    while(x[i].bday.month>12||x[i].bday.month<1)
    {
        printf("Invalid birth month");
        printf("\nMonth: ");
        scanf("%d",&x[i].bday.month);
    }
    printf("\nYear: ");
    scanf("%d",&x[i].bday.year);
    while(x[i].bday.year>2012)
    {
        printf("Invalid birth year");
        printf("\nYear: ");
        scanf("%d",&x[i].bday.year);
    }
    getchar(); // clear the buffer
    printf("\nEnter new contact's address: ");
    scanf("%[^\n]s",x[i].add);
    getchar();
    printf("\nEnter new contact's email: ");
    scanf("%s",x[i].email);
    while(!isValid(x[i].email))
    {
        printf("Invalid Email");
        printf("\nEnter new contact's email: ");
        scanf("%s",x[i].email);
    }
    printf("\nEnter new contact's number: ");
    scanf("%s",x[i].num);
    while(!NumValid(x[i].num))
    {
        printf("Invalid Number");
        printf("\nEnter new contact's number: ");
        scanf("%s",x[i].num);
    }
    printf("\n\nContact added successfully !");
}
