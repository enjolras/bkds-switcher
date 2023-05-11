#ifndef EFF00_CMDS_H
#define EFF00_CMDS_H

#define RD_SELECT_XPT	0x07
#define WR_SELECT_XPT	0x87
#define RD_UNK_13		0x13
#define RD_KEY			0x1a
#define WR_KEY_OFF		0x9a
#define WR_KEY_ON		0xda
#define RD_AUTO_RATE	0x18
#define WR_AUTO_RATE	0x98
#define WR_DSK			0x90	// HAVE TO CHECK WHAT IT DOES
#define WR_DSK_OFF		0x93	// SAME
#define WR_DSK_ON		0xd3	// SAME
#define RD_MATTE1		0x31	// FIRST MATTE
#define WR_MATTE1		0xb1
#define RD_MATTE2		0x32	// SECOND MATTE
#define WR_MATTE2		0xb2

#endif
