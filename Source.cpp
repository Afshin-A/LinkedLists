#include <iostream>

class Node {
public:
	Node(int data) {
		this->data = data;
	}
	int data;
	Node* next = nullptr;
	Node* previous = nullptr;
};

class SinglyLinkedList {
public:
	SinglyLinkedList(Node* head, Node* tail) {
		this->head = head;
		this->tail = tail;

		this->head->next = this->tail;
		//this->tail->previous = this->head;
	}

	void append(Node* node) {
		this->tail->next = node;
		this->tail = node;
	}

	void prepend(Node* node) {
		node->next = this->head;
		this->head = node;
	}

	void insertAfter(Node* node1) {
		//node1 node2 node3
		Node* temp;
		temp = node1->next;

	}
	void removeAfter(Node* node1) {
		Node* temp;
		if (node1 == this->tail) {
			return;
		}
		else if (node1 == nullptr) {
			temp = this->head;
			this->head = this->head->next;
			delete temp;
		}
		else {
			//node1 node2 node3
			//node1 node3
			temp = node1->next;
			node1->next = node1->next->next;
			delete temp;
		}
	}

	void print() {
		Node* current = this->head;
		while (current != nullptr) {
			std::cout << current->data << " ";
			current = current->next;
		}
		std::cout << std::endl;
	}

	Node* head;
	Node* tail;
};

class DoubleyLinkedList {
public:
	DoubleyLinkedList(Node* head, Node* tail) {
		this->head = head;
		this->tail = tail;

		this->head->next = this->tail;
		this->tail->previous = this->head;
	}
	
	void remove(Node* node2) {
		//node1 node2 node3
		//node1 node3
		try {
			Node* node1 = node2->previous;
			Node* node3 = node2->next;
			if (node1 == nullptr || node3 == nullptr) {
				std::string = "node" + "DNE in list";
				throw std::exception();
			}
			node1->next = node3;
			node3->previous = node1;
		}
		catch (std::exception except) {
			std::cout << except.what() << std::endl;
		}

	}

	void append(Node* node) {
		// tail node
		this->tail->next = node;
		node->previous = this->tail;
		this->tail = node;
	}

	void print() {
		Node* current = this->head;
		while (current != nullptr) {
			std::cout << current->data << " ";
			current = current->next;
		}
		std::cout << std::endl;
	}

	void reversePrint() {
		Node* current = this->tail;
		while (current != nullptr) {
			std::cout << current->data << " ";
			current = current->previous;
		}
		std::cout << std::endl;
	}



	Node* head;
	Node* tail;
};

int main() {
	Node* nodePtr1 = new Node(1);
	Node* nodePtr2 = new Node(2);
	Node* nodePtr3 = new Node(3);
	Node* nodePtr4 = new Node(4);
	Node* nodePtr5 = new Node(5);
	/*
	SinglyLinkedList list(nodePtr1, nodePtr2);
	list.print();
	list.append(nodePtr3);
	list.append(nodePtr4);
	list.append(nodePtr5);
	list.print();
	list.removeAfter(nodePtr3);
	list.print();
	*/
	DoubleyLinkedList d_list(nodePtr1, nodePtr2);
	d_list.append(nodePtr3);
	d_list.append(nodePtr4);
	d_list.append(nodePtr5);
	d_list.print();
	d_list.remove(nodePtr2);
	d_list.remove(new Node(3));
	d_list.print();
	d_list.reversePrint();


	return 0;
}