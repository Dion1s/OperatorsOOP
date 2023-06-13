#include "CPooint3D.h"

// Конструктор за замовчуванням
CPooint3D::CPooint3D() {
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

// Конструктор з параметрами
CPooint3D::CPooint3D(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

// Методи-члени для задавання та отримання значень полів
void CPooint3D::setX(double x) {
    this->x = x;
}

void CPooint3D::setY(double y) {
    this->y = y;
}

void CPooint3D::setZ(double z) {
    this->z = z;
}

double CPooint3D::getX() const {
    return x;
}

double CPooint3D::getY() const {
    return y;
}

double CPooint3D::getZ() const {
    return z;
}

bool CPooint3D::operator==(const CPooint3D& other) {
    return (x == other.x) && (y == other.y) && (z == other.z);
}