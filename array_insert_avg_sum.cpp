#include <iostream>
using namespace std;

int size;
int p;
int a[5];
int sum = 0;
int avg;

int insert(int element, int pos)
    {
        size++;
         for (int i=size;i>=pos;i--)
        a[i] = a[i - 1];

    a[pos - 1] = element;
    }

int sumcal()
{
    for(int i=0;i<size;i++)
    {
        sum+=a[i];
    }
    return sum;
}

int avgcl()
{
    avg=sum/size;
    return avg;
}

     int remove(int element)
    {
        int counter=0;
        for(int i=0;i<sizeof(a);i++)
        {
            if(a[i]==element)
            {
                for(int j=i;j<size-1;j++)
                {
                    a[j]=a[j+1];
                }
                counter++;
                i--;
                size--;
            }
        }
        if(counter==0)
        cout<<"Element not found!"<<endl;
        else
        cout<<"Element deleted!"<<endl;
    }

    void highLow()
    {
        int min=a[0];
        int max=a[0];

        for(int i=0;i<size;i++)
        {
            if(a[i]>max)
                max=a[i];
            else if(a[i]<min)
                min=a[i];
        }
    cout<<"Highest Element is: "<<max<<"\nSmallest Element is: "<<min<<endl;
    }

      void display()
    {
        for(int i=0;i<size;i++)
        {
            cout<<a[i]<<" ";
        }
    }

    void menu()
    {
        int choice;
        cout<<"Choose an option:\n1. Insert\n2. Remove\n3. Sum\n4. Average\n5. Higest & Lowest Element\n6. Exit"<<endl;
        cin>>choice;
        if(choice==1)
        {
            int e;
            cout<<"Enter element you want to insert: "<<endl;
            cin>>e;
             cout<<"Enter the position you want to insert the element at: "<<endl;
             cin>>p;
            insert(e,p);
            cout<<"Array after removing an element: "<<endl;
            display();
            cout<<endl;
            menu();
        }
        else if(choice==2)
        {
            cout<<"Enter element you want to remove: "<<endl;
             cin>>p;
             remove(p);
            cout<<"Array after removing an element: "<<endl;
            display();
            cout<<endl;
            menu();
        }
        else if(choice==3)
        {
            int tot=sumcal();
            cout<<"Sum of array elements: "<<tot<<endl;
            cout<<endl;
            menu();
        }
        else if(choice==4)
        {
            int tot2=avgcl();
           cout<<"Average of array elements: "<<tot2<<endl;
            cout<<endl;
            menu();
        }
        else if(choice==6)
        {
            cout<<"Goodbye";
        }
        else if(choice==5)
        {
            highLow();
            menu();
        }
        else
        {
            cout<<"Invalid Input";
        }
    }

int main()
{
    cout<<"Enter the size of array: ";
    cin>>size;
    a[size];
    cout<<"Enter "<<size<<" elements: "<<endl;
    for(int i=0;i<size;i++)
    {
         cin>>a[i];
    }
    cout<<"Original Array:"<<endl;
    display();
    cout<<endl;
    menu();
}



