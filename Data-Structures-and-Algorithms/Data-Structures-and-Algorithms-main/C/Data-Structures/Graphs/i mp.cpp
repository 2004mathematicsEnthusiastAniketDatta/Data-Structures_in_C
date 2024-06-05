#include <stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>
#define MAX_N 15
int n;
int cost[MAX_N][MAX_N];
int dp[1<<MAX_N][MAX_N];
int tsp(int mask,int pos){
	if(mask==(1 << n) - 1){
		return cost[pos][0];
	}
	if(dp[mask][pos] != -1){
		return dp[mask][pos];
	}
	int ans=INT_MAX;
for(int next=0;next<n;next++){
	if(mask & (1<<next) == 0){
			int newcost=cost[pos][next] + tsp(mask|1 << next,next);
			ans = (ans < newcost)? ans: newcost;
	}
}
 return dp[mask][pos] = ans;
}

int main(){
	printf("Enter the number of cities:");
	scanf("%d",&n);
	int i,j;
	printf("Enter the cost matrix");
	for(i=0;i<n;i++){
		for (j=0;j<n;j++){
			scanf("%d",cost[i][j]);
		}
	}
	memset(dp,-1,sizeof(dp));
	int mincost = tsp(1,0);
	    printf("Minimum cost of the TSP: %d \n", mincost);
    return 0;
}
