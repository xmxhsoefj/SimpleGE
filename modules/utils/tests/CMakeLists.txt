add_executable(SGE_Utils_Tests
  tests.cpp
)

target_link_libraries(SGE_Utils_Tests
  PRIVATE
    GTest::gtest_main
    SimpleGE::Utils
)

include(GoogleTest)
gtest_discover_tests(SGE_Utils_Tests)
