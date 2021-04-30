#include<iostream>
#include "Combination_formula.h"
using namespace std;

int Fabricate(int m, int n)
{
    int m_factorials = Multi(m, 1); // m!
    int n_factorials = Multi(n, 1); // n!
    int m_n_factorials = Multi(m-n, 1); // (m-n)!

    return m_factorials / (n_factorials * m_n_factorials);

}