#include<iostream.h>
#include<conio.h>
#include<string.h>
const int m=100;
class stck
{
 char s[m][m];
 int top;
 public:
 void push(char *);
 char* pop();
 stck(){top=-1;}
};
void stck::push(char *str)
{
 if(top==m-1)
 {cout<<"overflow";
  return;}
 strcpy(s[++top],str);
}
char *stck::pop()
{
 if(top==-1)
 {cout<<"Underflow";
  return "@";
 }
 return s[top--];
}
void conv(char *pre,char *res,stck s)
{
 strrev(pre);
 char a[m],e1[m],e2[m];
 for(int i=0;pre[i]!='\0';i++)
 {
  a[0]=pre[i];
  a[1]='\0';
  if(a[0]=='+'||a[0]=='-'||a[0]=='*'||a[0]=='/'||a[0]=='^')
  {
   strcpy(e1,s.pop());
   strcpy(e2,s.pop());
   strcpy(res,e1);
   strcat(res,e2);
   strcat(res,a);
   s.push(res);
  }
  else
  s.push(a);
 }
 cout<<"The expression:\n"<<res;
}
void main()
{
 stck s;
 clrscr();
 char pre[m],res[m];
 cout<<"Enter prefix:\n";
 cin>>pre;
 conv(pre,res,s);
 getch();
}
