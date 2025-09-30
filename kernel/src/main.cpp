#include "boot/limine.hpp"
#include "libk.hpp"
#include "drivers/fb.hpp"

extern "C" void kmain()
{
    libk::construct_globals();
    drivers::fb::init_framebuffer(boot::limine::get_framebuffer());
    auto* framebuffer{boot::limine::get_framebuffer()};

    // Note: we assume the framebuffer model is RGB with 32-bit pixels.
    for (std::size_t i = 0; i < 100; i++) {
        auto* fb_ptr{static_cast<volatile uint32_t *>(framebuffer->address)};
        fb_ptr[i * (framebuffer->pitch / 4) + i] = 0xff0000;
    }


    libk::hcf();
}
