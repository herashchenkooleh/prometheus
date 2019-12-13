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
        
        inline reference(reference&& obj) noexcept
            : m_counter(obj.m_counter.exchange(0))
        {
        }
        
        inline reference(const reference&) noexcept = delete;
        
        inline reference& operator=(reference&& obj) noexcept
        {
            if(this != &obj)
            {
                m_counter = obj.m_counter.exchange(0);
            }
            return *this;
        }
        
        inline ~reference() noexcept = default;
        
        inline void increment() noexcept
        {
            m_counter++;
        }
        
        inline void decrement() noexcept
        {
            m_counter--;
        }
        
        inline bool valid() const noexcept
        {
            return m_counter > 0;
        }

    private:
        std::atomic_size_t m_counter;
    };
}