add_executable(kernel
    src/main.cpp
)

target_link_libraries(kernel INTERFACE
    freestnd-c-hdrs
    freestnd-cxx-hdrs
)

target_link_libraries(kernel PRIVATE
    cc-runtime
    limine-protocol
)
