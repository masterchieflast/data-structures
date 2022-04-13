#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

struct List
{
private:
	Node* head; 

public:
	List() 
	{
		head = NULL; 
	}

	void addNode(int d)
	{
		Node* nd = new Node;

		nd->data = d; 	    
		nd->next = NULL;      

		if (head == NULL)     
			head = nd;

		else                  
		{
			Node* current = head;

			while (current->next != NULL)
				current = current->next;

			current->next = nd;
		}
	}

	void printList()
	{
		Node* current = head;

		while (current != NULL)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}
};

int main()
{
	List myList;

	myList.addNode(25);
	myList.addNode(20);
	myList.addNode(15);
	myList.addNode(10);
	myList.addNode(5);
	myList.printList();

	return 0;
}
