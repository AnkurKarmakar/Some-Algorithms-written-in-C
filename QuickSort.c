#include<stdio.h>
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
 

int partition (int arr[], int low, int high)
{
	int pivot=arr[low];
	int flag=0;//i is incremented or decremented on the basis of flag
	int i=high;int j=low;// j is the pivot index
	while(i != j)//i==j means all elements are checked
	{
		if(i < j)//if i lies to the left of pivot
		{
			if(pivot <= arr[i])
			{
				swap(&arr[j],&arr[i]);
				j=i;//store the new pivot index
				i=high;//if pivot moves to left set i=high
				flag=0;
			}
		}
		if( i > j)//if i lies to the right of pivot
		{
			if(pivot >= arr[i])
			{
				swap(&arr[j],&arr[i]);
				j=i;//store the new pivot index
				i=low;//if pivot moves to right set i=low
				flag=1;
			}
		}
		if(flag == 0)//i is incremented or decremented based on the value of flag
		i--;
		else
		i++;
	}
	return j;
}
void QuickSort(int arr[],int low,int high)
{
	if( low < high )
	{
		int p=partition(arr,low,high);
		QuickSort(arr,low,p-1);
		QuickSort(arr,p+1,high);
	}
	
}
void main()
{
	int n;int i;
	printf("enter the no of elements\n");
	scanf("%d",&n);
	int arr[n];
	printf("enter the element of array\n");
	for(i=0;i<n;i++)
	{	
		scanf("%d",&arr[i]);
	}
	QuickSort(arr,0,n-1);
	printf("\n\n");
	printf("sorted array\n");
	for(i=0;i<n;i++)
	{	
		printf("%d \n",arr[i]);
	}	
}
