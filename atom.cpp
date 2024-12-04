//
// Created by hasni on 04.12.2024.
//
#include "atom.h"
namespace interpretator {
    void Atom::clear() {
        if (type == STRING) {
            stringvalue.~basic_string(); // Освобождаем память строки
        }
    }

    int Atom::isnumber(long long int &num, double &dnum) {
        bool sign = false;
        unsigned long long int i = 0;
        if (stringvalue[i] == '-') {
            i = 1;
            sign = true;
        }
        bool flag_num = false;
        bool flag_point = true;
        for (; i < stringvalue.size(); ++i) {
            if (stringvalue[i] == '.') {
                if (flag_point) {
                    if (flag_num) {
                        flag_point = false;

                    } else {
                        return 0;
                    }
                } else {
                    return 0;
                }
            } else {
                if (stringvalue[i] >= '0' && stringvalue[i] <= '9') {
                    if (flag_point) {
                        num *= 10;
                        num += stringvalue[i] - '0';
                    } else {
                        dnum /= 10;
                        dnum += stringvalue[i] - '0';
                    }
                    flag_num = true;
                } else {
                    return false;
                }
            }
        }
        if (sign) {
            num *= -1;
            dnum *= -1;
        }
        if (flag_point)
            return 1;
        return 2;
    }

    void Atom::define() {
        if (type == STRING) {
// можно организовать все типы так, чтобы их определяло больше ли мы некторого числа или нет.
// Тогда можно установить тип за один проход цикла небольше n действий.
// пример: если на i этапе у нас S то данный тип может быть только с S, тогда наше число мы увеличиваем настолько,
// чтобы все типы(их поряок в некторой сортироке) которые не подходят были меньше этоо числа.
            if (stringvalue.size() >= 1) {
                long long int num = 0;
                double dnum = 0;
                int isval = isnumber(num, dnum);
                if (isval == 1) {
                    clear();
                    intvalue = num;
                    type = INT;
                    return;
                } else if (isval == 2) {
                    clear();
                    doublevalue = (double) num + dnum / 10;
                    type = DOUBLE;
                    return;
                }

            }
        }
    }

    Atom &Atom::operator+=(const char a) {
        switch (type) {
            case STRING:
                stringvalue += a;
                break;
            case INT:
                intvalue += a;
                break;
            case DOUBLE:
                doublevalue += a;
                break;
            default:
                std::cout << "Error: invalid type for operator+=" << std::endl;
        }
        return *this;
    }

    Atom &Atom::operator=(const std::string a) {
        type = STRING;
        stringvalue = a;
        return *this;
    }

    Atom &Atom::operator=(const double a) {
        type = DOUBLE;
        doublevalue = a;
        return *this;
    }

    Atom &Atom::operator=(const long long int a) {
        type = INT;
        intvalue = a;
        return *this;
    }

    valuetype Atom::get_type() {
        return type;
    }

    void Atom::init() {
        clear();
        new(&stringvalue) std::string();
        type = STRING;
    }

    Atom::~Atom() {
        clear();
    }

//    Atom::Atom(Pair *val) : type(PAIR), pairvalue(val) {}

    Atom::Atom(Nil *val) : type(NIL), nilvalue(val) {}

    Atom::Atom(std::string val) : type(STRING), stringvalue(val) {}

    Atom::Atom(double val) : type(DOUBLE), doublevalue(val) {}

    Atom::Atom(long long int val) : type(INT), intvalue(val) {}

    std::string Atom::get_stringvalue() {
        return stringvalue;
    }

    Atom::Atom(const Atom &other) {
        type = other.type;
        switch (type) {
            case STRING:
                new (&stringvalue) std::string(other.stringvalue);  // Используем placement new для копирования строки
                break;
            case INT:
                intvalue = other.intvalue;
                break;
            case DOUBLE:
                doublevalue = other.doublevalue;
                break;
            default:
                // Для других типов, если они есть
                break;
        }
    }

    Atom &Atom::operator=(const Atom &other) {
        if (this == &other) return *this;  // Защита от самоприсваивания

        // Освобождаем старые данные, если они есть
        if (type == STRING) {
            stringvalue.~basic_string();  // Явный вызов деструктора
        }

        type = other.type;
        switch (type) {
            case STRING:
                new (&stringvalue) std::string(other.stringvalue);  // Копируем строку
                break;
            case INT:
                intvalue = other.intvalue;
                break;
            case DOUBLE:
                doublevalue = other.doublevalue;
                break;
            default:
                // Для других типов
                break;
        }

        return *this;
    }

    Atom &Atom::operator+=(Atom a) {
        if (type !=a.get_type()){
            std::cout<<"error type +="<<std::endl;
        }else {
            switch (type) {
                case STRING:
                    stringvalue+=a.stringvalue;
                    break;
                case INT:
                    intvalue+=a.intvalue;
                    break;
                case DOUBLE:
                    doublevalue +=a.doublevalue;
                    break;
            }
        }
    }

    Atom &Atom::operator+(Atom a) {
        *this+=a;
    }

    Atom::Atom(valuetype val) {
        type=val;
        switch (val) {
            case STRING:
                stringvalue="";
                break;
            case INT:
                intvalue=0;
                break;
            case DOUBLE:
                doublevalue =0.0;
                break;
            case NIL:
                nilvalue=nil;
                break;
        }
    }

//    Atom::Atom(Atom* at) {
//        type=at->type;
//        intvalue=at->intvalue;
//        doublevalue=at->doublevalue;
//        stringvalue=at->stringvalue;
//        nilvalue=at->nilvalue;
//    }
}
