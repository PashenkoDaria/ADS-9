// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>
#include <iostream>

template <typename Tr>
struct Node {
    Node<Tr>* r = nullptr;
    Node<Tr>* l = nullptr;
    Node<Tr>* prev = nullptr;
    int count = 0;
    Tr value = "";
};
template <typename Tr>
class BST {
 private:
    Node<Tr>* root = nullptr;
    int height = 0;
    void printtree(Node<Tr>* tree, int ind) {
        std::cout << ind << " " << tree->value << std::endl;
        ++ind;
        if (tree->l != nullptr) {
            printtree(tree->l, ind);
        }
        if (tree->r != nullptr) {
            printtree(tree->r, ind);
        }
    }
    void getdepth(Node<Tr>* tree, int ind) {
        ++ind;
        if (tree->l != nullptr) {
            getdepth(tree->l, ind);
        }
        if (tree->r != nullptr) {
            getdepth(tree->r, ind);
        }
        if (ind > height) {
            height = ind;
        }
    }
    void delnode(Node<Tr>* node) {
        if (node->l != nullptr) {
            delnode(node->l);
        }
        if (node->r != nullptr) {
            delnode(node->r);
        }
        delete node;
    }

 public:
    BST() {
        root = nullptr;
        height = 0;
    }
    ~BST() {
        delnode(root);
    }
    void add(Tr item) {
        Node<Tr>* curnt = root;
        Node<Tr>* prev = nullptr;
        int pos = 0;
        while (true) {
            if (curnt == nullptr) {
                curnt = new Node<Tr>;
                curnt->l = nullptr;
                curnt->r = nullptr;
                curnt->value = item;
                curnt->count = 1;
                if (prev != nullptr) {
                    curnt->prev = prev;
                    if (pos == 1) {
                        prev->r = curnt;
                    } else {
                        prev->l = curnt;
                    }
                    pos = 0;
                    prev = nullptr;
                }
                if (root == nullptr) {
                    root = curnt;
                }
                break;
            }
            if (curnt->value < item) {
                prev = curnt;
                pos = 1;
                curnt = curnt->r;
            } else if (curnt->value == item) {
                curnt->count++;
                break;
            } else {
                prev = curnt;
                pos = -1;
                curnt = curnt->l;
            }
        }
    }
    int search(Tr item) {
        Node<Tr>* curnt = root;
        while (true) {
            if (curnt == nullptr) {
                throw std::string("tree is empty!");
            } else if (curnt->value < item) {
                curnt = curnt->r;
            } else if (curnt->value == item) {
                return curnt->count;
            } else {
                curnt = curnt->l;
            }
        }
    }
    void print() {
        Node<Tr>* curnt = root;
        printtree(curnt, 0);
    }
    int depth() {
        Node<Tr>* curnt = root;
        getdepth(curnt, 0);
        return height - 1;
    }
};
#endif  // INCLUDE_BST_H_
