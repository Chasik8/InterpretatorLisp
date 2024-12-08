//
// Created by hasni on 04.12.2024.
//

#ifndef INTERPRETER_LISP_PARSER_H
#define INTERPRETER_LISP_PARSER_H
#include "tree.h"
#include <stack>
namespace LispEnv {
    class Parser {
    private:
        std::string code;
    public:
        Parser(std::string s);

        int run(Tree *root);

        void update_atom(Tree *root, Atom *atom, bool &flag_init_atom) const;
    };
}
#endif //INTERPRETER_LISP_PARSER_H
