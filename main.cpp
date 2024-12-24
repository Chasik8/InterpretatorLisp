#include "interpretator.h"
int main() {
    LispEnv:: Parser pr("(-,(10,(5,2)))");
    LispEnv::Tree* root=new LispEnv::Tree(new LispEnv::Atom(LispEnv::nil));
    pr.run(root);
    LispEnv::solution(root);
    root->get_data()->print();
    return 0;
}
