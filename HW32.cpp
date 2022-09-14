#include <iostream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

//Darius Morar
//HW 3 pt 2

class BinarySearchTree
{
private:
	class node
	{
	public:
		node* left;
		node* right;
		node* parent;
		int key;
		string data;
	};

	
public:
	node* root;
	BinarySearchTree()
	{
		root = NULL;
	}
	bool isEmpty() const { return root == NULL; }
    void TREE_INSERT(int );
    void INORDER_TREE_WALK(node*);
    void TRANSPLANT(node*, node*);
    void DELETE(int);

};

void BinarySearchTree::TREE_INSERT(int d)
{
	// This implements the algorithm in page 261 of the textbook
	node* z = new node();
	z->key = d;
	z->left = NULL;
	z->right = NULL;

	node* y = NULL;
	node* x = root;
	node* parent = NULL;

	while (x != NULL)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	parent = y;
	if (y == NULL)
		root = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;
		
}

void BinarySearchTree::INORDER_TREE_WALK(node* x)
{
	if (x != NULL)
	{
		if (x->left) INORDER_TREE_WALK(x->left);
		cout << " " << x->key << " ";
		if (x->right) INORDER_TREE_WALK(x->right);
	}
	

}

void BinarySearchTree::TRANSPLANT(node* x, node* y)
{
    if(x->parent == NULL)
    {
        
    }
    else if (x == x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }
    if(y != NULL)
    {
        y->parent = x->parent;
    }
}

void BinarySearchTree::DELETE(int key)
{
	node* x = NULL;
	node* y = NULL;
	node* z = NULL;

	if(z->left == NULL)
	{
		cout << "Nope" << endl;
	}
}







int main()
{
	BinarySearchTree bst;
	int choice, key;
    string name;
	while (true)
	{
		cout << endl << endl;
		cout << " Binary Search Tree Example " << endl;
		cout << " ----------------------------- " << endl;
		cout << " 1. Enter a Flight " << endl;
		cout << " 2. Request Landing " << endl;
		cout << " 3. Withdraw Landing Request " << endl;
		cout << " 4. List Flights " << endl;
		cout << " 5. Exit " << endl;
		cout << " Enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1: 
            cout << "Enter flight name: ";
			cin >> name;
            cout << "Enter landing time: ";
            cin >> key;
			bst.TREE_INSERT(key);
			break;
		case 2: 
            cout << endl;
            cout << "Enter flight name: ";
            cin >> name;
            bst.DELETE(key);
/*			if(flight can land)
            {
                REMOVE();
                cout << "Flight ";
                cout << name;
                cout << " successfully landed!" << endl;
            }
            else
            {
                cout << "Flight ";
                cout << name;
                cout << " could not land." << endl;
            }
*/			break;
		case 3: 
            cout << endl;
            cout << "Enter flight name: ";
            cin >> name;
            cout << "Enter landing time: ";
            cin >> key;
			bst.TREE_INSERT(key);
			break;
		case 4: 
            cout << endl;
            bst.INORDER_TREE_WALK(bst.root);
			break;
		case 5: system("pause");
			return 0;
			break;
		default:
			cout << "Invalid choice";
		}
	}
}