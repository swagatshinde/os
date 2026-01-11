// Banker's algorithm
// add the following functionalities in your program
// a)Accept available
// b)Display Allocation,Max
// c)Display contemts of need matrix
// d)Display Available

// The Banker's Algorithm is primarily used for deadlock avoidance in operating systems.
// It acts as a gatekeeper to ensure that the system never enters an "unsafe" state that could lead to a freeze.

#include <stdio.h>
void main()
{
    int n, m, i, j;
    printf("Enter the number of resources (m): ");
    scanf("%d", &m);
    printf("Enter the number of processes (n): ");
    scanf("%d", &n);
    int available[m], work[m], allocation[10][10], max[10][10], need[10][10];
    printf("\nEnter the available matrix (%d elements): ", m);
    for (i = 0; i < m; i++)
    {
        scanf("%d", &available[i]);
        work[i] = available[i];
    }
    printf("Enter the allocation matrix :\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);
    printf("The allocation matrix is :\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("\t%d", allocation[i][j]);
        printf("\n");
    }
    printf("Enter the Max matrix :\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    printf("The max matrix is :\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("\t%d", max[i][j]);
        printf("\n");
    }

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];
    printf("\n ** need matrix is ** \n ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("\t%d", need[i][j]);
        printf("\n");
    }

    printf("\n ** Available Matrix ** \n");
    for (i = 0; i < m; i++)
    {
        printf("\t%d", work[i]);
    }
}


