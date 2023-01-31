#ifndef BSTREE_H_
#define BSTREE_H_
#include "account.h"
#include <iostream>
using namespace std;

class BSTree
{
public:
	BSTree();
	BSTree(const BSTree &source);
	~BSTree();

	bool Insert(Account*acc);
	bool Retrieve(const int& accountNumber, Account*& acc) const;
	void Display() const;
	bool IsEmpty() const;

	BSTree& operator=(const BSTree& source);


private:
	struct Node
	{
		Account* pAcct;
		Node* right = nullptr;;
		Node* left = nullptr;
	};
	Node* root;
	bool RecursiveInsert(Node* temp, Account* acc);
	void RecursivePrint(Node* p_root) const;
	Node* Copy(Node* P_node)const;
	void Empty(Node* &r)const;
};
#endif
