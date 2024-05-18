#include <iostream>
#include <map>
#include <vector>

//might want to make state something abstract later on.

class AbstractStateValueTable{

    virtual double get_value(int state) = 0;
    virtual void update_return(int state, double value) = 0;
    virtual void clear_return(int state) = 0;
};

class StateValueTable:AbstractStateValueTable{

    protected:
    std::map<int, double> m_state_to_value;
    std::map<int, std::vector<double>> m_state_to_vectors;
    int m_num_states;

    public:
    StateValueTable(int num_states);

    double get_value(int state) override;
    void update_return(int state, double value) override;
    void clear_return(int state) override;
    double get_average(int state);
};