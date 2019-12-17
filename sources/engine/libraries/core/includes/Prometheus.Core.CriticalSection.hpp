#pragma once

namespace prometheus::core
{
    class critical_section
    {
        friend class scoped_lock;

    public:
        inline critical_section() noexcept = default;
        
        inline critical_section(critical_section&&) noexcept = delete;
        
        inline critical_section(const critical_section&) noexcept = delete;
        
        inline critical_section& operator=(critical_section&&) noexcept = delete;
        
        inline critical_section& operator=(const critical_section&) noexcept = delete;
        
        inline ~critical_section() noexcept = default;
        
    private:
        inline void lock() noexcept
        {
            while (std::exchange(m_flag, true, ){ }; //TODO
        }
        
        inline void unlock() noexcept
        {
            std::exchange(); //TODO
        }
        
    private:
        std::atomic_bool m_flag;
    };
}