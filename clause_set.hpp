#include "clause.hpp";

class ClauseSet
{
    std::vector<Clause> clauses;
    public:
        ClauseSet() = default;
        bool IsSatisfiable();
        void Append(const Clause &to_add);
        
};

bool ClauseSet::IsSatisfiable()
{

}

void ClauseSet::Append(const Clause &to_add)
{
    clauses.push_back(to_add);
}