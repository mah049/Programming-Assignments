#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <utility> // for std::pair

template<typename Data>
class BST {

protected:

  /** Pointer to the root of this BST, or nullptr if the BST is empty */
  BSTNode<Data>* root;

  /** Number of Data items stored in this BST. */
  unsigned int isize;


public:

  /** iterator is an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
      Initialize an empty BST.
   */
  BST() : root(nullptr), isize(0)  {
  }


  /** Default destructor.
   *  It is virtual, to allow appropriate destruction of subclass objects.
   *  Delete every node in this BST.
   */ 
  virtual ~BST() {
    clear(); 
  }

  /** Insert a Data item in the BST.
   *  Return a pair, with the pair's first member set to an
   *  iterator pointing to either the newly inserted element
   *  or to the equivalent element already in the set.
   *  The pair's second element is set to true
   *  if a new element was inserted or false if an
   *  equivalent element already existed.
   */ 
  virtual std::pair<iterator,bool> insert(const Data& item) {
    /*if the root is empty create the node at the root*/
    if (root == NULL) {
      root = new BSTNode<Data>(item);
      /* increment the size of the tree*/
      this->isize++;
      return std::make_pair(BST<Data>::iterator(root), true);
    }
    
    /* creates an iterator that starts at the root*/
    iterator curr = iterator(root);
    
    /* while the data in the node does not equal the item to be inserted*/
    while (*curr != item) {
      /*if the item to be inserted is less than the curr node*/
      if (item < *curr) {
        /* if the iterator's left is null create the new node at that location*/
        if (curr.curr->left == NULL) {
	  curr.curr->left = new BSTNode<Data>(item);
	  /*update the values of the iterator*/
	  curr.curr->left->parent = curr.curr;
	  curr.curr = curr.curr->left;
	  this->isize++;
	  return std::make_pair(BST<Data>::iterator(curr.curr), true);
	}
	/* loop until it finds the left that is null*/
	else
	  curr.curr = curr.curr->left;
      }
      /* if the item to be inserted is greater than the curr node*/
      if (*curr < item) {
        /*if the iterator's right is null create the new node at that location*/
        if (curr.curr->right == NULL) {
	  curr.curr->right = new BSTNode<Data>(item);
	  /*update the values of the iterator*/
	  curr.curr->right->parent = curr.curr;
	  curr.curr = curr.curr->right;
	  this->isize++;
	  return std::make_pair(BST<Data>::iterator(curr.curr), true);
	}
	/*loop until it finds the right that is null*/
	else
	  curr.curr = curr.curr->right;
      }
    }

    /*if the item to be inserted is the same in the iterator do not insert*/
    if (*curr == item) {
      return std::make_pair(BST<Data>::iterator(curr.curr), false);
    }
    else 
      return std::make_pair(BST<Data>::iterator(curr.curr), true);
  }


  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or the end
   *  iterator if the item is not in the BST.
   */ 
  iterator find(const Data& item) const {
    
    /* if the tree does not exist*/
    if (root == NULL) 
      return end(); 
    
    /* creates an iterator that begins at the root*/
    iterator curr = BST<Data>::iterator(root);
    
    /* while the data of current does not match the item*/
    while (*curr != item) {
      /* if the item lies to the left of the current iterator node*/
      if (item < *curr) {
        /*the node does not exist so you return nullptr iterator*/
        if (curr.curr->left == NULL) {
	  return end();
	}
	/*loop through the tree*/
	else
	  curr.curr = curr.curr->left;
      }
      /* if the item lies to the right of the current iterator node*/
      if (*curr < item) {
        /* if the node does not exist you return a nullptr iterator*/
        if (curr.curr->right == NULL) {
	  return end();
	}
	/* loop through the tree*/
	else
	  curr.curr = curr.curr->right;
      }
    }
    /* if the iterator's data matches the item*/
    if (*curr == item) 
      /*return the current item node iterator*/
      return curr; 
    else
      return end();
  }

  
  /** Return the number of items currently in the BST.
   */ 
  unsigned int size() const {
    return this->isize;
  }

  /** Remove all elements from this BST, and destroy them,
   *  leaving this BST with a size of 0.
   */ 
  void clear() {
    if (root == NULL)
      return;
    root->clearNode();   
    /* destroy access and authority*/
    root = nullptr;
    isize = 0;
  }

  /** Return true if the BST is empty, else false.
   */ 
  bool empty() const {
    /* if the tree is empty*/
    if (isize == 0)
      return true;
    else
      return false;
  }

  /** Return an iterator pointing to the first item in the BST.
   */ 
  iterator begin() const {
    iterator curr = BST<Data>::iterator(root);
    /*loops until it finds the smallest element in the tree*/
    while (curr.curr->left != NULL){
      curr.curr = curr.curr->left;  
    }
    return curr;
  }

  /** Return an iterator pointing past the last item in the BST.
   */
  iterator end() const {
    return typename BST<Data>::iterator(nullptr);
  }

  

 };


#endif //BST_HPP
