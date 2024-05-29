#include <stdio.h>
#include <string.h>

void merge(float arr[], int item[], int low, int mid, int high){
    int i,t,j,k;
    i = t = low;
    j = mid+1;
    float temp[high+1];
    int index[high+1];
    while(i<=mid && j<=high){
        if(arr[i] >= arr[j]){
            temp[t] = arr[i];
            index[t++] = item[i++];
        }
        else if(arr[j] > arr[i]){
            temp[t] = arr[j];
            index[t++] = item[j++];
        }
    }
    while(i <= mid){
        temp[t] = arr[i];
        index[t++] = item[i++];
    }
    while(j <= high){
        temp[t] = arr[j];
        index[t++] = item[j++];
    }
    for(k=low; k<=high; k++){
        arr[k] = temp[k];
        item[k] = index[k];
    }
}

void mergeSort(float arr[], int item[], int low, int high){
    if(low < high)
    {
		int mid = (low+high) / 2;
		mergeSort(arr,item,low,mid);
		mergeSort(arr,item,mid+1,high);
		merge(arr,item,low,mid,high);
	}
}

float knapsack(int item[], float val[], float w[], int n, float weight){
    int i,index;
    float profit = 0,t;
    for(i=0;i<n;i++){
        index = item[i] - 1;
        if(w[index] <= weight){
            profit += val[index];
            weight -= w[index];
        }
        else{
            t = weight / w[index];
            profit += (t * val[index]);
            weight -= (t * w[index]);
        }
    }
    return profit;
}

float knapsack_frctional(int a[], int b[], int n, int c){
    int i,item[n];
    float val[n],w[n], weight = c;
    float fraction[n],temp[n];
    for(i=0; i<n; i++){
        item[i] = i+1;
        val[i] = a[i];
        w[i] = b[i];
    }
    for(i=0; i<n; i++){
        fraction[i] = val[i] / w[i];
        temp[i] = fraction[i];
    }
    mergeSort(fraction,item,0,n-1);
    return knapsack(item, val, w, n, weight);
}

int max(int a, int b){
    return (a>b)?a:b;
}

int knapsack_01(int val[],int w[],int n,int weight){
    int profit, i, j;
    int dp[n+1][weight+1];
    for(i=0;i<=weight;i++)
        dp[0][i] = 0;
    for(i=1;i<=n;i++)
        dp[i][0] = 0;

    for(i=1; i<=n; i++)
        for(j=1; j<=weight; j++){
            if(j < w[i-1])
                dp[i][j] = dp[i-1][j]; 
            else
                dp[i][j] = max(dp[i-1][j],val[i-1] + dp[i-1][j-w[i-1]]);
        }
    return dp[n][weight];
}

void main(){
    int i,n,W;
    printf("Enter n and W : ");
    scanf("%d %d",&n, &W);
    int val[n], w[n];
    printf("Enter the weights : ");
    for (i=0; i<n; i++)
    	scanf("%d", &w[i]);
	printf("Enter the values : ");
    for (i=0; i<n; i++)
    	scanf("%d", &val[i]);
    printf("Profit for 0/1 knapsack : %d\n", knapsack_01(val,w,n,W));
    printf("Profit for fractional knapsack : %f\n", knapsack_frctional(val, w, n, W));
}

