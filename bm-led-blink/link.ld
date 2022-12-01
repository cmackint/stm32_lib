ENTRY(Reset_handle)

_endStack = 0x20050000;
_minHeapSize = 0x200;
_minStackSize = 0x400;

MEMORY {
  FLASH ( rx )      : ORIGIN = 0x08000000, LENGTH = 1536K
  RAM ( rxw )       : ORIGIN = 0x20000000, LENGTH = 320K
}

SECTIONS {
  .vectorTable : {
    . = ALIGN(4);
    KEEP (*(.vectorTable))
    . = ALIGN(4);
  } >FLASH
 
  .text : {
    . = ALIGN(4);
    *(.text)
    *(.text*)
    . = ALIGN(4);
  } >FLASH

  .rodata : {
    . = ALIGN(4);
    *(.rodata)
    *(.rodata*)
    . = ALIGN(4);
  } >FLASH

  _startInitData = .;
  .data : AT(_startInitData) {
    . = ALIGN(4);
    _startData = .;
    *(.data)
    *(.data*)
    _endData = .;
    . = ALIGN(4); 
  } >RAM
  
  .bss : {
    . = ALIGN(4);
    _startBss = .;
    *(.bss)
    *(.bss*)
    *(COMMON)
    . = ALIGN(4);
    _endBss = .;
  } >RAM
  
  .userHeap : {
    . = ALIGN(4);
    _startRam = .;
    . = . + _minHeapSize;
    . = . + _minStackSize;
    . = ALIGN(4);
    _endRam = .;
  } >RAM
}
