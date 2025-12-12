#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>


#include "books.c"
#include "list.c"
#include "delete.c"
#include "issue.c"


void addBook();
void booksList();
void del();
void issueBook();
void issueList();

int main() {
    int ch;

    while(1){
        system("cls");
        printf("<== Library Management System ==>\n");
        printf("1. Add Book\n");
        printf("2. Books List\n");
        printf("3. Remove Book\n");
        printf("4. Issue Book\n");
        printf("5. Issued Book List\n");
        printf("0. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 0:
                exit(0);
            case 1:
                addBook();
                break;
            case 2:
                booksList();
                break;
            case 3:
                del();
                break;
            case 4:
                issueBook();
                break;
            case 5:
                issueList();
                break;
            default:
                printf("Invalid Choice...\n");
        }
        
        if(ch != 0){
            printf("Press Any Key To Continue...");
            getch();
        }
    }

    return 0;
}