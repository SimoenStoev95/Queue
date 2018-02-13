#include<iostream>

using namespace std;

template<typename T>
struct Node {
	T data;
	Node* next;
};

template<typename T>
class Queue {
public:
	// The big four
	Queue();
	Queue(const Queue&);
	~Queue();
	Queue& operator=(const Queue&);
	// Push and Pop
	void push(const T&);
	void pop(T&);
	// Empty
	bool empty() const;
	// get Front and get Rear
	void getFront(T&) const;
	void getRear(T&) const;
	// Print
	void print();
private:
	Node<T>* front;
	Node<T>* rear;
	void copyQueue(const Queue&);
	void deleteQueue();
};

template<typename T>
Queue<T>::Queue() {
	front = NULL;
	rear = NULL;
}

template<typename T>
Queue<T>::~Queue() {
	deleteQueue();
}

template<typename T>
Queue<T>::Queue(const Queue<T>& other) {
	copyQueue(other);
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other) {
	if (this != &other) {
		deleteQueue();
		copyQueue(other);
	}
	return *this;
}

template<typename T>
void Queue<T>::copyQueue(const Queue<T>& other) {
	front = NULL;
	rear = NULL;
	Node<T>* point = other.front;
	while (point != NULL) {
		push(point->data);
		point = point->next;
	}
}

template<typename T>
void Queue<T>::deleteQueue() {
	T x;
	while (!empty()) {
		pop(x);
	}
}

template<typename T>
void Queue<T>::push(const T& elem) {
	Node<T>* p = new Node<T>;
	p->data = elem;
	p->next = NULL;
	if (rear != NULL) {
		rear->next = p;
	}
	else {
		front = p;
	}
	rear = p;
}

template<typename T>
void Queue<T>::pop(T& elem) {
	if ( !empty() ) {
		Node<T>* p = front;
		elem = p->data;
		if (front == rear) {
			front = NULL;
			rear = NULL;
		}
		else {
			front = front->next;
		}
		delete p;
	}
	else {
		cout << "The queue is empty." << endl;
	}
}

template<typename T>
bool Queue<T>::empty() const {
	return rear == NULL;
}

template<typename T>
void Queue<T>::getFront(T& elem) const {
	if (!empty()) {
		elem = front->data;
	}
	else {
		cout << "The queue is empty, no way to get the head of the queue." << endl;
	}
}

template<typename T>
void Queue<T>::getRear(T& elem) const {
	if (!empty()) {
		elem = rear->data;
	}
	else {
		cout << "The queue is empty, no way to get the last element." << endl;
	}
}

template<typename T>
void Queue<T>::print() {
	T elem;
	while (!empty()) {
		pop(elem);
		cout << elem << "  ";
	}
	cout << endl;
}