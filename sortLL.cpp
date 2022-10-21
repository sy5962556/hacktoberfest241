// C++ program for the above approach:
#include <iostream>
using namespace std;

// Link list Node Class
class Node {
public:
	int data;
	Node* prev;
	Node* next;

	// Constructor function
	Node(int data)
	{
		this->data = data;
		this->prev = NULL;
		this->next = NULL;
	}
};

// Function to print linked list
void print(Node* head)
{
	Node* temp = head;

	// Iterate until node is NOT NULL
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

// Function to push a node in
// Doubly linked- list
void push(Node*& head, Node*& tail, int item)
{

	// If list is empty
	if (tail == NULL) {

		Node* temp = new Node(item);
		tail = temp;
		head = temp;
	}

	// List is not empty

	else {
		Node* temp = new Node(item);
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
}

// Function to swap the list
// Consisting of 0s and 1s
void swap(Node*& Node1, Node*& Node2)
{

	Node* temp;
	temp = Node1->next;
	Node1->next = Node2->next;
	Node2->next = temp;

	if (Node1->next != NULL)
		Node1->next->prev = Node1;
	if (Node2->next != NULL)
		Node2->next->prev = Node2;

	temp = Node1->prev;
	Node1->prev = Node2->prev;
	Node2->prev = temp;

	if (Node1->prev != NULL)
		Node1->prev->next = Node1;
	if (Node2->prev != NULL)
		Node2->prev->next = Node2;
}

// Function to sort the list
// Consisting of 0s and 1s
void sort(Node*& head, Node*& tail)
{

	// Base Case
	if (head == tail || head == NULL)
		return;

	// Initialize the pointers
	Node* first = head;
	Node* last = tail;

	while ((first != last)
		&& (first->prev != last)) {

		// If first->data is 0 then move
		// First towards right by 1
		if (first->data == 0)
			first = first->next;

		// If last->data is 1 then move
		// Last towards left by 1
		if (last->data == 1)
			last = last->prev;

		// If first->data is 1 and last->data is 0
		// then swap first and last node
		if (first->data == 1 && last->data == 0
			&& first->prev != last) {

			// Swapping the node
			swap(first, last);

			// if head = 1
			if (head == first)
				head = last;

			// if tail == 0
			if (tail == last)
				tail = first;

			// Swapping the pointer and
			// moved to next iteration
			Node* Temp = first;
			first = last->next;
			last = Temp->prev;
		}
	}
}

// Driver Code
int main()
{

	Node* head = NULL;
	Node* tail = NULL;

	push(head, tail, 1);
	push(head, tail, 1);
	push(head, tail, 0);
	push(head, tail, 0);
	push(head, tail, 1);
	push(head, tail, 0);
	push(head, tail, 1);
	push(head, tail, 1);
	push(head, tail, 0);
	push(head, tail, 0);

	sort(head, tail);

	print(head);

	return 0;
}
