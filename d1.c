#include<stdio.h>
int main()
{
    int n;
    int pos;
    int num;
    printf("Enter the number of integers:");
    scanf("%d",&n);
    int arr[n+1];
    printf("Enter the numbers:");
    int i;
    for(i=0; i<n; i++)
    scanf("%d",&arr[i]);
    printf("Enter position of new number:");
    scanf("%d",&pos);
    printf("Enter the number:");
    scanf("%d",&num);
    for(i=n; i>=pos; i--)
    arr[i]=arr[i-1];
    arr[pos-1]=num;
    for(i=0; i<=n; i++)
    printf("%d", arr[i]);
    return 0;
}