#include <stdio.h>
void main()
{
    int n, m, i, j, f = 0, rpn, k, proc = -1, flag = 1, grant = 1;
    printf("Enter the number of resources (m): ");
    scanf("%d", &m);
    printf("Enter the number of processes (n): ");
    scanf("%d", &n);
    int available[m], work[m], allocation[n][m], max[n][m], need[n][m], finish[n], work[m], sequence[n], request[m];
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

// accept request for process
printf(" |s there is any request ?[1/0]");
scanf("%d", &f);
if (f)
{
    printf("\n Enter process no : ");
    scanf("%d", &rpn);
    printf("Enter request : ");
    for (i = 0; i < m; i++)
        scanf("%d", &request[i]);
    printf("\n ** request matrix for process P%d ** \n", rpn);
    for (i = 0; i < n; i++)
        printf("\t%d", request[i]);
    printf("\n");
}
for (i = 0; i < n; i++)
    finish[i] = 0;

outer : for (i = 0; i < m; i++)
{
    if (finish[i] == 0)
    {
        for (j = 0; j < m; j++)
        {
            if(need[i][j]>work[i])
            flag=0;
        }
        if(flag==0)
        {
            
        }
    }
}
