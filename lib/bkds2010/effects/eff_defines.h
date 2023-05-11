#ifndef EFF_DEFINES_H
#define EFF_DEFINES_H

#define EFF_PPROW       0x00	// PPROW, i.e. top layer
#define EFF_ME1ROW      0x01	// ME1ROW, i.e. PGM/PST bus, etc.
#define EFF_CHRKEY      0x10	// CHROMA KEY OPERATIONS
#define EFF_FRMEM1      0x14	// FRAME MEMORY 1 OPERATIONS
#define EFF_FRMEM2      0x15	// FRAME MEMORY 2 OPERATIONS
#define EFF_MATTE       0x18	// MATTE OPERATIONS
#define EFF_VPROC       0x1e	// VPROC OPERATIONS / BUTTON CONFIG
#define EFF_CCR         0x1f	// COLOR CORRECTION
#define EFF_SYSCTRL     0x20	// SYSTEM CONTROL
#define EFF_EVENTMEM    0x21	// EVENT MEMORY
#define EFF_PRGPGM2     0x25	// SWITCHER FIRWMARE UPGRADE
#define EFF_PRGPGM      0x2e	// SWITCHER FIRMWARE UPGRADE
#define EFF_AUX1        0x30	// AUX1
#define EFF_AUX2        0x31	// AUX2
#define EFF_AUX3        0x32	// AUX3
#define EFF_AUX4        0x33	// AUX4
#define EFF_AUX5        0x34	// AUX5
#define EFF_AUX6        0x35	// AUX6
#define EFF_EDITPVW     0x3f	// EDIT PREVIEW
#define EFF_PING        0xff	// CONTROL PANEL SENDS PINGS TO THE SWITCHER

#endif
