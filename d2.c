#include<stdio.h>
int main()
{
    int n;
    int i, dlt;
    printf("Enter the number of integers:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the numbers:");
    for(i=0; i<n; i++)
    {
    scanf("%d",&arr[i]);
    }
    printf("Enter the postion to be deleted:");
    scanf("%d",&dlt);
    for(i=dlt-1;i<=n;i++)
    {
      arr[i]=arr[i+1];
    }
    for(i=0; i<n-1; i++)
    {
    printf("%d ",arr[i]);
    }
    return 0;
}