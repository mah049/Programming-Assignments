#include "boggleutil.h"

// inserts word into lexicon
void Lexicon::insert(LexNode** root, std::string & word) {
  // to go through word
  std::string::iterator it = word.begin();
  // base case
  if (*root == NULL) {
  	*root = new LexNode(*it);
  }
  // recursively go left if less than root
  if (*it < (*root)->getData()) {
  	insert(&((*root)->left), word);
  }
  // recursively go right if greater than root
  else if (*it > (*root)->getData()) {
  	insert(&((*root)->right), word);
  }
  // otherwise go into middle
  else {
  	++it;
  	// insert middle
	if (it != word.end()) {
      std::string temp (it, word.end());
	  insert(&((*root)->middle), temp);
	}
	// end of word 
	else {
	  (*root)->setEndBit(true);
	}
  }
}

// finds a certain word in lexicon
bool Lexicon::find(const std::string & word_to_check) {
  LexNode * current = root;
  int index = 0;
  int size = (int)word_to_check.length();
  // go through word
  while (index < size) {
  	// word not in lexicon
  	if (current == NULL) {
  	  return false;
  	}
  	// go through each char in word
  	char temp = word_to_check[index];
  	// found word
  	if (current->getEndBit() && index==(size-1) && 
  			current->getData()==temp) {
  	  return true;
  	}
  	// go left
  	if (temp < current->getData()) {
  	  current = current->left;
  	}
  	// go right
  	else if (temp > current->getData()) {
  	  current = current->right;
  	} 
  	// go down and next char in word
  	else {
  	  ++index;
  	  current = current->middle;
  	}
  }
  // didn't find
  return false;
}

// checks if word is prefix of word or word in lexicon and returns 
// pointer to last node of that word
LexNode* Lexicon::isPrefix(const std::string word) {
	LexNode * current = root;
	int index = 0;
	int size = (int)word.length();
	// go through word
	while (index < size) {
		// word not in lexicon
		if (current == NULL) {
		  return nullptr;
		}
		// go through word by char
		char temp = word[index];
		// we're at the end of word
		if (index == (size-1) && current->getData()==temp) {
		  break;
		}
		// go left
		if (temp < current->getData()) {
		  current = current->left;
		}
		// go right
		else if (temp > current->getData()) {
		  current = current->right;
		} 
		// go down and next char in word
		else {
		  ++index;
		  current = current->middle;
		}
	}
	// last node corresponding to node
	return current;
}