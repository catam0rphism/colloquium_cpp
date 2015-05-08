// Copyright 2015 Bratkovsky Dmitry
#ifndef COM_NN_D_CPP
#define COM_NN_D_CPP

#include "../../structs/struct.h"

#define DEBUG_MODE

ordinal COM_NN_D(const natural& l, const natural& r) {
    // natural a(left);
    // natural b(right);

    #ifdef DEBUG_MODE
    std::cout << "COM_NN_D" << std::endl;
    #endif  // DEBUG_MODE

    natural left = l;
    natural right = r;


    #ifdef DEBUG_MODE
    std::cout << "COPIED" << std::endl;
    #endif  // DEBUG_MODE

    // int r = 0;  // TODO(Belkin Dmitriy): r не нужно

    // if (a.order() == b.order()) {
    //     for (int i = a.order(); (i >= 0) && (r != 1) && (r != 2); --i) {
    //         if (a[i] > b[i]) {
    //             r = 1;
    //             break;
    //         }
    //         if (a[i] < b[i]) {
    //             r = 2;
    //             break;
    //         }
    //     }
    // } else {
    //     if (a.order() > b.order())
    //         r = 1;
    //     else
    //         r = 2;
    // }
    // switch (r) {
    // case 0:
    //     return ordinal::EQ;
    //     break;
    // case 1:
    //     return ordinal::GT;
    //     break;
    // case 2:
    //     return ordinal::LT;
    //     break;
    // default: throw;
    // }
    if (left.order() > right.order()) return ordinal::GT;

    #ifdef DEBUG_MODE
    std::cout << "GT" << std::endl;
    #endif  // DEBUG_MODE
    
    if (left.order() < right.order()) return ordinal::LT;

    #ifdef DEBUG_MODE
    std::cout << "LT" << std::endl;
    #endif  // DEBUG_MODE
    
    if (left.order() == right.order()) {

        #ifdef DEBUG_MODE
        std::cout << "EQ" << std::endl;
        #endif  // DEBUG_MODE
        
        for (int i = left.order(); i >= 0; i--) {

            #ifdef DEBUG_MODE
            std::cout << "COMPARE" << std::endl;
            #endif  // DEBUG_MODE
                        
            if (left[i] != right[i]) {

                #ifdef DEBUG_MODE
                std::cout << "COMPARE END" << std::endl;
                #endif  // DEBUG_MODE
                auto temp = ord(left[i], right[i]);

                #ifdef DEBUG_MODE
                std::cout << "CACHED" << std::endl;
                #endif  // DEBUG_MODE
                
                switch (temp) {
                    case ordinal::EQ: {

                        #ifdef DEBUG_MODE
                        std::cout << "SWITCH EQ" << std::endl;
                        #endif  // DEBUG_MODE
                        
                        return ordinal::EQ;
                    }
                    case ordinal::LT: {

                        #ifdef DEBUG_MODE
                        std::cout << "SWITCH LT" << std::endl;
                        #endif  // DEBUG_MODE
                        
                        return ordinal::LT;
                    }
                    case ordinal::GT: {

                        #ifdef DEBUG_MODE
                        std::cout << "SWITCH GT" << std::endl;
                        #endif  // DEBUG_MODE
                        
                        return ordinal::GT;
                    }
                }
            }
        }
    }

    #ifdef DEBUG_MODE
    std::cout << "FINISH" << std::endl;
    #endif  // DEBUG_MODE

    return ordinal::EQ;
}

bool natural::operator==(const natural &other) {
    return ordinal::EQ == COM_NN_D(*this, other);
}

bool natural::operator<(const natural &other) {
    return ordinal::LT == COM_NN_D(*this, other);
}

bool natural::operator>(const natural &other) {
    return ordinal::GT == COM_NN_D(*this, other);
}

bool natural::operator>=(const natural &other) {
    return !(*this < other);
}

bool natural::operator<=(const natural &other) {
    return !(*this > other);
}

#endif  // COM_NN_D_CPP
