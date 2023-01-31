#include "BSTree.h"
BSTree::BSTree():root(nullptr)
{
	
}

BSTree::BSTree(const BSTree& source):root(nullptr)
{
	*this = source;
}

BSTree::~BSTree()
{
	Empty(root);
}

bool BSTree::Insert(Account* acc)
{
	if (root == nullptr)
	{
		root = new Node;
		root->pAcct = acc;
		root->left = nullptr;
		root->right = nullptr;
		return true;
	}
	else
	{
		Node* temp = root;
		RecursiveInsert(temp, acc);
	}
	return false;
}

// retrieve object, first parameter is the ID of the account 
// second parameter holds pointer to found object, NULL if not found 
bool BSTree::Retrieve(const int& accountNumber, Account*& acc) const
{
	Node* temp = root;
	bool is_found = false;

	while (!is_found)
	{
		if ((temp != nullptr) && (accountNumber == temp->pAcct->account_id()))
		{
			is_found = true;
			acc = temp->pAcct;
			return is_found;
		}
		else if ((temp != nullptr) && (accountNumber > temp->pAcct->account_id()))
		{
			temp = temp->right;
		}
		else if ((temp != nullptr) && (accountNumber < temp->pAcct->account_id()))
		{
			temp = temp->left;
		}
		else
		{
			is_found = true;
		}
	}
	acc = nullptr; 
	return false;
}

// displays the contents of a tree to cout 
void BSTree::Display() const
{
	if (root == nullptr)
	{
		cerr << "ERROR: Empty account list" << endl;
	}
	RecursivePrint(root);
}

void BSTree::Empty(Node* &r)const
{
	if (r != nullptr)
	{
		Empty(r->left);
		Empty(r->right);
		delete r;
	}
	r = nullptr;
}

bool BSTree::IsEmpty()const
{
	return root == nullptr;
}

void BSTree::RecursivePrint(Node* p_root) const
{
		if ((p_root->left != nullptr) && (p_root->right != nullptr))
		{
			RecursivePrint(p_root->left);
			cout << *(p_root->pAcct) << endl;
			RecursivePrint(p_root->right);
		}
		else if (p_root->left != nullptr)
		{
			RecursivePrint(p_root->left);
			cout << *(p_root->pAcct) << endl;
		}
		else if (p_root->right != nullptr)
		{
			cout << *(p_root->pAcct) << endl;
			RecursivePrint(p_root->right);
		}
		else
		{
			cout << *(p_root->pAcct) << endl;
		}
}

bool BSTree::RecursiveInsert(Node* temp, Account* acc)
{
	if (acc->account_id() > temp->pAcct->account_id())
	{
		if (temp->right == nullptr)
		{
			Node* ins_node = new Node();
			ins_node->pAcct = acc;
			ins_node->left = nullptr;
			ins_node->right = nullptr;
			temp->right = ins_node;
			return true;
		}
		else
		{
			return RecursiveInsert(temp->right, acc);
		}
	}
	else if (acc->account_id() < temp->pAcct->account_id())
	{
		if (temp->left == nullptr)
		{
			Node* ins_node = new Node();
			ins_node->pAcct = acc;
			ins_node->left = nullptr;
			ins_node->right = nullptr;
			temp->left = ins_node;
			return true;
		}
		else
		{
			return RecursiveInsert(temp->left, acc);
		}
	}
	else
	{
		cerr << "ERROR: Account " << acc->account_id() << " is already opened. Transaction refused." << endl;
		return false;
	}
}

BSTree::Node* BSTree::Copy(Node* p_node) const
{
	if (p_node == nullptr)
	{
		return nullptr;
	}
	else
	{
		Node* n_node = new Node();
		n_node->pAcct = p_node->pAcct;
		n_node->left = Copy(p_node->left);
		n_node->right = Copy(p_node->right);
		return Copy(n_node);
	}
}

BSTree& BSTree::operator=(const BSTree& source)
{
	if( this != &source )
    {
        Empty(root);
        root = Copy( source.root );
	}
    return *this;
}

