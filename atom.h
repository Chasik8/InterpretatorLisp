//
// Created by hasni on 04.12.2024.
//

#ifndef INTERPRETER_LISP_ATOM_H
#define INTERPRETER_LISP_ATOM_H
#include <iostream>
#include "const.h"
#include <memory>
namespace interpretator {
    enum valuetype {
        INT, DOUBLE, STRING, NIL
    };
    class Atom {
    private:
        valuetype type;
        union {
            long long int intvalue;
            double doublevalue;
            std::string stringvalue;
            Nil *nilvalue;
//            Pair *pairvalue;
        };
    public:
        Atom(long long int val);

        Atom(double val);

        Atom(std::string val);

        Atom(Nil *val);

        Atom(valuetype val);

//        Atom(Pair *val);

        ~Atom();

        void clear();

        void init();

        valuetype get_type();

        Atom &operator=(const long long int a);

        Atom &operator=(const double a);

        Atom &operator=(const std::string a);

        Atom &operator+=(const char a);

        Atom &operator+(Atom a);

        Atom &operator+=(Atom a);

        Atom(const Atom& other);

        Atom& operator=(const Atom& other);

        void define();

        int isnumber(long long int &num, double &dnum);

        std::string get_stringvalue();
    };

};
#endif //INTERPRETER_LISP_ATOM_H
