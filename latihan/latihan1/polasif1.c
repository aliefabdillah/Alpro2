#include <stdio.h>

int main(){
    int i,j;
    int n;

    scanf("%d", &n);

    for (i = 0; i < n-1; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("-");
        }
        for (j = 0; j < n ; j++)
        {
            printf("*");
        }
        for (j = 1; j < n-i; j++)
        {
            printf("-");
        }
        for (j = 0; j < n; j++)
        {
            printf("*");
        }
        for (j = n-i; j > 0; j--)
        {
            printf("*");
        }
        printf("\n");
    }

    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < n-1; j++)
        {
            printf("-");
        }
        for (j = 0; j < n*3; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    for (i = 0; i < n-1; i++)
    {
        for ( j = 0; j < n-1; j++)
        {
            printf("-");
        }
        for ( j = n-i-1; j > 0; j--)
        {
            printf("*");
        }
        for ( j = 0; j <= (n+1)+(i+i); j++)
        {
            printf("-");
        }
        for ( j = n-i-1; j > 0; j--)
        {
            printf("*");
        }
        printf("\n");
    }

    for (i = 0; i < n; i++)
    {
        for ( j = 0; j < n-1; j++)
        {
            printf("-");
        }
        for ( j = 0; j <= i; j++)
        {
            printf("*");
        }
        /*
        for ( j = n-i ; j >= 0; j--)
        {
            printf("-");
        }
        for ( j = 0 ; j < 1; j++)
        {
            printf("-");
        }
        */
        for ( j = 0; j < n*2-i+1; j++)
        {
            printf("-");
        }
        for ( j = 0; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
        
    }
    return 0;
}