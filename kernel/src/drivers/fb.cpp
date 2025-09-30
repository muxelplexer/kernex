#include "drivers/fb.hpp"
#include "libk.hpp"
#include "limine.h"
#include <cstddef>

namespace drivers::fb
{
    namespace
    {
        limine_framebuffer* the_fb{nullptr};
    }
    void init_framebuffer(limine_framebuffer* fb)
    {
        the_fb = fb;
    }

    bool clear(uint32_t colour)
    {
        if (the_fb == nullptr)
            return true;

        if (colour > 0xFFFFFF)
        {
            libk::hcf();
        }
        const auto fb_width{the_fb->width};
        const auto fb_height{the_fb->height};

        for (std::size_t i = 0; i < fb_height; i++) {
            for (std::size_t j = 0; j < fb_width; j++)
            {
                pixel_put(j, i, colour);
            }
        }
        return false;
    }

    void pixel_put(const uint32_t xpos, const uint32_t ypos, const uint32_t colour)
    {
        if (the_fb == nullptr)
            return;

        const auto fb_height{the_fb->height};
        const auto fb_width{the_fb->width};
        const auto fb_pitch{the_fb->pitch};

        if (colour > 0xFFFFFF)
        {
            libk::hcf();
        }

        if (xpos >= fb_width)
            return;

        auto* fb_ptr{static_cast<volatile uint32_t *>(the_fb->address)};
        fb_ptr[ypos * (fb_pitch / 4) + xpos] = colour;
    }

    void bsod()
    {
        constexpr auto f_col(0xFFFFFF);
        constexpr auto offset{100};
        if (clear(0x0827f5))
            return;

        const auto fb_width{the_fb->width};
        const auto fb_height{the_fb->height};

        for (std::size_t i = offset; i < fb_height - offset; i++) {
            pixel_put(offset + 0, i, f_col);
            pixel_put(offset + 1, i, f_col);
            pixel_put(offset + 2, i, f_col);
        }
        for (std::size_t j = offset; j < (fb_width / 2); j++) {
            pixel_put(j, offset + 0, f_col);
            pixel_put(j, offset + 1, f_col);
            pixel_put(j, offset + 2, f_col);
        }
        for (std::size_t j = offset; j < (fb_width / 2) - offset; j++) {
            pixel_put(j, (fb_height / 2) - 1, f_col);
            pixel_put(j, (fb_height / 2) + 0, f_col);
            pixel_put(j, (fb_height / 2) + 1, f_col);
        }
    }
}
