#ifndef TREE_H
#define TREE_H
template <class T>
class Node {
public:
    Node();
    Node(T data);
    Node(const Node<T> & source);
    ~Node();
    Node & operator=(const Node<T> & source);
    T getData() const;
    Node<T> * getLeft() const;
    Node<T> * getRight() const;
    bool hasLeft() const;
    bool hasRight() const;
    void insert(T data);
    void inOrder() const;
    bool search(T searchData) const;
    int size();
    int height();
private:
    T myData;
    Node<T> * myLeft = nullptr;
    Node<T> * myRight = nullptr;
    void setLeft(Node<T> * left);
    void setRight(Node<T> * right);
    void setData(T data);
};

template <class T>
class Bst {
public:
    Bst();
    Bst(const Bst & source);
    ~Bst();
    Bst & operator=(const Bst & source);
    bool empty() const { return myRoot == nullptr; };
    void insert(T data);
    bool search(T searchData) const;
    void inOrder() const;
    int size();
    int height();
private:
    Node<T> * myRoot;
};
#endif