// Nec V20/V30/V33 interface

#include "necintrf.h"

struct VezContext {
	nec_Regs reg;
	
	unsigned char * ppMemRead[512];
	unsigned char * ppMemWrite[512];

	// Handlers
 #ifdef FASTCALL
	unsigned char (__fastcall *ReadHandler)(unsigned int a);
	void (__fastcall *WriteHandler)(unsigned int a, unsigned char d);
	unsigned char (__fastcall *ReadPort)(unsigned int a);
	void (__fastcall *WritePort)(unsigned int a, unsigned char d);
 #else
	unsigned char (__cdecl *ReadHandler)(unsigned int a);
	void (__cdecl *WriteHandler)(unsigned int a, unsigned char d);
	unsigned char (__cdecl *ReadPort)(unsigned int a);
	void (__cdecl *WritePort)(unsigned int a, unsigned char d);
 #endif
};

int VezInit(int nCount, unsigned int * typelist);
void VezExit();
void VezNewFrame();
int VezOpen(int nCPU);
void VezClose();

int VezMemCallback(int nStart,int nEnd,int nMode);
int VezMapArea(int nStart, int nEnd, int nMode, unsigned char *Mem);

void VezSetReadHandler(unsigned char (__fastcall *)(unsigned int));
void VezSetWriteHandler(void (__fastcall *)(unsigned int, unsigned char));
void VezSetReadPort(unsigned char (__fastcall *)(unsigned int));
void VezSetWritePort(void (__fastcall *)(unsigned int, unsigned char));

int VezReset();
int VezPc(int n);
int VezScan(int nAction);

int VezRun(int nCycles);

#define VEZ_IRQSTATUS_NONE 0
#define VEZ_IRQSTATUS_AUTO 1
#define VEZ_IRQSTATUS_ACK  2

void VezSetIRQLine(const int line, const int status);

