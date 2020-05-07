#include<iostream>
using namespace std;
class que
{
 int r,f,a[100],count;
 public:
 int empty()
 {
   if(count!=0)
   {return 0;}
   return 1;
 }
 que()
 {
  f=-1;r=-1;count=0;
 }
 void push(int n)
 {a[++r]=n;count++;}
 int pop()
 {count--;
return a[++f];}
 void sort(int d[100])
 {for(int i=f;i<r;i++)
  {for(int j=i+1;j<=r;j++)
   {if(d[a[i]]>d[a[j]])
     {int temp=a[i];
      a[i]=a[j];
      a[j]=temp;}
  }
 }
 }
};
void dijkstra(int d[100],int mat[100][100],int v,int p[100],int n)
{
 int i,temp;
 int vis[n]={0};
 que q;
 d[v]=0;
 p[v]=v;
 vis[v]=0;
 for(i=0;i<n;i++)
 {
  if(mat[v][i]!=9999 && mat[v][i]!=0)
  {
   d[i]=mat[v][i];
   p[i]=v;
  }
  else if(mat[v][i]!=0) 
  {
   d[i]=9999;
   p[i]=-1;
  }
 }
 for(i=0;i<n;i++)
 {if(i!=v)
  {q.push(i);cout<<"hi2";}
 }
 int prev=v;
 while(!q.empty())
 {
   q.sort(d);
   int ver=q.pop();
   vis[ver]=1;
  
   for(i=0;i<n;i++)
   {if(mat[ver][i]!=0&&mat[ver][i]!=9999)
    {
    if(vis[i]==1)continue;
    if(d[i]>(d[ver]+mat[ver][i]))
      {d[i]=d[ver]+mat[ver][i];
       p[i]=ver;
       }
   }}
 }
}
int main()
{
 int n,v;
 cout<<"Enter No of vertices:\n";
 cin>>n;
 int d[100]={0},mat[100][100],p[100];
 cout<<"Enter Adjacency distance Matrix:\n";
 for(int i=0;i<n;i++)
 for(int j=0;j<n;j++)
 cin>>mat[i][j];
 cout<<"Enter Source Matrix\n";
 cin>>v;
 dijkstra(d,mat,v,p,n);
 cout<<"Dijkstras solution:\n";
 for(int i=0;i<n;i++)
 {cout<<d[i]<<" "<<p[i]<<"\t";}
}
