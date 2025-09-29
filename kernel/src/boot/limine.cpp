#include "boot/limine.hpp"
#include "libk.hpp"
#include "limine.h"

extern "C"
{
    __attribute__((used, section(".limine_requests")))
    volatile LIMINE_BASE_REVISION(3);

    __attribute__((used, section(".limine_requests")))
    volatile limine_framebuffer_request framebuffer_request = {
        .id = LIMINE_FRAMEBUFFER_REQUEST,
        .revision = 0,
        .response = nullptr
    };

    __attribute__((used, section(".limine_requests_start")))
    volatile LIMINE_REQUESTS_START_MARKER;

    __attribute__((used, section(".limine_requests_end")))
    volatile LIMINE_REQUESTS_END_MARKER;
}

namespace boot::limine
{
    bool base_revision_supported()
    {
        return LIMINE_BASE_REVISION_SUPPORTED;
    }

    limine_framebuffer* get_framebuffer()
    {
        // Ensure we got a framebuffer.
        if (framebuffer_request.response == nullptr
            || framebuffer_request.response->framebuffer_count < 1) {
            libk::hcf();
        }
        return framebuffer_request.response->framebuffers[0];
    }
}
