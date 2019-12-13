#pragma once

#include "Prometheus.Core.Reference.hpp"

namespace prometheus::core
{
    template<typename type_t>
    class pointer
    {
        using type_ptr_t = type_t*;
        using const_type_ptr_t = type_t const*;
        using reference_ptr_t = reference*;
        
    public:
        inline pointer() noexcept
            : m_reference(new reference{})
            , m_object(nullptr)
        {
        }
        
        inline pointer(pointer&& obj) noexcept
            : m_reference(std::exchange(obj.m_reference, nullptr))
            , m_object(std::exchange(obj.m_object, nullptr))
        {
        }
        
        inline pointer(const pointer& obj) noexcept
            : m_reference(obj.m_reference)
            , m_object(obj.m_object)
        {
            m_reference->increment();
        }
        
        inline pointer& operator=(pointer&& obj) noexcept
        {
            if(this != &obj)
            {
                m_reference = obj.m_reference.exchange(0);
                m_object = std::exchange(obj.m_object, nullptr);
            }
            return *this;
        }
        
        inline pointer& operator=(const pointer& obj) noexcept
        {
            if(this != &obj)
            {
                destruct();

                m_reference = obj.m_reference;
                m_object = obj.m_object;

                initialize();
            }
            return *this;
        }
        
        inline ~pointer() noexcept
        {
            destruct();
        }
        
        inline type_t& operator*() noexcept
        {
            return *m_object;
        }
        
        inline const type_t& operator() const noexcept
        {
            return *m_object;
        }
        
        inline type_ptr_t operator->() noexcept
        {
            return m_object;
        }
        
        inline const_type_ptr_t operator->() const noexcept
        {
            return m_object;
        }

        inline operator std::nullptr_t() noexcept
        {
            return m_object;
        }
        
        inline operator bool() noexcept
        {
            return m_object != nullptr;
        }
        
    private:
        inline void initialize() noexcept
        {
            if(m_object)
            {
                m_reference->increment();
            }
        }

        inline void destruct() noexcept
        {
            m_reference->decrement();
            if(!m_reference->valid())
            {
                delete m_object;
                delete m_reference;
            }
        }
        
    private:
        reference_ptr_t m_reference;
        type_ptr_t m_object;
    };
}