#include<iostream>
using namespace std;
int count;

int indegree(int a[][10],int p,int n)
{
int c1=0;

for(int i=1;i<=n;i++)
{
  if(a[i][p]==1)
   c1++;
}

return c1;
}


int main()
{
int a[10][10],n,m,result;
count=0;
cout<<"Enter no of vertices\n";
cin>>n;
cout<<"Enter no of edges\n";
cin>>m;
for(int i=1;i<=n;i++)
 for(int j=1;j<=n;j++)
   a[i][j]=0;

int p,q;

for(int i=1;i<=m;i++)
{
cout<<"Enter Source ";
cin>>p;
cout<<"Enter destination";
cin>>q;
a[p][q]=1;
}

for(p=1;p<=n;p++)
{
int res=indegree(a,p,n);
cout<<endl;
cout<<"Indegree of  "<<p<<" is: "<<res<<endl;
}

return 0;
}
