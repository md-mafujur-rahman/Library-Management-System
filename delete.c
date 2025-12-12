#include <stdio.h>
#include <stdlib.h>

struct books
{
    int id;
    char bookName[50];
    char authorName[50];
    char date[12];
};

void del()
{
    FILE *fp, *ft;
    int id, f = 0;
    struct books b;

    system("cls");
    printf("<== Remove Books ==>\n\n");
    printf("Enter Book id to remove: ");
    scanf("%d", &id);

    fp = fopen("books.txt", "rb");
    ft = fopen("temp.txt", "wb");

    if (!fp || !ft)
    {
        printf("File Error!");
        return;
    }

    while (fread(&b, sizeof(b), 1, fp) == 1)
    {
        if (id == b.id)
            f = 1;
        else
            fwrite(&b, sizeof(b), 1, ft);
    }

    fclose(fp);
    fclose(ft);

    remove("books.txt");
    rename("temp.txt", "books.txt");

    if (f == 1)
        printf("Deleted Successfully\n");
    else
        printf("Record Not Found\n");
}