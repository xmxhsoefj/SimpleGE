// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <array>
#include <atomic>
#include <cstddef>

template<typename T, size_t len> // might need to reuse it - will see
class LockFreeQueue {
public:
    LockFreeQueue();
    bool push(const T &val);
    bool pop(T &res);
private:
    // TODO: check if ill think of a better container
    std::array<T, len> buf;
    std::atomic<size_t> head{0}, tail{0};
};
