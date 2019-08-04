// winload.c
// from this we build the winload32.efi or winload64.efi

// winload will use UEFI services for low level functions

// winloadXX.efi will be loaded from UEFI or from a bootmanager and cmd-line arguments can be passed to winloadXX.efi

#include "efi.h"

EFI_STATUS efi_main(EFI_HANDLE imageHandle, EFI_SYSTEM_TABLE* systemTable)
{

// if we just return and not called ExitBoot.. the system consider as loadFail and offer other bootmode or simply warmboot
// if we did ExitBoot then it restart normal and consider as last known good
// but a normal successful Load with ExitBoot will never return here, instead the kernel will  rt.ResetSystem (shutdown, warm-reboot, cold-reboot)

return EFI_SUCCESS;
}