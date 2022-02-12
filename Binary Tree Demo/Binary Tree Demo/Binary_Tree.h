#pragma once
#include "Node.h"
#include <iostream>

using namespace std;

//Create the class and initialize vars and functions
class Binary_Tree
{
public:
	node* root;
	Binary_Tree();
	void Insert1(int n);
	node* Insert2(node* temp, node* newNode);
	void Delete(int key);
	void PreTrav(node* t);
	void InTrav(node* t);
	void PostTrav(node* t);
};

