// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2025.2 (64-bit)
// Tool Version Limit: 2025.11
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
/***************************** Include Files *********************************/
#include "xcontrol.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XControl_CfgInitialize(XControl *InstancePtr, XControl_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Ctrl_BaseAddress = ConfigPtr->Ctrl_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XControl_Start(XControl *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XControl_ReadReg(InstancePtr->Ctrl_BaseAddress, XCONTROL_CTRL_ADDR_AP_CTRL) & 0x80;
    XControl_WriteReg(InstancePtr->Ctrl_BaseAddress, XCONTROL_CTRL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XControl_IsDone(XControl *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XControl_ReadReg(InstancePtr->Ctrl_BaseAddress, XCONTROL_CTRL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XControl_IsIdle(XControl *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XControl_ReadReg(InstancePtr->Ctrl_BaseAddress, XCONTROL_CTRL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XControl_IsReady(XControl *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XControl_ReadReg(InstancePtr->Ctrl_BaseAddress, XCONTROL_CTRL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XControl_EnableAutoRestart(XControl *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XControl_WriteReg(InstancePtr->Ctrl_BaseAddress, XCONTROL_CTRL_ADDR_AP_CTRL, 0x80);
}

void XControl_DisableAutoRestart(XControl *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XControl_WriteReg(InstancePtr->Ctrl_BaseAddress, XCONTROL_CTRL_ADDR_AP_CTRL, 0);
}

void XControl_InterruptGlobalEnable(XControl *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XControl_WriteReg(InstancePtr->Ctrl_BaseAddress, XCONTROL_CTRL_ADDR_GIE, 1);
}

void XControl_InterruptGlobalDisable(XControl *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XControl_WriteReg(InstancePtr->Ctrl_BaseAddress, XCONTROL_CTRL_ADDR_GIE, 0);
}

void XControl_InterruptEnable(XControl *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XControl_ReadReg(InstancePtr->Ctrl_BaseAddress, XCONTROL_CTRL_ADDR_IER);
    XControl_WriteReg(InstancePtr->Ctrl_BaseAddress, XCONTROL_CTRL_ADDR_IER, Register | Mask);
}

void XControl_InterruptDisable(XControl *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XControl_ReadReg(InstancePtr->Ctrl_BaseAddress, XCONTROL_CTRL_ADDR_IER);
    XControl_WriteReg(InstancePtr->Ctrl_BaseAddress, XCONTROL_CTRL_ADDR_IER, Register & (~Mask));
}

void XControl_InterruptClear(XControl *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XControl_WriteReg(InstancePtr->Ctrl_BaseAddress, XCONTROL_CTRL_ADDR_ISR, Mask);
}

u32 XControl_InterruptGetEnabled(XControl *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XControl_ReadReg(InstancePtr->Ctrl_BaseAddress, XCONTROL_CTRL_ADDR_IER);
}

u32 XControl_InterruptGetStatus(XControl *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XControl_ReadReg(InstancePtr->Ctrl_BaseAddress, XCONTROL_CTRL_ADDR_ISR);
}

