
#include <iostream>
#include <string>

auto GetStreetAddress()
{
    std::cout << "You will need to input a street address\n";
    std::string line;
    std::getline(std::cin, line);
    std::cout << "You entered: \n\t" << line << "\n";
    return line;
}

int main(int, char**)
{
    std::cout << "Hello, from GetGeoCoords!\n";

    auto streetAddress = GetStreetAddress();
    if (streetAddress.empty())
    {
        std::cout << "No street address to work with. Exiting app\n";
        return 1;
    }

    return 0;
}