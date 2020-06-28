#include <math.h>

//declaración el tipo de dato vector3D y sus metodos
struct Vector3D
{
    float x,y,z;
    Vector3D()=default;
    Vector3D(float a, float b, float e):x(a),y(b),z(e){}
    float& operator [] (int i)
    {
        return ((&x)[i]);
    }
    const float &operator[](int i) const 
    {
        return ((&x)[i]);
    }

    Vector3D& operator *=(float s){
        x*=s;
        y*=s;
        z*=s;
        return (*this);
    }
    Vector3D &operator/=(float s)
    {
        s = 1/s;
        x *= s;
        y *= s;
        z *= s;
        return (*this);
    }
    //inline permite optimizar funciones pequeñas en tiempo de compilación
    //no se crea una stack en memoria
    friend Vector3D operator *(const Vector3D& v, float s){
        return (Vector3D(v.x*s,v.y*s,v.z*s));
    }

    friend Vector3D operator /(const Vector3D &v, float s)
    {
        s=1/s;
        return (Vector3D(v.x * s, v.y * s, v.z * s));
    }

    friend Vector3D operator-(const Vector3D &v){
        return(Vector3D(-v.x,-v.y,-v.z));
    }
    inline float Magnitude (const Vector3D& v){
        return sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
    }
    inline Vector3D Normalize(const Vector3D &v){
        return (v/Magnitude(v));
    }

    Vector3D operator +=(const Vector3D& v){
        x += v.x;
        y += v.y;
        z += v.z;
        return (*this);
    }

    Vector3D operator-=(const Vector3D &v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return (*this);
    }
    friend Vector3D operator+(const Vector3D &v, const Vector3D &r)
    {
        return (Vector3D(v.x+r.x,v.y+r.y,v.z+r.z));
    }

    friend Vector3D operator-(const Vector3D &v, const Vector3D &r)
    {
        return (Vector3D(v.x - r.x, v.y - r.y, v.z - r.z));
    }
};

   




