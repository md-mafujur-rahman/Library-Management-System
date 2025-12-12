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

void addBook() {
    FILE *fp;
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    struct books b;
    
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(b.date, myDate);

    fp = fopen("books.txt", "ab");
    if(!fp){
        printf("File Error!");
        return;
    }

    printf("Enter book id: ");
    scanf("%d", &b.id);
    getchar();

    printf("Enter book name: ");
    fgets(b.bookName, 50, stdin);
    b.bookName[strcspn(b.bookName, "\n")] = 0;

    printf("Enter author name: ");
    fgets(b.authorName, 50, stdin);
    b.authorName[strcspn(b.authorName, "\n")] = 0;

    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);

    printf("Book Added Successfully\n");
}
