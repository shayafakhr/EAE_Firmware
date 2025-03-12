#include <gtest/gtest.h>
#include "pid_control.h"

TEST(PIDTest, ComputeTest) {
    PID pid(1.0, 0.1, 0.05);
    EXPECT_NEAR(pid.compute(100, 90), 10, 1.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
