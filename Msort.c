#include<stdio.h>
void merge_sort(int [],int,int);
void merge(int [],int,int,int);
void main()
{
    int a[30],i,n;
    printf("\nEnter no. of elements:");
    scanf("%d",&n);

    printf("\nEnter array data:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    merge_sort(a,0,n-1);

    printf("\nSorted data:");
    for(i=0;i<n;i++)
        printf("%4d",a[i]);
}

void merge_sort(int a[],int i,int j)
{
    int k;
    if(i<j)
    {
        k=(i+j)/2;
        merge_sort(a,i,k);
        merge_sort(a,k+1,j);
        merge(a,i,k,j);
    }
}

void merge(int a[],int l,int m,int u)
{
    int c[50],i,j,k;
    k=0;
    i=l;
    j=m+1;

    while(i<=m && j<=u)
    {
        if(a[i]<a[j])
        {
            c[k]=a[i];
            k++;i++;
        }
        else
        {
            c[k]=a[j];
            k++;j++;
        }
    }
    while(i<=m)
    {
        c[k]=a[i];
        i++;k++;

    }
    while(j<=u)
    {
        c[k]=a[j];
        k++;j++;
    }
    for(i=l,j=0;i<=u;i++,j++)
        a[i]=c[j];
}
