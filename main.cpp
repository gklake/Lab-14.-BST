#include <iostream>
#include "Tree.h"
#include "Tree.cpp"
using namespace std;
void print(Node<int> & n);
int main( )
{
  Bst<int> intBst;
  cout << intBst.size() << endl; // 0
  intBst.insert(50);
  cout << intBst.size() << endl; // 1
  intBst.insert(20);
  intBst.insert(70);
  cout << intBst.size() << endl; // 3
  intBst.insert(25);
  intBst.insert(100);
  intBst.insert(200);
  intBst.insert(300);
  cout << intBst.size() << endl; // 7


Bst<double> doubleBst;
doubleBst.insert(5.1);
doubleBst.insert(10.2);
doubleBst.insert(15.3);
cout << "Searching for value 7.5 " << boolalpha << doubleBst.search(7.5) << endl;
  return 0;
}

void print(Node<int> & n) {
    cout << "Data: " << n.getData() << endl;
    cout << "Has right: " << boolalpha << n.hasRight() << endl;
    cout << "Has left: " << boolalpha << n.hasLeft() << endl; 
    cout << endl;
}