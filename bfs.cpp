#include<iostream>
using namespace std;

void bfs(int a[20][20],int n,int source);

int main()
{

int a[20][20],n,i,j,source;

cout<<"Enter no of vertices \n";
cin>>n;

cout<<"Enter the adjacency matrix \n";
for(i=0;i<n;i++)
for(j=0;j<n;j++)
 cin>>a[i][j];

cout<<"Enter the source \n";
cin>>source;

cout<<"\nBFS of the graph is \n";
bfs(a,n,source);

cout<<"Entered matrix is \n";
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{cout<<a[i][j]<<" ";}
cout<<endl;}

return 0;

}


void bfs(int a[20][20] , int n , int source)
{

int visited[10],u,v,i;

for(i=0;i<n;i++)
visited[i]=0;

int q[20],f=-1,r=-1;

q[++r]=source;
visited[source] = 1;

while(f<r)
{
u=q[++f];
for(v=0;v<n;v++)
{
if(a[u][v]==1 && visited[v]==0)
{
visited[v]=1;
q[++r]=v;
}
}

cout<<u<<" ";
}
}
