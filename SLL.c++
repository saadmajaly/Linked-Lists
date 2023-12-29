#include <cmath>
#include <iostream>
using namespace std;
class Node{
public:
	int val;
	Node * next;

	Node(int value,Node * nxt)
	{
		this->val=value;
		this->next=nxt;
	}
	void setNext(Node *nxt)
	{
		this->next=nxt;
	}

};
class sll{
private:
	int size;
	Node * head;
	Node * tail;
public:
	sll()
	{
		size=0;
		head=NULL;
		tail=NULL;
	}
	bool isEmpty()
	{
		if(head==NULL && tail==NULL)
			return true;
		else
		    return false;
	}
	void print()
	{
		if(this->isEmpty())
			{throw("Error:the list is empty");}
		Node * temp;
		for(temp = head;temp!=NULL;temp=temp->next)
		{
			cout<<temp->val;
			if(temp->next!=NULL)
				cout<<",";

		}
	}
	void addToHead(int val)
	{
		Node * newNode = new Node(val,head);
		head = newNode;
		if(tail == NULL)
		{
			tail=newNode;
		}
	}
	void addToTail(int val)
	{
		Node * newNode = new Node(val,NULL);
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
	    Node * temp;
		for(temp=head;temp->next!=tail;temp=temp->next)
		{}
	    tail=temp;
	    temp=temp->next;
	    delete temp;
	}
	bool remove(int r)
	{
		Node * temp0;
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
		for(temp0=head,temp=head->next;temp->next!=NULL;temp=temp->next,temp0=temp0->next)
		{
			if(temp->val==r)
			{
				temp0->next=temp->next;
				delete temp;
				return true;
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
	sll list1;
	for(int i=1;i<11;i++)
	{
		list1.addToTail(i);
	}
	list1.print();
	cout<<endl;
	list1.remove(5);
	list1.print();
	cout<<endl;
	
	
}