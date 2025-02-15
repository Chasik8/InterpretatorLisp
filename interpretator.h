//
// Created by hasni on 08.12.2024.
//

#ifndef INTERPRETER_LISP_INTERPRETATOR_H
#define INTERPRETER_LISP_INTERPRETATOR_H
#include "tree.h"
#include <string>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#include <functional>
#include <any>
#include "parser.h"
namespace LispEnv {
//Сделано!
// Надо переделать, что бы возвращал Atom, тогда значения функции подгружаются на лету
// и тогда есть возможность разграничить список списков.
    std::pair<Tree*,bool>solution(Tree *root);

    Tree *sum(Tree *args);

    Tree *sub(Tree *args);

    Tree *mul(Tree *args);

    Tree *divv(Tree *args);

    Tree *passsum(Tree *args,Tree* ans);

    Tree *passsub(Tree *args,Tree* ans);

    Tree *passmul(Tree *args,Tree* ans);

    Tree *passdivv(Tree *args,Tree* ans);

    extern std::unordered_map <std::string, std::function<Tree*(Tree * )>> fun ;

    extern std::unordered_map <std::string, Tree * > global_value ;
}
#endif //INTERPRETER_LISP_INTERPRETATOR_H
