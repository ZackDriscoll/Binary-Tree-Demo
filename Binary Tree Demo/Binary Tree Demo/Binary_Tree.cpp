#include "Binary_Tree.h"

using namespace std;

//Constructor to declare a new tree with a null root
Binary_Tree::Binary_Tree()
{
	root = NULL;
};

//Insert2 is used in Insert1, so this should be written first
//Insert 2 handles where the new value goes, while Insert1 handles what the value is
node* Binary_Tree::Insert2(node* temp, node* newNode)
{
	//As long as the node is null set the temp value equal to the new node
	if (temp == NULL)
	{
		temp = newNode;
	}
	else if (temp->info < newNode->info)
	{
		//If the right node is empty set the right node equal to the new node value
		Insert2(temp->Right, newNode);
		if (temp->Right == NULL)
		{
			temp->Right = newNode;
		}
	}
	else
	{
		//If the left node is empty set the left node equal to the new node value
		Insert2(temp->Left, newNode);
		if (temp->Left == NULL)
		{
			temp->Left = newNode;
		}
	}

	return temp;
}

//Ultimately handles recognizing the new value to insert while Insert2 handles where the value goes
void Binary_Tree::Insert1(int n)
{
	node* temp = root;
	node* newnode;
	newnode = new node;
	newnode->Left = NULL;
	newnode->Right = NULL;
	newnode->info = n;
	root = Insert2(temp, newnode);
}

//PreTrav Function prints the tree starting from the specified node (top to bottom, left to right)
void Binary_Tree::PreTrav(node* t)
{
	if (root == NULL)
	{
		cout << "Nothing in my tree." << endl;
	}
	else if (t != NULL)
	{
		cout << t->info << " ";
		PreTrav(t->Left);
		PreTrav(t->Right);
	}
}

//InTrav Function prints every left node then every right node
void Binary_Tree::InTrav(node* t)
{
	if (root == NULL)
	{
		cout << "Nothing in my tree." << endl;
	}
	else if (t != NULL)
	{
		InTrav(t->Left);
		cout << t->info << " ";
		InTrav(t->Right);
	}
}

//PostTrav Function is used within the Delete Function since you need to delete the children first
void Binary_Tree::PostTrav(node* t)
{
	if (root == NULL)
	{
		cout << "Nothing in my tree." << endl;
	}
	else if (t != NULL)
	{
		PostTrav(t->Left);
		PostTrav(t->Right);
		cout << t->info << " ";
	}
}

//Delete function will not only delete, but also reassign nodes to keep order within the tree
//This is also deleting by key and not by value
void Binary_Tree::Delete(int key)
{
	node* temp = root;
	node* parent = root;
	node* marker;

	if (temp == NULL)
	{
		cout << "Nothing in my Tree." << endl;
	}
	else
	{
		while (temp != NULL && temp->info != key)
		{
			parent = temp;

			if (temp->info < key)
			{
				temp = temp->Right;
			}
			else
			{
				temp = temp->Left;
			}
		}
	}

	marker = temp;

	//If the value to delete is null
	if (temp == NULL)
	{
		cout << "Value not found." << endl;
	}
	//When trying to delete the root of the tree
	else if (temp == root)
	{
		if (temp->Right == NULL && temp->Left == NULL)
		{
			root = NULL;
		}
		else if (temp->Left == NULL)
		{
			root = temp->Right;
		}
		else if (temp->Right == NULL)
		{
			root = temp->Left;
		}
		else
		{
			node* temp1;
			temp1 = temp->Right;
			
			while (temp1->Left != NULL)
			{
				temp = temp1;
				temp1 = temp1->Left;
			}

			if (temp1 != temp->Right)
			{
				temp->Left = temp1->Right;
				temp1->Right = root->Right;
			}

			temp1->Left = root->Left;
			root = temp1;
		}
	}
	else
	{
		//Check if both nodes are null
		if (temp->Right == NULL && temp->Left == NULL)
		{
			if (parent->Right == temp)
			{
				parent->Right = NULL;
			}
			else
			{
				parent->Left = NULL;
			}
		}
		//Check if just the left node is null
		else if (temp->Left == NULL)
		{
			if (parent->Right == temp)
			{
				parent->Right = temp->Right;
			}
			else
			{
				parent->Left = temp->Right;
			}
		}
		//Check if just the right node is null
		else if (temp->Right == NULL)
		{
			if (parent->Right == temp)
			{
				parent->Right = temp->Left;
			}
			else
			{
				parent->Left = temp->Left;
			}
		}
		//Neither node is null (data is in both nodes)
		//Visually, this is like moving everying left and up to keep the tree complete
		else
		{
			node* temp1;
			parent = temp;
			temp1 = temp->Right;

			while (temp1->Left != NULL)
			{
				parent = temp1;
				temp1 = temp1->Left;
			}

			if (temp1 != temp->Right)
			{
				temp->Left = temp1->Right;
				temp1->Right = parent->Right;
			}

			temp1->Left = parent->Left;
			parent = temp1;
		}
	}

	delete marker;
}