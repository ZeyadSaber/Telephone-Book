#include <stdlib.h>
#include <stdio.h>
#include "declare.h"

int SAVE(contact* x,int cnt)
{
    int j;
    FILE* f = fopen("directory.txt","w");
    for(j=0;j<cnt;j++)
    {
        fprintf(f,"%s,",x[j].lname);
        fprintf(f,"%s,",x[j].fname);
        fprintf(f,"%d-%d-%d,",x[j].bday.day,x[j].bday.month,x[j].bday.year);
        fprintf(f,"%s,",x[j].add);
        fprintf(f,"%s,",x[j].email);
        fprintf(f,"%s\n",x[j].num);
    }
    fclose(f);
    printf("CONTACTS SAVED SUCCESSFULLY !\n");
    return 1;
}
