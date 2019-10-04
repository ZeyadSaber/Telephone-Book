#ifndef DECLARE_H_INCLUDED
#define DECLARE_H_INCLUDED


typedef struct
{
    int day,month,year;
}date;

typedef struct
{
    char lname[20],fname[20],add[60],email[25],num[20];
    date bday;
} contact;


#endif // DECLARE_H_INCLUDED
