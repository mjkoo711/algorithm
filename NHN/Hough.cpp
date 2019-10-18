#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct Node {
  char character;
  int frequency;
  Node *left, *right;
  Node(int c, int f): character(c), frequency(f) {
    left = NULL; right = NULL;
  }
};

struct Compare {
  bool operator() (Node* const& n1, Node* const& n2) {
    return n1->frequency >= n2->frequency;
  }
};

priority_queue<Node*, vector<Node*>, Compare> pq;

map<char, string> houghMap;
void find(Node* node, string code);
void set(char key, string value);
void print(string s);

int main() {
  string s = "AAAAABBBBCCCDDE";
  map<char, int> m;

  for (int i=0; i<s.size(); i++) {
    if (m[s[i]]) m[s[i]]++;
    else m[s[i]] = 1;
  }

  for (map<char, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
    pq.push(new Node(iter->first, iter->second));
  }

  while (pq.size() > 1) {
    Node *right = pq.top(); pq.pop();
    Node *left = pq.top(); pq.pop();
    Node *newNode = new Node(' ', left->frequency+right->frequency);
    newNode->left = left, newNode->right = right;
    pq.push(newNode);
  }

  Node *root = pq.top(); 
  find(root, "");
  print(s);
  return 0;
}

void find(Node* node, string code) {
  if (node->left == NULL && node->right == NULL) {
    set(node->character, code);
    return ;
  } 

  find(node->left, code+"0");
  find(node->right, code+"1");
}

void set(char key, string value) {
  houghMap[key] = value;
}

void print(string s) {
  for (int i=0; i<s.size(); i++) {
    cout << houghMap[s[i]] << " ";
  }
  cout << endl;
}

