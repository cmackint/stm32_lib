.syntax unified
.cpu cortex-m4
.fpu softvfp
.thumb

.global Reset_handle

.type Reset_handle, %function
Reset_handle:
    ldr r0, =_endStack
    mov sp, r0
    movs r0, #0 // Why is this not just mov?

    ldr r1, =_startData
    ldr r2, =_endData
    ldr r3, =_startInitData
    b copySidata_loop

copySidata:
    // Copy _startInitData[r0] into _startData[r0]
    ldr r4, [r3, r0]
    str r4, [r1, r0]
    adds r0, r0, #4
copySidata_loop:
    // Copy from _startData to _endData
    adds r4, r0, r1
    cmp r4, r2
    bcc copySidata
    
    movs r0, #0
    ldr r1, =_startBss
    ldr r2, =_endBss
    b zeroBss_loop

zeroBss:
    // Write 0 into _startBss[i]
    str r0, [r1]
    adds r1, r1, #4
zeroBss_loop:
    cmp r1, r2
    bcc zeroBss

    b main
.size Reset_handle, .-Reset_handle
