add_executable(SGE_ThreadManagement_Tests
  tests.cpp
)

target_link_libraries(SGE_ThreadManagement_Tests
  PRIVATE
    GTest::gtest_main
    SimpleGE::ThreadManagement
)

include(GoogleTest)
gtest_discover_tests(SGE_ThreadManagement_Tests)
