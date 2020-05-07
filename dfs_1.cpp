#include<iostream>
using namespace std;

void dfs(int a[20][20],int n,int source);

int main()
{
int a[20][20],source, n;
int i,j;

cout<<"Enter no of vertices";
cin>>n;

cout<<"Enter the adjacency matrix";
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
     cin>>a[i][j];

cout<<"Enter Source : ";
cin>>source;

cout<<"DFS of a graph is \n";
dfs(a,n,source);

cout<<"Entered matrix is \n";
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{cout<<a[i][j]<<" ";}
cout<<endl;}

return 1;
}


void dfs(int a[20][20],int n,int source)
{
int visited[10],u,v,i;

for(i=1;i<=n;i++)
 visited[i]=0;

int s[20],top=-1;

s[++top]=source;
visited[source]=1;


while(top>=0)
{
u=s[top--];
for(v=1;v<=n;v++)
{
if(a[u][v]==1 && visited[v]==0)
{
visited[v]=1;
s[++top]=v;
}
}
cout<<u<<" ";
}

}
  
