#pragma once

#include <atomic>

namespace prometheus::core
{
    class reference
    {
    public:
        inline reference() noexcept
            : m_counter({})
        {
        }
        
        
    private:
        std::atomic_size_t m_counter;
    };
}