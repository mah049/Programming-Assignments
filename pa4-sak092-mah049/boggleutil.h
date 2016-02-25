// Kyle Barron-Kraus <kbarronk>

#ifndef BOGGLEUTIL_H
#define BOGGLEUTIL_H

#include <cctype>
#include <algorithm>
#include <map>
#include <memory>
#include <string>
#include <utility>


/**
 * Class that represents a position on the Boggle Board.
 *
 * Each position contains its sanitized string that represents the
 * characters on that board position, as well as a boolean that
 * marks the board position as visited by a given search algorithm.
 */
class BoardPos {
  public:
    /**
     * Constructs a BoardPos with the given text. Text must have been
     * sanitized by the caller.
     */
    BoardPos(const std::string &text, int pos): text(text), 
                            visited(false), pos(pos) {}

    /**
     * Returns the characters on this BoardPos.
     */
    const std::string & getText() const {
        return this->text;
    }
    
    /**
     * Returns whether this BoardPos has been visited or not.
     */
    bool getVisited() const {
        return this->visited;
    }

    /**
     * Sets whether this BoardPos has been visited or not.
     */
    void setVisited(bool visited){
        this->visited = visited;
    }

    // returns position
    int getPos() const {
        return this->pos;
    }

    // setter for position
    void setPos(int position) {
        this->pos = position;
    }

    // gets revisited tag
    bool getReVisited() const {
        return this->reVisited;
    }

    // sets revisted tag
    void setReVisited(bool temp) {
        this->reVisited = temp;
    }
    
  private:
    /**
     * The characters that this BoardPos contains.
     */
    const std::string text;

    /**
     * Whether this BoardPos has been visited or not.
     */
    bool visited;

    // for backtracking
    bool reVisited;

    // position
    int pos;
};



/**
 * Implement class for Trie
 */
class LexNode {
  private:
    //Map of letters to child LexNodes corresponding to those letters
    //std::map<char, LexNode*> children;

    //indicate end of word
    bool endBit;

    //data
    char data;

  public:
    // Constructor
    LexNode(char data): endBit(false), data(data), left(0), middle(0)
        , right(0) {}

    // left middle and right pointers for ternary trie
    LexNode * left;
    LexNode * middle;
    LexNode * right;

    // gets character at node
    char getData() {
        return this->data;
    }

    // destructor stuff
    void clear() {
        if(left) {
          left->clear();
        }
        if(middle) {
          middle->clear();
        }
        if(right) {
          right->clear();
        }
        delete this;
    }

    // sets end bit
    void setEndBit(bool val) {
        this->endBit = val;
    }

    // gets end bit
    bool getEndBit() {
        return this->endBit;
    }
 };

class Lexicon {
  private:
    // Pointer to root of trie
    LexNode * root;

    // whether or not built
    bool lex_built;

  public:
    // Constructor
    Lexicon(): root(nullptr), lex_built(false) {}

    // Method to insert a word to Lexicon
    void insert (LexNode** root, std::string &word);

    // Method to check if a word exists in the Lexicon
    bool find (const std::string &word);

    // getter for built boolean
    bool isBuilt() {
        return this->lex_built;
    }

    // sets built boolean
    void setBuilt(bool val) {
        this->lex_built = val;
    }

    // gets pointer to root
    LexNode** getRoot() {
      return &this->root;
    }

    // gets root
    LexNode* getRootGAVW() {
      return this->root;
    }

    // checks if prefix of word in lexicon
    LexNode* isPrefix(const std::string word);

    // destructor
    ~Lexicon() {
        if (!root) {
            return;
        }
        root->clear();
        root = nullptr;
    }
 };


#endif // BOGGLEUTIL_H
