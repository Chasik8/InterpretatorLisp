#include "tree.h"
#include <string>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#include <functional>
#include <any>
#include "parser.h"
namespace interpretator {
    Atom* sum(std::vector<Atom*> args) {
        Atom* ans=new Atom(args[0]->get_type());
        for (long long int i=1;i<args.size();++i){
            *ans+=*args[i];
        }
        return ans;
    }
    class TreeSolution {
    private:
        using FuncType = std::function<std::any(std::vector<Atom*>)>;
        std::unordered_map<std::string, FuncType> fun;
    public:
        TreeSolution(){
            fun["+"]=sum;
        }
        // Надо переделать, что бы возвращал Atom, тогда значения функции подгружаются на лету
        // и тогда есть возможность разграничить список списков.
        int solution(Tree* root, std::vector<Atom*>& vec){
            if (root== nullptr){
                return 0;
            }
            // можно сделать сложные функции, чтобы не создавать вектор из указателей
            bool flag_fun=true;
            if (root->get_type()==NIL){
                solution(root->get_left(),vec);
                solution(root->get_right(),vec);
            }
            if (root->get_type()==STRING){
                auto f=fun.find(root->get_data()->get_stringvalue());
                if (f!=fun.end()){
                    flag_fun=false;
                    std::vector<Atom*> fvec;
                    solution(root->get_root()->get_right(),fvec);
                    auto dop=f->second;
                }
            }
            if (flag_fun){
                vec.push_back(root->get_data());
            }
            return 0;
        }
    };


}
int main() {
    interpretator:: Parser pr("(+,(12.3,2))");
    interpretator::Tree* root=new interpretator::Tree(0);
    pr.run(root);
    std::vector<interpretator::Atom*> vec;
    interpretator::TreeSolution trs;
    trs.solution(root,vec);

    return 0;
}
