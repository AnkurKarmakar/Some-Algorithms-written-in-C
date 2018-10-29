#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
void main()
{
	int n;int edge_count=0; int min; int a,b;int mincost = 0;
	printf("enter the number of nodes= ");
	scanf("%d",&n);
	int cost[n][n];
	bool taken[n];
	for(int i=0; i<n; i++)
		taken[i] = false;
	printf("Enter the adjacency matrix: \n");
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			scanf("%d",&cost[i][j]);
			if (cost[i][j] == 0)
				cost[i][j] = INT_MAX;
		}
	taken[0] = true;
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
					if(taken[i] != false)
					{
						min = cost[i][j];
						a = i;
						b = j;
					}
				}
			}
		}
		if(taken[a] == false || taken[b] == false)
		{
			printf("Edge %d: (%d , %d)	cost: %d \n",edge_count++, a, b, min);
			mincost = mincost + min;
			taken[b] = taken[a] = true;
		}
		cost[a][b]=cost[b][a]=INT_MAX;
	}
	printf("\n Minimum cost= %d \n",mincost);
}
