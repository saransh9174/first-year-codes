#include <iostream>
using namespace std;
int main()
{
int num=0,counter=0, leave=1;
do
{
cout<<"\nEnter 1 to increase counter: "<<endl;
cout<<"\nEnter 2 to reset counter: "<<endl;
cout<<"\nEnter any number to exit counter: "<<endl;
cin>>num;
if(num==1)
{
//while(num !=2)
//{
counter=counter+1;
cout<<"\n COUNTER: "<<counter<<endl;
}
else if(num==2)
{
counter=0;
cout<<"\n COUNTER: "<<counter<<endl;
}
else
{
leave=0;
cout<<"\nCounter exited"<<endl;
}
}while(leave!=0);
return 0;
}