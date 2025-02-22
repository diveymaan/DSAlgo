// BinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
//#include<stdlib.h>
#include<string>
#include<Bits.h>
#include<stack>
#include<queue>

using namespace std;
struct Node
{
	int data = 0;
	Node* left;
	Node* right;
	Node(int val)
	{
		this->data = val;
		left = right = NULL;
	}
};

void inOrder(Node* tree)
{
	if (tree == NULL)
		return;

	inOrder(tree->left);
	cout << tree->data<<" ";
	inOrder(tree->right);

	}

void inOrderVector(Node* tree, vector<Node*> &v)
{
	if (tree == NULL)
		return;

	inOrderVector(tree->left, v);
	v.push_back(tree);
	inOrderVector(tree->right, v);

}

void inOrderStack(Node* tree)
{

	while (tree == NULL)
		return;
	stack<Node *> s;
	Node * curr = tree;

	while (curr != NULL || s.empty() == FALSE)
	{
		while (curr != NULL)
		{
			s.push(curr);
			curr = curr->left;
		}

		curr = s.top();
		s.pop();

		cout << curr->data << " ";
		curr = curr->right;
	}

}

void preOrder(Node* tree)
{
	if (tree == NULL)
		return;

	cout << tree->data<<" ";
	preOrder(tree->left);
	preOrder(tree->right);

	}

void preOrderVector(Node* tree, vector<Node*> &v)
{
	if (tree == NULL)
		return;

	v.push_back(tree);
	preOrderVector(tree->left, v);
	preOrderVector(tree->right, v);

}
void preOrderStack(Node* tree)
{

	while (tree == NULL)
		return;
	stack<Node *> s;
	s.push(tree);
	Node * curr;

	while (s.empty() == FALSE)
	{
		curr = s.top();
		s.pop();
		cout << curr->data << " ";

		if (curr->right)
		{
			s.push(curr->right);
		}
		

		if (curr->left)
		{
			s.push(curr->left);
		}
		
			
	}

}


void postOrder(Node* tree)
{
	if (tree == NULL)
		return;

	postOrder(tree->left);
	postOrder(tree->right);

	cout << tree->data<<" ";
}

void printLevelOrder(Node* tree)
{
	while (tree == NULL)
		return;

	queue<Node *> q;

	q.push(tree);

	while (q.empty() != true)
	{
		int nodeCount = q.size();
		while (nodeCount > 0)
		{
			Node *tempNode = q.front();
			cout << tempNode->data << " ";
			q.pop();
			if (tempNode->left != NULL) 
				q.push(tempNode->left);
			if (tempNode->right != NULL)
				q.push(tempNode->right);
			nodeCount--;
		}
		cout << "\n";
	}

}

void printreverseLevelOrder(Node* tree)
{

		while (tree == NULL)
			return;

		queue<Node *> q;

		stack<Node *> st;
		Node *tempNode;

		q.push(tree);

		while (q.empty() != true)
		{
			tempNode = q.front();
				st.push(tempNode);
				q.pop();
				if (tempNode->left != NULL)
					q.push(tempNode->left);
				if (tempNode->right != NULL)
					q.push(tempNode->right);
			
		}
		while (st.empty() != true)
		{
			cout << st.top()->data << "  ";
			st.pop();
		}

}

void postOrderStack(Node* tree)
{

	while (tree == NULL)
		return;
	stack<Node *> s;
	s.push(tree);

	stack<int> temp;
	Node * curr=tree;

	while (s.empty() == FALSE)
	{
		curr = s.top();
		s.pop();

		temp.push(curr->data);
		if (curr->left)
		{
			s.push(curr->left);
		}
		if (curr->right)
		{
			s.push(curr->right);
		}

	}
		
	while (!temp.empty())
		{
			cout << temp.top() << " ";
			temp.pop();
		}
	

}

bool checkSubTree(Node* tree, Node* subtree)
{

	vector<Node*> v1, v2;

	if (subtree == NULL)
		return true;

	if (tree == NULL)
		return false;

	inOrderVector(tree, v1);
	inOrderVector(subtree, v2);

	if (search(v1.begin(), v1.end(), v2.begin(), v2.end()) == v1.end())
		return false;

	v1.erase(v1.begin(), v1.end());
	v2.erase(v2.begin(), v2.end());

	preOrderVector(tree, v1);
	preOrderVector(subtree, v2);

	if (search(v1.begin(), v1.end(), v2.begin(), v2.end()) == v1.end())
		return false;

	return true;
}

void mirrorBinaryTree(Node* tree)
{
	if (tree == NULL)
		return;

	swap(tree->left, tree->right);

	mirrorBinaryTree(tree->left);
	mirrorBinaryTree(tree->right);

}

void createBT(Node* &tree)
{
	tree = new Node(1);
	tree->left = new Node(2);
	tree->right = new Node(3);
	tree->left->left = new Node(4);
	tree->left->right = new Node(5);
	tree->right->left = new Node(6);
	tree->right->right = new Node(7);
	tree->right->left->left = new Node(8);
	tree->right->left->right = new Node(9);
}


bool checkIsLeaf(Node* tree)
{
	if (tree->left == NULL && tree->right == NULL)
		return true;
	else
		return false;
}

void printPath(vector<int> v)
{
	for (int i = v.size() - 1; i > 0; i--)
	{
		cout << v.at(i) << "->";
	}
	cout << v.at(0);
	cout << "\n";
}
void printRootToNodePath(Node* tree, vector<int> &v)
{
	if (tree == NULL)
		return;

	v.push_back(tree->data);
	if (checkIsLeaf(tree))
		printPath(v);

	printRootToNodePath(tree->left, v);
	printRootToNodePath(tree->right, v);

	v.pop_back();
}

void convertBTtoDLL(Node* tree, Node* &root, Node* &prev)
{

	if (tree == NULL)
		return;

	convertBTtoDLL(tree->left, root, prev);

	if (prev != NULL)
	{
		tree->left = prev;
		prev->right = tree;
	}
	else
		root = tree;

	prev = tree;

	convertBTtoDLL(tree->right, root, prev);
}

void printDLL(Node* &tree)
{
	Node* curr = tree;
	if (tree == NULL)
		return;

	while (curr != NULL)
	{
		cout <<curr->data<< "- ";
		curr = curr->right;
	}


}
void convertBTtoDLL(Node* tree)
{
	Node* prev = NULL;

	convertBTtoDLL(tree, tree, prev);
	printDLL(tree);
}

// Search for node value.
void searchNode(Node* root, int key, Node* parent)
{

	if (root == nullptr)
	{
		cout << "\n Tree is NULL";
		return;
	}
		

	if (root->data == key)
	{
		if (parent == nullptr)
			cout << "\n The node with key" << key << " is root node.";

		else if (key < parent->data)
			cout << "\n Given key is left node of key: " << parent->data;

		else if (key > parent->data)
			cout << "\n Given key is right node of key: " << parent->data;

		return;
	}

	if (key < root->data)
		return searchNode(root->left, key, root);

	return searchNode(root->right, key, root);
}


Node* insertNodeBST(Node* tree, int key)
{
	// if the root is null, create a new node an return it
	if (tree == nullptr)
		return new Node(key);

	// if given key is less than the root node, recurse for left subtree
	if (key < tree->data)
		tree->left = insertNodeBST(tree->left, key);

	// if given key is more than the root node, recurse for right subtree
	else
		tree->right = insertNodeBST(tree->right, key);

	return tree;
}


int main()
{
	Node* tree = new Node(1);
	tree->left = new Node(2);
	tree->right = new Node(3);
	tree->left->left = new Node(4);
	tree->left->right = new Node(5);

		cout << "\n InOrder Traversal is:";
		inOrder(tree);

		cout << "\n InOrder Traversal with Stack is:";
		inOrderStack(tree);

		cout << "\n PreOrder Traversal is:";
		preOrder(tree);
		cout << "\n PreOrder Traversal with Stack is:";
		preOrderStack(tree);

		cout << "\n PostOrder Traversal is:";
		postOrder(tree);
		cout << "\n PostOrder Traversal with Stack is:";
		postOrderStack(tree);

		tree->right->right = new Node(6);

		cout << "\nLevel Order Traversal: \n";
		printLevelOrder(tree);

		cout << "\nReverse Level Order Traversal: \n";
		printreverseLevelOrder(tree);

		cout << "\nCheck for Subtree: \n";
		if (checkSubTree(tree, tree->right))
			cout << "\n Given is a subtree combination.";
		else
			cout << "\n Given is not subtree combination.";

		cout << "\n Mirror Binary Tree :\n";
		mirrorBinaryTree(tree);
		printLevelOrder(tree);

		vector<int> v;
		createBT(tree);
		
		cout << "\n For Binary Tree:\n";
		printLevelOrder(tree);
		cout << "\n Leaf to Root Paths are:\n";
		printRootToNodePath(tree, v);
		
		convertBTtoDLL(tree);

		//Creating BST and Searching Node in BST.
		tree = nullptr;
		int keys[] = { 15, 10, 20, 8, 12, 25, 18, 16, 19, 30};

		for (int key : keys)
			tree = insertNodeBST(tree, key);

		searchNode(tree, 16, nullptr);
		getchar();
		return 0;
}
