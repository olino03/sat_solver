#include <vector>
#include <iostream>

// A literal is the smallest piece of information
// representing if a given is statement is either
// false or true under a given interpretation.

class Literal
{
    private:
        bool mNegated = false;
        char mName = ' ';
    public:
        bool getNegated() const;
        char getName() const;
        void setNegated(const bool negated);
        void setName(const char name);
        bool IsComplementary(const Literal *other) const;
        bool ValidName(const char name);
        Literal(const bool negated, const char name);
        Literal Negate();
        friend bool operator==(const Literal &first, const Literal &second);
        friend bool operator<(const Literal &first, const Literal &second);
};

bool Literal::IsComplementary(const Literal *other) const
{
    if(this->mName != other->mName)
        return false;
    if(this->mNegated != other->mNegated)
        return false;
    return true;
}

Literal Literal::Negate()
{
    return Literal(!this->mNegated, this->mName);
}

bool operator==(const Literal &first, const Literal &second)
{
    return first.mName == second.mName && first.mNegated == second.mNegated;
}

bool operator<(const Literal &first, const Literal &second)
{
    if(first.mName < second.mName)
        return false;
    if(first.mName == second.mName)
        return first.mNegated < second.mNegated;
    return true;
}

bool Literal::getNegated() const
{
    return mNegated;
}

char Literal::getName() const
{
    return mName;
}

void Literal::setNegated(const bool negated)
{
    mNegated = negated;
}

void Literal::setName(const char name)
{
    mName = name;
}

bool Literal::ValidName(const char name)
{
    if(name > 'A' && name < 'Z')
        return true;
    return false;
}