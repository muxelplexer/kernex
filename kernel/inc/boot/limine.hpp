#pragma once
#include "limine.h"

namespace boot::limine
{
    bool base_revision_supported();
    limine_framebuffer* get_framebuffer();
}
