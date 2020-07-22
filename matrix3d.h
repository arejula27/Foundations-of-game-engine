#pragma once
#include "vector3d.h"
struct Matrix3D 
{
    private:
        float n[3][3];
    public:
        Matrix3D()= default;
        Matrix3D(float n00, float n01, float n02,
                 float n10, float n11, float n12,
                 float n20, float n21, float n22 ){
                     n[0][0] = n00;
                     n[0][1] = n01;
                     n[0][2] = n02;
                     n[1][0] = n10;
                     n[1][1] = n11;
                     n[1][2] = n12;
                     n[2][0] = n20;
                     n[2][1] = n21;
                     n[2][2] = n22;         
                 }
        Matrix3D (const Vector3D& a,const Vector3D& b, const Vector3D& c){
            n[0][0] = a.x ;n[0][1] = a.y; n[0][2] = a.z;
            n[0][0] = b.x ;n[0][1] = b.y; n[0][2] = b.z;
            n[0][0] = c.x ;n[0][1] = c.y; n[0][2] = c.z;
        }
        
        //devuelve un numero de la matriz
        float& operator() (int i,int j){
            return (n[i][j]);
        }

        //devuelve un numero de la matriz 
        const float &operator()(int i, int j) const 
        {
            return (n[i][j]);
        }

        //devuelve una fila de la matriz como vector3D
        Vector3D& operator[](int j){
            return (*reinterpret_cast<Vector3D *> (n[j]));
        }

        //devuelve una fila de la matriz como vector3D
        const Vector3D &operator[](int j) const
        {
            return (*reinterpret_cast<const Vector3D *>(n[j]));
        }

        friend Matrix3D operator *(const Matrix3D& A, const Matrix3D& B){
            return (Matrix3D(A(0, 0) * B(0, 0) + A(0, 1) * B(1, 0) + A(0, 2) * B(2, 0),
                             A(0, 0) * B(0, 1) + A(0, 1) * B(1, 1) + A(0, 2) * B(2, 1),
                             A(0, 0) * B(0, 2) + A(0, 1) * B(1, 2) + A(0, 2) * B(2, 2),
                             A(1, 0) * B(0, 0) + A(1, 1) * B(1, 0) + A(1, 2) * B(2, 0),
                             A(1, 0) * B(0, 1) + A(1, 1) * B(1, 1) + A(1, 2) * B(2, 1),
                             A(1, 0) * B(0, 2) + A(1, 1) * B(1, 2) + A(1, 2) * B(2, 2), 
                             A(2, 0) * B(0, 1) + A(2, 1) * B(1, 1) + A(2, 2) * B(2, 1),
                             A(2, 0) * B(0, 2) + A(2, 1) * B(1, 2) + A(2, 2) * B(2, 2),
                             A(2, 0) * B(0, 2) + A(2, 1) * B(1, 2) + A(2, 2) * B(2, 2)
             ));
        }
        friend Vector3D operator*(const Matrix3D &M, const Vector3D &v)
        {
            return (Vector3D(M(0, 0) * v.x + M(0, 1) * v.y + M(0, 2) *
                    v.z, M(1, 0) * v.x + M(1, 1) * v.y + M(1, 2) * v.z,
                    M(2, 0) * v.x + M(2, 1) * v.y + M(2, 2) * v.z));
        }

       
};

    float Determinante(const Matrix3D& M){
            return (M(0,0) * (M(1,1) * M(2,2) - M(1,2) * M(2,1))+
                    M(0,1) * (M(1,2) * M(2,0) - M(1,0) * M(2,2))+
                    M(0,2) * (M(2,1) * M(2,1) - M(1,1) *M(2,0)));
        }


    Matrix3D Inverse(const Matrix3D& M){
        const Vector3D& a = M[0];
        const Vector3D& b = M[1];
         const Vector3D& c = M[2];

        Vector3D r0 = Cross(b,c);
        Vector3D r1 = Cross(c,a);
        Vector3D r2 = Cross(a,b);

        float invDet = 1.0f/Dot(r2,c);

        return Matrix3D (r0.x * invDet,r0.y * invDet, r0.z * invDet,
                                r1.x * invDet, r1.y * invDet, r1.z * invDet,
                                r2.x * invDet, r2.y * invDet, r2.z * invDet);


    }