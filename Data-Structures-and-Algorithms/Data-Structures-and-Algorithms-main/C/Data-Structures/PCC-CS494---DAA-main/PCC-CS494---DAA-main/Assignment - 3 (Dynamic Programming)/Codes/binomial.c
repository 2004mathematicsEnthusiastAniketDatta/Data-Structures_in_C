#include<stdio.h>
#include<stdlib.h>
long binomial(long n, long k)
{
	long dp[n+1][k+1];
	//DP TABLE
	for(long i=0; i<=n;i++)
	{
		for(long j=0; j<=k && j<=i ; j++)
		{
			if(j==0 || j==i)
				dp[i][j]=1;
			else 
                		dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            
		}
	}
	return dp[n][k];
}
int main()
{
	long n,k;
	printf("\nEnter the value of n: ");
	scanf("%ld",&n);
	printf("\nEnter the value of k: ");
	scanf("%ld",&k);
	if (n<k)
		printf("\nn cannot be less than k.");
	else{
		long result = binomial(n,k);
		printf("\nThe binomial coefficient is: %ld ",result);}
	return 0;
}
