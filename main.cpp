#include "interpretator.h"
int main() {
    LispEnv:: Parser pr("(+,(((+,(10,100)),3),(2,(+,(200,300)))))");
    LispEnv::Tree* root=new LispEnv::Tree(new LispEnv::Atom(LispEnv::nil));
    pr.run(root);
    LispEnv::solution(root);
    return 0;
}
