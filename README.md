# UEFI-BootLoader: winload.efi

note: i just started. there is nothing usefull here yet. it is for testing github..


a boot loader for a windows compatible OS

start with a boot loader for pc x86 (32bit) and x64(64bit)

the boot loader create a boot parameter block struct ..initialize with data (boot parameters)
load the system registry file into memory as system-HIVE.
load kernel modules into memory: ntoskrnl.exe hal.dll vidmem.dll kdcom.dll ..
load boot drivers
call kernel entry point.

UEFI will be a 32 or 64 bit boot environment and maybe  our boot loader will be called directly with saved boot arguments (strings) or
from a boot manager.

our boot loader is a module in native PE format. it can be 32bit or 64bit: winload32.efi or winload64.efi

if any error occur while loading the system registry or the modules or when starting the kernel, we reboot .. warm start.
