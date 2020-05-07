#include<iostream.h>
#include<conio.h>
#include<math.h>
const int max=100;
isoperator(char );
int findres(int,int,char);
class stack
{
 int top;
 int s[max];
 public:
 void push(int );
 int pop();
 void disp();
 isempty();
 stack(){top=-1;}
};
void stack::push(int ele)
{
 if(top==max-1)
 {cout<<"overflow";
  return;
 }
 s[++top]=ele;
}
int stack::pop()
{
 if(top==-1)
 {cout<<"underflow";
  return -99;}
 int x=s[top];
 top--;
 return x;
}
void stack::disp()
{for(int i=0;i<=top;i++)
 {cout<<s[i]<<" ";}
}
stack::isempty()
{
 if(top==-1){return 1;}
 else{return 0;}
}
void evalpost(char *pf,stack s)
{
 for(int i=0;pf[i]!='\0';i++)
 {if(isoperator(pf[i])==0)
  {s.push(pf[i]-'0');}
  else
  {if(!s.isempty())
   {
    int e2=s.pop();
    int e1=s.pop();
    int res=findres(e1,e2,pf[i]);
    s.push(res);
   }
  }
 }
 cout<<"\nValue=";
 s.disp();
}
isoperator(char c)
{switch(c)
 {
  case '+':
  case '-':
  case '*':
  case '/':
  case '^':return 1;
  default:return 0;
 }
}
int findres(int e1,int e2,char p)
{switch(p)
 {case '+':return (e1+e2);
  case '-':return (e1-e2);
  case '*':return (e1*e2);
  case '/':return (e1/e2);
  case '^':return pow(e1,e2);
  default:return -99;
 }
}
void main()
{
 clrscr();
 char exp[max];
 int res;
 stack s;
 cout<<"Enter postfix expression\n";
 cin>>exp;
 evalpost(exp,s);
 getch();
}