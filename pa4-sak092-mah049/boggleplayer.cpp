#include "boggleplayer.h"

using namespace std;

// initializes shit
void BogglePlayer::setBoard(unsigned int rows, unsigned int cols,
            std::string **diceArray){
	// set vars of board
	this->rows = rows;
	this->cols = cols;
	// go through array and set board
	for (unsigned int i=0; i<rows; i++) {
		for (unsigned int j=0; j<cols; j++) {
		  string temp (diceArray[i][j]);
		  transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		  BoardPos current(temp, (i*cols+j));
		  board.push_back(current);	
		}
	}
	// done
	this->board_built = true;
}

// debug stuff
void BogglePlayer::print(unsigned int rows, unsigned int cols) {
	for (unsigned int i=0; i<rows; i++) {
        for (unsigned int j=0; j<cols; j++) {
            cout<<board[i*cols+j].getText()<<", "<<(board[i*cols+j].getVisited() ? "true":"false")<<endl;
        }
        cout<<endl;
    }
    cout<<endl;
}

// checks if string is on board and gives positions for it
std::vector<int> BogglePlayer::isOnBoard(const std::string &word_to_check){
	vector<int> positions;// to be returned
	vector<BoardPos>::iterator it;// go through board
	stack<BoardPos> S; // stack for dfs
	unsigned int pos = 0; // start
	// start node
	for (it = board.begin(); it != board.end(); ++it) {
		it->setVisited(false);
		it->setReVisited(false);
		if (it->getText().compare(0, it->getText().size(), 
			word_to_check, 0, it->getText().size()) == 0) {
			S.push(*it);
		}
	}
	// modified dfs
	while (!S.empty()) {
		int curr = S.top().getPos(); // current top of stack
		S.pop();
		// revisited check for backtracking
		if (board[curr].getReVisited() == true) {
			board[curr].setReVisited(false);
			board[curr].setVisited(false);
			// go back
			pos -= board[curr].getText().size();
			positions.pop_back();
		}
		// we found it
		else if (board[curr].getVisited() == false && board[curr].getText().compare(0, 
				board[curr].getText().size(), word_to_check, pos, 
				board[curr].getText().size()) == 0) {
			board[curr].setVisited(true);
			// we found so push to vector
			positions.push_back(curr);
			pos += board[curr].getText().size();
			// all of word so done
			if (pos == word_to_check.size()) {
				break;
			}
			board[curr].setReVisited(true);
			S.push(board[curr]);
			// get all unvisted neighbors
			getNeighbors(board[curr].getPos(), &S);
		}
	}
	// done
	return positions;
}

// helper for is on board
void BogglePlayer::getNeighbors(int current, stack<BoardPos> * myStack) {
	int rowNum = current / cols; // current row
	int colNum = current % cols; // current col
	// bounds check and visited flag checks
	if (rowNum < (rows-1)) {
		if (board[current+cols].getVisited() == false) {
			myStack->push(board[current+cols]);
		}
	}
	if (rowNum > 0) {
		if (board[current-cols].getVisited() == false) {
			myStack->push(board[current-cols]);
		}
	}
	if (colNum < (cols-1)) {
		if (board[current+1].getVisited() == false) {
			myStack->push(board[current+1]);
		}
	}
	if (colNum > 0) {
		if (board[current-1].getVisited() == false) {
			myStack->push(board[current-1]);
		}
	}
	if (rowNum < (rows-1) && colNum < (cols-1)) {
		if (board[current+cols+1].getVisited() == false) {
			myStack->push(board[current+cols+1]);
		}
	}
	if (rowNum < (rows-1) && colNum > 0) {
		if (board[current+cols-1].getVisited() == false) {
			myStack->push(board[current+cols-1]);
		}
	}
	if (rowNum > 0 && colNum < (cols-1)) {
		if (board[current-cols+1].getVisited() == false) {
			myStack->push(board[current-cols+1]);
		}
	}
	if (rowNum > 0 && colNum > 0) {
		if (board[current-cols-1].getVisited() == false) {
			myStack->push(board[current-cols-1]);
		}
	}
}

// builds lexicon using set
void BogglePlayer::buildLexicon(const std::set<std::string> &word_list){
	// call insert() of lexicon to insert word to trie
	vector<string> temp (word_list.size());
	copy(word_list.begin(), word_list.end(), temp.begin());
	// randomly insert into trie for efficency
	random_shuffle(temp.begin(), temp.end());
	// insert into lex
	vector<string>::iterator it;
	for (it=temp.begin(); it!=temp.end(); ++it) {
		lex.insert(lex.getRoot(), *it);
		//cout<<*it<<"\n";
	}
	lex.setBuilt(true);
}

// checks if word is in lexicon
bool BogglePlayer::isInLexicon(const std::string &word_to_check){
	// call find() of lexicon to find if word is present in trie
	if (!lex.isBuilt()) {
		return false;
	}
	bool val = lex.find(word_to_check);
	return val;
}

// finds all words in lexicon that are on board
bool BogglePlayer::getAllValidWords(unsigned int minimum_word_length,
                                       std::set<std::string> *words) {
	// basic checks
	if (!lex.isBuilt() || !board_built) {
		return false;
	}
	// go through board and call getWords
	string word_matched;
	LexNode * cur = lex.getRootGAVW();
	for (int i=0; i<rows; i++) {
		for (int j=0; j<cols; j++) {
			// reset all the shit
			vector<BoardPos>::iterator it;
			for (it = board.begin(); it != board.end(); ++it) {
				it->setVisited(false);
				it->setReVisited(false);
			}
			getWords(i, j, cur, word_matched, words, minimum_word_length);
		}
	}
	// done
	return true;
}

// helper for GAVW
void BogglePlayer::getWords(unsigned int row, unsigned int col, LexNode * currNode, 
		string word_matched, set<string> * words, unsigned int minimum_word_length) {

	// reset flags
	int pos = row*cols+col;
	if (board[pos].getReVisited() == true) {
		board[pos].setReVisited(false);
		board[pos].setVisited(false);
		//word_matched.erase(word_matched.length()-board[pos].getText().length()-1, 
			//board[pos].getText().length());
	}
	else if (board[pos].getVisited() == false) {
		board[pos].setVisited(true);
		board[pos].setReVisited(true);
	}
	else {
		return;
	}
	
	string word2 (board[pos].getText());
	string word1 (word_matched);
	word1 += word2;
	currNode = lex.isPrefix(word1);
	//cout<<currNode->getData()<<endl;
	// is prefix helper call
	if (currNode == NULL) {
		board[pos].setReVisited(false);
		board[pos].setVisited(false);	
		return;
	}

	// append to found word
	word_matched += board[pos].getText();

	// if endbit set and length >= minlength, then we found valid word
	if (currNode->getEndBit() && (unsigned int)word_matched.length()>=minimum_word_length) {
		words->insert(word_matched);
		//word_matched.clear();
	}
	// call getwords for all neighbors of (row,col)
	int curr = pos;
	int rowNum = curr / cols;
	int colNum = curr % cols;
	// checks for bounds and vistied flags
	if (rowNum < (rows-1)) {
		if (board[curr+cols].getVisited() == false) {
		  getWords(row+1,col,currNode,word_matched,words,minimum_word_length);
		}
	}
	if (rowNum > 0) {
		if (board[curr-cols].getVisited() == false) {
	      getWords(row-1,col,currNode,word_matched,words,minimum_word_length);
		}
	}
	if (colNum < (cols-1)) {
		if (board[curr+1].getVisited() == false) {
		  getWords(row,col+1,currNode,word_matched,words,minimum_word_length);
		}
	}
	if (colNum > 0) {
		if (board[curr-1].getVisited() == false) {
		  getWords(row,col-1,currNode,word_matched,words,minimum_word_length);
		}
	}
	if (rowNum < (rows-1) && colNum < (cols-1)) {
		if (board[curr+cols+1].getVisited() == false) {
		  getWords(row+1,col+1,currNode,word_matched,words,minimum_word_length);
		}
	}
	if (rowNum < (rows-1) && colNum > 0) {
		if (board[curr+cols-1].getVisited() == false) {
		  getWords(row+1,col-1,currNode,word_matched,words,minimum_word_length);
		}
	}
	if (rowNum > 0 && colNum < (cols-1)) {
		if (board[curr-cols+1].getVisited() == false) {
		  getWords(row-1,col+1,currNode,word_matched,words,minimum_word_length);
		}
	}
	if (rowNum > 0 && colNum > 0) {
		if (board[curr-cols-1].getVisited() == false) {
		  getWords(row-1,col-1,currNode,word_matched,words,minimum_word_length);
		}
	}
	// gotta reset as go up recursive calls
	board[pos].setReVisited(false);
	board[pos].setVisited(false);
}

// whatever
void BogglePlayer::getCustomBoard(std::string **&new_board,
            unsigned int *rows, unsigned int *cols){

}
