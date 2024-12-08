//
// Created by hasni on 04.12.2024.
//
#include "parser.h"
namespace LispEnv{
void Parser::update_atom(Tree *root, Atom *atom, bool &flag_init_atom) const {
    if (flag_init_atom){
        atom->define();
        root->set_data(*atom);
        atom->init();
        flag_init_atom=false;
    }
}

int Parser::run(Tree *root) {
    std::stack<char> st;
    Atom* atom=new Atom("");
    bool flag_init_atom=false;
    // можно переделать, чтобы тип определялся походу добавления значения, заранее хранить все типы и
    // как только тип будет одназначно определен установить tom и
    // добавлять только туда (пример если было 123, после 1 мы сразу знаем что это число, тогда меням флаг на то,
    // что тип определн и добавлемя его сразу в atom, тогда можно добавить тип функции,
    // что уберет вычиление хеша для unordered_map)
    // можно удалить direction из дерева и сделать временной переменной,
    // ведь он не где не исоьзуеться, а внутри скобок всегда должна быть запятая (,).
    for (unsigned long long int i=0;i<code.size();++i){
        if (code[i]!=' '){
            switch (code[i]) {
                case '(':
                    update_atom(root, atom, flag_init_atom);
                    root=root->add(new Tree(new Atom(nil)),false);
                    break;
                case ',':
                    update_atom(root, atom, flag_init_atom);
                    root=root->get_root();
                    root=root->add(new Tree(new Atom(nil)),true);
                    break;
                case ')':
                    update_atom(root, atom, flag_init_atom);
                    root=root->get_root();
                    break;
                default:
                    *atom+=code[i];
                    flag_init_atom=true;
                    break;
            }
        }
    }
    return 0;
}

Parser::Parser(std::string s) {
    code=s;
}
}
