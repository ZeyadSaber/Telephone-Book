#include <stdio.h>
#include <stdlib.h>
#include "declare.h"
#include "search.h"
#include "add.h"
#include "delete.h"
#include "modify.h"
#include "string.h"
#include "print.h"
#include "quit.h"
#include "save.h"

contact x[200];
int i=0;

int load()
{
    FILE* s= fopen("directory.txt","r");
    while(!feof(s))
    {
        fscanf(s,"%[^,],",x[i].lname);
        fscanf(s,"%[^,],",x[i].fname);
        fscanf(s,"%d-",&x[i].bday.day);
        fscanf(s,"%d-",&x[i].bday.month);
        fscanf(s,"%d,",&x[i].bday.year);
        fscanf(s,"%[^,],",x[i].add);
        fscanf(s,"%[^,],",x[i].email);
        fscanf(s,"%s\n",x[i].num);
        i++;
    }
    printf("Contacts Loaded Successfully !\n");
    fclose(s);
    return i;
}



int main()
{
    int command=0,s=0,loaded=0;
    printf("\t\tTELEPHONE BOOK\n\t\t--------------");
    printf("\n\nChoose the number associated to your command:\n1- Load\n2- Query\n3- Add\n4- Delete\n5- Modify\n6- Print\n7- Save\n8- Quit\n\n");
    scanf("%d",&command);
    while(command!=1 && command!=3)
    {
        printf("No Contacts Loaded\nPlease Enter #1 to load contacts: ");
        scanf("%d",&command);
    }
    do
    {
        if(command==1 && !loaded)
        {
            load();
            loaded=1;
        }
        else if(command==2)
            search(x,i);
        else if(command==3)
        {
            ADD(x,i);
            i++;
        }
        else if(command==4)
        {
            int deleted = DELETE(x,i);
            if(deleted)
                i--;
        }
        else if (command==5)
            modify(x,i);
        else if(command==6)
            bubbleSort(x,i);
        else if(command==7)
            s = SAVE(x,i);
        else if(command==8)
            Quit(s,x,i);
        else if(command>8)
            printf("Unknown command\n");
        else
            printf("Contacts already loaded\n");
        printf("\n\nChoose the number associated to your command:\n1- Load\n2- Query\n3- Add\n4- Delete\n5- Modify\n6- Print\n7- Save\n8- Quit\n\n");
    }
    while(scanf("%d",&command));
    return 0;
}
