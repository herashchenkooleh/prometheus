#pragma once

namespace prometheus::math
{
    class vector4f
    {
    public:
        inline vector4f() noexcept
        {
        }
    private:
        float m_components;
    };
}