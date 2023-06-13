#include "CSphere.h"

// ����������� �� �������������
CSphere::CSphere() {
    radius = 0.0;
}

// ����������� � �����������
CSphere::CSphere(const CPooint3D& center, double radius) {
    this->center = center;
    this->radius = radius;
}

// ������-����� ��� ��������� �� ��������� ������� ����
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

// ����������� ����� ������� ���
double CSphere::calculateSurfaceArea() const {
    return 4.0 * 3.14 * radius * radius;
}

// ����������� ��'��� ���
double CSphere::calculateVolume() const {
    return (4.0 / 3.0) * 3.14 * radius * radius * radius;
}

// ����������� ��� � ������� �� ����� �������� ���������
void CSphere::translate(double dx, double dy, double dz) {
    double x = center.getX() + dx;
    double y = center.getY() + dy;
    double z = center.getZ() + dz;
    center.setX(x);
    center.setY(y);
    center.setZ(z);
}

// ��������� ������ ��� � ������ ������� ����
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
            //������ �������� ������ �����.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (!validInput);
}

 //���� ����� � �������
void CSphere::consoleOutput() const {
    std::cout << "Center coordinates: (" << center.getX() << "; " << center.getY() << "; " << center.getZ() << ")" << std::endl;
    std::cout << "Radius: " << radius << std::endl;
    std::cout << "Surface Area: " << calculateSurfaceArea() << std::endl;
    std::cout << "Volume: " << calculateVolume() << std::endl;
}

// ����������� ������ ��� � ������� �� ����� �������� ��������� (+)
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

// ��������� ������ ��� � ������ ������� ���� (*)
CSphere CSphere::operator*(double other) const {
    CSphere sphere = *this;
    sphere.radius *= other;
    return sphere;
}

// �������� ��� � ������ ����� (>>)
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

// ��������� ��� � ���� ������ (<<)
std::ostream& operator<<(std::ostream& os, const CSphere& sphere) {
    os << "Center coordinates: (" << sphere.getCenter().getX() << "; " << sphere.getCenter().getY() << "; " << sphere.getCenter().getZ() << ")" << std::endl;
    os << "Radius: " << sphere.getRadius() << std::endl;
    os << "Surface Area: " << sphere.calculateSurfaceArea() << std::endl;
    os << "Volume: " << sphere.calculateVolume() << std::endl;
    return os;
}

// г��� (==)
bool CSphere::operator==(const CSphere& other) {
    return (center == other.center) && (radius == other.radius);
}

// ������ (!=)
bool CSphere::operator!=(const CSphere& other) {
    return !(*this == other);
}

