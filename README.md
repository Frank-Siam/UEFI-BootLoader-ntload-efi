# UEFI-BootLoader: winload.efi

note: i just started. there is nothing usefull here yet. it is for testing github..


this project is a boot loader for a windows compatible OS used in a UEFI boot environment.

UEFI will be a 32 or 64 bit boot environment, dependend from the hardware.
this boot loader will be called directly with saved boot arguments (strings) or
from a boot manager. or the file is renamed to bootx.efi (32bit) or bootx64 (64bit) and copy into
/efi/boot on the boot disk by a setup programm.

this boot loader is a module in native PE format subsystem efi. 
winload.efi can be 32bit or 64bit, select in build.

winload.efi need to know the path to the system root deice and a root directory path.

we give a Root device path to the volume. the volume becomes the root volume c:
we give a Root path: Windows or Reactos or NTOS.

the system registry file has the name "system" or "system.hive" and is normal "C:\Windows\System32\config\system"
we can specify a other file path for the system hive file name with a cmdline parameter.
from the given info this bootloader will build filenames for the system registry file and all modules what it loads into memory.

winload.efi do this:
1. create a boot parameter block struct (BPB) so kernel can use later.

2. initialize boot parameter block:
copy given boot parameters from winload.efi-commandline or boot.ini into boot parameter block. 
save root device path and root directory path into boot parameter block. 
load the system registry file into memory as system-HIVE. save the handle in boot parameter block. 
load kernel modules into memory: ntoskrnl.exe hal.dll bootvid.dll kdcom.dll ..
load boot drivers into memory:
copy hardware info from UEFI tables into boot parameter block.
copy memory map info from UEFI into boot parameter block.
setup UEFI runtime service table so the kernel can call UEFI services for reboot, shutdown etc.

3. call kernel entry point.

if any error occur while loading the system registry or the modules or when starting the kernel, we reboot .. warm start.
if the operating system (windows) is loaded normal, we never return from the kernel. the operating system will call
UEFI services directly for reboot or shutdown.

each volume on disk has a volume id.
we will use this id to build the root device path better then just the volume index. so we can move and copy the volumes with disk utilities and boot will always work.
the kernel will also remember its root volume id in the system registry.
so if somebody just copy all the files from a working root volume to a new disk or volume. the kernel can recognize this and react acordingly.

Todo: handle resume from a suspend to RAM or suspend to disk.