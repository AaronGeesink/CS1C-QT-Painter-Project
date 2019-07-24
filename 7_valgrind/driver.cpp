#include <iostream>
#include "vector.h"
using namespace project;
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(4);
    v.push_back(1);
    cout << "Size:" << v.size() << endl;
    v.resize(10);
    v.push_back(41);
    v.reserve(60);
    cout << "Capacity: " << v.capacity() << endl;

    vector<double> dv(10);
    dv.push_back(31.1);

    vector<int> v2(v);
    v2 = v;

    int i = v2[1];
    v2[1] = 31;
    i = v2[100];

    return 0;
}