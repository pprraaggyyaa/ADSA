#include<stdio.h>

int Binary_Search(int arr[], int n, int x, int *comparisons)
{
    int low =0;
    int high = n-1;
    *comparisons = 0;

    while (low <= high)
    {
    int mid = low + (high-low)/2;
    
    (*comparisons)++;
    if (arr[mid] == x)
        return mid;
    else if (arr[mid] < x)
        low = mid+1;
    else
        high = mid-1;
    }
    return -1;
}

int Ternary_Search(int arr[], int n, int x, int *comparisons)
{
    int low = 0;
    int high = n-1;

    while(low <= high)
    {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;
        
        (*comparisons)++;
        if(arr[mid1]==x)
        {
            return mid1;
        }

        (*comparisons)++;
         if(arr[mid2]==x)
        {
            return mid2;
        }
        if (arr[mid1]>x)
        {
            high = mid1 - 1; //search left
        }
        else if (x > arr[mid2])
        {
            low = mid2+1;// search right
           
        }
        else{
            low = mid1 + 1;   // search middle third
            high = mid2 - 1;
        }
    }
        return -1;
}

int main()
{
    int n, x, comp_bin, comp_ter;
    
    printf("Enter the size of array:");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the list of elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the elements you want to search:");
    scanf("%d", &x);


    //binary search
    int result_bin = Binary_Search(arr, n, x, &comp_bin);

    if(result_bin != -1)
    {
        printf("Found at index : %d\n", result_bin);
    }
    else{
         printf("Not Found at index ");
    }

    printf("Number of comparisons : %d\n", comp_bin);


    //ternary result

    int result_ter = Ternary_Search(arr, n, x, &comp_ter);
    if (result_ter != -1)
        printf("Ternary Search: Found at index %d\n", result_ter);
    else
        printf("Ternary Search: Not Found");
    printf("  Comparisons = %d\n", comp_ter);

    return 0;
}