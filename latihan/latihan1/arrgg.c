#include <stdio.h>

int main(){
    int i,j;
    int n,m;
    
    //input panjang array, deklarasi array1 dan mengiis array1
    scanf("%d", &n);
    int arr1[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }

    //input panjang array2, deklarasi array2, dan mengisi array2
    scanf("%d", &m);
    int arr2[m];
    for (j = 0; j < m; j++)
    {
        scanf("%d", &arr2[j]);
    }

    //cek ganjil genap
    int temp = 0;
    /*
    if (n != m)
    {
        printf("tidak valid\n");
    }
    */
   if(n<m)
   {
        i=0;
        while(i<n)
        {
            j=0;
            while(j<n)
            {
                if ((arr1[i]%2 == 0) == (arr2[j]%2 == 0))
                {
                    temp++;
                }
                else if ((arr1[i]%2 != 0) == (arr2[j]%2 != 0))
                {
                    temp++;
                }
                else
                {
                    temp = 0;
                }
                j++;
            }
            i++;
        }
   }
   else if (m < n)
   {
       i=0;
        while(i<m)
        {
            j=0;
            while(j<m)
            {
                if ((arr1[i]%2 == 0) == (arr2[j]%2 == 0))
                {
                    temp++;
                }
                else if ((arr1[i]%2 != 0) == (arr2[j]%2 != 0))
                {
                    temp++;
                }
                else
                {
                    temp = 0;
                }
                j++;
            }
            i++;
        }
   }
   else
   {
       i=0;
        while(i<n)
        {
            j=0;
            while(j<m)
            {
                if ((arr1[i]%2 == 0) == (arr2[j]%2 == 0))
                {
                    temp++;
                }
                else if ((arr1[i]%2 != 0) == (arr2[j]%2 != 0))
                {
                    temp++;
                }
                else
                {
                    temp = 0;
                }
                j++;
            }
            i++;
        }
   }
   

        if (temp > 0)
        {
            printf("valid\n");
        }
        else
        {
            printf("tidak valid\n");
        }

    return 0;
}