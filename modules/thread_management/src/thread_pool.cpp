// SPDX-License-Identifier: MPL-2.0

#include "thread_pool.hpp"
#include <thread>

ThreadPool::ThreadPool(size_t threads_amount = std::thread::hardware_concurrency())
    : workers(threads_amount) {
    for (ThreadWorker &w : this->workers) {
        w.pool = this;
        w.thread = std::thread(&ThreadPool::ThreadWorker::run, &w);
        w.running.store(true, std::memory_order_relaxed);
    }
}
ThreadPool::~ThreadPool() {/**TODO*/}
size_t ThreadPool::enqueue(const JobFn &req_fn) { /**TODO*/return 0; }
void ThreadPool::await(size_t fn_id) {/**TODO*/}
void ThreadPool::awaitAll(void) {/**TODO*/}

void ThreadPool::ThreadWorker::run(void) {

}
