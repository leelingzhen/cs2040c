#include <iostream>
#include "simpleIntLinkedList.h"
using namespace std;

int main()
{
	List l;

	l.insertHead(123);
	l.insertHead(11);
	l.insertHead(9);
	l.insertHead(1);
	l.insertHead(20);

	// testing headItem()
	// printf("printing headItem()\n");
	// int head_item = l.headItem();
	// printf("head_item is %d\n\n", head_item);
	// 
	// //testing empty
	// printf("printing empty()\n");
	// printf("list should not be empty here\n");
	// printf("list empty: %d\n\n", l.empty());




	for (int i = 0; i < 5; i++) {
		cout << "The current list is: ";
		l.print();
		cout << "Does 9 exist in the list? " << (l.exist(9) ? "Yes" : "No") << endl << endl;
		l.removeHead();
	}

	// testing headItem()
	printf("printing headItem() which should return -1\n");
	printf("head_item is %d\n\n", l.headItem());

	
	//testing empty()
	printf("printing empty()\n");
	printf("list should  be empty here\n");
	printf("list empty: %d\n\n", l.empty());

	printf("creating new list\n");
	List new_list;

	// creating a new list in which 23 would be the tail item
	new_list.insertHead(23);
	new_list.insertHead(10);
	new_list.insertHead(5);

	printf("testing tailItem\n");
	printf("tail item for new_list is: %d\n\n", new_list.tailItem());

	// testing removeTail
	printf("testing removeTail()\n");
	printf("before remove tail: ");
	new_list.print();
	new_list.removeTail();
	printf("after remove tail: ");
	new_list.print();



	return 0;

}
