/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
#include <algorithm>

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    // your code here
	Node* temp;
	temp = t->right;
	t->right = temp->left;
	temp->left = t;

	temp->height = max(heightOrNeg1(temp->left), heightOrNeg1(temp->right)) + 1;
	t->height = max(heightOrNeg1(t->left), heightOrNeg1(t->right)) + 1;
	t=temp;
	
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    // your code here
	Node* temp;
	temp = t->left;
	t->left = temp->right;
	temp->right = t;

	temp->height = max(heightOrNeg1(temp->left), heightOrNeg1(temp->right)) + 1;
	t->height = max(heightOrNeg1(t->left), heightOrNeg1(t->right)) + 1;

	t=temp;
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    // your code here
	rotateRight(t->right);
	rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    // your code here
	int difference = heightOrNeg1(subtree->left) - heightOrNeg1(subtree->right);
	if(difference <= 1 && difference >= -1) return;
	else if(difference >= 2){
		if(heightOrNeg1(subtree->left->left) > heightOrNeg1(subtree->left->right)) {
			rotateRight(subtree);
		}
		else rotateLeftRight(subtree);
	}
	else if(difference <= -2){
		if(heightOrNeg1(subtree->right->right) > heightOrNeg1(subtree->right->left)) {
			rotateLeft(subtree);
		}
		else rotateRightLeft(subtree);
	}
	subtree->height = max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right)) + 1;
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here
	if(subtree == NULL){
		subtree = new Node (key, value);
	}
	else if(key < subtree->key){
		insert(subtree->left, key, value);
		rebalance(subtree);
	}
	else if(key > subtree->key){
		insert(subtree->right, key, value);
		rebalance(subtree);
	}
	subtree->height = max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right)) + 1;
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
	if (subtree == NULL) return;
	if (key < subtree->key) {
        // your code here
		remove(subtree->left, key);
		rebalance(subtree);
	}
	else if (key > subtree->key) {
        // your code here
		remove(subtree->right, key);
		rebalance(subtree);
	}
	else if(key == subtree->key) {
		if(subtree->left == NULL && subtree->right == NULL) {
		/* no-child remove */
		// your code here
			delete(subtree);
			subtree = NULL;
		}		
		else if (subtree->left != NULL && subtree->right != NULL) {
        	    /* two-child remove */
        	    // your code here
			Node* temp = subtree->left;
			while(temp->right != NULL) temp = temp->right;
			subtree->key = temp->key;
			subtree->value = temp->value;
			remove(subtree->left, temp->key);
			rebalance(subtree);
		}
		else {
        	    /* one-child remove */
        	    // your code here
			Node* temp = subtree;
			if(subtree->left == NULL)   subtree = subtree->right;
			else  subtree = subtree->left;
			delete temp;
			temp = NULL;
		}
        	// your code here
	}
	if(subtree == NULL) return;
	rebalance(subtree);
	return;
}
