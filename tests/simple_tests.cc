#include <gtest/gtest.h>
#include <stateValueTable.hpp>

TEST(simle_test, get_value){
    StateValueTable svTable1(2);

    EXPECT_GT(svTable1.get_value(0),0);
}

TEST(simple_test, update_return)
{
    StateValueTable svTable1(2);

    svTable1.update_return(0,1);

    EXPECT_EQ(svTable1.get_average(0),1);
}