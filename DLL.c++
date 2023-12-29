#include <cmath>
#include <iostream>
using namespace std;
class Node{
public:
	int val;
	Node * next;
    Node * prev;
	Node(int value,Node * nxt,Node * prev)
	{
		this->val=value;
		this->next=nxt;
		this->prev=prev;
	}
	void setNext(Node *nxt)
	{
		this->next=nxt;
	}

};
class dll{
private:
	int size;
	Node * head;
	Node * tail;
public:
	dll()
	{
		size=0;
		head=nullptr;
		tail=nullptr;
	}
	bool isEmpty()
	{
		if(head==nullptr && tail==nullptr)
			return true;
		else
		    return false;
	}
	void print()
	{
		if(this->isEmpty())
			{throw("Error:the list is empty");}
		Node * temp;
		for(temp = head;temp!=nullptr;temp=temp->next)
		{
			cout<<temp->val;
			if(temp->next!=nullptr)
				cout<<",";

		}
	}
	void addToHead(int val)
	{
		Node * newNode = new Node(val,head,nullptr);
		head = newNode;
		if(tail == nullptr)
		{
			tail=newNode;
		}
	}
	void addToTail(int val)
	{
		Node * newNode = new Node(val,nullptr,tail);
		if(isEmpty())
		{
			head=newNode;
			tail=newNode;
		}
		else
		{
		    tail->setNext(newNode);
		    tail=newNode;
		}
	}
	void remove_head()
	{
		if(head==nullptr)
			{throw("Error: the list is empty");}
		Node * temp = head->next;
		delete head;
		head=temp;
	}
	void remove_tail()
	{
		if(tail==nullptr)
			{throw("Error: the list is empty");}
	    Node * temp=tail;
	    tail=tail->prev;
	    delete temp;
	    tail->next=nullptr;
	    
	}
	bool remove(int r)
	{
		Node * temp;
		if(head->val==r)
		{
			remove_head();
			return true;
		}
		if(tail->val==r)
		{
			remove_tail();
			return true;
		}
		if(isEmpty())
		{
			throw("Error:this list is empty");
		}
		for(temp=head;temp!=nullptr;temp=temp->next)
		{
			if(temp->val==r)
			{
				temp->next->prev=temp->prev;
				temp->prev->next=temp->next;
			}
		}
	}
	const bool is_in_list(int s)
	{
		Node * temp;
		for(temp=head;temp!=NULL;temp=temp->next)
		{
			if(temp->val==s)
				return true;
		}
		return false;
	} 

};

int main() {

	
	
}