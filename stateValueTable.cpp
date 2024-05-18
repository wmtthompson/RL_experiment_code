
#include "stateValueTable.hpp"

StateValueTable::StateValueTable(int num_states):m_num_states(num_states)
{
    for( int i = 0; i < m_num_states; ++i)
    {
        m_state_to_value[i] = 1.0;
        m_state_to_vectors[i] = std::vector<double>();
    }
}

double StateValueTable::get_value(int state)
{
    m_state_to_value[state];
}

void StateValueTable::update_return(int state, double value)
{
    m_state_to_vectors[state].push_back(value);
}

void StateValueTable::clear_return(int state)
{
    m_state_to_vectors[state].clear();
}

double StateValueTable::get_average(int state)
{
    double total = 0;
    auto vec = m_state_to_vectors[state];
    for( double d: vec)
    {
        total += d;
    }
    return total/ vec.size();
}