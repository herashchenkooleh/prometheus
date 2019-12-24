#pragma once

namespace prometheus::editor
{
    class application
    {
        struct impl;
        using impl_ptr = impl*;

    public:
        application() noexcept;

        application(application&&) noexcept = delete;

        application(const application&) noexcept = delete;

		application& operator=(application&&) noexcept = delete;

        application& operator=(const application&) noexcept = delete;

        ~application() noexcept;

        bool init() noexcept;
        bool deinit() noexcept;
        bool run() noexcept;

    private:
        impl_ptr m_impl;
    };
}