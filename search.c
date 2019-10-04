#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "declare.h"

void search( contact* x,int cnt)
{
    char s[25];
    int i=0,found=0;
    printf("Enter the last name of contact you are searching for: ");
    scanf("%s",s);

    for(i=0;i<cnt;i++)
    {
        if(!strcasecmp(x[i].lname,s))
        {
            printf("Last name: %s\nFirst name: %s\n",x[i].lname,x[i].fname);
            printf("Birth date: %d-%d-%d\n",x[i].bday.day,x[i].bday.month,x[i].bday.year);
            printf("Address: %s\n",x[i].add);
            printf("City: %s\n",x[i].email);
            printf("Number: %s\n\n",x[i].num);
            found = 1;
        }
    }

    if(!found)
        printf("No Contact Found\n");
}
