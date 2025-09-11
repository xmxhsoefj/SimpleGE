// SPDX-License-Identifier: MPL-2.0

#include <cstddef>
#include <gtest/gtest.h>
#include <lock-free_queue.hpp>

TEST(LockFreeQueue, IdsTest) {
    LockFreeQueue<uint8_t, 100> q;
    for (size_t i = 0; i < 100; i++) {
        EXPECT_EQ(i, q.push(i));
    }
}
