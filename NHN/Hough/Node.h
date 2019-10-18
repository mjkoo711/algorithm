#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>
using namespace std;

class Node {
  public:
  char character;
  int frequency;
  Node *left, *right;
  
  public:
  Node(int c, int f): character(c), frequency(f) {
    left = NULL; right = NULL;
  }
};

#endif