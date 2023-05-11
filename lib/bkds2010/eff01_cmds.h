#ifndef EFF01_CMDS_H
#define EFF01_CMDS_H

#define RD_SELECT_XPT_PGM	0x00	// SELECT XPT PGM BUS
#define WR_SELECT_XPT_PGM	0x80
#define RD_SELECT_XPT_PST	0x01	// SELECT XPT PST BUS
#define WR_SELECT_XPT_PST	0x81
#define RD_SELECT_XPT_KEY1	0x07	// SELECT XPT KEY1 BUS
#define WR_SELECT_XPT_KEY1	0x87
#define RD_SELECT_XPT_KEY2	0x0d	// SELECT XPT KEY2 BUS
#define WR_SELECT_XPT_KEY2	0x8d
#define RD_UTIL				0x0f	// UTIL?
#define WR_UTIL				0x8f
#define RD_NEXT_TRANS		0x10	// NEXT TRANSITION
#define WR_NEXT_TRANS		0x90
#define RD_TRANS_TYPE		0x11	// TRANSITION TYPE (MIX/WIPE/DME)
#define WR_TRANS_TYPE		0x91
#define RD_AUTO_RATE		0x18	// AUTO TRANS RATE
#define WR_AUTO_RATE		0x98
#define RD_UNK_A1			0x21	// UNKNOWN COMMAND
#define WR_UNK_A1			0xa1
#define RD_UNK_9C			0x1c	// UNKNOWN COMMAND
#define WR_UNK_9C			0x9c
#define RD_UNK_8A			0x0a	// UNKNOWN COMMAND
#define	WR_UNK_8A			0x8a
#define RD_KEY				0x1a	// KEY
#define WR_KEY_OFF			0x9a
#define WR_KEY_ON			0xda
#define RD_WIPE				0x1b	// WIPE OPERATIONS
#define WR_WIPE_OFF			0x9b
#define WR_WIPE_ON			0xdb
#define RD_WIPEPOS			0x29	// WIPE POSITION
#define WR_WIPEPOS			0xa9
#define RD_WIPEPARAMS		0x2b	// WIPE PARAMS
#define WR_WIPEPARAMS		0xab
#define RD_MIXPARAMS		0x2f	// MIX PARAMS
#define WR_MIXPARAMS		0xaf
#define RD_MATTEPARAMS1		0x30	// MATTE PARAMS 1
#define WR_MATTEPARAMS1		0xb0
#define RD_MATTEPARAMS2		0x31	// MATTE PARAMS 2
#define WR_MATTEPARAMS2		0xb1
#define RD_MATTEPARAMS3		0x32	// MATTE PARAMS 3
#define WR_MATTEPARAMS3		0xb2
#define RD_MATTEPARAMS4		0x37	// MATTE PARAMS 4
#define WR_MATTEPARAMS4		0xb7
#define RD_MATTEPARAMS5		0x39	// MATTE PARAMS 5
#define WR_MATTEPARAMS5		0xb9
#define RD_MATTEPARAMS6		0x3a	// MATTE PARAMS 6
#define WR_MATTEPARAMS6		0xba
#define RD_TBAR				0x28	// TBAR VALUES
#define WR_TBAR				0xa8

#endif
