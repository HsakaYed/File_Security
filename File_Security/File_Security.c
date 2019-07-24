#include<stdio.h>
#include<windows.h>
void main()
{
    char ch;
    system("color c");
    system("title FILE SECURITY");
    SYSTEMTIME sysTIME;
    GetSystemTime(&sysTIME);
    printf("----------------------------Today's Date------------------------------");
    printf("\n");
    printf("%d/%d/%d",sysTIME.wDay,sysTIME.wMonth,sysTIME.wYear);
    printf("\n");
    printf("----------------------------------------------------------------------\n");
    printf("------------------------Terms and Conditions-------------------------\n");
    printf("*Make sure all your files must saved in .txt extension\n"
           "*Your file name should not exceed 30 characters\n"
           "*Encrypting your file will make it unreadable\n"
           "*To read the file you must decrypt it\n");
    printf("---------------------------------------------------------------------\n");
    printf("\n");
    do
    {
    int i;
    char fname[30];
    printf("------------------------------Options--------------------------------\n");
    printf("*Enter '1' to encrypt your file\n"
           "*Enter '2' to decrypt your file\n");
    printf("---------------------------------------------------------------------\n");
    printf("\nEnter your choice: ");
    scanf("%d",&i);
    switch(i)
    {
    case 1:
        printf("\nEnter the file name (with extension like file.txt): ");
        fflush(stdin);
        scanf("%s",fname);
        FILE *fp1=fopen(fname,"r");
        if(fp1==NULL)
        {
            perror("Error: ");
            printf("\nPress any key to exit\n");
            getch();
            exit(1);
        }
        FILE *fp2=fopen("tmpfile.txt","w");
        if(fp2==NULL)
        {
            fclose(fp1);
            printf("\nError occured\n"
                   "Cannot be continued further\n"
                   "Press any key to exit\n");
            getch();
            exit(2);
        }
        while(1)
        {
            ch=fgetc(fp1);
            if(feof(fp1))
            {
                break;
            }
            else
            {
            ch=ch+100;
            fputc(ch,fp2);
            }
        }
        fclose(fp1);
        fclose(fp2);
        fp1=fopen(fname,"w");
        if(fp1==NULL)
        {
            perror("Error: ");
            printf("\nPress any key to exit....");
            getch();
            exit(3);
        }
        fp2=fopen("tmpfile.txt","r");
        if(fp2==NULL)
        {
            fclose(fp1);
            printf("\nError occured\n"
                   "Cannot be continued further\n"
                   "Press any key to exit....\n");
            getch();
            exit(4);
        }
        while(1)
        {
            ch=fgetc(fp2);
            if(feof(fp2))
            {
                break;
            }
            else
            {
                fputc(ch,fp1);
            }
        }
        printf("Encryption of %s file is successfully done!!",fname);
        fclose(fp1);
        fclose(fp2);
        remove("tmpfile.txt");
        break;
    case 2:
        printf("\nEnter the file name (with extension like file.txt): ");
        fflush(stdin);
        scanf("%s",fname);
        fp1=fopen(fname,"r");
        if(fp1==NULL)
        {
            perror("Error: ");
            printf("\nPress any key to exit....");
            getch();
            exit(5);
        }
        fp2=fopen("tmpfile.txt","w");
        if(fp2==NULL)
        {
            fclose(fp1);
            printf("\nError occured\n"
                   "Cannot be continued further\n"
                   "Press any key to exit....\n");
            getch();
            exit(6);
        }
        while(1)
        {
            ch=fgetc(fp1);
            if(feof(fp1))
            {
                break;
            }
            else
            {
                ch=ch-100;
                fputc(ch,fp2);
            }
        }
        fclose(fp1);
        fclose(fp2);
        fp1=fopen(fname,"w");
        if(fp1==NULL)
        {
            printf("Cannot open file\n");
            printf("Press any key to continue....");
            getch();
            exit(7);
        }
        fp2=fopen("tmpfile.txt","r");
        if(fp2==NULL)
        {
            fclose(fp1);
            printf("\nError occured\n"
                   "Cannot be continued further\n"
                   "Press any key to exit....\n");
            getch();
            exit(8);
        }
        while(1)
        {
            ch=fgetc(fp2);
            if(feof(fp2))
            {
                break;
            }
            else
            {
                fputc(ch,fp1);
            }
        }
        printf("\nDecryption of %s file is successfully done!!",fname);
        fclose(fp1);
        fclose(fp2);
        remove("tmpfile.txt");
        break;
    default:
        printf("\nInvalid Choice");
    }
    printf("\nDo you want to decrypt your file?\n"
           "Enter 'y' for Yes\n"
           "Enter 'n' for No\n");
    fflush(stdin);
    scanf("%c",&ch);
    }
    while(ch=='y');
    printf("Bye!!");
    getch();
}
