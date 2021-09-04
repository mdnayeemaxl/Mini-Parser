#include <iostream>
#include <string>
#include<cstdio>
#include<cstdlib>
#include <fstream>
using namespace std;
int c=1,t=0;
char a[100],a1[100];
struct node
{  char data;
    int line;
    struct node *next;
};
struct node *top=NULL,*top1=NULL,*top2=NULL,*head=NULL;


char push( char ch)
{  if(ch=='('){
    struct node *curr;
    curr=(struct node*) malloc (sizeof (struct node));
    curr->next=top;
    top=curr;
}
else if(ch=='[')
{
      struct node *cur;
    cur=(struct node*) malloc (sizeof (struct node));
    cur->next=top1;
    top1=cur;
}
else if(ch=='{')
    {
            struct node *cur1;
    cur1=(struct node*) malloc (sizeof (struct node));
    cur1->line=c;
    if(top2==NULL)
    {
        cur1->next=NULL;
        top2=cur1;
    }
    else{
    cur1->next=top2;
    top2=cur1;
    }
}
}


void pop(char p)
{
    if(p==')'){
    struct node *temp;
    temp=top;
    top=top->next;
    free(temp);
    }
    else if(p==']')
    {
          struct node *temp1;
    temp1=top1;
    top1=top1->next;
    free(temp1);

    }
    else if(p=='}')
    {
    struct node *temp2;
    temp2=top2;
    top2=top2->next;
    free(temp2);
    }
}


void destroy()
{

    struct node *temp,*l;
    while(top!=NULL)
    {
        l=top->next;
        free(top);
        top=l;
    }
}


void destroy2()
{

    struct node *temp3,*l2;
    while(top1!=NULL)
    {
        l2=top1->next;
        free(top1);
        top1=l2;
    }
}


void clist(char ti)
{
            struct node *sta;
sta=(struct node*) malloc (sizeof (struct node));
    sta->data=ti;
    if(head==NULL)
    {
        sta->next=NULL;
        head=sta;
    }
    else{
    sta->next=head;
    head=sta;
    }
}


int check2(char r)
{
    int y=0;
        struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==r)
    {
     y=1;
    }

        temp=temp->next;
    }
    return y;
}


void check(char a1[],int n1)
{
    for(int i=0;i<n1;i++)
    {
         int d9=0,f9=0;

        if(a1[i]=='>'||a1[i]=='<'||a1[i]=='+'||a1[i]=='-'||a1[i]=='*'||a1[i]=='/'||a1[i]=='='||a1[i]=='%')
        {

          d9=check2(a1[i+1]);


        if(a1[i+1]>='a' && a1[i+1]<='z'){
        if(d9!=1)
          {
           cout<<a1[i+1]<<" is not declare in the scope "<<endl;
          }
        }

          f9=check2(a1[i-1]);
        if(a1[i-1]>='a' && a1[i-1]<='z'){
          if(f9!=1)
          {
           cout<<a1[i-1]<<" is not declare in the scope "<<endl;
          }
         }
        }
    }
}


void perse(char a[],int n){

    for(int i=0; i<n; i++){

      if((a[i]=='(' || a[i]==')') && a[n-1]!=';')
        {
            if('('==a[i])
            {
                push(a[i]);
            }

            else if(')'==a[i])
            {
                if(top==NULL)
                {
                    cout<<"opening (  missing in line number "<<c<<endl;
                }
                else
                {
                    pop(a[i]);
                }
            }
        }


 else if((a[i]=='(' || a[i]==')') && a[n-1]==';' )
        {
            if('('==a[i])
            {
                push(a[i]);
            }

            else if(')'==a[i])
            {
                if(top==NULL)
                {
                    cout<<"opening (  missing of line number "<<c<<endl;
                }
                else
                {
                    pop(a[i]);
                }
            }
        }

       else  if((a[i]=='['||a[i]==']') && a[n-1]==';')
        {
            if('['==a[i])
            {
                push(a[i]);
            }

            else if(']'==a[i])
            {
                if(top1==NULL)
                {
                    cout<<"opening [ missing in line number "<<c<<endl;
                }
                else
                {
                    pop(a[i]);
                }

        }
        }
      else  if((a[i]=='{'||a[i]=='}') && a[n-1]!=';')
            {
                 if('{'==a[i])
            {
                push(a[i]);
            }

            else
            {if(top2==NULL)
              {
                  cout<<"Opening { missing in line "<<c<<endl;
              }
              else{
            pop(a[i]);
              }
            }
            }

            }

    if(top!=NULL)
    {
        cout<<"closing ) missing in line "<<c<<endl;

    }
    if(top1!=NULL)
    {
        cout<<"closing ] missing in line "<<c<<endl;

    }
    destroy();
    destroy2();

}


void indenty(char a[],int n)
{
  if(a[0]=='i'&&a[1]=='n'&&a[2]=='t' && a[n-1]==';')
{int l=4;
  while(a[l]!='\0'){
        if(a[l]>='a' && a[l]<='z' )
  {
       //cout<<"a[l] ="<<a[l]<<endl;
       clist(a[l]);
  }
  l++;
}
}
  if(a[0]=='f' && a[1]=='l'&& a[2]=='o' && a[3]=='a' && a[4]=='t' && a[n-1]==';'){
    int s=6;
  while(a[s]!='\0'){
        if(a[s]>='a' && a[s]<='z' )
  {
       //cout<<"a[l] ="<<a[l]<<endl;
       clist(a[s]);
  }
  s++;
}
}
}

void display()
{
     struct node *temp;
    temp=head;
    while(temp!=NULL)
    {

        cout<<temp->data<<"  ";
        temp=temp->next;
    }
}


int main()
{
    int i,j;
    ifstream infile;
    infile.open("mathExpression.txt");
    string line;
    string vari;


    while (getline(infile, line))
    {
        i=0;
        while(line[i]!='\0')
        {
            a[i]=line[i];
            i++;
        }
        perse(a,i);
        indenty(a,i);
        cout<<endl;

        c++;
    }
    if(top2!=NULL)
    {
     while(top2!=NULL)
     {
      cout<<" Closing } missing for line "<<top2->line<<endl;
      top2=top2->next;
     }
    }
    infile.close();


    ifstream inf;
    inf.open("mathExpression.txt");
        while (getline(inf,vari))
    {
        j=0;
        while(vari[j]!='\0')
        {
            a1[j]=vari[j];
            j++;
        }
check(a1,j);
    }

    inf.close();
    return 0;
}



