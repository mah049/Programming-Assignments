/******************************************************
 * Tester file to test basic functionality of your code
 * ****************************************************/

#include "baseboggleplayer.h"
#include "boggleplayer.h"
#include <iostream>
#include <vector>
#include <string>
#include <set>

int main () {

  BaseBogglePlayer * p = new BogglePlayer();
  set<string> lex;
  string wordA("cab");
  string wordX("m");
  lex.insert(wordA);
  lex.insert("cabin");
  lex.insert("cabp");
  lex.insert("cbp");

  string row0[] = {"b", "a"};
  string row1[] = {"p", "C"};
  //string row2[] = {"S", "a", "N"};
  string* board[] = {row0,row1};
  set<string> words;
  vector<int> locations;

  p->buildLexicon(lex);

  p->setBoard(2,2,board);
  //((BogglePlayer*)p)->print(4,4);

  /*if(p->isInLexicon(wordX)) {
    std::cerr << "Apparent problem with isInLexicon #1." << std::endl;
    return -1;
  }
  if(!p->isInLexicon(wordA)) {
    std::cerr << "Apparent problem with isInLexicon #2." << std::endl;
    return -1;
  }

  if(p->isOnBoard(wordX).size() > 0) {
    std::cerr << "Apparent problem with isOnBoard #1." << std::endl;
    return -1;
  }

  locations.clear();
  locations = p->isOnBoard("cabcs");
  vector<int>::iterator it;
  for (it = locations.begin(); it != locations.end(); ++it) {
    std::cout<<*it<<" ";
  }
  std::cout<<"\n";

  if(locations.size() != 6) {
    std::cerr << "Apparent problem with isOnBoard #2." << std::endl;
    //std::cout<<locations.size()<<std::endl;
    return -1;
  }
  
  if(!p->getAllValidWords(0,&words)) {
    std::cerr << "Apparent problem with getAllValidWords #1." << std::endl;
    return -1;
  }*/
  p->getAllValidWords(0,&words);
  set<string>::iterator it;
  for (it=words.begin(); it!=words.end(); ++it) {
    std::cout<<*it<<std::endl;
  }
  /*if(words.size() != 1 || words.count(wordA) != 1) {
    std::cerr << "Apparent problem with getAllValidWords #2." << std::endl;
    return -1;
  }*/

  delete p;
  return 0;

}
