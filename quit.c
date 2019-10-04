#include <stdlib.h>
#include <stdio.h>
#include "declare.h"
#include "save.h"


void Quit(int saved, contact* x,int i)
{
    int ex=0;
    if(saved)
        exit(0);
    else
    {

        printf("Are you sure you want to exit?\nAll changes will be discarded.\n1- Exit anyway \t2- Save&Exit\n");
        scanf("%d",&ex);
        while(ex!=1 && ex!=2)
        {
            printf("Unknown command\nPlease enter 1 to exit or 2 to save&exit\n");
            scanf("%d",&ex);
        }
        if(ex==1)
            exit(0);
        else
        {
            SAVE(x,i);
            exit(0);
        }
    }
}
