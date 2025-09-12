// SPDX-License-Identifier: MPL-2.0

#include "lock-free_queue.hpp"

template<typename T, size_t buf_size>
size_t LockFreeQueue<T, buf_size>::push(const T &val) {
    auto head = this->head.load(std::memory_order_relaxed);
    /** buffer is empty */
    if ((this->tail.load(std::memory_order_acquire) - head) == 1) return buf_size;
    /**
     * for now I'll handle buf and head/tail overflows and 'infinite amount'
     * of threads that way
     * I'll have to rethink if completely unique id's will be needed
     */
    auto n_head = (head + 1) % buf_size;
    this->head.store(n_head, std::memory_order_release);
    this->buf[head] = val;
    /**
     * returning id in case I need it, but with current implementation
     * it's not completely unique, might rewrite if uniqueness'll be needed
     */
    return head;
}

template<typename T, size_t buf_size>
size_t LockFreeQueue<T, buf_size>::pop(T &res) {
    auto tail = this->head.load(std::memory_order_relaxed);
    /** buffer is empty */
    if (tail == this->head.load(std::memory_order_acquire)) return buf_size;
    res = this->buf[tail];
    tail = (tail + 1) % buf_size;
    this->tail.store(tail, std::memory_order_release);
    return tail;
}
