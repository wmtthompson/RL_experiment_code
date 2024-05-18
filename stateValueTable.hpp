#include <iostream>
#include <map>
#include <vector>

//might want to make state something abstract later on.

/**
 * @class AbstractStateValueTable
 * @brief An abstract class for a table that stores values for each state in a system.
 */
class AbstractStateValueTable {
    /**
     * @var virtual double get_value(int)
     * @brief Pure virtual function to retrieve the value associated with a given state.
     * @param int state The state number.
     * @return double The value for the given state.
     */
    virtual double get_value(int state) = 0;

    /**
     * @var virtual void update_return(int, double)
     * @brief Pure virtual function to update the return value associated with a given state.
     * @param int state The state number.
     * @param double value The new return value for the given state.
     */
    virtual void update_return(int state, double value) = 0;

    /**
     * @var virtual void clear_return(int)
     * @brief Pure virtual function to clear the return value associated with a given state.
     * @param int state The state number.
     */
    virtual void clear_return(int state) = 0;
};

/**
 * @class StateValueTable
 * @brief A concrete implementation of AbstractStateValueTable that stores values for each state in a system.
 */
class StateValueTable : AbstractStateValueTable {
private:
    /**
     * @var std::map<int, double> m_state_to_value
     * @brief Map from state number to value associated with that state.
     */
    std::map<int, double> m_state_to_value;

    /**
     * @var std::map<int, std::vector<double>> m_state_to_vectors
     * @brief Map from state number to vector of values associated with that state.
     */
    std::map<int, std::vector<double>> m_state_to_vectors;

    /**
     * @var int m_num_states
     * @brief Number of states in the system.
     */
    int m_num_states;

public:
    /**
     * @brief Constructor for StateValueTable.
     * @param int num_states The number of states in the system.
     */
    StateValueTable(int num_states);

    /**
     * @brief Retrieve the value associated with a given state.
     * @param int state The state number.
     * @return double The value for the given state.
     */
    double get_value(int state) override;

    /**
     * @brief Update the return value associated with a given state.
     * @param int state The state number.
     * @param double value The new return value for the given state.
     */
    void update_return(int state, double value) override;

    /**
     * @brief Clear the return value associated with a given state.
     * @param int state The state number.
     */
    void clear_return(int state) override;

    /**
     * @brief Retrieve the average of all values for a given state.
     * @param int state The state number.
     * @return double The average value for the given state.
     */
    double get_average(int state);
};