//
// Created by hasni on 04.12.2024.
//
#include "tree.h"
namespace LispEnv {
    Atom* nullatom=new Atom(nullnode);
    Tree* nulltree=new Tree(nullatom);
    bool Tree::set_left(Tree *val) {
        left = val;
        return true;
    }

    bool Tree::set_right(Tree *val) {
        right = val;
        return true;
    }

    bool Tree::set_data(const Atom& val) {
        *data = val;
        return true;
    }

    Tree *Tree::get_right() {
        return right;
    }

    Tree *Tree::get_root() {
        return root;
    }

    Tree *Tree::add(Tree *val,bool direction) {
        if (direction) {
            if (set_right(val)) {
                right->root = this;
                return right;
            }
            std::cout << "error right" << std::endl;
        }
        if (set_left(val)) {
            left->root = this;
            return left;
        }
        std::cout << "error left" << std::endl;
        return nullptr;
    }

    Tree::Tree(Atom *val) : data(val), left(nulltree),right(nulltree) {}

    valuetype Tree::get_type() {
        if (data== nullptr)
            return NIL;
        return data->get_type();
    }

    Atom* Tree::get_data() {
        return data;
    }

    Tree *Tree::get_left() {
        return left;
    }

    Tree* Tree::copy_data(const Tree *other) {
        if (this == other) return this;  // Защита от самоприсваивания
        *data=*other->data;
        return this;
    }
};