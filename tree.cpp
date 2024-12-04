//
// Created by hasni on 04.12.2024.
//
#include "tree.h"
namespace interpretator {
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

    bool Tree::set_direction(bool direct) {
        direction = direct;
        return true;
    }

    Tree *Tree::add(Tree *val) {
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

    Tree::Tree(Atom *val) : data(val) {}

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
};