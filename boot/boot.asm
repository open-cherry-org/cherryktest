[org 0x7C00]
    mov ah, 0x0E
    mov si, msg
.print:
    lodsb
    or al, al
    jz .done
    int 0x10
    jmp .print
.done:
    cli
    jmp 0x0000:0x7E00  ; jump to kernel
msg db "Cherry KTest booting...", 0
times 510-($-$$) db 0
dw 0xAA55
