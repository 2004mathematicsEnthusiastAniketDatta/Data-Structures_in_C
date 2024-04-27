#include<stdio.h>
#define MAX 50
 struct stack {
  int a[MAX];
  int top;
 }s;


  void init()
  {

      s.top=-1;
  }
  int isempty()
  {

      if(s.top==-1)
      {

          return 1;
      }
      else{
        return 0;
      }
  }
  int isfull()
  {

      if(s.top==MAX-1)
      {

          return 1;
      }
      else{
        return 0;
      }
  }

   void push(int num)
   {
       s.top++;
       s.a[s.top]=num;

   }
   int pop()
   {

     int v;
     v=s.a[s.top];
     s.top--;
   }

   void dfs(int g[20][20],int n)
   {
        int visited[20]={0};
        int i,flag=0;
         push(0);
         printf("%d\t",s.top);
         visited[s.top]=1;
        while(!isempty())
        {
            flag=0;

           for(i=0;i<n;i++)
           {

             if(g[s.top][i]==1&&visited[i]==0)
             {
                  push(i);
                  visited[i]=1;
                  printf("%d\t",i);
                  flag=1;
                  break;
             }


           }
            if(flag==0)
             {

                 pop();
             }
        }

   }
  int main()
{
    init();

    int g[20][20],i,j,n;
    printf("\n enter the  number of vertices");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {

        for(j=0;j<n;j++)
        {

            scanf("%d",&g[i][j]);

        }
    }
      for(i=0;i<n;i++)
      {
          for(j=0;j<n;j++)
          {

              printf("%d\t",g[i][j]);
          }
          printf("\n");
      }

      dfs(g,n);
      return 0;
}

