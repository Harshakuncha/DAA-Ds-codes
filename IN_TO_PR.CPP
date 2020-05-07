#include<iostream.h>
#include<conio.h>
#include<string.h>
const int max=100;
class stack
{
 char s[max];
 int top;
 public:
 void push(char);
 char pop();
 stack(){top=-1;}
 isempty();
};
void stack::push(char ch)
{
 if(top==max-1)
 {cout<<"overflow";
  return;}
 s[++top]=ch;
}
char stack::pop()
{
 if(top==-1)
 {cout<<"Underflow";
  return '@';
 }
 return s[top--];
}
stack::isempty()
{
 if(top==-1)
 {return 1;}
 else
 return 0;
}
int prec(char ch)
{
 switch(ch)
 {
  case '^':return 3;
  case '*':
  case '/':return 2;
  case '+':
  case '-':return 1;
  default: return 0;
 }
}
void convPre(char *in,char *pre,stack s)
{
 int i,k=0;
 char e1,e2;
 strrev(in);
 for(i=0;in[i]!='\0';i++)
 {
  e1=in[i];
  switch(e1)
  {
   case ')':s.push(e1);
	    break;
   case '(':while((e2=s.pop())!=')')
	    {pre[k++]=e2;}
   case '+':
   case '-':
   case '*':
   case '/':
   case '^':if(!s.isempty())
	    {
	     e2=s.pop();
	     while(prec(e1)<prec(e2))
	     {if(!s.isempty())
	      {pre[k++]=e2;
	       if(!s.isempty())
	       {e2=s.pop();}
	       else
	       {break;}
	      }
	      else
	      {pre[k++]=e2;
	       break;
	      }
	     }
	     if(prec(e1)>=prec(e2))
	     {s.push(e2);}

	     s.push(e1);
	    }
	    else
	    {s.push(e1);}
	    break;
   default:pre[k++]=e1;
	   break;
  }
 }
 while(!s.isempty())
 {pre[k++]=s.pop();}
 pre[k]='\0';
 strrev(pre);
 cout<<"\nThe prefix expression:\n";
 cout<<pre;
}
void main()
{clrscr();
 char in[max],pre[max];
 stack s;
 cout<<"Enter the expression";
 cin>>in;
 convPre(in,pre,s);
 getch();
}
