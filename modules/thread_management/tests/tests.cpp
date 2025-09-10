// SPDX-License-Identifier: MPL-2.0

#include <gtest/gtest.h>
#include <thread_management.hpp>

TEST(ThreadManagementTest, InitTest) {
  EXPECT_STREQ("Hello world!", get_hello_world_string().c_str());
  EXPECT_STRNE("Bye world!", get_hello_world_string().c_str());
}
