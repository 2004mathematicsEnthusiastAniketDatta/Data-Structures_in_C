#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void queen(int,int,int[],int);
void print(int,int[],int);
int place(int,int,int[]);
 
int main()
{
int n,i,j;
int board[20],count;
printf("\n\nEnter number of Queens:");
scanf("%d",&n);
queen(1,n,board,count);
return 0;
}
 
void print(int n, int board[], int count)
{
int i,j;
printf("\n\nSolution %d:\n\n",++count);
 
for(i=1;i<=n;++i)
  printf("\t%d",i);
 
for(i=1;i<=n;++i)
{
  printf("\n\n%d",i);
  for(j=1;j<=n;++j) 
  {
   if(board[i]==j)
    printf("\tQ"); 
   else
    printf("\t-"); 
  }
}
}

int place(int row,int column,int board[])
{
int i;
for(i=1;i<=row-1;++i)
{
  if(board[i]==column)
   return 0;
  else
   if(abs(board[i]-column)==abs(i-row))
    return 0;
}
 
return 1; 
}
 
void queen(int row,int n, int board[], int count)
{
int column;
for(column=1;column<=n;++column)
{
  if(place(row,column,board))
  {
   board[row]=column; 
   if(row==n) 
    print(n,board,count); 
   else 
    queen(row+1,n,board,count);
  }
}
}
