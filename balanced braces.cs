#include <iostream>
#include <cstring>
using namespace std;


int stack[100];
int size=100;
int top=-1;
int push_counter=0;
int pop_counter=0;

string push(char ch,int n) //ascii (=40 {=123 [=91 )=41 }=125 ]=93
{
    if(top>(size-1)) //checks if the stack is full
    return "Overflow";
    else{
    stack[++top]=(int)ch;
    return "true"; //returns true when the element is pushed
 
    }
}

string pop(char ch)
{
    if(top<=-1)
    return "Underflow"; //checks if the stack is empty
    else if(ch==')' && (char)stack[top]=='(' || ch=='}' && (char)stack[top]=='{' || ch==']' && (char)stack[top]=='[') //pops element only when it finds a matching pair
    {
        top--;
        return "true";
    }
    else
    {
        return "false"; //returns false if ch does not have a matching pair
    }
}


int main()
{
    string str="";
    bool over_under=false; //counter variable for overflow and undeflow conditions
    cout<<"Enter a String: ";
    cin>>str;
    for(int i=0;i<str.length();i++)
    {
        if(str.at(i)=='('||str.at(i)=='{'||str.at(i)=='[')
        {
           
            string rs=push(str[i],push_counter);
            if(rs=="Overflow"){
                over_under=true;
                cout<<"OVERFLOW!";
            }
            else if(rs=="true")
            {
                push_counter++; //counter to keep track of current iteration of pushed element
                continue; //if element is successfully pushed, then the loop continues
            }
        }
        else if(str.at(i)==')'||str.at(i)=='}'||str.at(i)==']')
        {
            string r=pop(str.at(i));
            if(r=="Underflow"){
                over_under=true;
                cout<<"UNDERFLOW!";
                break;
            }
            else if(r=="false"){
                cout<<"The string is UNBALANCED!";
                break;
            }
            else if(r=="true"){
                pop_counter++; //counter to keep track of number of elements popped
            }
        }
    }
    if(push_counter==0) 
    cout<<"The string is INVALID!";
    else if(pop_counter==push_counter && over_under==false)
    cout<<"The string is BALANCED ";
    else if(push_counter<pop_counter || push_counter>pop_counter)
    cout<<"The string is UNBALANCED ";
}