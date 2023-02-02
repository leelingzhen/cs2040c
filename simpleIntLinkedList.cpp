#include <iostream>
#include "simpleIntLinkedList.h"
using namespace std;

ListNode::ListNode(int n)
{
	_item = n;
	_next = NULL;
}

void List::insertHead(int n)
{
	ListNode *aNewNode = new ListNode(n);
	aNewNode->_next = _head;
	_head = aNewNode;
	_size++;
};

void List::removeHead()
{
	if (_size > 0) {
		ListNode *temp = _head;
		_head = _head->_next;
		delete temp;
		_size--;
	}
}

void List::print() {

	ListNode *reader = _head;
	while (reader != NULL) {
		cout << reader->_item << ' ';	
		reader = reader->_next;
	}
	cout << endl;
}

bool List::exist(int n) {

	ListNode *reader = _head;
	while (reader != NULL) {
		if (reader->_item == n){
			return 1;
		}
		reader = reader->_next;
	}
	return 0; 
}

int List::headItem()
{
	ListNode *reader = _head;

	return reader != NULL ? reader->_item : -1; // modify this
}

bool List::empty()
{
	// if _head is a null ptr , it is an empty list
	// 1 means its empty 0 means its not empty
	return _head ? 0 : 1;
}

int List::tailItem()
{
	ListNode* last_ptr;
	if (empty()){
		return -1;
	};
	for (ListNode* ptr = _head; ptr; ptr = ptr->_next){
		last_ptr = ptr;
	}
	return last_ptr->_item;
}

void List::removeTail() {

	// first check if the list is empty 
	if (empty()) {
		cout << "is empty"<< endl;
		return;
	}
	cout << "is not empty"<< endl;

	ListNode* last_ptr;
	for (auto ptr = _head; ptr; ptr = ptr->_next) {
		if (ptr->_next->_next == NULL) {
			// first create a temp that points to the last instance of the list
			auto temp = ptr->_next;
			ptr->_next = NULL;
			delete temp;
			_size--;
		}

	}
	return;

}

List::~List()
{
	while (_size != 0)
		removeHead();
};

