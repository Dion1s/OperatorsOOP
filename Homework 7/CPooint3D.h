#ifndef CPOINT3D_H
#define CPOINT3D_H

#include <cmath>
#include <iostream>
#include <limits>

class CPooint3D {
private:
    double x;
    double y;
    double z;

public:
    // ������������
    CPooint3D();
    CPooint3D(double x, double y, double z);

    // ������-�����
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    double getX() const;
    double getY() const;
    double getZ() const;

     bool operator==(const CPooint3D& other);
};

#endif  
