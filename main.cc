#include <iostream>
#include "vector3d.h"
#include "matrix3d.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Vector3D v(3, 3, 3);
    for (int i = 0; i < 3; i++)
        cout << v[i] << endl;
    cout <<"Normalizado"<< endl;
    Vector3D r = v.Normalize(v);
    for (int i = 0; i < 3; i++)
        cout << r[i] << endl;

    return 0;
}