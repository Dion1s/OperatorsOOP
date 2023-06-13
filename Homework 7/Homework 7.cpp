#include "CSphere.h"
#include <iostream>

int main() {
    int choice;
    bool exit = false;
    CSphere sphere;
    CSphere s1;
    CSphere s2;

    double surfaceArea;
    double volume;
    double x, y, z;
    double factor;
    
    while (!exit) {
        std::cout << "| -------------------------" << std::endl;
        std::cout << "| Menu:" << std::endl;
        std::cout << "| 1. Create a new sphere" << std::endl;
        std::cout << "| 2. Calculate surface area" << std::endl;
        std::cout << "| 3. Calculate volume" << std::endl;
        std::cout << "| 4. Move sphere" << std::endl;
        std::cout << "| 5. Increase radius" << std::endl;
        std::cout << "| 6. All informations" << std::endl;
        std::cout << "| 7. Operator = " << std::endl;
        std::cout << "| 0. Exit" << std::endl;
        std::cout << "| -------------------------" << std::endl;
        std::cout << "  Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            //sphere.consoleInput();
            std::cin >> sphere;

            break;
        }
        case 2: {
            surfaceArea = sphere.calculateSurfaceArea();
            std::cout << "Surface Area: " << surfaceArea << std::endl;
            break;
        }
        case 3: {
            volume = sphere.calculateVolume();
            std::cout << "Volume: " << volume << std::endl;
            break;
        }
        case 4: {
            std::cout << "Enter the coordinates to move the sphere (x, y, z): ";
            std::cin >> x >> y >> z;
            CPooint3D point(x, y, z);
            //sphere.translate(x, y, z);
            sphere = sphere + point;
            break;
        }
        case 5: {
           std::cout << "Enter the factor to increase the radius: ";
            std::cin >> factor;
            //sphere.increaseRadius(factor);
            sphere = sphere * factor;;

            break;
        }
        case 6: {
            //sphere.consoleOutput();
            std::cout << sphere << std::endl;;
            break;
        }
        case 7: {
            std::cout << "Enter two sphere: \n";
            std::cin >> s1 >> s2;
            if (s1 == s2) {
                std::cout << "Sphere 1 and Sphere 2 are equal." << std::endl;
            }
            else {
                std::cout << "Sphere 1 and Sphere 2 are not equal." << std::endl;
            }

            if (s1 != s2) {
                std::cout << "Sphere 1 and Sphere 2 are not equal." << std::endl;
            }
            else {
                std::cout << "Sphere 1 and Sphere 2 are equal." << std::endl;
            }
            break;
        }
        case 0: {
            exit = true;
            break;
        }
        default: {
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
        }
    }

    return 0;
}

