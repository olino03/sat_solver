#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        std::cerr << "Insufficient arguments";
        return -1;
    }
    if(argc > 2)
    {
        std::cerr << "Too many arguments";
        return -1;
    }    
    return 0;
}