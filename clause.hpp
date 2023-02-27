#include <vector>
#include <algorithm>
#include "literal.hpp"

// Clauses are a collection of ordered Literals
// representing a given interpretation

class Clause
{
    private:
        std::vector<Literal> mLiterals;
    public:
        Clause(std::vector<Literal> &literals);
        void Insert(const Literal &it);
        int Find (const Literal &it) const;
        int FindNegated(const Literal &it) const;
        Clause ResolveClause(const Clause &second);
        friend bool operator==(const Clause &first, const Clause &second);
};

Clause::Clause(std::vector<Literal> &literals)
{
    sort(literals.begin(), literals.end());
    this->mLiterals = std::move(literals);
}

void Clause::Insert(const Literal &it)
{
    int iterator_offset = -1;
    for(int i = 0 ; i < mLiterals.size(); i++)
    {
        if(it < mLiterals[i])
            iterator_offset = i;
        else
            break;
    }
    mLiterals.insert(mLiterals.begin() + iterator_offset, it);
}

// Find method returns a positive int
// representing the index position
// or -1 in case no match is found

int Clause::Find(const Literal &it) const
{
    int index = 0;
    for(auto &current : mLiterals)
    {
        if(current == it)
        {
            return index;
        }
        index++;
    }
    return -1;
}

int Clause::FindNegated(const Literal &it) const
{
    Literal mirror = Literal(!it.getNegated(), it.getName());
    return this->Find(mirror);
}

bool operator==(const Clause &first, const Clause &second)
{
    if(first.mLiterals.size() != second.mLiterals.size())
        return false;
    for(int i = 0 ; i < first.mLiterals.size(); i++)
    {
        if(first.mLiterals[i] == second.mLiterals[i])
            continue;
        else
            return false;       
    }
    return true;
}

Clause Clause::ResolveClause(const Clause &second)
{
    
}