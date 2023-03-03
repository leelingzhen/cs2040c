#pragma oncj
#include <iostream>
#include <cmath>
using namespace std;

template <class T>
class BinarySearchTree;

template <class T>
class TreeNode {
private:
	T _item;
	TreeNode<T>* _left;
	TreeNode<T>* _right;
	int _height;
public:
	TreeNode(T x) { _left = _right = NULL; _item = x; _height = 0; };

	friend BinarySearchTree<T>;
};

template <class T>
class BinarySearchTree {
protected:
	int _size;
	TreeNode<T>* _root;
	void _printTree(int indent, TreeNode<T>*, bool withHeight);

	// The following functions are optional for you to implement. 
	TreeNode<T>*  _insert(TreeNode<T>* current, T x);
	void _inOrderPrint(TreeNode<T>*);
	void _postOrderPrint(TreeNode<T>*);
	void _preOrderPrint(TreeNode<T>*);
	TreeNode<T>* _rightRotation(TreeNode<T>*);
	TreeNode<T>* _leftRotation(TreeNode<T>*);
	T _searchMax(TreeNode<T>*);
	T _searchMin(TreeNode<T>*);
	TreeNode<T>* _search(TreeNode<T>*, T);
	void _destroySubTree(TreeNode<T>*);
	TreeNode<T>* _leftBalance(TreeNode<T>*);
	TreeNode<T>* _rightBalance(TreeNode<T>*);

public:
	BinarySearchTree() { _root = NULL; _size = 0; }
	~BinarySearchTree();
	int size() { return _size; };
	void insert(T);
	void printTree(bool withHeight = 1);
	void inOrderPrint();
	void postOrderPrint();
	void preOrderPrint();
	void balance_tree(TreeNode<T>*);
	T searchMax(); 
	T searchMin();
	bool exist(T x);
	T search(T x) { return T(); };
	T successor(T);
	int balance(TreeNode<T>* );
	int balance();

};

template <class T>
bool BinarySearchTree<T>::exist(T x) {
	TreeNode<T>* search_node = _search(_root, x);
	
	return search_node->_item == x;
}


template <class T>
void BinarySearchTree<T>::insert(T x)
{
	_root = _root ? _insert(_root, x) : new TreeNode<T>(x);
	if (_size == 0) _size++;
}

template <class T>
void BinarySearchTree<T>::_printTree(int indent, TreeNode<T>* node, bool withHeight) {

	if (!node)
		return;

	if (node->_right)
		_printTree(indent + 2, node->_right, withHeight);
	for (int i = 0; i < indent; i++)
		cout << "  ";
	cout << node->_item;
	if (withHeight)
		cout << "(h=" << node->_height << ")";
	cout << endl;
	if (node->_left)
		_printTree(indent + 2, node->_left, withHeight);


};

template <class T>
void BinarySearchTree<T>::printTree(bool withHeight) {
	_printTree(0, _root, withHeight);
}


template <class T>
void BinarySearchTree<T>::preOrderPrint() {

	_preOrderPrint(_root);
	cout << endl;
}

template <class T>
void BinarySearchTree<T>::balance_tree(TreeNode<T>* node ){
	// cout << "inside balance_tree function " ;
	// cout << "where _root is: " <<_root->_item; //<< " left is " << _root->_left->_item << " right is " << _root->_right->_item;
	TreeNode<T>* temp;
	int tree_balance = balance(node);
	// cout << " tree balance is : " << tree_balance ;
	if (tree_balance > 1) {
		temp = _leftBalance(node);
		_root = temp;
		// cout << " moved _root to left where _root is now: "<<_root->_item;
	} else if (tree_balance < -1) {
		temp = _rightBalance(node);
		_root = temp;
		// cout << " moved _root to right where _root is now: "<< _root->_item ;
	}
	// cout << endl;
}


template <class T>
void BinarySearchTree<T>::_preOrderPrint(TreeNode<T>* node) {
	if (!node) return;
	cout << node->_item << " ";
	_preOrderPrint(node->_left);
	_preOrderPrint(node->_right);
}


template <class T>
void BinarySearchTree<T> ::_destroySubTree(TreeNode<T>* node)
{
	if (node->_left)
		_destroySubTree(node->_left);
	if (node->_right)
		_destroySubTree(node->_right);
	delete node;
}

template <class T>
BinarySearchTree<T> :: ~BinarySearchTree()
{
	if (_root)
		_destroySubTree(_root);
}



template <class T>
void BinarySearchTree<T>::inOrderPrint() {
	_inOrderPrint(_root);
	std::cout << std::endl;
}


template <class T>
void BinarySearchTree<T>::_inOrderPrint(TreeNode<T>* node) {
	if (node == NULL) {
		return;
	}
	_inOrderPrint(node->_left);
	std::cout << node->_item << " ";
	_inOrderPrint(node->_right);
}


template <class T>
void BinarySearchTree<T>::postOrderPrint() {
	_postOrderPrint(_root);
	std::cout << std::endl;
}


template <class T>
void BinarySearchTree<T>::_postOrderPrint(TreeNode<T>* node) {
	if (node == NULL) {
		return;
	}
	_postOrderPrint(node->_left);
	_postOrderPrint(node->_right);
	std::cout << node->_item << " ";
}

template <class T>
TreeNode<T>* BinarySearchTree<T>::_insert(TreeNode<T>* current, T x) {
	// function uses some sort of inOrder traversal (DFS) to insert nodes
	
	int left_height = 0;
	int right_height = 0;

	if (current->_item > x)
	{
		if (current->_left)
			current->_left = _insert(current->_left, x);
		else
		{
			current->_left = new TreeNode<T>(x);
			_size++;
		}
	}
	else if (x > current->_item) {
		if (current->_right)
			current->_right = _insert(current->_right, x);
		else
		{
			current->_right = new TreeNode<T>(x);
			_size++;
		}
	}
	else
		return current; // When the node already existed in the tree
	
	// cout <<"current "<< current->_item<< " height " << current->_height << " left height: " << left_height << " right height: " << right_height << endl;
	
	
	if (balance(_root) > 1 or balance(_root) < -1 ){
		balance_tree(_root);
	}

	if (current->_left) {
		left_height = current->_left->_height;
	}
	if (current->_right) {
		right_height = current->_right->_height;
	}
	current->_height = max(left_height, right_height) + 1;




	return current;

}
template <class T>
T BinarySearchTree<T>::searchMax() {
	return _searchMax(_root);
}

template <class T>
T BinarySearchTree<T>::_searchMax(TreeNode<T>* current) {
	if (current->_right == NULL) {
		return current->_item;
	}
	return _searchMax(current->_right);
}

template <class T>
T BinarySearchTree<T>::searchMin() {
	return _searchMin(_root);
}

template <class T>
T BinarySearchTree<T>::_searchMin(TreeNode<T>* current) {
	if (current->_left == NULL) {
		return current->_item;
	}
	return _searchMin(current->_left);
}

template <class T>
TreeNode<T>* BinarySearchTree<T>::_search(TreeNode<T>* current, T x) {
	TreeNode<T>* node = current;
	TreeNode<T>* parent;

	while (node) {
		parent = node;
		if (x < node->_item){
			node = node->_left;	
		} else if (x > node->_item) {
			node = node->_right;
		} else if (node->_item == x) {
			return node;
		}
	}

	return parent;
}


template <class T>
T BinarySearchTree<T>::successor(T x)
{
	TreeNode<T>* search_node = _search(_root, x);

	// if the item searched is greater than the target x , we found the successor
	if (search_node->_item > x) {
		return search_node->_item;
	

	// if the item found is == target x, and there is a right subtree we have to find the minimum in the right tree
	} else if (search_node->_item == x and search_node->_right){
		TreeNode<T>* node = search_node->_right;
		while (node->_left) {
			node = node->_left;
		}
		return node->_item;

	// we have to find the successor, we know for sure search node is in the tree
	// we just have to find the lowest ancestor that goes left
	} else {
		TreeNode<T>* node = _root;
		TreeNode<T>* successor;
		while (node->_item != search_node->_item) {
			if (search_node->_item > node->_item) {
				node = node->_right;
			} else if (search_node->_item < node->_item) {
				successor = node;
				node = node->_left;
			}
		}
		return successor->_item;
	}

}

template <class T>
TreeNode<T>* BinarySearchTree<T>::_leftRotation(TreeNode<T>* node)
{
	TreeNode<T>* new_root = node->_right;
	int temp_height = node->_height;
	node->_right= new_root->_left;
	new_root->_left= node;

	// swapping the old root height with new root height
	node->_height = new_root->_height;
	new_root->_height = temp_height;

	return new_root;
}

template <class T>
TreeNode<T>* BinarySearchTree<T>::_rightRotation(TreeNode<T>* node)
{
	TreeNode<T>* new_root = node->_left;
	int temp_height = node->_height;
	node->_left= new_root->_right;
	new_root->_right = node;

	// swapping the old root height with new root height
	node->_height = new_root->_height;
	new_root->_height = temp_height;

	return new_root;
}

template <class T>
TreeNode<T>* BinarySearchTree<T>::_leftBalance(TreeNode<T>* node){
	// this function will balance the tree when the left subtree is 
	// left heavy and will return the root node to the subtree
	TreeNode<T>* new_root;
	int tree_balance = balance(node->_left);
	if (tree_balance < -1) {
		node->_left = _leftRotation(node->_left);
	}
	
	new_root = _rightRotation(node);
	return new_root;
}

template<class T>
TreeNode<T>* BinarySearchTree<T>::_rightBalance(TreeNode<T>* node) {
	// this function will balance the tree when the right subtree is
	// right heavy and return the head of the new subtree
	TreeNode<T>* new_root;
	int tree_balance = balance(node->_right);
	if (tree_balance > 1){
		node->_right = _rightRotation(node->_right);
	}
	new_root = _leftRotation(node);
	return new_root;
}

template<class T>
int BinarySearchTree<T>::balance(TreeNode<T>* node){
	// function will output the balance of the tree
	//  +ve -> left heavy
	//  -ve -> right heavy
	int left_height = 0;
	int right_height = 0;
	if (node->_left) {
		left_height = node->_left->_height;
	}
	if (node->_right) {
		right_height = node->_right->_height;
	}
	return left_height - right_height;
}

template<class T>
int BinarySearchTree<T>::balance() {
	return balance(_root);
}
	
