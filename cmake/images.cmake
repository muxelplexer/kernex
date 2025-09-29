set(LIMINE_BOOTLOADER_DIR "${CMAKE_SOURCE_DIR}/ext/limine-bootloader")
set(LIMINE_CONFIG "${CMAKE_SOURCE_DIR}/limine.conf")
set(LIMINE_EFI_CD "${LIMINE_BOOTLOADER_DIR}/limine-uefi-cd.bin")
set(LIMINE_EFI "${LIMINE_BOOTLOADER_DIR}/BOOTAA64.EFI")
add_custom_command(
    OUTPUT kernel.iso
    COMMAND rm -rf iso_root/ && mkdir -p iso_root/boot/limine &&
            cp kernel/kernel iso_root/boot/ &&
            cp -v ${LIMINE_EFI_CD} iso_root/boot/limine/ &&
            mkdir -p iso_root/EFI/boot &&
            cp -v ${LIMINE_CONFIG} iso_root/EFI/boot/ &&
            cp -v ${LIMINE_EFI} iso_root/EFI/boot/ &&
            xorriso -as mkisofs -R -r -J
                    --efi-boot boot/limine/limine-uefi-cd.bin
                    -efi-boot-part --efi-boot-image --protective-msdos-label
                    iso_root -o kernel.iso
    DEPENDS ${CMAKE_SOURCE_DIR}/cmake/images.cmake
    DEPENDS kernel
    DEPENDS ${LIMINE_CONFIG}
    DEPENDS ${LIMINE_EFI_CD}
    DEPENDS ${LIMINE_EFI}
)

add_custom_command(
    OUTPUT ovmf/ovmf-code-aarch64.fd
    COMMAND
        curl -Lo ovmf/ovmf-code-aarch64.fd https://github.com/osdev0/edk2-ovmf-nightly/releases/latest/download/ovmf-code-aarch64.fd &&
        dd if=/dev/zero of=ovmf/ovmf-code-aarch64.fd bs=1 count=0 seek=67108864 2>/dev/null
)

add_custom_target(run
    DEPENDS kernel.iso
    DEPENDS ovmf/ovmf-code-aarch64.fd
    COMMAND
        qemu-system-aarch64
            -M virt
            -cpu cortex-a72
            -device ramfb
            -device qemu-xhci
            -device usb-kbd
            -device usb-mouse
            -drive if=pflash,unit=0,format=raw,file=ovmf/ovmf-code-aarch64.fd,readonly=on
            -cdrom kernel.iso
)

add_custom_target(run-dbg
    DEPENDS kernel.iso
    DEPENDS ovmf/ovmf-code-aarch64.fd
    COMMAND
        qemu-system-aarch64
            -s -S
            -M virt
            -cpu cortex-a72
            -device ramfb
            -device qemu-xhci
            -device usb-kbd
            -device usb-mouse
            -drive if=pflash,unit=0,format=raw,file=ovmf/ovmf-code-aarch64.fd,readonly=on
            -cdrom kernel.iso
)
