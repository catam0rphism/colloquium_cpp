
#include <string>
#include <iostream>

#include "../mathoid.h"

natural pow(const natural& a, int n) {
    natural res = 1;
    for (int i = 0; i < n; ++i)
    {
        res = res * a;
    }
    return res;
}

natural fact(int n) {
    natural res = 1;
    for (int i = 2; i <= n; ++i)
    {
        res = res * natural(i);    
    }
    return res;
}

int main(int argc, char const *argv[])
{

    string st_a;
    std::cin >> st_a;

    natural x(st_a);
    
    fractional my_exp;

    const int ACCURACY = 8;
    for (int i = 0; i < ACCURACY; ++i)
    {
        fractional d(pow(x,i), fact(i));
        std::cout << d << std::endl;

        auto tmp_my_exp = ADD_QQ_Q(my_exp, d);
        my_exp = tmp_my_exp;
    }
    
    // auto foo = RED_Q_Q(my_exp);

    std::cout << my_exp << std::endl;
    return 0;
}