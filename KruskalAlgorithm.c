#include<stdio.h>
#include<limits.h>
int parent[100];
int find(int i)
{
	while(parent[i])
		i=parent[i];
	return i;
}
int union1(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}
void main()
{
	int n;int edge_count=0; int min; int a,b;int mincost = 0;
	printf("enter the number of nodes= ");
	scanf("%d",&n);
	int cost[n][n];
	printf("Enter the adjacency matrix: \n");
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			scanf("%d",&cost[i][j]);
			if (cost[i][j] == 0)
				cost[i][j] = INT_MAX;
		}
	printf("\n\n\n");
	while(edge_count < n-1)
	{
		min = INT_MAX;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(cost[i][j] < min)
				{
						min = cost[i][j];
						a = i;
						b = j;
				}
			}
		}
		a=find(a);
		b=find(b);
		if(union1(a,b))
		{
			printf("%d edge (%d,%d) 	=%d\n",edge_count++, a, b, min);
			mincost +=min;
		}
		cost[a][b]=cost[b][a]=INT_MAX;
	}
	printf("\n Minimum cost= %d \n",mincost);
}
