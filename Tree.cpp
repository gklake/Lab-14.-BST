#include "Tree.h"
#include <iostream>
using namespace std;

template <class T>
Node<T>::Node() 
: myData(0), myLeft(nullptr), myRight(nullptr)
{
    //intentionally empty
} 
 
template <class T>
Node<T>::Node(T data)
: myData(data), myLeft(nullptr), myRight(nullptr)
{
    //intentionally empty
}

template <class T>
Node<T>::~Node() {
    if(getLeft() != nullptr) {
        delete getLeft();
    }

    if(getRight() != nullptr) {
        delete getRight();
    }
    //cout << "Deleting " << getData() << endl;
}

template <class T>
Node<T>::Node(const Node<T> & source) {
    if(source.hasLeft()) {
        setLeft(new Node(*source.getLeft()));
    }
    if(source.hasRight()) {
        setRight(new Node(*source.getRight()));
    }
    setData(source.getData());
} 

template <class T>
Node<T> & Node<T>::operator=(const Node<T> & source) {
    if(this != &source) {
        // not self-assigning
        if(getLeft() != nullptr) {
            delete getLeft();
        }

        if(getRight() != nullptr) {
            delete getRight();
        }

        if(source.hasLeft()) {
            setLeft(new Node(*source.getLeft()));
        }
        if(source.hasRight()) {
            setRight(new Node(*source.getRight()));
        }
        setData(source.getData());
    }
    return *this;
}

template <class T>
void Node<T>::setLeft(Node<T> * left) {
    myLeft = left;
}

template <class T>
bool Node<T>::hasLeft() const {
    return myLeft != nullptr;
}

template <class T>
Node<T> * Node<T>::getLeft() const {
    return myLeft;
}

template <class T>
void Node<T>::setRight(Node<T> * right) {
    myRight = right;
}

template <class T>
bool Node<T>::hasRight() const {
    return myRight != nullptr;
}

template <class T>
Node<T> * Node<T>::getRight() const {
    return myRight;
}

template <class T>
T Node<T>::getData() const {
    return myData;
}

template <class T>
void Node<T>::setData(T data) {
    myData = data;
}

template <class T>
void Node<T>::insert(T data) {
    if(data <= getData()) {
        if(hasLeft()) {
            getLeft()->insert(data);
        } else {
            setLeft(new Node(data));
        }
    } else {
        if(hasRight()) {
            getRight()->insert(data);
        } else {
            setRight(new Node(data));
        }
    }
}

template <class T>
void Node<T>::inOrder() const {
    if(hasLeft()) {
        getLeft()->inOrder();
    }
    cout << getData() << " ";
    if(hasRight()) {
        getRight()->inOrder();
    }

}

template <class T>
int Node<T>::size(){
  if(!hasLeft() && !hasRight()){
    return 1;
  } else {
    int size = 1;
    if(hasLeft()) {
      size += getLeft()->size();
    }
    if(hasRight()){
      size += getRight()->size();
    }
    return size;
  }
  return 0;
}

template <class T>
int Node<T>::height(){
  if(!hasLeft() && !hasRight()){
    return 1;
  } else {
    int leftHeight = 0;
    int rightHeight = 0;
    if(hasLeft()) {
      leftHeight = getLeft()->height();
    }
    if(hasRight()){
      rightHeight = getRight()->height();
    } 
    if(leftHeight > rightHeight){
      return 1 + leftHeight;
    } else {
      return 1 + rightHeight;
    }
  }
}

template <class T>
int Bst<T>::height(){
  if(!empty()){
    return myRoot->height();
  }
  return 0;
}

template <class T>
int Bst<T>::size(){
  if(!empty()){
    return myRoot->size();
  }
  return 0;
}


template <class T>
Bst<T>::Bst() : myRoot(nullptr) {

}

template <class T>
Bst<T>::~Bst() {
    if(! empty()) {
        delete myRoot;
    }
}

template <class T>
void Bst<T>::insert(T data) { 
    if(empty()) {
        myRoot = new Node<T>(data);
    } else {
        myRoot->insert(data);
    }
}

template <class T>
void Bst<T>::inOrder() const {
    if(! empty()) {
        myRoot->inOrder();
        cout << endl;
    }
}

template <class T>
bool Bst<T>::search(T searchData) const {
    if(empty()) {
        return false;
    }
    return myRoot->search(searchData);
}

template <class T>
bool Node<T>::search(T searchData) const {
    if(getData() == searchData) {
        return true;
    } else if(getData() > searchData && hasLeft()) {
        return getLeft()->search(searchData);
    } else if(getData() < searchData && hasRight()) {
        return getRight()->search(searchData);
    } else {
        return false;
    }
}