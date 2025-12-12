#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct books {
    int id;
    char bookName[50];
    char authorName[50];
    char date[12];
};

struct student {
    int id;
    char sName[50];
    char sClass[50];
    int sRoll;
    char bookName[50];
    char date[12];
};

void issueBook() {
    FILE *fp;
    int found = 0;
    char myDate[12];
    
    struct books b;
    struct student s;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(s.date, myDate);

    system("cls");
    printf("<== Issue Books ==>\n\n");
    printf("Enter Book id to issue: ");
    scanf("%d", &s.id);
    getchar();

    fp = fopen("books.txt", "rb");
    if(!fp){
        printf("File Error!");
        return;
    }

    while(fread(&b, sizeof(b), 1, fp) == 1){
        if(b.id == s.id){
            strcpy(s.bookName, b.bookName);
            found = 1;
            break;
        }
    }
    fclose(fp);

    if(!found){
        printf("Book Not Found\n");
        return;
    }

    fp = fopen("issue.txt", "ab");

    printf("Enter Student Name: ");
    fgets(s.sName, 50, stdin);
    s.sName[strcspn(s.sName, "\n")] = 0;

    printf("Enter Student Class: ");
    fgets(s.sClass, 50, stdin);
    s.sClass[strcspn(s.sClass, "\n")] = 0;

    printf("Enter Student Roll: ");
    scanf("%d", &s.sRoll);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    printf("Book Issued Successfully\n");
}

void issueList() {
    FILE *fp;
    struct student s;

    system("cls");
    printf("<== Book Issue List ==>\n\n");
    printf("%-10s %-30s %-20s %-10s %-30s %s\n\n",
           "S.id", "Name", "Class", "Roll", "Book Name", "Date");

    fp = fopen("issue.txt", "rb");
    if(!fp){
        printf("No issued books found.\n");
        return;
    }

    while(fread(&s, sizeof(s), 1, fp) == 1){
        printf("%-10d %-30s %-20s %-10d %-30s %s\n",
               s.id, s.sName, s.sClass, s.sRoll, s.bookName, s.date);
    }

    fclose(fp);
}