#pragma once
#include "limine.h"

namespace drivers::fb
{
    void init_framebuffer(limine_framebuffer* fb);
    bool clear(uint32_t colour);
    void pixel_put(const uint32_t xpos, const uint32_t ypos, const uint32_t colour);
    void bsod();
}
