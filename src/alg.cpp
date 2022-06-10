// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
    std::ifstream file(filename);
    if (!file) {
        throw std::string("file not found!");
    }
    std::string word = "";
    while (!file.eof()) {
        char c = file.get();
        int ascicode = c;
        if ((ascicode >= 65 && ascicode <= 90) || (ascicode >= 97 && ascicode <= 122)) {
            word += tolower(ascicode);
        } else {
            if (word != "") {
                tree.add(word);
                word = "";
            }
        }
    }
    file.close();
    return tree;// поместите сюда свой код
}
