//
// Created by hasni on 04.12.2024.
//

#ifndef INTERPRETER_LISP_TREE_H
#define INTERPRETER_LISP_TREE_H
#include <iostream>
#include "atom.h"
namespace LispEnv{
    // надо сделать константным, но надо добавить еще один конструктор
extern Atom* nullatom;
class Tree {
private:
    Atom *data;
    Tree *right;
    Tree *left;
    Tree *root;
//    bool direction = false;
public:
    Tree(Atom *val);

    bool set_left(Tree *val);

    bool set_right(Tree *val);

    Tree *add(Tree *val,bool direction);

    bool set_direction(bool direct);

    Tree *get_root();

    Tree *get_right();

    Tree* copy_data(const Tree* other);

    bool set_data(const Atom& val);
    valuetype get_type();
    Atom* get_data();
    Tree *get_left();
};
extern Tree* nulltree;
};
#endif //INTERPRETER_LISP_TREE_H
