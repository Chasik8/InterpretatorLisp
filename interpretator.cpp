//
// Created by hasni on 08.12.2024.
//
#include "interpretator.h"
namespace LispEnv {
    std::unordered_map <std::string, std::function<Tree*(Tree * )>> fun ={
            // надо будет придумать какой-то флаг типо #, что можно было использовать строку +
            {"+", sum},
            {"-", sub},
            {"*", mul},
            {"/", divv}
    };
    std::unordered_map <std::string, Tree * > global_value;
// надо бы избавится от pair, нужен флаг, что была операция, так как после нее надо заменить iter в sum а iter.root()
// иначе будем повторно считать те же значения
    std::pair<Tree*,bool>solution(Tree *root) {
        if (root == nullptr) {
            return std::pair(nullptr,false);
        }
        // можно сделать сложные функции, чтобы не создавать вектор из указателей
        if (root->get_type() == NIL) {
            solution(root->get_left());
            solution(root->get_right());
        }
        if (root->get_type() == STRING) {
            auto f = fun.find(root->get_data()->get_stringvalue());
            if (f != fun.end()) {
                return std::pair(f->second(root->get_root()->get_right())->get_root(),true);
            }
        }
        return std::pair(root,false);
    }
    // предполагается, что (,) не будет их удалит лексер
    Tree *sum(Tree *args) {
        if (args->get_data()->get_type() != NIL) {
            return args;
        }
        Tree *iter = args->get_left();
        while (iter->get_data()->get_type() == NIL) {
            iter = iter->get_left();
        }
        auto ans_solution=solution(iter);
        args->get_root()->copy_data(ans_solution.first);
        if (ans_solution.second){
            iter=iter->get_root();
        }
        while (iter!=args){
            passsum(iter->get_root()->get_right(),args->get_root());
            iter=iter->get_root();
        }
        return args;
    }
    Tree *passsum(Tree *args, Tree* ans) {
        if (args->get_left()==nulltree){
            ans->set_data(*ans->get_data() + *args->get_data());
        }else{
            passsum(args->get_left(),ans);
            passsum(args->get_right(),ans);
        }
        return ans;
    }
    Tree *sub(Tree *args) {
        if (args->get_data()->get_type() != NIL) {
            return args;
        }
        Tree *iter = args->get_left();
        while (iter->get_data()->get_type() == NIL) {
            iter = iter->get_left();
        }
        auto ans_solution=solution(iter);
        args->get_root()->copy_data(ans_solution.first);
        if (ans_solution.second){
            iter=iter->get_root();
        }
        while (iter!=args){
            passsub(iter->get_root()->get_right(),args->get_root());
            iter=iter->get_root();
        }
        return args;
    }
    Tree *passsub(Tree *args, Tree* ans) {
        if (args->get_left()==nulltree){
            ans->set_data(*ans->get_data() - *args->get_data());
        }else{
            passsub(args->get_left(),ans);
            passsub(args->get_right(),ans);
        }
        return ans;
    }

    Tree *mul(Tree *args) {
        if (args->get_data()->get_type() != NIL) {
            return args;
        }
        Tree *iter = args->get_left();
        while (iter->get_data()->get_type() == NIL) {
            iter = iter->get_left();
        }
        auto ans_solution=solution(iter);
        args->get_root()->copy_data(ans_solution.first);
        if (ans_solution.second){
            iter=iter->get_root();
        }
        while (iter!=args){
            passmul(iter->get_root()->get_right(),args->get_root());
            iter=iter->get_root();
        }
        return args;
    }
    Tree *passmul(Tree *args, Tree* ans) {
        if (args->get_left()==nulltree){
            ans->set_data(*ans->get_data() * *args->get_data());
        }else{
            passmul(args->get_left(),ans);
            passmul(args->get_right(),ans);
        }
        return ans;
    }
    Tree *divv(Tree *args) {
        if (args->get_data()->get_type() != NIL) {
            return args;
        }
        Tree *iter = args->get_left();
        while (iter->get_data()->get_type() == NIL) {
            iter = iter->get_left();
        }
        auto ans_solution=solution(iter);
        args->get_root()->copy_data(ans_solution.first);
        if (ans_solution.second){
            iter=iter->get_root();
        }
        while (iter!=args){
            passdivv(iter->get_root()->get_right(),args->get_root());
            iter=iter->get_root();
        }
        return args;
    }
    Tree *passdivv(Tree *args, Tree* ans) {
        if (args->get_left()==nulltree){
            ans->set_data(*ans->get_data() / *args->get_data());
        }else{
            passdivv(args->get_left(),ans);
            passdivv(args->get_right(),ans);
        }
        return ans;
    }
}