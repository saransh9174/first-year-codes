#include <iostream>
#include <string.h>

using namespace std;

int counter=0;

int count()
{
    counter++;
    return counter;
}

int reset()
{
    counter=0;
}

int main()
{
    int choice;
    cout<<"Choose an option:\n1. Count\n2. Reset"<<endl;
    cin>>choice;

    if(choice==3)
    {
        cout<<"Goodbye";
    }
    else{

    switch(choice){
    case 1: 
            cout<<"Counter value: "<<count()<<endl;
            break;
    case 2: 
            reset();
            cout<<"Counter value has reset to 0"<<endl;
            break;
    case 3: cout<<"Goodbye";
            break;
    default: cout<<"Invalid Input";
            cout<<endl;
            break;
    }
    main();
    }
}



