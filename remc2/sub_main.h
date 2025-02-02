#pragma once

//#include "engine/defs.h"

//#include "stdafx.h"

//#include <dir.h>

//#include <vld.h>//only for debug

#include <array>
#include <typeinfo>

#include "utilities/DataFileIO.h"
#include "utilities/BitmapIO.h"

#include "engine/XUnk_D4350.h"
#include "engine/Type_D404C.h"
#include "engine/Type_D94F0_Bldgprmbuffer.h"
#include "engine/Type_D93C0_Bldgprmbuffer.h"
#include "engine/Type_MapScreenPortals_E17CC.h"
#include "engine/Type_SecretMapScreenPortals_E2970.h"
#include "engine/Basic.h"
#include "engine/Sound.h"
#include "engine/Type_Animations.h"
#include "engine/Animation.h"
#include "engine/GameRenderOriginal.h"
#include "engine/GameRenderHD.h"
#include "engine/GameRenderNG.h"
#include "engine/GameRenderGL.h"

#include "engine/Terrain.h"

#include "portability/port_net.h"

//#define __CFSHL__(x, y) (x<<y)
//#define __CFSHL__(x, y) 1
/*int32_t __CFSHL__(uint32_t x, uint32_t y) {
	return 1;
}*/
//myprintf("invalid_operation:__CFSHL__(x, y)")
//#define __RCR__(x, y) printf("invalid_operation:__RCR__(x, y)")
//#define __RCL__(x, y) printf("invalid_operation:__RCL__(x, y)")
//#define __ROL4__(x, y) __ROL__(x, y)       // Rotate left
//#define __ROR4__(x, y) __ROR__(x, y)       // Rotate left

#include "engine/sub_main_mouse.h"
//#include "engine/ail_sound.h"

/* This file has been generated by the Hex-Rays decompiler.
Copyright (c) 2007-2017 Hex-Rays <info@hex-rays.com>

Detected compiler: Watcom C++
*/

/*int sub_main(int argc, char **argv, char **envp);
int sub_97F90(x_DWORD *a1);
int sub_980D0(x_DWORD *a1, int a2);
int sub_98170(x_DWORD *a1, int a2, int a3);
int sub_A158B(int a1, __int16 a2, x_WORD *a3, x_WORD *a4);
bool sub_A4CB0();
int sub_A4F10(int a1, char a2, char a3, char a4);
x_DWORD * sub_A5850(int a1, char a2, unsigned int a3, signed int a4, int a5);*/

#ifndef SUB_MAIN_ACTIVE
#define SUB_MAIN_ACTIVE

#define O_RDONLY        0x00    /* read only */
#define O_WRONLY        0x01    /* write only */
#define O_RDWR          0x02    /* read and write */
#define O_BINARY        0x10    /* file contains - binary data */
#define O_TEXT          0x20    /* - text (\n terminated records) */
#define O_CREAT         0x200   /* replace, or create t */
#define O_TRUNC         0x400   /* open with truncation */

#ifdef _MSC_VER

#include <stdlib.h>
#define bswap_16(x) _byteswap_ushort(x)
#define bswap_32(x) _byteswap_ulong(x)
#define bswap_64(x) _byteswap_uint64(x)

#elif defined(__APPLE__)

// Mac OS X / Darwin features
#include <libkern/OSByteOrder.h>
#define bswap_16(x) OSSwapInt16(x)
#define bswap_32(x) OSSwapInt32(x)
#define bswap_64(x) OSSwapInt64(x)

#elif defined(__sun) || defined(sun)

#include <sys/byteorder.h>
#define bswap_16(x) BSWAP_16(x)
#define bswap_32(x) BSWAP_32(x)
#define bswap_64(x) BSWAP_64(x)

#elif defined(__FreeBSD__)

#include <sys/endian.h>
#define bswap_16(x) bswap16(x)
#define bswap_32(x) bswap32(x)
#define bswap_64(x) bswap64(x)

#elif defined(__OpenBSD__)

#include <sys/types.h>
#define bswap_16(x) swap16(x)
#define bswap_32(x) swap32(x)
#define bswap_64(x) swap64(x)

#elif defined(__NetBSD__)

#include <sys/types.h>
#include <machine/bswap.h>
#if defined(__BSWAP_RENAME) && !defined(__bswap_32)
#define bswap_16(x) bswap16(x)
#define bswap_32(x) bswap32(x)
#define bswap_64(x) bswap64(x)
#endif

#else

#define bswap_16(x) ((uint16_t) ((((x) >> 8) & 0xff) | (((x) & 0xff) << 8)))
#define bswap_32(x)					\
  ((((x) & 0xff000000u) >> 24) | (((x) & 0x00ff0000u) >> 8)	\
   | (((x) & 0x0000ff00u) << 8) | (((x) & 0x000000ffu) << 24))
#define bswap_64(x)			\
  ((((x) & 0xff00000000000000ull) >> 56)	\
   | (((x) & 0x00ff000000000000ull) >> 40)	\
   | (((x) & 0x0000ff0000000000ull) >> 24)	\
   | (((x) & 0x000000ff00000000ull) >> 8)	\
   | (((x) & 0x00000000ff000000ull) << 8)	\
   | (((x) & 0x0000000000ff0000ull) << 24)	\
   | (((x) & 0x000000000000ff00ull) << 40)	\
   | (((x) & 0x00000000000000ffull) << 56))

#endif

#ifndef _countof
#define _countof(arr) sizeof(arr) / sizeof(arr[0])
//dirty
#endif

//#if !defined(_M_I86) && !defined(__WINDOWS_386__)

/* dword registers */

struct DWORDREGS {
	unsigned int eax;
	unsigned int ebx;
	unsigned int ecx;
	unsigned int edx;
	unsigned int esi;
	unsigned int edi;
	unsigned int cflag;
};

//#endif
/*
// word registers

struct WORDREGS {
	unsigned short ax;  //__FILLER(_1)
		unsigned short bx;  //__FILLER(_2)
		unsigned short cx;  //__FILLER(_3)
		unsigned short dx;  //__FILLER(_4)
		unsigned short si;  //__FILLER(_5)
		unsigned short di;  //__FILLER(_6)
#if defined(__WINDOWS_386__)
		unsigned short cflag;
#else
		unsigned int cflag;
#endif
};

// byte registers

struct BYTEREGS {
	unsigned char al, ah;  //__FILLER(_1)
		unsigned char bl, bh;  //__FILLER(_2)
		unsigned char cl, ch;  //__FILLER(_3)
		unsigned char dl, dh;  //__FILLER(_4)
};

union REGS {
#if defined(_M_I86) || defined(__WINDOWS_386__)
	struct WORDREGS  x;
#else
	struct DWORDREGS x;
#endif
	struct WORDREGS  w;
	struct BYTEREGS  h;
};
*/
//#define REGS x_DWORD[6]

/*extern x_WORD __CS__;
extern x_WORD __GS__;
extern x_WORD __DS__;
extern x_WORD __ES__;
extern x_WORD __FS__;
extern x_WORD __SS__;*/

//extern char IsTable[];

#pragma pack (1)
typedef struct {//lenght 6
	int8_t* bitmapData_0;
	int16_t bitmapIndex_4;
}
sub2x_BYTE_E7EE0x;

typedef struct {//lenght 24
	int32_t dword_0;
	int32_t dword_4;
	int32_t dword_8;
	int32_t dword_12;
	sub2x_BYTE_E7EE0x* bitmapsStr_16;
	int8_t* bitmapsData_20xx;
}
subx_BYTE_E7EE0x;

typedef struct {
	unsigned long LastTimeRendered_0;
	int16_t PosX_4;
	int16_t PosY_6;
	int16_t ActSprite_8;
	int8_t FirstSprite_10;
	int8_t LastSprite_11;
} type_MainMenuAnimations_E1748;

typedef struct {//lenght 30
	int32_t dword_0;
	int32_t dword_4;
	int16_t word_8;
	int16_t word_10;
	int16_t word_12;
	int16_t word_14;
	int16_t word_16;
	int16_t word_18;
	int8_t byte_20;
	int8_t byte_21;
	int16_t word_22;
	int16_t word_24;
	int16_t word_26;
	//int8_t stuba[1];
	int16_t word_28;
	//int8_t stubb[1];
} type_x_BYTE_E25ED_db_str;
#pragma pack (16)

extern filearray_struct x_DWORD_E9B20[4];

extern __int16 x_WORD_E29DA_type_resolution; // weak

#pragma pack (1)
typedef struct {//lenght 18
	int16_t word_0;
	int16_t word_2;
	int16_t word_4;
	int16_t word_6;
	int16_t word_8;
	int16_t word_10;
	int16_t word_12;
	int16_t word_14;
	int8_t byte_16;
	int8_t byte_17;
}
type_E24BCx;
#pragma pack (16)


#pragma pack (1)
typedef struct {//lenght 18
	int16_t word_0;
	int16_t word_2;
	int16_t word_4;
	int16_t word_6;
	int16_t word_8;
	int16_t word_10;
	int16_t word_12;
	int16_t word_14;
	int16_t word_16;
}
type_x_BYTE_E25ED_2BB;
#pragma pack (16)

#pragma pack (1)
typedef struct {
	int32_t x_DWORD_18058C;
	int32_t x_DWORD_180590; // [4]//unk_18058Cstr.x_DWORD_180590//1
	int32_t x_DWORD_180594; // [8]//unk_18058Cstr.x_DWORD_180594//2
	int32_t x_DWORD_180598; // [12]//unk_18058Cstr.x_DWORD_180598//3
	int32_t x_DWORD_18059C; // [16]//unk_18058Cstr.x_DWORD_18059C//4
	int32_t x_DWORD_1805A0; // weak//unk_18058Car[20]//5
	int32_t x_DWORD_1805A4; // weak//unk_18058Car[0x18]//6
	int32_t x_DWORD_1805A8; // weak//unk_18058Car[28]//7
	int32_t x_DWORD_1805AC; // weak//unk_18058Car[0x20]//8
	axis_2d_32 x_DWORD_1805B0_mouse;
	//int32_t x_DWORD_1805B0_mouse.x; // weak//unk_18058Car[36]
	//int32_t x_DWORD_1805B0_mouse.y; // weak//unk_18058Car[40]
	int32_t x_DWORD_1805B8_mouse_position_x; // weak//unk_18058Car[44]
	int32_t x_DWORD_1805BC_mouse_position_y; // weak//unk_18058Car[48]
	int16_t x_WORD_1805C0_arrow_keys; // weak//unk_18058Car[52] // keyboard buttons
	int16_t x_WORD_1805C2_joystick; // weak//unk_18058Car[54]
	int16_t x_WORD_1805C4_vio1_analog_joy; // weak//unk_18058Car[56]
	int16_t x_WORD_1805C6_vio2_analog_joy; // weak//unk_18058Car[58]
	int16_t x_WORD_1805C8; // weak//unk_18058Car[60]
	uint8_t unk_1805CE[84]; // weak//unk_18058Car[66]
	int16_t stub_180622;
} type_unk_18058Cstr;//end 180624
#pragma pack (16)

//extern type_x_DWORD_17DE38str x_DWORD_17DE38str;
/*
extern int16_t x_DWORD_17DEE4_mouse_positionx; // weak
extern int16_t x_DWORD_17DEE4_mouse_positiony; // weak
extern __int16 x_WORD_17DEEC; // weak
extern __int16 x_WORD_17DEEE; // weak
extern __int16 x_WORD_17DEF0; // weak
extern __int16 x_WORD_17DEF2; // weak
extern __int16 x_WORD_17DEF4; // weak
extern __int16 x_WORD_17DEF6; // weak
extern __int16 x_WORD_17DEF8; // weak
extern __int16 x_WORD_17DEFA; // weak
extern __int16 x_WORD_17DEFC; // weak
extern __int16 x_WORD_17DEFE; // weak
extern __int16 x_WORD_17DF00; // weak
extern __int16 x_WORD_17DF02; // weak
extern __int16 x_WORD_17DF04; // weak
extern __int16 x_WORD_17DF06; // weak
extern __int16 x_WORD_17DF08; // weak
extern __int16 x_WORD_17DF0A; // weak
extern __int16 x_WORD_17DF0C; // weak
extern __int16 x_WORD_17DF0E; // weak
extern char x_BYTE_17DF10_get_key_scancode; // weak
extern char x_BYTE_17DF11_last_key_status; // weak
*/

extern uint16_t x_WORD_17B4E0; // 34c4e0


extern char isCaveLevel_D41B6;

#pragma pack (1)
typedef struct {//lenght 16
	int16_t x1_26_0;//0 x
	int16_t y1_28_1;//1 y
	int16_t word_30_2;//2
	int16_t word_32_3;//3
	int16_t word_34_4;//4
	int16_t word_36_5;//5
	int16_t word_38_6;//6
	int16_t click_40_7;//7
	int16_t nocl_42_8;//8
} type_str_word_26;

typedef struct {//lenght 44
	uint32_t dword_0;
	//int16_t word_2;
	int32_t dword_4;//4 dword
	//int16_t word_6;//remove it
	int16_t selected_8;
	int16_t xmin_10;
	int16_t ymin_12;
	int16_t sizex_14;
	int16_t sizey_16;
	int16_t word_18;
	uint8_t byte_20;//index of gold sprite
	uint8_t byte_21;//index of gray sprite
	int8_t byte_22;
	int8_t canSelect_23;
	int8_t gold_color_24;
	int8_t byte_25;
	//int16_t word_24;//23 and 24 byte
	type_str_word_26 str_26;//0
	//int16_t word_28;//1
	//int16_t word_30;//2
	//int16_t word_32;//3
	//int16_t word_34;//4
	//int16_t word_36;//5
	//int16_t word_38;//6
	//int16_t click_40;//7
	//int16_t nocl_42;
}
type_WORD_E1F84;
#pragma pack (16)

#pragma pack (1)
typedef struct //lenght 50
{
	uint32_t x_DWORD_17DB70; // weak
	int16_t x_WORD_17DB74; // weak 4
	int16_t unk_17DB76_posx; // weak 6
	int16_t unk_17DB78_posy; // weak 8
	int16_t fill1; // test 10
	int16_t fill2; // test 12
	int16_t unk_17DB7E; // weak 14
	int16_t unk_17DB80; // weak 16
	int16_t x_WORD_17DB82_shift_step; // weak 18
	int16_t x_WORD_17DB84; // weak 20
	int16_t x_WORD_17DB86; // weak 22
	int16_t x_WORD_17DB88; // weak 24
	int16_t x_WORD_17DB8A; // weak 26
	int16_t x_WORD_17DB8C; // weak 28
	int8_t x_BYTE_17DB8E; // weak 30
	int8_t x_BYTE_17DB8F; // weak 31
	int16_t unk_17DB90; // weak 32
	uint8_t unk_17DB92[6]; // weak 32
	uint8_t fill3[16]; // fill
} type_x_DWORD_17DB70str;
#pragma pack (16)

// typedef struct NCB{
//				BYTE     ncb_command;	/* NetBIOS command (see netbios.h) */
//BYTE     ncb_retcode;	/* NetBIOS return code; 0xFF until asynchronous call  finishes */
//BYTE     ncb_lsn;	/* local session number */
//BYTE     ncb_num; 	/* NetBIOS name number */
//DWORD    ncb_buffer;	/* transmit/receive buffer */
//WORD     ncb_length;	/* buffer length */
//BYTE     ncb_callName[16];  	/* name of remote node to send datagram or to be connected; */
//		/* when listening for connections: name trying to connect  */
//BYTE     ncb_name[16];	/* local name */
//BYTE     ncb_rto;	/* receive timeout in 500 ms units;  0=forever */
//BYTE     ncb_sto;	/* send timeout in 500 ms units;  0=default */
//DWORD    ncb_post;	/* ptr to post-processing routine */
//	/* (DOS: ES:BX points to NCB when entered. Ends with RETF) */
//BYTE     ncb_lana_num;	/* LAN adapter number; 0-based */
//BYTE     ncb_cmd_cplt;	/* completion status */
//BYTE     ncb_reserved[14];
//		 } NCB;

extern Pathstruct pstr[];
extern char x_BYTE_D4B80;

void j___delay(x_DWORD); // weak
unsigned long j___clock();

void WriteBufferToBMP(uint16_t width, uint16_t height, uint8_t* ptrPalette, uint8_t* ptrBuffer);

void sub_43C60(unsigned __int8 a1, char a2, int a3, int a4);

void SetStagetagForTermod_49830(Type_Level_2FECE* terrain);
void GenerateEvents_49290(Type_Level_2FECE* terrain, char a2, uint16_t width, uint16_t height);

void sub_49F30();

void DrawHelpText_6FC50(__int16 a1);

void sub_6EBF0(filearray_struct* a1);

char sub_533B0_decompress_levels(__int16 a1, Type_Level_2FECE* a2, std::string customLevelPath = "");

//int /*__noreturn*/ sub_10000(); // weak
type_event_0x6E8E* sub_15CB0(/*type_str_0x6E8E* a1,*/ type_event_0x6E8E* a2); // weak
char sub_15D40(__int16 a1, type_event_0x6E8E* a2, type_event_0x6E8E* a3); // weak
int16_t sub_16730(/*int a1,*/ type_event_0x6E8E* a2, char a3); // weak
int16_t sub_16CA0(baxis_2d* a2, __int16 a3, char a4); // weak
void sub_17A00(int8_t* a1, signed int a2, __int16 a3); // weak
int _wcpp_1_unwind_leave__120(int32_t a, int32_t b, int32_t c);// weak
void sub_1A070(signed int a1, __int16 a2);
void JUMPOUT(int* adr);
void JUMPOUT(int32_t cs, int* adr);
void JUMPOUT(int32_t cs, int a, int* adr);
void sub_1F0C0(/*type_str_0x6E8E* a1,*/ type_event_0x6E8E* a2);
void sub_253B0(/*int result, */type_event_0x6E8E* a2, unsigned __int8 a3, unsigned __int8 a4);
signed int sub_369F0(/*signed int a1,*/ __int16 a2);
//void qmemcpy(void* a, void* b, size_t c);
void sub_2A340(/*int a1, type_str_0x6E8E* a2, type_str_0x6E8E* a3, int a4, *//*type_str_0x6E8E* a5, */type_event_0x6E8E* a6);
void sub_2AA90(/*type_str_0x6E8E* a1, */type_event_0x6E8E* a2, type_event_0x6E8E* a3);
void sub_2BD10_draw_line(__int16 a1, __int16 a2, __int16 a3, __int16 a4, unsigned __int8 a5);
void ClearGraphicsBuffer_72883(void* ptrBuffer, uint16_t width, uint16_t height, char value);
void DrawVolumeSettings_303D0();
int _wcpp_1_unwind_leave__62(void); //weak
//int sub_7FCB0_draw_text_with_border(/*int a1,*/ char* a2, int32_t a3, int32_t a4, int a5, uint8_t a6, unsigned __int8 a7, uint32_t a8);//560cb0
signed int sub_36A50(/*signed int a1, */char a2);
void sub_36920(/*signed __int16 a1, */type_event_0x6E8E* a2);
void sub_48A20(int a1, char a2, char a3, int a4, int a5, unsigned __int8 a6);
//void __outx_WORD(unsigned short Port, unsigned short Data);
//void __outx_BYTE(unsigned short Port, unsigned char Data);
//unsigned char __inx_BYTE(unsigned short Port);
void sub_41BC0();
void sub_44EE0_smooth_tiles(/*int a1, */uaxis_2d a2);
void sub_54600_mouse_reset();
void sub_56A30_init_game_level(unsigned int a1, int16_t level = -1, std::string customLevelPath = "");
void sub_5B870_copy_sentence(char* langbuffer, char** langindexbuffer, uint32_t count);
void sub_47320_in_game_loop(signed int a1);
void sub_56D60(unsigned int a1, char a2);
void SetCenterScreenForFlyAssistant_6EDB0();
int NetworkInitConnection_7308F(char* a2, __int16 a3);
void NetworkUpdateConnections2_74374();
int16_t GetIndexNetwork2_74515();
void sub_7A060_get_mouse_and_keyboard_events();
void sub_7AA70_load_and_decompres_dat_file(const char* a1, uint8_t* a2, int a3, int a4);
void DrawAndEventsInGame_47560(uint32_t a3, signed int a4, __int16 a5);
void GameEvents_51BB0();
//x_DWORD /*__cdecl*/ toupper(x_DWORD); //weak
void sub_55C60(type_str_0x2BDE* loc0x2BDE);
int32_t /*__cdecl*/ fix_filelength(int32_t);// weak
//x_DWORD /*__cdecl*/ access(char* path, uint32_t flags);// weak
//x_DWORD /*__cdecl*/ mkdir(char* path);
int32_t /*__cdecl*/ settextposition(int32_t, int32_t);// weak
void outtext(const char* text);// weak
int /*__fastcall*/ gettextposition(int32_t, int32_t, int32_t);// weak
int32_t /*__cdecl*/ signal(int32_t, int32_t);// weak
//int __cdecl unknown_libname_1(char *a1);
//void _disable();
//void _enable();
//long _InterlockedExchange(long volatile * Target, long Value);
//x_DWORD /*__cdecl*/ dos_getvect(x_DWORD);// weak
//void(*dos_getvect(x_DWORD number))();
//x_DWORD /*__cdecl*/ dos_setvect(x_DWORD number, void(*actcall)(), x_DWORD);// weak
//unsigned char _BitScanReverse(unsigned long * Index, unsigned long Mask);
//void sub_8F920(uint8_t a1byte1, uint8_t a1byte2, int16_t posx, int16_t posy, uint8_t* a4, unsigned __int8 a5, char a6);
//void sub_8F935_bitmap_draw_final(uint8_t a1byte1, uint8_t a1byte2, uint16_t a2, int a3, uint8_t* a4, uint8_t setbyte, char a6);
uint8_t NetworkAddName_74767(/*signed __int16* a1,*/ myNCB* a2x, char* a3);
//x_DWORD /*__cdecl*/ segread(SREGS*); //weak
//x_DWORD /*__cdecl*/ int386x(x_DWORD, x_DWORD, x_DWORD, x_DWORD);// weak
//int int386x(int, REGS *, REGS *, struct SREGS *);
//unsigned char __readgsx_BYTE(unsigned long Offset);
//unsigned short __readgsx_WORD(unsigned long Offset);
void sub_753D0();
void sub_7A110_load_hscreen(char a1, char a2);
void ResetMouse_7B5A0();
void sub_7B5D0();
void ClearScrollDialogVars_7C020(type_str_word_26* a1x);
char sub_7C200(uint8_t a1);
void sub_7E840_draw_textbox_with_line(type_E24BCx* a1x, __int16 a2, __int16 a3);
void sub_7E8D0(x_WORD* a1, __int16 a2, __int16 a3, __int16 a4, __int16 a5, __int16 a6, __int16 a7);
bool sub_7E9D0(x_WORD* a1, x_WORD* a2, x_WORD* a3);
void sub_81CA0(int a1, int a2, __int16 a3, __int16 a4, type_x_BYTE_E25ED_db_str* a5);
signed int sub_7E5A0_pre_draw(int a1, int a2, __int16 a3, __int16 a4, uint8_t* a5, __int16 a6, __int16 a7);
void sub_81260(int a1, int a2, int8_t* a3, __int16 a4, __int16 a5);
int sub_812D0_drawDotBitmap(__int16 a1, __int16 a2);
signed __int16 sub_81EE0(int a1, int a2, int a3, signed __int16 a4, __int16 a5, __int16 a6);
bool sub_80D40_move_graphics_and_play_sounds(__int16 a2, __int16 a3, __int16 a4, __int16 a5, char a6);
void sub_85CC3_draw_round_frame(/*unsigned int a1, int a2, */unsigned __int16* a3);
//void sub_840B8(char a1, bool a2, char a3, char a4);
//unsigned     int __readeflags(void);

__int16 sub_840D3(char _CF, bool _ZF, char _SF, char _OF);//ShowPerifery
void  sub_841CE(__int16 a1);//ShowPerifery
//sub_8EA7B ShowPerifery
//sub_A0F06 ShowPerifery
//sub_A12C5 ShowPerifery
//sub_AC70E ShowPerifery
//sub_AC7F6 ShowPerifery
//sub_AC843 ShowPerifery
//sub_AC8DD ShowPerifery
//sub_AC918 ShowPerifery
//sub_B5022 ShowPerifery
//sub_B5128 ShowPerifery
//sub_B51B3 ShowPerifery
//sub_B522B ShowPerifery
//sub_6FDA0 ShowPerifery
//sub_90530 ShowPerifery
//sub_B5015 ShowPerifery
//sub_840B8 ShowPerifery

char sub_86860_speak_Sound(unsigned __int16 a1);
void sub_86EB0(unsigned __int8 a1, unsigned __int8 a2, char a3);
int16_t sub_89B60_aplicate_setting(uint8_t a1);
//void __writeeflags(unsigned Value);
int32_t /*__cdecl*/ gets(int32_t);// weak
//x_DWORD /*__cdecl*/ fix_tell(x_DWORD);// weak
int32_t /*__cdecl*/ expand(int32_t, int32_t);// weak
//int /*__fastcall*/ _wcpp_1_unwind_leave__132(x_DWORD);// weak
void sub_8BA10(int a2, int* a3, char* a4, int a5);
double /*__fastcall*/ _CHP(int32_t);// weak
char sub_8B980(int a1, int a2, char* a3, int a4);
signed int sub_8BBE0(uint8_t* a1);
void sub_8CD27_set_cursor(posistruct_t a2);
signed int sub_8CEDF_install_mouse();
int16_t sub_90B27_VGA_pal_fadein_fadeout(TColor* a1x, uint8_t shadow_levels, bool a3);
void sub_90D6E_VGA_set_video_mode_320x200_and_Palette(TColor* Palette);
void sub_90E07_VGA_set_video_mode_640x480_and_Palette(TColor* Palette);
void CopyScreen(void* source, void* desc, unsigned __int16 width, unsigned __int16 height);
size_t WriteFile_98CAA(FILE* a1, uint8_t* a2, uint32_t a3);
signed int sub_9A10A_check_keyboard();
bool sub_9AE04(int a1, int a2);
/*
HDIGDRIVER sub_93330_AIL_install_DIG_driver_file(char* filename, IO_PARMS* IO);
char sub_9AE90(int eax0, int edx0, int ebx0, int* a1, int8_t* a2, int a3, int a4);
int sub_931F0_AIL_install_DIG_INI(HDIGDRIVER* a2, char* digPath);
HMDIDRIVER sub_95850_AIL_install_MDI_driver_file(char* filename, IO_PARMS* IO);
int32_t sub_95710_AIL_install_MDI_INI(HMDIDRIVER* mdi, char* fileName);
*/
uint32_t /*__cdecl*/ x_read(FILE* descriptor, uint8_t* data, uint32_t size);// weak
double IF_DPOW(double, double);// weak
int32_t x_dos_setdrive(int32_t a, int32_t* b);
//int /*__cdecl*/ x_chdir(const char* path);
//char* /*__cdecl*/ x_getcwd(x_DWORD a, x_DWORD b);// weak
//int32_t /*__cdecl*/ x_outp(int32_t, char);// weak
//int32_t /*__cdecl*/ x_inp(int32_t);// weak
//x_DWORD *sub_9E720(int a1, int a2, int a3);
/*
int sub_A3720_AIL_API_install_DIG_INI(HDIGDRIVER* dig, char* digPath);
HDIGDRIVER sub_A3600_AIL_API_install_DIG_driver_file(char* filename, IO_PARMS* IO);
int32_t sub_A78F0_AIL_API_install_MDI_INI(HMDIDRIVER* mdi, char* fileName);
HMDIDRIVER sub_A77D0_AIL_API_install_MDI_INI(char* filename, IO_PARMS* IO);
*/
int32_t /*__cdecl*/ x_setmode(FILE* path, int mode);// weak
//uint32_t sub_98AE0(uint8_t *a1);
//__int16 sub_98B2C(unsigned __int8 a1, int a2);
//char sub_98BAF(int a1);
__int16 sub_98AE9(__int16* a1, int a2);
unsigned __CFRCR__(__int16 a, unsigned __int8 b);
uint32_t /*__cdecl*/ x_write(FILE* descriptor, uint8_t* buffer, uint32_t size_t);
//int32_t /*__cdecl*/ x_tolower(int32_t);// weak
//FILE* x_open(char* path, int pmodex);
//void __writegsx_WORD(unsigned long Offset, unsigned short Data);
//void __writegsx_DWORD(unsigned long Offset, unsigned long Data);
//x_DWORD /*__cdecl*/ dos_read(x_DWORD, char, x_DWORD, x_DWORD, x_DWORD);// weak
void __inx_BYTEstring(unsigned short Port, unsigned char* Buffer, unsigned long Count);
//unsigned int __getcallerseflags(void);
//void __sidt(void *Destination);
//unsigned long __readcr0(void);
//void __writecr0(unsigned __int32 Data);
int sub_ACE8D(int16_t* a1, int a2, int* a3);
void sub_AD0E2(int8_t* a1, int a2, int* a3, int8_t** a4);
void sub_ACF1A(int8_t* a1, int a2, int* a3);
void sub_B5F8F(__int16 a1, uint16_t* a2, int32_t a3, __int16* a4);
int sub_BD320(int result, int8_t* a2, int8_t* a3, int a4, int a5, uint8_t* a6);
void sub_B5EFA(__int16 a1, uint16_t* a2, int32_t a3, __int16* a4);
Type_SecretMapScreenPortals_E2970* sub_824B0(__int16 a1);
Type_SecretMapScreenPortals_E2970* sub_824E0(__int16 a1);

void sub_101C0();
void sub_5BCC0_set_any_variables1();
signed int sub_5C1B0_set_any_variables2();
signed int sub_5BF50_load_psxdata();

void CleanF5538_716A0();

void CreateIndexes_6EB90(filearray_struct* a1);

//type_str_0x6E8E* pre_sub_4A190(uint32_t adress, int16_t* a1,int type);
type_event_0x6E8E* pre_sub_4A190_axis_3d(uint32_t adress, axis_3d* a1);//pre 22b190

void pre_sub_4A190_0x6E8E(uint32_t adress, type_event_0x6E8E* a1);//pre 22b190

//---------------------------

//char sub_54200();

void sub_71410_process_tmaps();
void SetCDFilePaths(const char* cdDataPath, Pathstruct pstr[]);
void initposistruct();

void Initialize();
int /*__cdecl*/ sub_main(int argc, char **argv, char **envp);

#endif //SUB_MAIN_ACTIVE
