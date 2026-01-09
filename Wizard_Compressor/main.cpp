#include <iostream>
#include <string>
#include <fstream>


int main()
{


    std::ifstream file("./input.txt");
    std::string line;

    while(std::getline(file, line)){
        std::cout << line << '\n';
    }

    return 0;
}
