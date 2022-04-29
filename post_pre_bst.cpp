#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};

struct tree *root = NULL;

struct tree *insert(struct tree *r, int val)
{
    struct tree *newnode = new tree; // allocating memory for a node: newnode
    newnode->data = val; // assigning a value to the node's data field
    newnode->left = NULL;  // initializing the node's next and previous addresses to NULL
    newnode->right = NULL;
    if (r == NULL)
    {
        r = newnode;
    }
    else if (val < r->data)
    {
        r->left = insert(r->left, val); //recursively calling & traversing the left side of the tree
    }
    else
    {
        r->right = insert(r->right, val); //recursively calling & traversing the right side of the tree
    }
    return r;
}

void inorder(struct tree *r) //inorder display: L N R
{
    if (r != NULL)
    {
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }
}

void postorder(struct tree *r) //postorder diaplay: L R N
{
    if (r != NULL)
    {
        postorder(r->left);
        postorder(r->right);
        cout << r->data << " ";
    }
}

void preorder(struct tree *r) //preorder display: N L R
{
    if (r != NULL)
    {
        cout << r->data << " ";
        preorder(r->left);
        preorder(r->right);
    }
}

void search(struct tree *r, int val) //to search if the specified element exists in the tree or not
{
    if (r != NULL)
    {
        if (r->data == val)
        {
            cout << "Element found in the Binary Tree!" << endl;
        }
        else if (val < r->data)
        {
            return search(r->left, val); //to traverse the left part of the root
        }
        else
        {
            return search(r->right, val); //to traverse the right part of the root
        }
    }
    else
    {
        cout << "Element not found in the tree!" << endl;
    }
}

int main()
{
    int choice = 0;
    int choice2 = 0;
    int create_counter = 0;
    int in_val = 0;
    string v = "";

    do
    {
        cout << "\nBST OPERATIONS\n1. Create\n2. Insert\n3. Display\n4. Search\n5. Exit" << endl;
        cout << "Enter: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            // v="";
            cout << "\nEnter a value or enter `e` to exit" << endl;
            while (v != "e")
            {
                cout << "Enter a value to insert: " << endl;
                cin >> v;
                if (v == "e")
                    break;
                stringstream value(v);
                int x = 0;
                value >> x;
                insert(root, x);
                v = "";
            }
            break;
        case 2:
            cout << "Enter a value to insert: " << endl;
            cin >> in_val;
            root = insert(root, in_val);
            break;

        case 3:
            cout << "\nHow do you want to display?\n1. Preorder\n2. Inorder\n3. Postorder\n4. Back" << endl;
            cin >> choice2;
            switch (choice2)
            {
            case 1:
                cout << endl;
                for (int i = 0; i < create_counter * 3; i++)
                {
                    cout << "-";
                }
                cout << endl;
                cout << "PREORDER DISPLAY" << endl;
                preorder(root);
                for (int i = 0; i < create_counter * 3; i++)
                {
                    cout << "-";
                }
                cout << endl;

                break;
            case 2:
                cout << endl;
                for (int i = 0; i < create_counter * 3; i++)
                {
                    cout << "-";
                }
                cout << endl;
                cout << "INORDER DISPLAY" << endl;
                inorder(root);
                for (int i = 0; i < create_counter * 3; i++)
                {
                    cout << "-";
                }
                cout << endl;

                break;
            case 3:
                cout << endl;
                for (int i = 0; i < create_counter * 3; i++)
                {
                    cout << "-";
                }
                cout << endl;
                cout << "POSTORDER DISPLAY" << endl;
                postorder(root);
                for (int i = 0; i < create_counter * 3; i++)
                {
                    cout << "-";
                }
                cout << endl;

                break;
            case 4:
                break;
            default:
                cout << "\nInvalid Input" << endl;
            }
            break;

        case 4:
            cout << "Enter a value to search: " << endl;
            cin >> in_val;
            search(root, in_val);
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