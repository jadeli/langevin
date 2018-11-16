#include <gtest/gtest.h>
#include "../include/random.h"

using namespace langevin;

TEST(Random, init) {
    Random rand(RandomType::RANLXS0);

    EXPECT_GT(1, rand.next());

    rand.destroy();
}