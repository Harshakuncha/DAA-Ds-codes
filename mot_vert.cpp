#include<iostream>
using namespace std;

int main()
{
int a[20][20],i,j,n;
int b[20][20];


cout<<"Enter number of vertices\n";
cin>>n;

cout<<"Enter adjacency matrix \n";
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
cin>>a[i][j];

for(i=1;i<=n;i++)
{int count=0;
 for(j=1;j<=n;j++)
  {
    if(a[i][j]==1)
      {int k=1;
        while(k<=n)
          {
            if(a[j][k]==1 && a[k][j]==0)
              {
               k++;count++;
               }
            else 
              k++;
           }
      }
else 
continue;
   }
if(count!=0){cout<<"Mother vertex is : "<<i<<endl;}
}

return 0;
}
                

