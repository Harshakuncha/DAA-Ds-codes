#include<iostream>
using namespace std;
void add(int a[][10],int b[][10],int c[][10],int n,int cons)
{
 for(int i=0;i<n;i++)
 {for(int j=0;j<n;j++)
	{if(cons==0)
         c[i][j]=a[i][j]+b[i][j];
         else
          c[i][j]=a[i][j]-b[i][j];
         }
 }
}
void multiply(int a[][10],int b[][10],int c[][10],int n)
{
 for(int i=0;i<n;i++)
 {for(int j=0;j<n;j++)
	{c[i][j]=0;
	 for(int k=0;k<n;k++)
	  {
		c[i][j]+=a[i][k]*b[k][j];	
 	  }
        }
 }
}

int main()
{
 int n,i,j,p,q;
 cout<<"Enter n:";
 cin>>n;
 if(n%2!=0)
	{cout<<"Wrong n\n";
	 return 0;}
 int a[10][10],b[10][10],c[10][10];
 int a1[10][10],a2[10][10],a3[10][10],a4[10][10];
 int b1[10][10],b2[10][10],b3[10][10],b4[10][10];
 int c1[10][10],c2[10][10],c3[10][10],c4[10][10];
 int temp[10][10],temp2[10][10];
 int d[10][10],e[10][10],f[10][10],g[10][10],h[10][10],I[10][10],J[10][10];
 cout<<"Enter A Matrix:\n";
 for(i=0;i<n;i++)
	for(j=0;j<n;j++)
		cin>>a[i][j];
 cout<<"Enter B Matrix:\n";
 for(i=0;i<n;i++)
	for(j=0;j<n;j++)
		cin>>b[i][j];
 for(i=0;i<n/2;i++)
	for(j=0;j<n/2;j++)
		{a1[i][j]=a[i][j];
		 b1[i][j]=b[i][j];}
 for(i=0,p=0;i<n/2;i++,p++)
	for(j=n/2,q=0;j<n;j++,q++)
		{a2[p][q]=a[i][j];
		 b2[p][q]=b[i][j];}
 for(i=n/2,p=0;i<n;i++,p++)
	for(j=0,q=0;j<n/2;j++,q++)
		{a3[p][q]=a[i][j];
		 b3[p][q]=b[i][j];}
 for(i=n/2,p=0;i<n;i++,p++)
	for(j=n/2,q=0;j<n;j++,q++)
		{a4[p][q]=a[i][j];
		 b4[p][q]=b[i][j];}
 add(b2,b4,temp,n/2,1);
 multiply(a1,temp,d,n/2);
 add(b3,b1,temp,n/2,1);
 multiply(a4,temp,e,n/2);
 add(a3,a4,temp,n/2,0);
 multiply(temp,b1,f,n/2);
 add(a1,a2,temp,n/2,0);
 multiply(b4,temp,g,n/2);
 add(a3,a1,temp,n/2,1);
 add(b1,b2,temp2,n/2,0);
 multiply(temp,temp2,h,n/2);
 add(a2,a4,temp,n/2,1);
 add(b3,b4,temp2,n/2,0);
 multiply(temp,temp2,I,n/2);
 add(a1,a4,temp,n/2,0);
 add(b1,b4,temp2,n/2,0);
 multiply(temp,temp2,J,n/2);
 add(e,I,temp,n/2,0);
 add(temp,J,temp2,n/2,0);
 add(temp2,g,c1,n/2,1);
 add(d,g,c2,n/2,0);
 add(e,f,c3,n/2,0);
 add(d,h,temp,n/2,0);
 add(temp,J,temp2,n/2,0);
 add(temp2,f,c4,n/2,1);
 for(i=0;i<n/2;i++)
  {for(j=0;j<n/2;j++)
    cout<<c1[i][j];
   cout<<endl;
  }
 cout<<endl;
 for(i=0;i<n/2;i++)
  {for(j=0;j<n/2;j++)
    cout<<c2[i][j];
   cout<<endl;
  }
 cout<<endl;
 for(i=0;i<n/2;i++)
  {for(j=0;j<n/2;j++)
    cout<<c3[i][j];
   cout<<endl;
  }
 cout<<endl;
 for(i=0;i<n/2;i++)
  {for(j=0;j<n/2;j++)
    cout<<c4[i][j];
   cout<<endl;
  }
 /*for(p=0,i=0;i<n/2;i++)
 {for(j=0,q=0;i*/
}

