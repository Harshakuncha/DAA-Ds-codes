#include<iostream.h>
#include<conio.h>
const int max=100;
int prec(char );
class stack
{
 int top;
 char s[max];
 public:
 void push(char );
 char pop();
 void disp();
 isempty();
 stack(){top=-1;}
};
void stack::push(char ele)
{
 if(top==max-1)
 {cout<<"overflow";
  return;
 }
 s[++top]=ele;
}
char stack::pop()
{
 if(top==-1)
 {cout<<"underflow";
  return '@';}
 char x=s[top];
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
void convPost(char *in,char *pf,stack s)
{
 int k=0,i;
 for(i=0;in[i]!='\0';i++)
 {char e1,e2;
  e1=in[i];
  switch(e1)
  {
   case '(':s.push(e1);
	    break;
   case ')'://while((e2=s.pop())!='(')
	    //{pf[k++]=e2;}
	    if((e2=s.pop())=='(')
	    {break;}
	    else
	    { pf[k++]=e2;
	     i--;}
	    break;
   case '+':
   case '-':
   case '*':
   case '/':
   case '^':if(!s.isempty())
	    {e2=s.pop();
	     while(prec(e1)<=prec(e2))
	     {pf[k++]=e2;
	      if(!s.isempty())
	      {e2=s.pop();}
	      else
	      {break;}
	     }
	    }
	    if (prec(e1)>prec(e2))
	    {s.push(e2);}
	    s.push(e1);
	    break;
   default:pf[k++]=e1;
	   break;
  }
 }
 while(!s.isempty())
 pf[k++]=s.pop();
 pf[k]='\0';
 cout<<pf;
}
int prec(char c)
{switch(c)
 {case '+':
  case '-':return 1;
  case '*':
  case '/':return 2;
  case '^':return 3;
  default:return 0;
 }
}
void main()
{
 clrscr();
 stack s1;
 char exp[max],res[max];
 cout<<"Enter the expression\n";
 cin>>exp;
 cout<<"The postfix expresion is:\n";
 convPost(exp,res,s1);
 getch();
}