add_executable(kernel
    src/libk.cpp
    src/main.cpp
    src/boot/limine.cpp
    src/drivers/fb.cpp
)
target_include_directories(kernel PUBLIC
    inc/
)

target_link_libraries(kernel INTERFACE
)

target_link_libraries(kernel PRIVATE
    freestanding-std
    cc-runtime
    limine-protocol
)

set(KERNEL_C_FLAGS
    -Os
    -g
    -nostdlib
    -ffreestanding
    -std=c11
)

set(KERNEL_CXX_FLAGS
    -std=c++20
    -fno-rtti
    -fno-exceptions
)

target_compile_options(kernel PRIVATE
    $<$<COMPILE_LANGUAGE:C>:${KERNEL_C_FLAGS}>
    $<$<COMPILE_LANGUAGE:CXX>:${KERNEL_C_FLAGS} ${KERNEL_CXX_FLAGS}>
)


target_link_options(kernel PRIVATE
    -nostdlib
    -static
    -z max-page-size=0x1000
    --gc-sections
    -T ${CMAKE_CURRENT_SOURCE_DIR}/linker.ld
)
