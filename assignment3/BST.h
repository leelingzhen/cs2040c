#pragma once
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
	int _getHeight(TreeNode<T>*);
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
	TreeNode<T>* _balance_tree(TreeNode<T>*);


public:
	BinarySearchTree() { _root = NULL; _size = 0; }
	~BinarySearchTree();
	int size() { return _size; };
	void insert(T);
	void printTree(bool withHeight = 1);
	void inOrderPrint();
	void postOrderPrint();
	void preOrderPrint();
	T searchMax(); 
	T searchMin();
	bool exist(T x);
	T search(T x) { return T(); };
	T successor(T);
	int balance(TreeNode<T>* );
	int balance();

};
#include "BST.hpp"
