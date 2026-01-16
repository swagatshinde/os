// File Allocation
//1.Contiguous/sequential File allocation 
//Q.write a program to simulate sequential(Contiguous)file allocation method.Assume Disk 
//with n number of blocks.give value of n as input .write a menu driven program with menu
// otions as mentioned above and implement each option.

//The drawback of this file allocation is external fragmentation problem and file cannot grow efficiently.  


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_FILES 50
#define MAX_NAME 20

int *bitVector;
int n;

struct Directory
{
    char filename[MAX_NAME];
    int start;
    int length;
} dir[MAX_FILES];

int fileCount = 0;

/* Display bit vector */
void showBitVector()
{
    printf("\n Bit Vector : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d", bitVector[i]);
    }
    printf("\n");
}

/* create new file using contiguous allocation */

void createFile()
{
    char name[MAX_NAME];
    int len;
    printf("\n enter file name : ");
    scanf("%s", name);
    printf("Enter file length(No.of blocks) : ");
    scanf("%d", &len);
    if (len <= 0 || len > n)
    {
        printf("Invalid file length!.\n");
        return;
    }
    // Search for contiguous free blocks
    for (int i = 0; i <= n - len; i++)
    {
        int j;
        for (j = 0; j < len; j++)
        {
            if (bitVector[i + j] == 1)
                break;
        }
        if (j == len)
        {
            // allocate block
            for (j = 0; j < len; j++)
                bitVector[i + j] = 1;
            strcpy(dir[fileCount].filename, name);
            dir[fileCount].start = i;
            dir[fileCount].length = len;
            fileCount++;
            printf("File '%s' Allocated Successfully.\n", name);
            printf("Start Block : %d ,Length : %d \n", i, len);
            return;
        }
    }
    printf("Not enough contigious free space to allocate file.\n");
}
// show Directory

void showDirectory()
{
    if (fileCount == 0)
    {
        printf("\n Directory is empty.\n");
        return;
    }
    printf("\n Directory Contents : \n");
    printf("Filename \t Start Block \t Length \n");
    for (int i = 0; i < fileCount; i++)
    {
        printf("%s\t\t%d\t\t%d\n", dir[i].filename, dir[i].start, dir[i].length);
    }
}

// Delete a File

void deleteFile()
{
    char name[MAX_NAME];
    printf("\n Enter File Name to Delete : ");
    scanf("%s", name);
    for (int i = 0; i < fileCount; i++)
    {
        if (strcmp(dir[i].filename, name) == 0)
        {
            // free blocks
            for (int j = 0; j < dir[i].length; j++)
            {
                bitVector[dir[i].start + j] = 0;
            }
            // shift directory entries
            for (int k = i; k < fileCount - 1; k++)
            {
                dir[k] = dir[k + 1];
            }
            fileCount--;
            printf("File '%s' Deleted Sucessfully.\n", name);
            return;
        }
    }
    printf("File Not Found \n");
}

int main()
{
    int choice;

    printf("Enter Number of Disk Blocks : ");
    scanf("%d", &n);
    bitVector = (int *)malloc(sizeof(int));

    // Random initialization

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        bitVector[i] = rand() % 2;
    }
    do
    {
        printf("\n ** Contiguous File Allocation ** \n");
        printf("1.Show Bit Vector \n");
        printf("2.Create new File \n");
        printf("3.Show Directory \n");
        printf("4.Delete File \n");
        printf("5.Exit \n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            showBitVector();
            break;
        case 2:
            createFile();
            break;
        case 3:
            showDirectory();
            break;
        case 4:
            deleteFile();
            break;
        case 5:
            printf("Exiting...");
            break;

        default:
            printf("Invalid Choice! \n");
        }
    } while (choice != 5);
    free(bitVector);
    return 0;
}
