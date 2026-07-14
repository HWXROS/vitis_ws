// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2025.2 (64-bit)
// Tool Version Limit: 2025.11
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#ifdef SDT
#include "xparameters.h"
#endif
#include "xcontrol.h"

extern XControl_Config XControl_ConfigTable[];

#ifdef SDT
XControl_Config *XControl_LookupConfig(UINTPTR BaseAddress) {
	XControl_Config *ConfigPtr = NULL;

	int Index;

	for (Index = (u32)0x0; XControl_ConfigTable[Index].Name != NULL; Index++) {
		if (!BaseAddress || XControl_ConfigTable[Index].Ctrl_BaseAddress == BaseAddress) {
			ConfigPtr = &XControl_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XControl_Initialize(XControl *InstancePtr, UINTPTR BaseAddress) {
	XControl_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XControl_LookupConfig(BaseAddress);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XControl_CfgInitialize(InstancePtr, ConfigPtr);
}
#else
XControl_Config *XControl_LookupConfig(u16 DeviceId) {
	XControl_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XCONTROL_NUM_INSTANCES; Index++) {
		if (XControl_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XControl_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XControl_Initialize(XControl *InstancePtr, u16 DeviceId) {
	XControl_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XControl_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XControl_CfgInitialize(InstancePtr, ConfigPtr);
}
#endif

#endif

