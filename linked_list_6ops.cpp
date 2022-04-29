#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

int create_counter = 0;
struct node *head = NULL;

void create() // to create a linked list
{
    string v = "";
    cout << "\nEnter a value or enter `e` to exit" << endl;
    while (v != "e")
    {
        struct node *newnode = new node;
        cout << "Enter a value to insert: " << endl;
        cin >> v;
        if (v == "e")
            break;
        stringstream value(v); // converting string input to integer
        int x = 0;
        value >> x;
        newnode->data = x;
        newnode->next = NULL;
        if (head == NULL) // for the first node in the list
        {
            head = newnode;
        }
        else // performing insertions in end here
        {
            struct node *ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newnode;
        }
        create_counter++; // to store the size of the list created
    }
    cout << "\nCreated a linked list of size " << create_counter << endl;
}

void in_begin(int value) // to insert an element in the beginning of the list
{
    struct node *newnode = new node; // allocating memory for a node: newnode
    newnode->data = value;           // assigning a value to the node's data space
    newnode->next = head;            // assigning address of head to the address pointer of newnode, in order to create a link
    head = newnode;                  // making the newnode head since it is now the first node
    cout << value << " added to the list at the beginning!" << endl;
}

void in_end(int value) // to insert an element at the end of the list
{
    struct node *newnode = new node;
    newnode->data = value;
    newnode->next = NULL;
    if (head == NULL) // if the list is empty
    {
        head = newnode;
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
    cout << value << " added to the list at the end!" << endl;
}

void in_after(int value, int pos) // to insert an element after a specified node, in the list
{
    struct node *newnode = new node;
    struct node *ptr = head;    // initializing a pointer which will traverse ahead preptr, until preptr reaches the node after which insertion is to happen
    struct node *preptr = head; // initializing another pointer variable to traverse up till the node after which a new node is to be inserted
    int check = 0;              // counter variable to check whether the specified node to insert after exists or not

    while (preptr->data != pos) // traversing uptil the node after which a node has to be inserted
    {
        preptr = ptr;
        ptr = ptr->next;
        if (ptr == NULL) // if the traversal reaches end of the list, which means, the specified node does not exist
        {
            check = 1;
            break;
        }
    }
    if (check == 1)
    {
        cout << "Specified data does not exist!" << endl;
    }
    else
    {
        preptr->next = newnode;
        newnode->data = value;
        newnode->next = ptr;
    }
    cout << value << " added to the list after " << pos << endl;
}

void in_before(int value, int pos) // to insert an element before a specified node, in the list
{
    struct node *newnode = new node;
    struct node *ptr = head;    // initializing a pointer variable to traverse until the node before which a new node is to be inserted
    struct node *preptr = head; // initializing another pointer which will traverse behind ptr, until the ptr reaches the node before which insertion has to happen
    int check = 0;

    while (ptr->data != pos)
    {
        preptr = ptr;
        ptr = ptr->next;
        if (ptr == NULL)
        {
            check = 1;
            break;
        }
    }
    if (check == 1)
    {
        cout << "Specified node data does not exist!" << endl;
    }
    else
    {
        preptr->next = newnode;
        newnode->data = value;
        newnode->next = ptr;
    }
    cout << value << " added to the list before " << pos << endl;
}

void del_begin() // to delete the first node of the list
{
    if (head == NULL) // if no node exists, no deletions can take place, therefore, the underflow condition
    {
        cout << "\nUNDERFLOW!" << endl;
    }
    else
    {
        struct node *temp = head; // temporary variable to store the first node which is to be deleted
        head = head->next;        // shifting the head to second node
        free(temp);               // deleting the first node
        cout << "\nFirst element deleted!" << endl;
    }
}

void del_end() // to delete the last node of the list
{
    if (head == NULL)
    {
        cout << "\nUNDERFLOW!" << endl;
    }
    else
    {
        struct node *ptr = head;    // pointer variable to traverse until the last node of the list
        struct node *preptr = head; // pointer variable to traverse until the second last node of the list
        while (ptr->next != NULL)   // to traverse until it reaches the last node of the list
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = NULL; // since last node is to be deleted, the second last node now points to NULL
        free(ptr);           // deleting the last node
        cout << "\nLast element deleted!" << endl;
    }
}

void del_value(int value) // to delete the specified node
{
    if (head == NULL)
    {
        cout << "\nUNDERFLOW!" << endl;
    }
    else
    {
        struct node *ptr = head;    // pointer variable to traverse until the node which is to be deleted
        struct node *preptr = head; // pointer variable to traverse behind ptr until ptr reaches the node which is to be deleted
        struct node *proptr = head; // pointer variable to traverse ahead of ptr until ptr reaches the node which is to be deleted
        int check = 0;              // counter variable to check whether the specified node to delete, exists or not

        while (ptr->data != value) // traverseing until ptr reaches the node which is to be deleted
        {
            preptr = ptr;
            ptr = ptr->next;
            if (ptr == NULL)
            {
                check = 1;
                break;
            }
            else
            {
                proptr = ptr->next;
            }
        }
        if (check == 1)
        {
            cout << "\nValue does not exist!" << endl;
        }
        else
        {
            preptr->next = proptr;
            free(ptr);
            cout << "\nElement deleted!" << endl;
        }
    }
}

void del_after(int pos)
{
    if (head == NULL)
    {
        cout << "\nUNDERFLOW!" << endl;
    }
    else
    {
        struct node *newnode = new node;
        struct node *ptr = head;    // to traverse ahead of preptr, and store the node which is to be deleted
        struct node *preptr = head; // initializing a pointer variable to traverse until the node after which a node has to be deleted
        struct node *proptr = head; // to traverse ahead ptr and store the node before which a node has to be deleted
        int check = 0;              // counter variable to check whether the specified node to delete after exists or not

        while (preptr->data != pos)
        {
            preptr = ptr;
            ptr = ptr->next;

            if (ptr == NULL)
            {
                check = 1;
                break;
            }
            else
                proptr = ptr->next;
        }
        if (check == 1)
        {
            cout << "\nSpecified node/ node after specified node does not exist!" << endl;
        }
        else
        {
            preptr->next = proptr;
            free(ptr);
            cout << "\nElement after " << pos << " deleted!" << endl;
        }
    }
}

void display() //to display the data of each node in the linked list
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " "; // printing data of each node as the pointer traverses until the last node
        ptr = ptr->next;
    }
    cout << "\n";
}

int main()
{
    int choice = 0;  // to store the user input of outer switch cases
    int in_val = 0;  // to store the value which is to be inserted
    int choice2 = 0; // to store the user input of inner (nested) switch cases
    int pos = 0;     // to store the position of node after/before which an element is to be inserted/deleted
    
    do
    {
        cout << "\nLINKED LISTS OPERATIONS\n1. Create\n2. Insert\n3. Delete\n4. Display\n5. Exit" << endl;
        cout << "Enter: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (create_counter == 0)
            {
                create();
            }
            else
            {
                cout << "\nLinked List is already created!" << endl;
            }
            break;

        case 2:
            if (create_counter == 0)
            {
                cout << "\nYou need to create a linked list first!" << endl;
                break;
            }
            else
            {
                cout << "\nWhere do you want to insert?\n1. Beginning\n2. End\n3. Before a node\n4. After a node\n5. Back" << endl;
                cin >> choice2;
                switch (choice2)
                {
                case 1:
                    cout << ">>>INSERT BEGINNING<<<\nEnter a value to insert: " << endl;
                    cin >> in_val;
                    in_begin(in_val);
                    break;
                case 2:
                    cout << ">>>INSERT END<<<\nEnter a value to insert: " << endl;
                    cin >> in_val;
                    in_end(in_val);
                    break;
                case 3:
                    cout << ">>>INSERT BEFORE<<<\nEnter a value to insert: " << endl;
                    cin >> in_val;
                    cout << "Insert before which value?" << endl;
                    cin >> pos;
                    in_before(in_val, pos);
                    break;
                case 4:
                    cout << ">>>INSERT AFTER<<<\nEnter a value to insert: " << endl;
                    cin >> in_val;
                    cout << "Insert after which value?" << endl;
                    cin >> pos;
                    in_after(in_val, pos);
                    break;
                case 5:
                    break;
                default:
                    cout << "\nInvalid Input" << endl;
                }
            }
            break;

        case 3:
            if (create_counter == 0)
            {
                cout << "\nYou need to create a linked list first!" << endl;
                break;
            }
            else
            {
                cout << "\nWhere do you want to delete from?\n1. Beginning\n2. End\n3. A value\n4. After a node\n5. Back" << endl;
                cin >> choice2;
                switch (choice2)
                {
                case 1:
                    del_begin();
                    break;
                case 2:
                    del_end();
                    break;
                case 3:
                    cout << ">>>DELETE VALUE<<<\nEnter a value to delete: " << endl;
                    cin >> in_val;
                    del_value(in_val);
                    break;
                case 4:
                    cout << ">>>DELETE AFTER<<<\nDelete after which value?" << endl;
                    cin >> pos;
                    del_after(pos);
                    break;
                case 5:
                    break;
                default:
                    cout << "\nInvalid Input" << endl;
                }
            }
            break;

        case 4:
            if (create_counter == 0)
            {
                cout << "\nList is empty. You need to create a linked list first!" << endl;
                break;
            }
            else
            {
                cout << endl;
                for (int i = 0; i < create_counter * 3; i++)
                {
                    cout << "-";
                }
                cout << endl;
                cout << "LINKED LIST" << endl;
                display();
                for (int i = 0; i < create_counter * 3; i++)
                {
                    cout << "-";
                }
                cout << endl;
            }
            break;

        case 5:
            cout << "Goodbye!" << endl;
            break;

        default:
            cout << "\nInvalid Input" << endl;
            break;
        }
    } while (choice < 5);
}
