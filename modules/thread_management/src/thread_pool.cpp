// SPDX-License-Identifier: MPL-2.0

#include "thread_pool.hpp"
#include <thread>

ThreadPool::ThreadPool(size_t threads_amount = std::thread::hardware_concurrency()) {}
ThreadPool::~ThreadPool() {}
size_t ThreadPool::enqueue(const JobFn &req_fn) { return 0; }
void ThreadPool::await(size_t fn_id) {}
void ThreadPool::awaitAll(void) {}
