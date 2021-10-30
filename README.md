# UEFI-BootLoader: winload.efi

note: i just started. there is nothing usefull here yet. it is for testing github..


this project is a boot loader for a windows compatible OS used in a UEFI boot environment.
it is for pc x86 (32bit) and x64(64bit), winload.efi as a 32 or 64bit PE (select in build).

UEFI will be a 32 or 64 bit boot environment dependend from the hardware.
this boot loader will be called directly with saved boot arguments (strings) or
from a boot manager.

our boot loader is a module in native PE format. it can be 32bit or 64bit: winload32.efi or winload64.efi

winload.efi do this:
1. create a boot parameter block struct (BPB) so kernel can use later.

2. initialize boot parameter block:
copy given boot parameters from winload.efi-commandline or boot.ini into boot parameter block. 
load the system registry file into memory as system-HIVE. save the handle in boot parameter block. 
load kernel modules into memory: ntoskrnl.exe hal.dll bootvid.dll kdcom.dll ..
load boot drivers into memory:
copy hardware info from UEFI tables into boot parameter block.
copy memory map info from UEFI into boot parameter block.
setup UEFI runtime service table so the kernel can call UEFI services for reboot, shutdown etc.

3. call kernel entry point.

if any error occur while loading the system registry or the modules or when starting the kernel, we reboot .. warm start.
if the ooerating system (windows) is loaded normal, we never return from the kernel. the operating system will call
UEFI services directly for reboot or shutdown.

winload.efi need to know the path to the system registry file. the volume where that file is becomes the root volume c:
this file has the name "system" or "system.hive" and is normal "C:\Windows\System32\config\system"

Todo: handle resume from a suspend to RAM or suspend to disk.