#pragma once

namespace prometheus::core
{
    template<typename type_t, size_t size>
    class array
    {
    public:
        inline array() noexcept
        {
        }
        
        inline array(array& obj) noexcept
    private:
        type_t m_data[size];
    };
}