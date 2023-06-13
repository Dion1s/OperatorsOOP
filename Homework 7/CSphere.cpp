#include "CSphere.h"

// Конструктор за замовчуванням
CSphere::CSphere() {
    radius = 0.0;
}

// Конструктор з параметрами
CSphere::CSphere(const CPooint3D& center, double radius) {
    this->center = center;
    this->radius = radius;
}

// Методи-члени для задавання та отримання значень полів
void CSphere::setCenter(const CPooint3D& center) {
    this->center = center;
}

void CSphere::setRadius(double radius) {
    this->radius = radius;
}

CPooint3D CSphere::getCenter() const {
    return center;
}

double CSphere::getRadius() const {
    return radius;
}

// Знаходження площі поверхні кулі
double CSphere::calculateSurfaceArea() const {
    return 4.0 * 3.14 * radius * radius;
}

// Знаходження об'єму кулі
double CSphere::calculateVolume() const {
    return (4.0 / 3.0) * 3.14 * radius * radius * radius;
}

// Перенесення кулі в просторі на задані значення координат
void CSphere::translate(double dx, double dy, double dz) {
    double x = center.getX() + dx;
    double y = center.getY() + dy;
    double z = center.getZ() + dz;
    center.setX(x);
    center.setY(y);
    center.setZ(z);
}

// Збільшення радіусу кулі у задану кількість разів
void CSphere::increaseRadius(double factor) {
    radius *= factor;
}

void CSphere::consoleInput() {
    double x, y, z;
    std::cout << "Enter the center coordinates of the sphere (x, y, z): ";
    std::cin >> x >> y >> z;
    center.setX(x);
    center.setY(y);
    center.setZ(z);

    bool validInput = false;
    do {
        try {
            std::cout << "Enter the radius of the sphere: ";
            std::cin >> radius;

            if (radius <= 0.0) {
                throw std::runtime_error("Radius must be greater than 0.");
            }

            validInput = true;
        }
        catch (const std::exception& e) {
            std::cout << "Invalid input: " << e.what() << std::endl;
            std::cin.clear();
            //виконує очищення буфера вводу.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (!validInput);
}

 //Вивід даних в консоль
void CSphere::consoleOutput() const {
    std::cout << "Center coordinates: (" << center.getX() << "; " << center.getY() << "; " << center.getZ() << ")" << std::endl;
    std::cout << "Radius: " << radius << std::endl;
    std::cout << "Surface Area: " << calculateSurfaceArea() << std::endl;
    std::cout << "Volume: " << calculateVolume() << std::endl;
}

// Перенесення центру кулі в просторі на задані значення координат (+)
CSphere CSphere::operator+(const CPooint3D& other) const {
    CSphere sphere = *this;
    sphere.center.setX(center.getX() + other.getX());
    sphere.center.setY(center.getY() + other.getY());
    sphere.center.setZ(center.getZ() + other.getZ());
    return sphere;
}

CSphere CSphere::operator+() const{
    return *this;
}

// Збільшення радіусу кулі у задану кількість разів (*)
CSphere CSphere::operator*(double other) const {
    CSphere sphere = *this;
    sphere.radius *= other;
    return sphere;
}

// Введення кулі з потоку вводу (>>)
std::istream& operator>>(std::istream& is, CSphere& sphere) {
    double x, y, z;
    std::cout << "Enter the center coordinates of the sphere (x, y, z): \n";
    is >> x >> y >> z;
    sphere.setCenter(CPooint3D(x, y, z));

    bool validInput = false;
    do {
        try {
            std::cout << "Enter radius: \n";
            is >> sphere.radius;

            if (sphere.radius <= 0.0) {
                throw std::runtime_error("Radius must be greater than 0.");
            }

            validInput = true;
        }
        catch (const std::exception& e) {
            std::cout << "Invalid input: " << e.what() << std::endl;
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (!validInput);

    return is;
}

// Виведення кулі в потік виводу (<<)
std::ostream& operator<<(std::ostream& os, const CSphere& sphere) {
    os << "Center coordinates: (" << sphere.getCenter().getX() << "; " << sphere.getCenter().getY() << "; " << sphere.getCenter().getZ() << ")" << std::endl;
    os << "Radius: " << sphere.getRadius() << std::endl;
    os << "Surface Area: " << sphere.calculateSurfaceArea() << std::endl;
    os << "Volume: " << sphere.calculateVolume() << std::endl;
    return os;
}

// Рівне (==)
bool CSphere::operator==(const CSphere& other) {
    return (center == other.center) && (radius == other.radius);
}

// Нерівне (!=)
bool CSphere::operator!=(const CSphere& other) {
    return !(*this == other);
}

