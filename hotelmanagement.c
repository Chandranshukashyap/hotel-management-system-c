

#include <stdio.h>
#include <string.h>
#include <time.h>

#define reset   "\x1b[0m"
#define black   "\x1b[30m"
#define bblack  "\x1b[40m"

#define yellow  "\x1b[33m"
#define byellow "\x1b[43m"
#define green   "\x1b[32m"
#define bgreen  "\x1b[42m"
#define blue    "\x1b[34m"
#define bblue   "\x1b[44m"
#define white   "\x1b[37m"
#define bwhite  "\x1b[47m"
#define red     "\x1b[31m"
#define bred    "\x1b[41m"

void datetime(char *buffer);
void add_data();
void menu();
void show_data();

struct management
{
    char cu_name[100];
    char cu_idname[100];
    char cu_idnum[100];
    char cu_add[100];
    char cu_mob[100];
    char cu_time[100];
};

int main()
{
    menu();
    return 0;
}


void datetime(char *buffer)
{
    time_t now;
    time(&now);

    strcpy(buffer, ctime(&now));
}



void menu()
{
    int ch;

    printf(red "\n :: HOTEL MANAGEMENT SYSTEM ::\n" reset);

    printf("----------------------------------------------\n");

    printf(green "\n\t MAIN MENU:-\n" reset);

    printf("----------------------------------------------\n");

    printf(white "\n\t -: ROOM DETAILS :-\n" reset);

    printf("\n");

    printf(yellow "\n\t 1. Single Bed Room:\t\t 600.00" reset);
    printf("\n\t 2. Double Bed Room:\t\t 1000.00");
    printf("\n\t 3. Single Bed Deluxe:\t\t 1200.00");
    printf("\n\t 4. Double Bed Deluxe:\t\t 1800.00");
    printf("\n\t 5. Show History");

    printf(white "\n\n Enter your selected number: " reset);

    scanf("%d", &ch);

    switch(ch)
    {
        case 1:
            printf(yellow "\nYou selected Single Bed Room.\n" reset);
            add_data();
            break;

        case 2:
            printf(green "\nYou selected Double Bed Room.\n" reset);
            add_data();
            break;

        case 3:
            printf("\nYou selected Single Bed Deluxe.\n");
            add_data();
            break;

        case 4:
            printf("\nYou selected Double Bed Deluxe.\n");
            add_data();
            break;

        case 5:
            printf("\nShow History:-\n");
            show_data();
            break;

        default:
            printf(red "\nSorry, your selection is wrong.\n" reset);
            printf("Please try again.\n\n");

            menu();
    }
}


// ================= ADD CUSTOMER DATA =================

void add_data()
{
    FILE *fp;
    struct management mng;

    fp = fopen("chandu.dat", "ab");

    if(fp == NULL)
    {
        printf(red "\nFile could not be opened!\n" reset);
        return;
    }

    printf(white "\nCUSTOMER DETAILS:\n" reset);
    printf("----------------------------------\n");

    datetime(mng.cu_time);

    printf("\nBooking Time: %s", mng.cu_time);

    
    printf("\n1. CUSTOMER NAME : ");
    scanf(" %99[^\n]", mng.cu_name);

    
    printf("2. CUSTOMER ID NAME : ");
    scanf(" %99[^\n]", mng.cu_idname);

    
    printf("3. CUSTOMER ID NUM : ");
    scanf(" %99[^\n]", mng.cu_idnum);

    
    printf("4. CUSTOMER ADDRESS : ");
    scanf(" %99[^\n]", mng.cu_add);

    
    printf("5. CUSTOMER MOBILE : ");
    scanf(" %99[^\n]", mng.cu_mob);

    
    fwrite(&mng, sizeof(mng), 1, fp);

    fclose(fp);

    printf(green "\nCustomer data saved successfully!\n" reset);

    menu();
}




void show_data()
{
    int i = 1;

    FILE *fp;

    struct management mng;

    fp = fopen("chandu.dat", "rb");

    if(fp == NULL)
    {
        printf(red "\nNo history found!\n" reset);
        menu();
        return;
    }

    printf("\n");
    printf("S.NO\tCUSTOMER NAME\tID NAME\t\tID NUMBER\tADDRESS\t\t\tMOBILE\t\tTIME\n");

    printf(blue);
    printf("-------------------------------------------------------------------------------------------------------------\n");
    printf(reset);

    while(fread(&mng, sizeof(mng), 1, fp) == 1)
    {
        printf(
            "%d\t%-15s\t%-12s\t%-12s\t%-20s\t%-12s\t%s",
            i,
            mng.cu_name,
            mng.cu_idname,
            mng.cu_idnum,
            mng.cu_add,
            mng.cu_mob,
            mng.cu_time
        );

        i++;
    }

    fclose(fp);

    printf("\n");

    menu();
}
