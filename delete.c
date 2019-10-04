#include <stdlib.h>
#include <stdio.h>
#include "declare.h"
#include "string.h"

int DELETE(contact* x,int idx)
{
    char ln[20],fn[20];
    int i,k,empty=0 ;
    printf("Enter contact to be deleted last name: ");
    scanf("%s",ln);
    getchar();
    printf("\nEnter contact to be deleted first name: ");
    scanf("%s",fn);
    for(i=0;i<idx;i++)
    {
        if(!strcasecmp(x[i].lname,ln)&&!strcasecmp(x[i].fname, fn))
        {
            printf("Are you sure you want to delete the following contact?\n1- Yes \t2- No(search for another contact)\n\n");
            printf("Last name: %s\nFirst name: %s\n",x[i].lname,x[i].fname);
            printf("Birth date: %d-%d-%d\n",x[i].bday.day,x[i].bday.month,x[i].bday.year);
            printf("Address: %s\n",x[i].add);
            printf("City: %s\n",x[i].email);
            printf("Number: %s\n\n",x[i].num);
            scanf("%d",&empty);
            while(empty!=1 && empty!=2)
            {
                printf("Unknown command\nPlease enter 1 to delete or 2 to search for another contact\n");
                scanf("%d",&empty);
            }
            if(empty==1)
                break;
        }
    }
    if(i==idx){
        printf("Contact entered is not found\n");
        return 0;
    }
    else{
        for(k=i;k<idx-1;k++)
            x[k]=x[k+1];
        printf("Contact deleted !");
        return 1;
    }
}
