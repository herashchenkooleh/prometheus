#pragma once

#include "Prometheus.Core.CriticalSection.hpp"

namespace prometheus::core
{
    class scoped_lock
    {
    public:
        inline scoped_lock(critical_section& section) noexcept
            : m_section(section)
        {
            m_section.lock();
        }
        
        inline scoped_lock(scoped_lock&&) noexcept = delete;
        
        inline scoped_lock(const scoped_lock&) noexcept = delete;
        
        inline scoped_lock& operator=(scoped_lock&&) noexcept = delete;
        
        inline scoped_lock& operator=(const scoped_lock&) noexcept = delete;
        
        inline ~scoped_lock() noexcept
        {
            m_section.unlock();
        }

    private:
        critical_section& m_section;
    };
}