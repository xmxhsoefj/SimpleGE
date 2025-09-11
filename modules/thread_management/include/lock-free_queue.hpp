// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <array>
#include <atomic>
#include <cstddef>

template<typename T, size_t buf_size>
class LockFreeQueue {
public:
    size_t push(const T &val);
    size_t pop(T &res);
private:
    std::array<T, buf_size> buf;
    std::atomic<size_t> head{0}, tail{0};
};

#include "lock-free_queue_impl.hpp"
