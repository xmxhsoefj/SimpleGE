// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <functional>
#include <cstddef>
#include "lock-free_queue.hpp"
#include <thread>

using JobFn = std::function<void()>;

/** for now don't see any need to make it not hardcoded */
constexpr size_t threadPoolQueueSize = 1024;
constexpr size_t threadWorkerQueueSize = 1024;

struct Job {
    JobFn fn;
    size_t id;
};

class ThreadPool {
public:
    ThreadPool();
    ThreadPool(size_t threads_amount);
    ~ThreadPool();
    /** TODO: implement passing and returning values */
    size_t enqueue(const JobFn &req_fn);
    void await(size_t fn_id);
    void awaitAll(void);
private:
    class ThreadWorker {
    public:
        void run(void);
    private:
        std::thread thread;
        LockFreeQueue<Job, threadWorkerQueueSize> queue;
        ThreadPool *pool;
        std::atomic<bool> running{false};

    friend class ThreadPool;
    };

    LockFreeQueue<Job, threadPoolQueueSize> queue;
    std::vector<ThreadWorker> workers;
};
