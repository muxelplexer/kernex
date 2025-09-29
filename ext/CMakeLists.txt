# CC-RUNTIME START
add_library(cc-runtime STATIC
    cc-runtime/src/absvdi2.c
    cc-runtime/src/absvsi2.c
    cc-runtime/src/absvti2.c
    cc-runtime/src/addvdi3.c
    cc-runtime/src/addvsi3.c
    cc-runtime/src/addvti3.c
    cc-runtime/src/ashldi3.c
    cc-runtime/src/ashlti3.c
    cc-runtime/src/ashrdi3.c
    cc-runtime/src/ashrti3.c
    cc-runtime/src/bswapdi2.c
    cc-runtime/src/bswapsi2.c
    cc-runtime/src/clzdi2.c
    cc-runtime/src/clzsi2.c
    cc-runtime/src/clzti2.c
    cc-runtime/src/cmpdi2.c
    cc-runtime/src/cmpti2.c
    cc-runtime/src/ctzdi2.c
    cc-runtime/src/ctzsi2.c
    cc-runtime/src/ctzti2.c
    cc-runtime/src/divdi3.c
    cc-runtime/src/divmoddi4.c
    cc-runtime/src/divmodsi4.c
    cc-runtime/src/divmodti4.c
    cc-runtime/src/divsi3.c
    cc-runtime/src/divti3.c
    cc-runtime/src/ffsdi2.c
    cc-runtime/src/ffssi2.c
    cc-runtime/src/ffsti2.c
    cc-runtime/src/int_util.c
    cc-runtime/src/lshrdi3.c
    cc-runtime/src/lshrti3.c
    cc-runtime/src/moddi3.c
    cc-runtime/src/modsi3.c
    cc-runtime/src/modti3.c
    cc-runtime/src/muldi3.c
    cc-runtime/src/mulodi4.c
    cc-runtime/src/mulosi4.c
    cc-runtime/src/muloti4.c
    cc-runtime/src/multi3.c
    cc-runtime/src/mulvdi3.c
    cc-runtime/src/mulvsi3.c
    cc-runtime/src/mulvti3.c
    cc-runtime/src/negdi2.c
    cc-runtime/src/negti2.c
    cc-runtime/src/negvdi2.c
    cc-runtime/src/negvsi2.c
    cc-runtime/src/negvti2.c
    cc-runtime/src/paritydi2.c
    cc-runtime/src/paritysi2.c
    cc-runtime/src/parityti2.c
    cc-runtime/src/popcountdi2.c
    cc-runtime/src/popcountsi2.c
    cc-runtime/src/popcountti2.c
    cc-runtime/src/subvdi3.c
    cc-runtime/src/subvsi3.c
    cc-runtime/src/subvti3.c
    cc-runtime/src/ucmpdi2.c
    cc-runtime/src/ucmpti2.c
    cc-runtime/src/udivdi3.c
    cc-runtime/src/udivmoddi4.c
    cc-runtime/src/udivmodsi4.c
    cc-runtime/src/udivmodti4.c
    cc-runtime/src/udivsi3.c
    cc-runtime/src/udivti3.c
    cc-runtime/src/umoddi3.c
    cc-runtime/src/umodsi3.c
    cc-runtime/src/umodti3.c
)

target_include_directories(cc-runtime PUBLIC
    cc-runtime/src
)
# CC-RUNTIME END

# FREESTND START
add_library(freestanding-std INTERFACE)
target_include_directories(freestanding-std INTERFACE
    freestnd-c-hdrs/aarch64/include/
    freestnd-cxx-hdrs/aarch64/include/
)
# FREESTND END
# LIMINE START
add_library(limine-protocol INTERFACE)
target_include_directories(limine-protocol INTERFACE
    limine-protocol/include/
)
# LIMINE END
