#include<iostream.h>
#include<conio.h>
#include<string.h>
const int max=100;
class stack
{
 int top;
 char s[max][max];
 public:
 stack(){top=-1;}
 void push(char *);
 char* pop();
 void disp();
};
void stack::push(char *str)
{
 if(top==max-1)
 {cout<<"Overflow";
  return;}
 strcpy(s[++top],str);
}
char* stack::pop()
{if(top==-1)
 {cout<<"underflow";
  return "@";
 }
 return s[top--];
}
void stack::disp()
{for(int i=0;i<=top;i++)
 {cout<<s[i]<<endl;}
}
void convin(char *pf,stack s)
{
 char ch[max],e1[max],e2[max],res[max];
 for(int i=0;pf[i]!='\0';i++)
 {ch[0]=pf[i];
  ch[i]='\0';
  if(ch[0]=='+' || ch[0]== '-' || ch[0]=='*' || ch[0] == '/')
  {strcpy(e1,s.pop());
   strcpy(e2,s.pop());
   strcpy(res,"(");
   strcat(res,e1);
   strcat(res,ch);
   strcat(res,e1);
   strcat(res,")");
   s.push(res);
  }
  else{s.push(ch);}
 }
 cout<<"\nInfix expression is:\n";
 s.disp();
}
void main()
{
 clrscr();
 char pf[max];
 stack s1;
 cout<<"Enter postfix expression:\n";
 cin>>pf;
 convin(pf,s1);
 getch();
}