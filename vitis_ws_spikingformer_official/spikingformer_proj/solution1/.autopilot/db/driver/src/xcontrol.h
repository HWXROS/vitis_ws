// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2025.2 (64-bit)
// Tool Version Limit: 2025.11
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef XCONTROL_H
#define XCONTROL_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xcontrol_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
#ifdef SDT
    char *Name;
#else
    u16 DeviceId;
#endif
    u64 Ctrl_BaseAddress;
} XControl_Config;
#endif

typedef struct {
    u64 Ctrl_BaseAddress;
    u32 IsReady;
} XControl;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XControl_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XControl_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XControl_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XControl_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
#ifdef SDT
int XControl_Initialize(XControl *InstancePtr, UINTPTR BaseAddress);
XControl_Config* XControl_LookupConfig(UINTPTR BaseAddress);
#else
int XControl_Initialize(XControl *InstancePtr, u16 DeviceId);
XControl_Config* XControl_LookupConfig(u16 DeviceId);
#endif
int XControl_CfgInitialize(XControl *InstancePtr, XControl_Config *ConfigPtr);
#else
int XControl_Initialize(XControl *InstancePtr, const char* InstanceName);
int XControl_Release(XControl *InstancePtr);
#endif

void XControl_Start(XControl *InstancePtr);
u32 XControl_IsDone(XControl *InstancePtr);
u32 XControl_IsIdle(XControl *InstancePtr);
u32 XControl_IsReady(XControl *InstancePtr);
void XControl_EnableAutoRestart(XControl *InstancePtr);
void XControl_DisableAutoRestart(XControl *InstancePtr);


void XControl_InterruptGlobalEnable(XControl *InstancePtr);
void XControl_InterruptGlobalDisable(XControl *InstancePtr);
void XControl_InterruptEnable(XControl *InstancePtr, u32 Mask);
void XControl_InterruptDisable(XControl *InstancePtr, u32 Mask);
void XControl_InterruptClear(XControl *InstancePtr, u32 Mask);
u32 XControl_InterruptGetEnabled(XControl *InstancePtr);
u32 XControl_InterruptGetStatus(XControl *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
