#include "clause.hpp";

class ClauseSet
{
    private:
        std::vector<Clause> clauses;
    public:
        ClauseSet() = default;
        bool IsSatisfiable();
};