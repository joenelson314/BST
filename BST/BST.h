/*
Student Name: Joseph Nelson
Student NetID: jgn86
Compiler Used: Visual Studio
Program Description:
BST class definition and functions.
*/



#pragma once
#include <ostream>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;


class Node{
public:
	int data;
	Node* left;
	Node* right;
	Node() :data(0), left(nullptr), right(nullptr) {}
	Node(int data) :data(data), left(nullptr), right(nullptr) {}
};

class BST {
private:
	Node* root;
	bool search(Node* node, int x);
	bool insert(Node* node, int x);
	Node* remove(Node* node, int x);
	void inOrder(Node* node, ostream& os);
	void preOrder(Node* node, ostream& os);
	void postOrder(Node* node, ostream& os);


public:
	BST() :root(nullptr) {}
	bool search(int x) { return search(root, x); }
	bool insert(int x) { return insert(root, x); }
	bool remove(int x) { return remove(root, x); }
	void inOrder(ostream& os) { inOrder(root, os); }
	void postOrder(ostream& os) { postOrder(root, os); }
	void preOrder(ostream& os) { preOrder(root, os); }
};


bool BST::search(Node* node, int x) { 
	if (node == nullptr) {
		return false;
	}
	if (node->data == x) {
		return true;
	}

	if (node->data < x) {
		return search(node->right, x);
	}

	if (node->data < x) {
		return search(node->left, x);
	}
}

bool BST::insert(Node* node, int x) {
	if (node == nullptr)
	{
		node = new Node(x);
		return true;
	}

	if (node->data > x)
	{
		return insert(node->left, x);
	}

	if (node->data < x)
	{
		return insert(node->right, x);
	}

	return false;
}

Node* minValueNode(Node* node)
{
	Node* current = node;

	while (current && current->left != nullptr)
		current = current->left;

	return current;
}



Node* BST :: remove(Node* node, int x) {
	if (node == nullptr) {
		return node;
	}

	if (x < node->data)
		node->left = remove(node->left, x);			//Had to change return type to get this working 

	else if (x > node->data)
		node->right = remove(node->right, x);

	else
	{
		if (node->left == nullptr)
		{
			Node* temp = node->right;
			free(node);
			return temp;
		}
		else if (node->right == nullptr)
		{
			Node* temp = node->left;
			free(node);
			return temp;
		}

		Node* temp = minValueNode(node->right);

		node->data = temp->data;

		node->right = remove(node->right, temp->data);
	}
	return node;
}

void BST::inOrder(Node* node, ostream& os) {
	if (node == nullptr)
		return;

	inOrder(node->left,os);			//left, root, right

	os << node->data << " ";

	inOrder(node->right,os);
}
void BST::preOrder(Node* node, ostream& os) {
	if (node == nullptr)
		return;

	os << node->data << " ";		//root, left, right

	preOrder(node->left,os);

	preOrder(node->right,os);
}
void BST::postOrder(Node* node, ostream& os) {
	if (node == nullptr)
		return;

	postOrder(node->left,os);		//left,right, root 

	postOrder(node->right,os);

	os << node->data << " ";
}
