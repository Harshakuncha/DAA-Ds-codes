#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<math.h>
const int m=100;
class stck
{
 int s[m],top;
 public:
 void push(int);
 int pop();
 isempty();
 stck(){top=-1;}
};
void stck::push(int num)
{
 if(top==m-1)
 {cout<<"overflow";
  return;
 }
 s[++top]=num;
}
int stck::pop()
{
 if(top==-1)
 {cout<<"Underflow";
  return -99;
 }
 return s[top--];
}
stck::isempty()
{if(top==-1)
 return 1;
 else
 return 0;
}
int findres(int e1,int e2,char c)
{
 switch(c)
 {
  case '+':return (e1+e2);
  case '-':return (e1-e2);
  case '*':return (e1*e2);
  case '/':return (e1/e2);
  case '^':return (pow(e1,e2));
  default:return 0;
 }
}
int isop(char ch)
{
 if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
 return 1;
 else
 return 0;
}
void preeval(char *pre,stck s)
{
 int e1,e2,res;
 strrev(pre);
 for(int i=0;pre[i]!='\0';i++)
 {
  char ch;
  ch=pre[i];
  if(!isop(ch))
  {s.push(ch-'0');}
  else
  {if(!s.isempty())
   {e1=s.pop();
    e2=s.pop();
    res=findres(e1,e2,ch);
    s.push(res);
   }
  }
 }
 cout<<"The answeris:"<<s.pop();
}
void main()
{
 clrscr();
 stck s;
 char pre[m];
 cout<<"Enter prefix Expression:\n";
 cin>>pre;
 preeval(pre,s);
 getch();
}
