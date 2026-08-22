/* This is a templetized linked list program to get a file input from the user and build a sorted linked list
* the program also insert an object and create a sorted linked list
* it also add and merge two sorted linked lists and create a single sorted linked list
* the program also make a deep copy of a given linked list and assign it for another linked list
* the program also peek and remove items from the linked list, and delete all items from the linked list
*/

#ifndef LIST_342_H_
#define LIST_342_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template<class T>
struct Node
{
	T* data = nullptr;
	Node* next = nullptr;
};

template<class T>
class List342
{
public:
	List342();
	List342(const List342<T>& source);
	~List342();

	bool BuildList(string file_name);
	bool Insert(T* obj);
	bool Remove(T target, T& result);
	bool Peek(T target, T& result) const;
	bool isEmpty() const;
	void DeleteList();
	bool Merge(List342& list1);

	List342 operator+(const List342& source)const;
	List342 operator+=(const List342& source);
	bool operator==(const List342& rhs)const;
	bool operator!=(const List342& rhs)const;

	List342& operator=(const List342& source);
	friend ostream& operator<< <>(ostream& stream, const List342& ls342);

private:
	Node <T>* head_;
};

template<class T>
List342<T>::List342() : head_(nullptr)
{

}

template<class T>
List342<T>::List342(const List342<T>& source) : head_(nullptr)
{
	*this = source;
}

template<class T>
List342<T>::~List342()
{
	Node<T>* temp = nullptr;
	while (head_ != nullptr)
	{
		temp = head_;
		head_ = head_->next;
		delete temp->data;
		temp->data = nullptr;
		delete temp;
		temp = nullptr;
	}
	head_ = nullptr;
}

//builds an ascnedingly sorted linked list from an input file
template<class T>
bool List342<T>::BuildList(string file_name)
{
	ifstream in_file;
	in_file.open(file_name);
	if (!in_file)
	{
		cout << "Couldn't open the file" << endl;
		return false;
	}
	while (!in_file.eof())
	{
		T temp;
		in_file >> temp; //using overloaded >> stream from the input object
		Insert(&temp);
	}
	in_file.close();
	return true;
}

//insert a given object by pointer at the appropirate place and create an ascendingly sorted linked list
template<class T>
bool List342<T>::Insert(T* obj)
{
	//empty list case
	if (head_ == nullptr)
	{
		head_ = new Node<T>;
		head_->data = new T;
		*(head_->data) = *obj;
		return true;
	}
	//first in line - at the begining
	if (*obj < *(head_->data))
	{
		Node<T>* ins_node = new Node<T>;
		ins_node->data = new T;
		*(ins_node->data) = *obj;
		ins_node->next = head_;
		head_ = ins_node;
		return true;
	}
	if (*obj == *(head_->data)) //check for duplicates
	{
		return false;
	}
	Node<T>* p_node = head_;
	while ((p_node->next != nullptr) && (*(p_node->next->data) < *obj))
	{
		p_node = p_node->next;
	}
	if ((p_node->next != nullptr) && (*(p_node->next->data) == *obj)) //no duplicates
	{
		return false;
	}
	Node<T>* ins_node = new Node<T>;
	ins_node->data = new T;
	*(ins_node->data) = *obj;
	ins_node->next = p_node->next;
	p_node->next = ins_node;
	return true;
}

//Check and removes the target from the linked list and stores its value if it is removed
template<class T>
bool List342<T>::Remove(T target, T& result)
{
	if (head_ == nullptr)
	{
		return false;
	}
	if (*(head_->data) == target)
	{
		Node<T>* temp = head_;
		head_ = head_->next;
		result = *(temp->data);
		delete temp->data;
		temp->data = nullptr;
		temp->next = nullptr; 
		delete temp;
		temp = nullptr;
		return true;
	}
	Node<T>* p_node = head_;
	while ((p_node->next != nullptr) && (*(p_node->next->data) < target))
	{
		p_node = p_node->next;
	}
	if (p_node->next == nullptr)
	{
		return false;
	}
	if (*(p_node->next->data) == target)
	{
		Node<T>* tmp = p_node->next;
		result = *(tmp->data);
		p_node->next = p_node->next->next;
		delete tmp->data;
		tmp->data = nullptr;
		delete tmp;
		tmp = nullptr;
		return true;
	}
	return false;
}

//Checks whether the target is in the linked list and it stores the value if it is found
template<class T>
bool List342<T>::Peek(T target, T& result) const
{
	if (head_ == nullptr)
	{
		return false;
	}
	if (*(head_->data) == target)
	{
		result = *(head_->data);
		return true;
	}
	Node<T>* p_node = head_;
	while ((p_node->next != nullptr) && (*(p_node->next->data) < target))
	{
		p_node = p_node->next;
	}
	if (p_node->next == nullptr)
	{
		return false;
	}
	if (*(p_node->next->data) == target)
	{
		result = *(p_node->next->data);
		return true;
	}
	return false;
}

//checks whether the linked list is empty
template<class T>
bool List342<T>::isEmpty() const
{
	if (head_ != nullptr)
	{
		return false;
	}
	return true;
}

//DeleteList() removes all items and deallocates all memeory in the linked list
template<class T>
void List342<T>::DeleteList()
{
	Node<T>* temp = nullptr;
	while (head_ != nullptr)
	{
		temp = head_;
		head_ = head_->next;
		delete temp->data;
		temp->data = nullptr;
		delete temp;
		temp = nullptr;
	}
	head_ = nullptr;
}

//the Merge() function takes a sorted list and merges into the calling sorted list without allocating
//new memory. At termination, it cleans up the passed in linked list
template<class T>
bool List342<T>::Merge(List342& list1)
{
	if (this == &list1 || list1.head_ == nullptr)
	{
		return false;
	}
	//if destination is empty, point head_ to the source
	if (head_ == nullptr)
	{
		head_ = list1.head_;
		list1.head_ = nullptr;
		return true;
	}
	Node<T>* s_node = list1.head_;
	if (*(head_->data) >= *(s_node->data))
	{
		list1.head_ = list1.head_->next;
		if (*(head_->data) == *(s_node->data))
	    {
			delete (s_node->data);
			s_node->data = nullptr;
		    delete s_node;
			s_node = nullptr;
		}
		else
		{
			s_node->next = head_;
		    head_ = s_node;
		}
	}
	Node<T> *d_node = head_;
	while ((list1.head_ != nullptr) && (list1.head_->data != nullptr))
	{
		if (d_node->next != nullptr)
		{
			s_node = list1.head_;
			s_node->data = list1.head_->data; 
			if (*(s_node->data) < *(d_node->next->data))
		    {
				list1.head_ = list1.head_->next;
				s_node->next = d_node->next;
				d_node->next = s_node;
				d_node = s_node;
				s_node = nullptr;
		    }
		    else if (*(s_node->data) == *(d_node->next->data))
		    {
				list1.head_ = list1.head_->next;
		        delete s_node->data;
				s_node->data = nullptr;
		        delete s_node;
				s_node = nullptr;
	        }
		    else
	        {
				d_node = d_node->next;
		    }
		}
		else
		{
			d_node->next = s_node;
		    list1.head_ = nullptr;
	        return true;
	    }
	}
	return true;	
}

//deep copy and assign a given linked list object for another linked list object
template<class T>
List342<T>& List342<T>::operator=(const List342<T>& source)
{
	if (this == &source) 
	{		
		return *this;
	}
	//clean up the memory on the destination object
	DeleteList(); 

	if (source.head_ == nullptr)
	{
		return *this;
	}
	//create destination node and source node
	Node<T>* d_node = new Node<T>;
	Node<T>* s_node = nullptr;
	Node<T>* temp = nullptr;
	T* d_node_data = new T;
	*d_node_data = *(source.head_->data); 
	d_node->data = d_node_data;
	d_node->next = nullptr;
	head_ = d_node;
	temp = head_;
	s_node = (source.head_)->next;

	while (s_node != nullptr)
	{
		d_node = new Node<T>;
		d_node_data = new T;
		*(d_node_data) = *(s_node->data);
		d_node->data = d_node_data;
		d_node->next = nullptr;
		temp->next = d_node;
		temp = temp->next;
		s_node = s_node->next;
	}
	return *this;
}

template<class T>
List342<T> List342<T>::operator+=(const List342<T>& source)
{
	if (source.head_ == nullptr)
	{
		return *this;
	}
	if (head_ == nullptr)
	{
		*this = source;
		return *this;
	}
	List342<T> source_copy = source;
	this->Merge(source_copy);
	return *this;
}

template<class T>
List342<T> List342<T>::operator+(const List342<T>& source)const
{
	List342<T> result = *this;
	result += source;
	return result;
}

//checks wheteher two linked lists are equal
template<class T>
bool List342<T>::operator==(const List342<T>& rhs)const
{
	if (((head_ == nullptr) && (rhs.head_ == nullptr)) || ((head_ != nullptr) && (rhs.head_ == nullptr)))
	{
		return false;
	}
	
	Node<T>* curr = head_;
	Node<T>* curr_rhs = rhs.head_;
	while (curr != nullptr && curr_rhs != nullptr)
	{
		if (*(curr->data) == *(curr_rhs->data))
		{
			curr = curr->next;
			curr_rhs = curr_rhs->next;
		}
		else
		{
			return false;
		}
	}
	if ((curr == nullptr && curr_rhs == nullptr) || (curr != nullptr && curr_rhs != nullptr))
	{
		return true;
	}
	return false;
}

template<class T>
bool List342<T>::operator!=(const List342& rhs)const
{
	return !(*this == rhs);
}

template<class T>
ostream& operator<<(ostream& stream, const List342<T>& ls342)
{
	Node<T>* p_node = ls342.head_;
	while (p_node != nullptr) 
	{
		stream << *(p_node->data);
		p_node = p_node->next;
	}
	return stream;
}
#endif

