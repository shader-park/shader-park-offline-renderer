#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

std::string pad_number(int n)
{
    std::ostringstream ss;
    ss << std::setw( 7 ) << std::setfill( '0' ) << n;
    return ss.str();
}

void save_image(uint8_t *pixels, int x, int y, std::string name, int count) {
    std::ofstream file(name+pad_number(count+1)+".ppm", std::ofstream::binary);
    if (file.is_open()) {
        file << "P6\n" << x << " " << y << "\n" << "255\n";
        file.write((char *)pixels, x*y*3);
        file.close();
    } else {
        std::cout << "Could not open file :(\n";
    }
}