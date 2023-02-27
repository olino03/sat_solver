#include <iostream>
#include <fstream>
#include <string>
#include "clause_set.hpp"

ClauseSet parse_input(std::ifstream &input)
{
    ClauseSet parsed_clause_set;
    std::string unparsed_clause;
    while(std::getline(input, unparsed_clause))
    {
        Clause current_clause;
        for(int i = 0 ; i < unparsed_clause.size(); i++)
        {
            if(unparsed_clause[i] == '!')
            {
                if(Literal::ValidName(unparsed_clause.at(i + 1)))
                {
                    current_clause.Insert(Literal(true, unparsed_clause[i + 1]));
                    i++;
                }
                else
                {
                    throw "Input file containts unspecified characters";
                }
            }
            if(Literal::ValidName(unparsed_clause[i]))
            {
                current_clause.Insert(Literal(false, unparsed_clause[i]));
            }
        }
        parsed_clause_set.Append(current_clause);
    }
    return parsed_clause_set;
}

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
    try
    {
        std::ifstream input(argv[0]);
        std::ofstream output(argv[1]);
        if(input.fail())
            throw "Input file not found";
        if(output.fail())
            throw "Can't create output file";
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}