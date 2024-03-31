// Importing the required header files
#include <math.h> 
#include <stdio.h> 
#include<stdlib.h>
#include<conio.h>
// Creating MACRO for finding the maximum number 
#define max(x, y) (((x) > (y)) ? (x) : (y)) 

// Creating MACRO for finding the minimum number 
#define min(x, y) (((x) < (y)) ? (x) : (y)) 

// Function to return the maximum profit 
// that can be made after buying and 
// selling the given stocks 
int maxProfit(int price[], int start, int end) 
{ 

	// If the stocks can't be bought 
	if (end <= start) 
		return 0; 

	// Initialise the profit 
	int profit = 0; 

	// The day at which the stock 
	// must be bought 
	for (int i = start; i < end; i++) { 

		// The day at which the 
		// stock must be sold 
		for (int j = i + 1; j <= end; j++) { 

			// If buying the stock at ith day and 
			// selling it at jth day is profitable 
			if (price[j] > price[i]) { 

				// Update the current profit 
				int curr_profit 
					= price[j] - price[i] 
					+ maxProfit(price, start, i - 1) 
					+ maxProfit(price, j + 1, end); 

				// Update the maximum profit so far 
				profit = max(profit, curr_profit); 
			} 
		} 
	} 
	return profit; 
} 

// Driver Code 
int main() 
//{   int size;
//    printf("Enter the size of the array:");
//    scanf("%d",&size);
//    int price[size];
//	printf("Enter element:");
//	int i;
//	for(i=0;i<size;i++){
//		scanf("%d",&price[i]);
//	}
     {
		
	int price[] = { 100, 180, 260, 310, 40, 535, 695 }; 
	int size = sizeof(price) / sizeof(price[0]); 
	printf("%d", maxProfit(price, 0, size - 1)); 
	return 0; 
}

