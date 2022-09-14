#include <iostream>
#include <cstdlib>
using namespace std;

//Darius Morar
//HW 3 pt 1

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
	void INORDER_TREE_WALK(node*);
	void TREE_INSERT(int);

	void PRE_ORDER_TREE_WALK(node*);
	void POST_ORDER_TREE_WALK(node*);
	node* FIND_MAX(node*);
	void REMOVE_MAX(node*);
	node* FIND_MIN(node*);
	node* SUCCESSOR(int);
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

void BinarySearchTree::PRE_ORDER_TREE_WALK(node* x)
{
	if (x != NULL)
	{
		cout << " " << x->key << " ";
		if (x->left) PRE_ORDER_TREE_WALK(x->left);
		if (x->right) PRE_ORDER_TREE_WALK(x->right);
	}
}

void BinarySearchTree::POST_ORDER_TREE_WALK(node* x)
{
	if (x != NULL)
	{
		if (x->left) POST_ORDER_TREE_WALK(x->left);
		if (x->right) POST_ORDER_TREE_WALK(x->right);
		cout << " " << x->key << " ";
	}
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

BinarySearchTree::node* BinarySearchTree::FIND_MAX(node* x)
{
	while(x->right != NULL)
	{
		x = x->right;
	}
	return x;
}

void BinarySearchTree::REMOVE_MAX(node* x)
{
	while(x->right->right != NULL)
	{
		x = x->right;
	}
	delete(x->right);
	x->right = NULL;

}

//we need this method in order to use successor
BinarySearchTree::node* BinarySearchTree::FIND_MIN(node* x)
{
	while(x->left != NULL)
	{
		x = x->left;
	}
	return x;
}

BinarySearchTree::node* BinarySearchTree::SUCCESSOR(int key)
{
	node* x = NULL;
	node* y = NULL;

	if(x->right != NULL)
	{
		return FIND_MIN(x->right);
	}
	y = x->parent;
	while(y != NULL && x == y->right)
	{
		x = y;
		y = y->parent;
	}
	return y;

}

void BinarySearchTree::TRANSPLANT(node* x, node* y)
{

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
	while (true)
	{
		cout << endl << endl;
		cout << " Binary Search Tree Example " << endl;
		cout << " ----------------------------- " << endl;
		cout << " 1. Insert a Node " << endl;
		cout << " 2. Pre-Order Traversal " << endl;
		cout << " 3. Post-Order Traversal " << endl;
		cout << " 4. In-Order Traversal " << endl;
		cout << " 5. Find Max " << endl;
		cout << " 6. Remove Max " << endl;
		cout << " 7. Successor " << endl;
		cout << " 8. Delete a Node " << endl;
		cout << " 9. Exit " << endl;
		cout << " Enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << " Enter key (int value) to be inserted : ";
			cin >> key;
			bst.TREE_INSERT(key);
			break;
		case 2: cout << endl;
			cout << " Pre-Order Traversal " << endl;
			cout << " -------------------" << endl;
			bst.PRE_ORDER_TREE_WALK(bst.root);
			break;
		case 3: cout << endl;
			cout << " Post-Order Traversal " << endl;
			cout << " -------------------" << endl;
			bst.POST_ORDER_TREE_WALK(bst.root);
			break;
		case 4: cout << endl;
			cout << " In-Order Traversal " << endl;
			cout << " -------------------" << endl;
			bst.INORDER_TREE_WALK(bst.root);
			break;
		case 5: cout << endl;
			cout << " Find Max " << endl;
			cout << " -------------------" << endl;
			cout << bst.FIND_MAX(bst.root)->key << endl;
			break;
		case 6: cout << endl;
			cout << " Remove Max " << endl;
			cout << " -------------------" << endl;
			bst.REMOVE_MAX(bst.root);
			cout << "Removed Max" << endl;
			break;
		case 7: cout << endl;
			cout << " Eneter key (int value) in order to find its successor: ";
			cin >> key;
			cout << " Successor " << endl;
			cout << " -------------------" << endl;
			if(bst.SUCCESSOR(key) == NULL)
			{
				cout << "There is no successor" << endl;
			} 
			else
			{
				cout << bst.SUCCESSOR(key)->key << endl;
			}
			break;
		case 8: cout << endl;
			cout << " Delete a Node " << endl;
			cout << " -------------------" << endl;
			//bst.DELETE(bst.root);
			break;
		case 9: system("pause");
			return 0;
			break;
		default:
			cout << "Invalid choice";
		}
	}
}