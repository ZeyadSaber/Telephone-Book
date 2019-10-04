#include <stdlib.h>
#include <stdio.h>
#include "declare.h"
#include "string.h"

contact c;

void bubbleSort(contact* x, int i)
{
    int j,k;
    int sorted;
    for(j=0; j<i-1; j++)
    {
        sorted=0;
        for(k=0; k<i-j-1; k++)
        {
            if(strcasecmp(x[k].lname,x[k+1].lname)==1)
            {
                c=x[k];
                x[k]=x[k+1];
                x[k+1]=c;
                sorted = 1;
            }
            else if(!strcasecmp(x[k].lname,x[k+1].lname))
            {
                if(strcasecmp(x[k].fname,x[k+1].fname)==1)
                {
                    c=x[k];
                    x[k]=x[k+1];
                    x[k+1]=c;
                    sorted = 1;
                }
                else if(!strcasecmp(x[k].fname,x[k+1].fname))
                {
                    if(strcasecmp(x[k].num,x[k+1].num)==1)
                    {
                        c=x[k];
                        x[k]=x[k+1];
                        x[k+1]=c;
                        sorted = 1;
                    }
                }
            }
        }
        if(!sorted)
            break;
    }
    for(j=0; j<i; j++)
    {
        printf("Last name: %s\nFirst name: %s\n",x[j].lname,x[j].fname);
        printf("Birth date: %d-%d-%d\n",x[j].bday.day,x[j].bday.month,x[j].bday.year);
        printf("Address: %s\n",x[j].add);
        printf("E-mail: %s\n",x[j].email);
        printf("Number: %s\n\n",x[j].num);
    }
}
