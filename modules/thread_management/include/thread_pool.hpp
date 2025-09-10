// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <functional>
#include <cstddef>
#include "lock-free_queue.hpp"

using JobFn = std::function<void()>;

struct Job {
    JobFn fn;
    size_t id;
};

class ThreadPool {
public:
    ThreadPool();
    ThreadPool(size_t threads_amount);
    ~ThreadPool();
    size_t enqueue(const JobFn &req_fn);
    void await(size_t fn_id);
    void awaitAll(void);
private:
    LockFreeQueue<Job, 1024> queue;
};
