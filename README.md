# UEFI-BootLoader
a boot loader for a windows compatible OS

start with a boot loader for pc x86 (32bit) and x64(64bit)

the boot loader create a boot parameter block struct ..initialize with data (boot parameters)
load modules into memory: the kernel, hal, vidmem, boot drivers
jump to kernel entry point.

UEFI will be a 32bit boot environment and maybe  our boit loader will be called directly with saved boot arguments (strings) or
from a boot manager.

our boot loader is module in native PE format. it can be 32bit or 64bit. 

if any error occur while loading the modules or when starting the kernel, we reboot .. warm start.
