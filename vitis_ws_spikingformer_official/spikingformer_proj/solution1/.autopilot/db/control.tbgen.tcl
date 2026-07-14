set moduleName control
set isTopModule 1
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set isPipelined_legacy 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set restart_counter_num 0
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set hasInterrupt 0
set DLRegFirstOffset 0
set DLRegItemOffset 0
set svuvm_can_support 1
set cdfgNum 202
set C_modelName {control}
set C_modelType { void 0 }
set ap_memory_interface_dict [dict create]
set C_modelArgList {
	{ g0 int 32 regular {axi_master 2 stable }  }
	{ v944 int 64 regular  }
	{ v945 int 64 regular  }
	{ v946 int 64 regular  }
}
set hasAXIMCache 0
set l_AXIML2Cache [list]
set AXIMCacheInstDict [dict create]
set C_modelArgMapList {[ 
	{ "Name" : "g0", "interface" : "axi_master", "bitwidth" : 32, "direction" : "READWRITE", "id_num" : 1, "bitSlice":[ {"cElement": [{"cName": "v944","offset": { "type": "dynamic","port_name": "v944"},"direction": "READWRITE"},{"cName": "v945","offset": { "type": "dynamic","port_name": "v945"},"direction": "READWRITE"},{"cName": "v946","offset": { "type": "dynamic","port_name": "v946"},"direction": "READWRITE"}]}]} , 
 	{ "Name" : "v944", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "v945", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "v946", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} ]}
# RTL Port declarations: 
set portNum 68
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst_n sc_in sc_logic 1 reset -1 active_low_sync } 
	{ m_axi_g0_AWVALID sc_out sc_logic 1 signal 0 } 
	{ m_axi_g0_AWREADY sc_in sc_logic 1 signal 0 } 
	{ m_axi_g0_AWADDR sc_out sc_lv 64 signal 0 } 
	{ m_axi_g0_AWID sc_out sc_lv 1 signal 0 } 
	{ m_axi_g0_AWLEN sc_out sc_lv 8 signal 0 } 
	{ m_axi_g0_AWSIZE sc_out sc_lv 3 signal 0 } 
	{ m_axi_g0_AWBURST sc_out sc_lv 2 signal 0 } 
	{ m_axi_g0_AWLOCK sc_out sc_lv 2 signal 0 } 
	{ m_axi_g0_AWCACHE sc_out sc_lv 4 signal 0 } 
	{ m_axi_g0_AWPROT sc_out sc_lv 3 signal 0 } 
	{ m_axi_g0_AWQOS sc_out sc_lv 4 signal 0 } 
	{ m_axi_g0_AWREGION sc_out sc_lv 4 signal 0 } 
	{ m_axi_g0_AWUSER sc_out sc_lv 1 signal 0 } 
	{ m_axi_g0_WVALID sc_out sc_logic 1 signal 0 } 
	{ m_axi_g0_WREADY sc_in sc_logic 1 signal 0 } 
	{ m_axi_g0_WDATA sc_out sc_lv 32 signal 0 } 
	{ m_axi_g0_WSTRB sc_out sc_lv 4 signal 0 } 
	{ m_axi_g0_WLAST sc_out sc_logic 1 signal 0 } 
	{ m_axi_g0_WID sc_out sc_lv 1 signal 0 } 
	{ m_axi_g0_WUSER sc_out sc_lv 1 signal 0 } 
	{ m_axi_g0_ARVALID sc_out sc_logic 1 signal 0 } 
	{ m_axi_g0_ARREADY sc_in sc_logic 1 signal 0 } 
	{ m_axi_g0_ARADDR sc_out sc_lv 64 signal 0 } 
	{ m_axi_g0_ARID sc_out sc_lv 1 signal 0 } 
	{ m_axi_g0_ARLEN sc_out sc_lv 8 signal 0 } 
	{ m_axi_g0_ARSIZE sc_out sc_lv 3 signal 0 } 
	{ m_axi_g0_ARBURST sc_out sc_lv 2 signal 0 } 
	{ m_axi_g0_ARLOCK sc_out sc_lv 2 signal 0 } 
	{ m_axi_g0_ARCACHE sc_out sc_lv 4 signal 0 } 
	{ m_axi_g0_ARPROT sc_out sc_lv 3 signal 0 } 
	{ m_axi_g0_ARQOS sc_out sc_lv 4 signal 0 } 
	{ m_axi_g0_ARREGION sc_out sc_lv 4 signal 0 } 
	{ m_axi_g0_ARUSER sc_out sc_lv 1 signal 0 } 
	{ m_axi_g0_RVALID sc_in sc_logic 1 signal 0 } 
	{ m_axi_g0_RREADY sc_out sc_logic 1 signal 0 } 
	{ m_axi_g0_RDATA sc_in sc_lv 32 signal 0 } 
	{ m_axi_g0_RLAST sc_in sc_logic 1 signal 0 } 
	{ m_axi_g0_RID sc_in sc_lv 1 signal 0 } 
	{ m_axi_g0_RUSER sc_in sc_lv 1 signal 0 } 
	{ m_axi_g0_RRESP sc_in sc_lv 2 signal 0 } 
	{ m_axi_g0_BVALID sc_in sc_logic 1 signal 0 } 
	{ m_axi_g0_BREADY sc_out sc_logic 1 signal 0 } 
	{ m_axi_g0_BRESP sc_in sc_lv 2 signal 0 } 
	{ m_axi_g0_BID sc_in sc_lv 1 signal 0 } 
	{ m_axi_g0_BUSER sc_in sc_lv 1 signal 0 } 
	{ v944 sc_in sc_lv 64 signal 1 } 
	{ v945 sc_in sc_lv 64 signal 2 } 
	{ v946 sc_in sc_lv 64 signal 3 } 
	{ s_axi_ctrl_AWVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_ctrl_AWREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_ctrl_AWADDR sc_in sc_lv 4 signal -1 } 
	{ s_axi_ctrl_WVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_ctrl_WREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_ctrl_WDATA sc_in sc_lv 32 signal -1 } 
	{ s_axi_ctrl_WSTRB sc_in sc_lv 4 signal -1 } 
	{ s_axi_ctrl_ARVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_ctrl_ARREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_ctrl_ARADDR sc_in sc_lv 4 signal -1 } 
	{ s_axi_ctrl_RVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_ctrl_RREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_ctrl_RDATA sc_out sc_lv 32 signal -1 } 
	{ s_axi_ctrl_RRESP sc_out sc_lv 2 signal -1 } 
	{ s_axi_ctrl_BVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_ctrl_BREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_ctrl_BRESP sc_out sc_lv 2 signal -1 } 
	{ interrupt sc_out sc_logic 1 signal -1 } 
}
set NewPortList {[ 
	{ "name": "s_axi_ctrl_AWADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "ctrl", "role": "AWADDR" },"address":[{"name":"control","role":"start","value":"0","valid_bit":"0"},{"name":"control","role":"continue","value":"0","valid_bit":"4"},{"name":"control","role":"auto_start","value":"0","valid_bit":"7"}] },
	{ "name": "s_axi_ctrl_AWVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ctrl", "role": "AWVALID" } },
	{ "name": "s_axi_ctrl_AWREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ctrl", "role": "AWREADY" } },
	{ "name": "s_axi_ctrl_WVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ctrl", "role": "WVALID" } },
	{ "name": "s_axi_ctrl_WREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ctrl", "role": "WREADY" } },
	{ "name": "s_axi_ctrl_WDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "ctrl", "role": "WDATA" } },
	{ "name": "s_axi_ctrl_WSTRB", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "ctrl", "role": "WSTRB" } },
	{ "name": "s_axi_ctrl_ARADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "ctrl", "role": "ARADDR" },"address":[{"name":"control","role":"start","value":"0","valid_bit":"0"},{"name":"control","role":"done","value":"0","valid_bit":"1"},{"name":"control","role":"idle","value":"0","valid_bit":"2"},{"name":"control","role":"ready","value":"0","valid_bit":"3"},{"name":"control","role":"auto_start","value":"0","valid_bit":"7"}] },
	{ "name": "s_axi_ctrl_ARVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ctrl", "role": "ARVALID" } },
	{ "name": "s_axi_ctrl_ARREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ctrl", "role": "ARREADY" } },
	{ "name": "s_axi_ctrl_RVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ctrl", "role": "RVALID" } },
	{ "name": "s_axi_ctrl_RREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ctrl", "role": "RREADY" } },
	{ "name": "s_axi_ctrl_RDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "ctrl", "role": "RDATA" } },
	{ "name": "s_axi_ctrl_RRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "ctrl", "role": "RRESP" } },
	{ "name": "s_axi_ctrl_BVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ctrl", "role": "BVALID" } },
	{ "name": "s_axi_ctrl_BREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ctrl", "role": "BREADY" } },
	{ "name": "s_axi_ctrl_BRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "ctrl", "role": "BRESP" } },
	{ "name": "interrupt", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ctrl", "role": "interrupt" } }, 
 	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst_n", "role": "default" }} , 
 	{ "name": "m_axi_g0_AWVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "AWVALID" }} , 
 	{ "name": "m_axi_g0_AWREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "AWREADY" }} , 
 	{ "name": "m_axi_g0_AWADDR", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "g0", "role": "AWADDR" }} , 
 	{ "name": "m_axi_g0_AWID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "AWID" }} , 
 	{ "name": "m_axi_g0_AWLEN", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "g0", "role": "AWLEN" }} , 
 	{ "name": "m_axi_g0_AWSIZE", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "g0", "role": "AWSIZE" }} , 
 	{ "name": "m_axi_g0_AWBURST", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "g0", "role": "AWBURST" }} , 
 	{ "name": "m_axi_g0_AWLOCK", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "g0", "role": "AWLOCK" }} , 
 	{ "name": "m_axi_g0_AWCACHE", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "g0", "role": "AWCACHE" }} , 
 	{ "name": "m_axi_g0_AWPROT", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "g0", "role": "AWPROT" }} , 
 	{ "name": "m_axi_g0_AWQOS", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "g0", "role": "AWQOS" }} , 
 	{ "name": "m_axi_g0_AWREGION", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "g0", "role": "AWREGION" }} , 
 	{ "name": "m_axi_g0_AWUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "AWUSER" }} , 
 	{ "name": "m_axi_g0_WVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "WVALID" }} , 
 	{ "name": "m_axi_g0_WREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "WREADY" }} , 
 	{ "name": "m_axi_g0_WDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "g0", "role": "WDATA" }} , 
 	{ "name": "m_axi_g0_WSTRB", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "g0", "role": "WSTRB" }} , 
 	{ "name": "m_axi_g0_WLAST", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "WLAST" }} , 
 	{ "name": "m_axi_g0_WID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "WID" }} , 
 	{ "name": "m_axi_g0_WUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "WUSER" }} , 
 	{ "name": "m_axi_g0_ARVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "ARVALID" }} , 
 	{ "name": "m_axi_g0_ARREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "ARREADY" }} , 
 	{ "name": "m_axi_g0_ARADDR", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "g0", "role": "ARADDR" }} , 
 	{ "name": "m_axi_g0_ARID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "ARID" }} , 
 	{ "name": "m_axi_g0_ARLEN", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "g0", "role": "ARLEN" }} , 
 	{ "name": "m_axi_g0_ARSIZE", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "g0", "role": "ARSIZE" }} , 
 	{ "name": "m_axi_g0_ARBURST", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "g0", "role": "ARBURST" }} , 
 	{ "name": "m_axi_g0_ARLOCK", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "g0", "role": "ARLOCK" }} , 
 	{ "name": "m_axi_g0_ARCACHE", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "g0", "role": "ARCACHE" }} , 
 	{ "name": "m_axi_g0_ARPROT", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "g0", "role": "ARPROT" }} , 
 	{ "name": "m_axi_g0_ARQOS", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "g0", "role": "ARQOS" }} , 
 	{ "name": "m_axi_g0_ARREGION", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "g0", "role": "ARREGION" }} , 
 	{ "name": "m_axi_g0_ARUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "ARUSER" }} , 
 	{ "name": "m_axi_g0_RVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "RVALID" }} , 
 	{ "name": "m_axi_g0_RREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "RREADY" }} , 
 	{ "name": "m_axi_g0_RDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "g0", "role": "RDATA" }} , 
 	{ "name": "m_axi_g0_RLAST", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "RLAST" }} , 
 	{ "name": "m_axi_g0_RID", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "RID" }} , 
 	{ "name": "m_axi_g0_RUSER", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "RUSER" }} , 
 	{ "name": "m_axi_g0_RRESP", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "g0", "role": "RRESP" }} , 
 	{ "name": "m_axi_g0_BVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "BVALID" }} , 
 	{ "name": "m_axi_g0_BREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "BREADY" }} , 
 	{ "name": "m_axi_g0_BRESP", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "g0", "role": "BRESP" }} , 
 	{ "name": "m_axi_g0_BID", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "BID" }} , 
 	{ "name": "m_axi_g0_BUSER", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "BUSER" }} , 
 	{ "name": "v944", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "v944", "role": "default" }} , 
 	{ "name": "v945", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "v945", "role": "default" }} , 
 	{ "name": "v946", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "v946", "role": "default" }}  ]}

set ArgLastReadFirstWriteLatency {
	control {
		g0 {Type IO LastRead 1717 FirstWrite -1}
		v944 {Type I LastRead 0 FirstWrite -1}
		v945 {Type I LastRead 20 FirstWrite -1}
		v946 {Type I LastRead 10 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_2299_1_VITIS_LOOP_2300_2_VITIS_LOOP_2301_3 {
		g0 {Type O LastRead -1 FirstWrite 1}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_2282_1_VITIS_LOOP_2283_2_VITIS_LOOP_2284_3 {
		g0 {Type IO LastRead 12 FirstWrite 11}
		sext_ln2286 {Type I LastRead 0 FirstWrite -1}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		v944 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_3 {
		g0 {Type I LastRead 1 FirstWrite -1}
		sext_ln2263 {Type I LastRead 0 FirstWrite -1}
		v928 {Type O LastRead -1 FirstWrite 2}}
	control_Pipeline_VITIS_LOOP_2265_1_VITIS_LOOP_2266_2_VITIS_LOOP_2267_3 {
		g0 {Type O LastRead -1 FirstWrite 3}
		sext_ln2265 {Type I LastRead 0 FirstWrite -1}
		v928 {Type I LastRead 1 FirstWrite -1}}
	control_Pipeline_5 {
		g0 {Type I LastRead 1 FirstWrite -1}
		sext_ln2231 {Type I LastRead 0 FirstWrite -1}
		v914 {Type O LastRead -1 FirstWrite 2}}
	control_Pipeline_VITIS_LOOP_2233_1_VITIS_LOOP_2234_2_VITIS_LOOP_2235_3_VITIS_LOO {
		g0 {Type IO LastRead 20 FirstWrite 19}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		sext_ln2265 {Type I LastRead 0 FirstWrite -1}
		v914 {Type I LastRead 2 FirstWrite -1}
		v944 {Type I LastRead 0 FirstWrite -1}
		v949 {Type I LastRead 0 FirstWrite -1}}
	kernel589 {
		g0 {Type IO LastRead 12 FirstWrite 11}
		v846 {Type I LastRead 0 FirstWrite -1}
		v847 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_2211_1_VITIS_LOOP_2212_2_VITIS_LOOP_2213_3 {
		g0 {Type IO LastRead 15 FirstWrite 14}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		v1159 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_2113_1_VITIS_LOOP_2114_2_VITIS_LOOP_2115_3 {
		g0 {Type IO LastRead 11 FirstWrite 16}
		sext_ln2117 {Type I LastRead 0 FirstWrite -1}
		sext_ln2113 {Type I LastRead 0 FirstWrite -1}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		v944 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_2211_1_VITIS_LOOP_2212_2_VITIS_LOOP_2213_31 {
		g0 {Type IO LastRead 15 FirstWrite 14}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		v1159 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_2191_1_VITIS_LOOP_2192_2_VITIS_LOOP_2193_3 {
		g0 {Type IO LastRead 11 FirstWrite 16}
		sext_ln2113 {Type I LastRead 0 FirstWrite -1}
		sext_ln2265 {Type I LastRead 0 FirstWrite -1}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		sext_ln2113_2 {Type I LastRead 0 FirstWrite -1}
		sext_ln2299_1 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_2173_1_VITIS_LOOP_2174_2_VITIS_LOOP_2175_3 {
		g0 {Type IO LastRead 16 FirstWrite 15}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		v1159 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_2155_1_VITIS_LOOP_2156_2_VITIS_LOOP_2157_3 {
		g0 {Type IO LastRead 14 FirstWrite 13}
		sext_ln2159 {Type I LastRead 0 FirstWrite -1}
		v1050 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_2134_1_VITIS_LOOP_2135_2_VITIS_LOOP_2136_3 {
		g0 {Type IO LastRead 14 FirstWrite 13}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		sext_ln2265 {Type I LastRead 0 FirstWrite -1}
		v1159 {Type I LastRead 0 FirstWrite -1}
		sext_ln2265_1 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_2113_1_VITIS_LOOP_2114_2_VITIS_LOOP_2115_32 {
		g0 {Type IO LastRead 11 FirstWrite 16}
		sext_ln2265 {Type I LastRead 0 FirstWrite -1}
		sext_ln2113_1 {Type I LastRead 0 FirstWrite -1}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		sext_ln2265_1 {Type I LastRead 0 FirstWrite -1}
		sext_ln2299_1 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_2093_1_VITIS_LOOP_2094_2_VITIS_LOOP_2095_3 {
		g0 {Type IO LastRead 17 FirstWrite 16}
		sext_ln2113_1 {Type I LastRead 0 FirstWrite -1}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		sext_ln2113_3 {Type I LastRead 0 FirstWrite -1}
		v1159 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_2061_1_VITIS_LOOP_2062_2_VITIS_LOOP_2063_3 {
		g0 {Type O LastRead -1 FirstWrite 1}
		sext_ln2061 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_2044_1_VITIS_LOOP_2045_2_VITIS_LOOP_2046_3 {
		g0 {Type IO LastRead 7 FirstWrite 6}
		sext_ln2159 {Type I LastRead 0 FirstWrite -1}
		sext_ln2061 {Type I LastRead 0 FirstWrite -1}
		v945 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_18 {
		g0 {Type I LastRead 1 FirstWrite -1}
		sext_ln2025 {Type I LastRead 0 FirstWrite -1}
		v830 {Type O LastRead -1 FirstWrite 2}}
	control_Pipeline_VITIS_LOOP_2027_1_VITIS_LOOP_2028_2_VITIS_LOOP_2029_3 {
		g0 {Type O LastRead -1 FirstWrite 3}
		sext_ln2027 {Type I LastRead 0 FirstWrite -1}
		v830 {Type I LastRead 1 FirstWrite -1}}
	kernel571 {
		g0 {Type IO LastRead 12 FirstWrite 11}
		v748 {Type I LastRead 0 FirstWrite -1}
		v749 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1999_5_VITIS_LOOP_2000_6 {
		g0 {Type IO LastRead 18 FirstWrite 17}
		sext_ln2061 {Type I LastRead 0 FirstWrite -1}
		sext_ln2027 {Type I LastRead 0 FirstWrite -1}
		sext_ln2004 {Type I LastRead 0 FirstWrite -1}
		zext_ln1996_1 {Type I LastRead 0 FirstWrite -1}
		phi_mul15060 {Type I LastRead 0 FirstWrite -1}
		v819 {Type I LastRead 0 FirstWrite -1}
		v945 {Type I LastRead 0 FirstWrite -1}
		zext_ln1999 {Type I LastRead 0 FirstWrite -1}
		v958 {Type I LastRead 0 FirstWrite -1}
		v824 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1975_1_VITIS_LOOP_1976_2_VITIS_LOOP_1977_3 {
		g0 {Type IO LastRead 15 FirstWrite 14}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		v1159 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1877_1_VITIS_LOOP_1878_2_VITIS_LOOP_1879_3 {
		g0 {Type IO LastRead 11 FirstWrite 16}
		sext_ln1881 {Type I LastRead 0 FirstWrite -1}
		sext_ln1877 {Type I LastRead 0 FirstWrite -1}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		v944 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1975_1_VITIS_LOOP_1976_2_VITIS_LOOP_1977_33 {
		g0 {Type IO LastRead 15 FirstWrite 14}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		v1159 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1955_1_VITIS_LOOP_1956_2_VITIS_LOOP_1957_3 {
		g0 {Type IO LastRead 17 FirstWrite 16}
		v945 {Type I LastRead 0 FirstWrite -1}
		sext_ln2299_1 {Type I LastRead 0 FirstWrite -1}
		sext_ln1877 {Type I LastRead 0 FirstWrite -1}
		sext_ln2265 {Type I LastRead 0 FirstWrite -1}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1937_1_VITIS_LOOP_1938_2_VITIS_LOOP_1939_3 {
		g0 {Type IO LastRead 16 FirstWrite 15}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		v1159 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1919_1_VITIS_LOOP_1920_2_VITIS_LOOP_1921_3 {
		g0 {Type IO LastRead 14 FirstWrite 13}
		sext_ln2159 {Type I LastRead 0 FirstWrite -1}
		v1050 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1898_1_VITIS_LOOP_1899_2_VITIS_LOOP_1900_3 {
		g0 {Type IO LastRead 14 FirstWrite 13}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		sext_ln2265 {Type I LastRead 0 FirstWrite -1}
		v1159 {Type I LastRead 0 FirstWrite -1}
		sext_ln2265_1 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1877_1_VITIS_LOOP_1878_2_VITIS_LOOP_1879_34 {
		g0 {Type IO LastRead 17 FirstWrite 16}
		v945 {Type I LastRead 0 FirstWrite -1}
		sext_ln2299_1 {Type I LastRead 0 FirstWrite -1}
		sext_ln2265 {Type I LastRead 0 FirstWrite -1}
		sext_ln1882 {Type I LastRead 0 FirstWrite -1}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1857_1_VITIS_LOOP_1858_2_VITIS_LOOP_1859_3 {
		g0 {Type IO LastRead 17 FirstWrite 16}
		sext_ln1882 {Type I LastRead 0 FirstWrite -1}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		sext_ln1882_1 {Type I LastRead 0 FirstWrite -1}
		v1159 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1825_1_VITIS_LOOP_1826_2_VITIS_LOOP_1827_3 {
		g0 {Type O LastRead -1 FirstWrite 1}
		sext_ln2061 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1808_1_VITIS_LOOP_1809_2_VITIS_LOOP_1810_3 {
		g0 {Type IO LastRead 7 FirstWrite 6}
		sext_ln2159 {Type I LastRead 0 FirstWrite -1}
		sext_ln2061 {Type I LastRead 0 FirstWrite -1}
		v945 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_32 {
		g0 {Type I LastRead 1 FirstWrite -1}
		sext_ln1789 {Type I LastRead 0 FirstWrite -1}
		v732 {Type O LastRead -1 FirstWrite 2}}
	control_Pipeline_VITIS_LOOP_1791_1_VITIS_LOOP_1792_2_VITIS_LOOP_1793_3 {
		g0 {Type O LastRead -1 FirstWrite 3}
		sext_ln2265 {Type I LastRead 0 FirstWrite -1}
		v732 {Type I LastRead 1 FirstWrite -1}}
	kernel553 {
		g0 {Type IO LastRead 12 FirstWrite 11}
		v650 {Type I LastRead 0 FirstWrite -1}
		v651 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1763_5_VITIS_LOOP_1764_6 {
		g0 {Type IO LastRead 18 FirstWrite 17}
		sext_ln2061 {Type I LastRead 0 FirstWrite -1}
		sext_ln2265 {Type I LastRead 0 FirstWrite -1}
		sext_ln1768 {Type I LastRead 0 FirstWrite -1}
		zext_ln1760_1 {Type I LastRead 0 FirstWrite -1}
		phi_mul15135 {Type I LastRead 0 FirstWrite -1}
		v721 {Type I LastRead 0 FirstWrite -1}
		v945 {Type I LastRead 0 FirstWrite -1}
		zext_ln1763 {Type I LastRead 0 FirstWrite -1}
		v949 {Type I LastRead 0 FirstWrite -1}
		v726 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1739_1_VITIS_LOOP_1740_2_VITIS_LOOP_1741_3 {
		g0 {Type IO LastRead 15 FirstWrite 14}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		v1159 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1641_1_VITIS_LOOP_1642_2_VITIS_LOOP_1643_3 {
		g0 {Type IO LastRead 11 FirstWrite 16}
		sext_ln1645 {Type I LastRead 0 FirstWrite -1}
		sext_ln2113 {Type I LastRead 0 FirstWrite -1}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		v944 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1739_1_VITIS_LOOP_1740_2_VITIS_LOOP_1741_35 {
		g0 {Type IO LastRead 15 FirstWrite 14}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		v1159 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1719_1_VITIS_LOOP_1720_2_VITIS_LOOP_1721_3 {
		g0 {Type IO LastRead 11 FirstWrite 16}
		sext_ln2113 {Type I LastRead 0 FirstWrite -1}
		sext_ln2265 {Type I LastRead 0 FirstWrite -1}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		sext_ln2113_2 {Type I LastRead 0 FirstWrite -1}
		sext_ln2299_1 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1701_1_VITIS_LOOP_1702_2_VITIS_LOOP_1703_3 {
		g0 {Type IO LastRead 16 FirstWrite 15}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		v1159 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1683_1_VITIS_LOOP_1684_2_VITIS_LOOP_1685_3 {
		g0 {Type IO LastRead 14 FirstWrite 13}
		sext_ln2159 {Type I LastRead 0 FirstWrite -1}
		v1050 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1662_1_VITIS_LOOP_1663_2_VITIS_LOOP_1664_3 {
		g0 {Type IO LastRead 14 FirstWrite 13}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		sext_ln2265 {Type I LastRead 0 FirstWrite -1}
		v1159 {Type I LastRead 0 FirstWrite -1}
		sext_ln2265_1 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1641_1_VITIS_LOOP_1642_2_VITIS_LOOP_1643_36 {
		g0 {Type IO LastRead 17 FirstWrite 16}
		v945 {Type I LastRead 0 FirstWrite -1}
		sext_ln2299_1 {Type I LastRead 0 FirstWrite -1}
		sext_ln2265 {Type I LastRead 0 FirstWrite -1}
		sext_ln1882 {Type I LastRead 0 FirstWrite -1}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1621_1_VITIS_LOOP_1622_2_VITIS_LOOP_1623_3 {
		g0 {Type IO LastRead 17 FirstWrite 16}
		sext_ln1882 {Type I LastRead 0 FirstWrite -1}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		sext_ln1882_1 {Type I LastRead 0 FirstWrite -1}
		v1159 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1589_1_VITIS_LOOP_1590_2_VITIS_LOOP_1591_3 {
		g0 {Type O LastRead -1 FirstWrite 1}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1572_1_VITIS_LOOP_1573_2_VITIS_LOOP_1574_3 {
		g0 {Type IO LastRead 12 FirstWrite 11}
		sext_ln2159 {Type I LastRead 0 FirstWrite -1}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		v944 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1557_1_VITIS_LOOP_1558_2_VITIS_LOOP_1559_3 {
		g0 {Type O LastRead -1 FirstWrite 1}
		sext_ln2265 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1534_1_VITIS_LOOP_1535_2_VITIS_LOOP_1536_3_VITIS_LOO {
		g0 {Type IO LastRead 15 FirstWrite 14}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		sext_ln2265 {Type I LastRead 0 FirstWrite -1}
		v1159 {Type I LastRead 0 FirstWrite -1}
		v949 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1518_1_VITIS_LOOP_1519_2_VITIS_LOOP_1520_3 {
		g0 {Type O LastRead -1 FirstWrite 1}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1501_1_VITIS_LOOP_1502_2_VITIS_LOOP_1503_3 {
		g0 {Type IO LastRead 7 FirstWrite 6}
		sext_ln2265 {Type I LastRead 0 FirstWrite -1}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		v944 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_50 {
		g0 {Type I LastRead 1 FirstWrite -1}
		sext_ln1482 {Type I LastRead 0 FirstWrite -1}
		v607 {Type O LastRead -1 FirstWrite 2}}
	control_Pipeline_VITIS_LOOP_1484_1_VITIS_LOOP_1485_2_VITIS_LOOP_1486_3 {
		g0 {Type O LastRead -1 FirstWrite 3}
		sext_ln2265 {Type I LastRead 0 FirstWrite -1}
		v607 {Type I LastRead 1 FirstWrite -1}}
	kernel531 {
		g0 {Type IO LastRead 12 FirstWrite 11}
		v525 {Type I LastRead 0 FirstWrite -1}
		v526 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1456_5_VITIS_LOOP_1457_6 {
		g0 {Type IO LastRead 18 FirstWrite 17}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		sext_ln2265 {Type I LastRead 0 FirstWrite -1}
		sext_ln1461 {Type I LastRead 0 FirstWrite -1}
		zext_ln1453_1 {Type I LastRead 0 FirstWrite -1}
		phi_mul15231 {Type I LastRead 0 FirstWrite -1}
		v596 {Type I LastRead 0 FirstWrite -1}
		v944 {Type I LastRead 0 FirstWrite -1}
		zext_ln1456 {Type I LastRead 0 FirstWrite -1}
		v949 {Type I LastRead 0 FirstWrite -1}
		v601 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1432_1_VITIS_LOOP_1433_2_VITIS_LOOP_1434_3 {
		g0 {Type IO LastRead 15 FirstWrite 14}
		sext_ln2061 {Type I LastRead 0 FirstWrite -1}
		v1021 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1334_1_VITIS_LOOP_1335_2_VITIS_LOOP_1336_3 {
		g0 {Type IO LastRead 11 FirstWrite 16}
		sext_ln1334 {Type I LastRead 0 FirstWrite -1}
		sext_ln2113_1 {Type I LastRead 0 FirstWrite -1}
		sext_ln2061 {Type I LastRead 0 FirstWrite -1}
		sext_ln1334_1 {Type I LastRead 0 FirstWrite -1}
		sext_ln2061_1 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1432_1_VITIS_LOOP_1433_2_VITIS_LOOP_1434_37 {
		g0 {Type IO LastRead 15 FirstWrite 14}
		sext_ln2061 {Type I LastRead 0 FirstWrite -1}
		v1021 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1412_1_VITIS_LOOP_1413_2_VITIS_LOOP_1414_3 {
		g0 {Type IO LastRead 11 FirstWrite 16}
		sext_ln2113_1 {Type I LastRead 0 FirstWrite -1}
		sext_ln2027 {Type I LastRead 0 FirstWrite -1}
		sext_ln2061 {Type I LastRead 0 FirstWrite -1}
		sext_ln2113_3 {Type I LastRead 0 FirstWrite -1}
		sext_ln2061_1 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1394_1_VITIS_LOOP_1395_2_VITIS_LOOP_1396_3 {
		g0 {Type IO LastRead 16 FirstWrite 15}
		sext_ln2061 {Type I LastRead 0 FirstWrite -1}
		v1021 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1376_1_VITIS_LOOP_1377_2_VITIS_LOOP_1378_3 {
		g0 {Type IO LastRead 14 FirstWrite 13}
		sext_ln1882 {Type I LastRead 0 FirstWrite -1}
		v1154 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1355_1_VITIS_LOOP_1356_2_VITIS_LOOP_1357_3 {
		g0 {Type IO LastRead 14 FirstWrite 13}
		sext_ln2061 {Type I LastRead 0 FirstWrite -1}
		sext_ln2027 {Type I LastRead 0 FirstWrite -1}
		v1021 {Type I LastRead 0 FirstWrite -1}
		sext_ln2027_1 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1334_1_VITIS_LOOP_1335_2_VITIS_LOOP_1336_38 {
		g0 {Type IO LastRead 17 FirstWrite 16}
		v944 {Type I LastRead 0 FirstWrite -1}
		sext_ln2061_1 {Type I LastRead 0 FirstWrite -1}
		sext_ln2027 {Type I LastRead 0 FirstWrite -1}
		sext_ln1339 {Type I LastRead 0 FirstWrite -1}
		sext_ln2061 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1314_1_VITIS_LOOP_1315_2_VITIS_LOOP_1316_3 {
		g0 {Type IO LastRead 17 FirstWrite 16}
		sext_ln1339 {Type I LastRead 0 FirstWrite -1}
		sext_ln2061 {Type I LastRead 0 FirstWrite -1}
		sext_ln1339_1 {Type I LastRead 0 FirstWrite -1}
		v1021 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1282_1_VITIS_LOOP_1283_2_VITIS_LOOP_1284_3 {
		g0 {Type O LastRead -1 FirstWrite 1}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1267_1_VITIS_LOOP_1268_2_VITIS_LOOP_1269_3 {
		g0 {Type IO LastRead 7 FirstWrite 6}
		sext_ln1882 {Type I LastRead 0 FirstWrite -1}
		v944 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1252_1_VITIS_LOOP_1253_2_VITIS_LOOP_1254_3 {
		g0 {Type O LastRead -1 FirstWrite 1}
		sext_ln2027 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1229_1_VITIS_LOOP_1230_2_VITIS_LOOP_1231_3_VITIS_LOO {
		g0 {Type IO LastRead 15 FirstWrite 14}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		sext_ln2027 {Type I LastRead 0 FirstWrite -1}
		v1159 {Type I LastRead 0 FirstWrite -1}
		v958 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1213_1_VITIS_LOOP_1214_2_VITIS_LOOP_1215_3 {
		g0 {Type O LastRead -1 FirstWrite 1}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1196_1_VITIS_LOOP_1197_2_VITIS_LOOP_1198_3 {
		g0 {Type IO LastRead 12 FirstWrite 11}
		sext_ln2027 {Type I LastRead 0 FirstWrite -1}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		v944 {Type I LastRead 0 FirstWrite -1}}
	kernel9 {
		g0 {Type IO LastRead 13 FirstWrite -1}
		v61 {Type I LastRead 0 FirstWrite -1}
		v62 {Type I LastRead 10 FirstWrite -1}}
	kernel9_Pipeline_1 {
		g0 {Type I LastRead 1 FirstWrite -1}
		sext_ln171 {Type I LastRead 0 FirstWrite -1}
		v63 {Type O LastRead -1 FirstWrite 2}}
	kernel9_Pipeline_VITIS_LOOP_173_1_VITIS_LOOP_174_2_VITIS_LOOP_175_3 {
		g0 {Type O LastRead -1 FirstWrite 3}
		sext_ln173 {Type I LastRead 0 FirstWrite -1}
		v63 {Type I LastRead 1 FirstWrite -1}}
	kernel26 {
		g0 {Type IO LastRead 12 FirstWrite 11}
		v153 {Type I LastRead 0 FirstWrite -1}
		v154 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1172_5_VITIS_LOOP_1173_6 {
		g0 {Type IO LastRead 18 FirstWrite 17}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		sext_ln1877 {Type I LastRead 0 FirstWrite -1}
		sext_ln1177 {Type I LastRead 0 FirstWrite -1}
		zext_ln1169_1 {Type I LastRead 0 FirstWrite -1}
		phi_mul15319 {Type I LastRead 0 FirstWrite -1}
		v478 {Type I LastRead 0 FirstWrite -1}
		v944 {Type I LastRead 0 FirstWrite -1}
		zext_ln1172 {Type I LastRead 0 FirstWrite -1}
		v992 {Type I LastRead 0 FirstWrite -1}
		v483 {Type I LastRead 0 FirstWrite -1}}
	kernel35 {
		g0 {Type IO LastRead 15 FirstWrite 14}
		v203 {Type I LastRead 0 FirstWrite -1}}
	kernel28 {
		g0 {Type IO LastRead 17 FirstWrite 16}
		v159 {Type I LastRead 0 FirstWrite -1}
		v160 {Type I LastRead 0 FirstWrite -1}
		v161 {Type I LastRead 0 FirstWrite -1}}
	kernel34 {
		g0 {Type IO LastRead 17 FirstWrite 16}
		v194 {Type I LastRead 0 FirstWrite -1}
		v195 {Type I LastRead 0 FirstWrite -1}
		v196 {Type I LastRead 0 FirstWrite -1}}
	kernel32 {
		g0 {Type IO LastRead 16 FirstWrite 15}
		v187 {Type I LastRead 0 FirstWrite -1}}
	kernel30 {
		g0 {Type IO LastRead 14 FirstWrite 13}
		v178 {Type I LastRead 0 FirstWrite -1}}
	kernel29 {
		g0 {Type IO LastRead 14 FirstWrite 13}
		v168 {Type I LastRead 0 FirstWrite -1}
		v169 {Type I LastRead 0 FirstWrite -1}}
	kernel7 {
		g0 {Type IO LastRead 17 FirstWrite 16}
		v40 {Type I LastRead 0 FirstWrite -1}
		v41 {Type I LastRead 0 FirstWrite -1}}
	kernel42 {
		g0 {Type IO LastRead 13 FirstWrite -1}
		v231 {Type I LastRead 0 FirstWrite -1}
		v232 {Type I LastRead 10 FirstWrite -1}}
	kernel42_Pipeline_1 {
		g0 {Type I LastRead 1 FirstWrite -1}
		sext_ln571 {Type I LastRead 0 FirstWrite -1}
		v233 {Type O LastRead -1 FirstWrite 2}}
	kernel42_Pipeline_VITIS_LOOP_573_1_VITIS_LOOP_574_2 {
		g0 {Type O LastRead -1 FirstWrite 2}
		sext_ln573 {Type I LastRead 0 FirstWrite -1}
		v233 {Type I LastRead 0 FirstWrite -1}}
	kernel83 {
		g0 {Type IO LastRead 18 FirstWrite 17}
		v438 {Type I LastRead 0 FirstWrite -1}
		v439 {Type I LastRead 0 FirstWrite -1}
		v440 {Type I LastRead 0 FirstWrite -1}}
	kernel83_Pipeline_VITIS_LOOP_1081_3 {
		g0 {Type IO LastRead 18 FirstWrite 17}
		sext_ln1083 {Type I LastRead 0 FirstWrite -1}
		sext_ln1084 {Type I LastRead 0 FirstWrite -1}
		sext_ln1085 {Type I LastRead 0 FirstWrite -1}
		zext_ln1080 {Type I LastRead 0 FirstWrite -1}
		v438 {Type I LastRead 0 FirstWrite -1}
		v440 {Type I LastRead 0 FirstWrite -1}
		zext_ln1081 {Type I LastRead 0 FirstWrite -1}
		v446 {Type I LastRead 0 FirstWrite -1}}
	kernel69 {
		g0 {Type IO LastRead 11 FirstWrite 10}
		v381 {Type I LastRead 0 FirstWrite -1}
		v382 {Type I LastRead 0 FirstWrite -1}}
	kernel78 {
		g0 {Type IO LastRead 14 FirstWrite 13}
		v432 {Type I LastRead 0 FirstWrite -1}}
	kernel71 {
		g0 {Type IO LastRead 16 FirstWrite 15}
		v393 {Type I LastRead 0 FirstWrite -1}
		v394 {Type I LastRead 0 FirstWrite -1}
		v395 {Type I LastRead 0 FirstWrite -1}}
	kernel77 {
		g0 {Type IO LastRead 16 FirstWrite 15}
		v424 {Type I LastRead 0 FirstWrite -1}
		v425 {Type I LastRead 0 FirstWrite -1}
		v426 {Type I LastRead 0 FirstWrite -1}}
	kernel75 {
		g0 {Type IO LastRead 15 FirstWrite 14}
		v418 {Type I LastRead 0 FirstWrite -1}}
	kernel73 {
		g0 {Type IO LastRead 13 FirstWrite 12}
		v410 {Type I LastRead 0 FirstWrite -1}}
	kernel72 {
		g0 {Type IO LastRead 13 FirstWrite 12}
		v401 {Type I LastRead 0 FirstWrite -1}
		v402 {Type I LastRead 0 FirstWrite -1}}
	kernel70 {
		g0 {Type IO LastRead 16 FirstWrite 15}
		v386 {Type I LastRead 0 FirstWrite -1}
		v387 {Type I LastRead 0 FirstWrite -1}}
	kernel68 {
		g0 {Type IO LastRead 11 FirstWrite 10}
		v376 {Type I LastRead 0 FirstWrite -1}
		v377 {Type I LastRead 0 FirstWrite -1}}
	kernel67 {
		g0 {Type IO LastRead 10 FirstWrite 11}
		v370 {Type I LastRead 1 FirstWrite -1}
		v371 {Type I LastRead 0 FirstWrite -1}}
	kernel67_Pipeline_VITIS_LOOP_911_1_VITIS_LOOP_912_2_VITIS_LOOP_913_3 {
		g0 {Type IO LastRead 10 FirstWrite 11}
		sext_ln915 {Type I LastRead 0 FirstWrite -1}
		sext_ln911 {Type I LastRead 0 FirstWrite -1}
		v370 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_897_1_VITIS_LOOP_898_2_VITIS_LOOP_899_3 {
		g0 {Type IO LastRead 10 FirstWrite 11}
		sext_ln897 {Type I LastRead 0 FirstWrite -1}
		v1015 {Type I LastRead 0 FirstWrite -1}}
	kernel61 {
		g0 {Type IO LastRead 10 FirstWrite 2}
		v333 {Type I LastRead 0 FirstWrite -1}
		v334 {Type I LastRead 7 FirstWrite -1}}
	kernel61_Pipeline_VITIS_LOOP_819_1_VITIS_LOOP_820_2_VITIS_LOOP_821_3 {
		g0 {Type IO LastRead 1 FirstWrite 2}
		sext_ln819 {Type I LastRead 0 FirstWrite -1}
		sext_ln819_1 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_880_1_VITIS_LOOP_881_2_VITIS_LOOP_882_3 {
		g0 {Type IO LastRead 1 FirstWrite 2}
		sext_ln897 {Type I LastRead 0 FirstWrite -1}
		sext_ln880 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1150_1_VITIS_LOOP_1151_2_VITIS_LOOP_1152_3 {
		g0 {Type O LastRead -1 FirstWrite 1}
		sext_ln1150 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1118_1_VITIS_LOOP_1119_2_VITIS_LOOP_1120_3 {
		g0 {Type IO LastRead 1 FirstWrite 2}
		sext_ln1150 {Type I LastRead 0 FirstWrite -1}
		sext_ln897 {Type I LastRead 0 FirstWrite -1}}
	kernel63 {
		g0 {Type IO LastRead 20 FirstWrite 19}
		v345 {Type I LastRead 0 FirstWrite -1}
		v346 {Type I LastRead 0 FirstWrite -1}
		v347 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_836_1_VITIS_LOOP_837_2_VITIS_LOOP_838_3 {
		g0 {Type IO LastRead 12 FirstWrite 11}
		sext_ln897 {Type I LastRead 0 FirstWrite -1}
		sext_ln841 {Type I LastRead 0 FirstWrite -1}
		v945 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1135_1_VITIS_LOOP_1136_2_VITIS_LOOP_1137_3 {
		g0 {Type O LastRead -1 FirstWrite 1}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1101_1_VITIS_LOOP_1102_2_VITIS_LOOP_1103_3 {
		g0 {Type IO LastRead 1 FirstWrite 2}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		sext_ln897 {Type I LastRead 0 FirstWrite -1}}
	kernel60 {
		g0 {Type IO LastRead 20 FirstWrite 19}
		v320 {Type I LastRead 0 FirstWrite -1}
		v321 {Type I LastRead 0 FirstWrite -1}
		v322 {Type I LastRead 0 FirstWrite -1}}
	kernel59 {
		g0 {Type IO LastRead 15 FirstWrite 14}
		v310 {Type I LastRead 0 FirstWrite -1}
		v311_val {Type I LastRead 0 FirstWrite -1}
		v312 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_751_1_VITIS_LOOP_752_2_VITIS_LOOP_753_3 {
		g0 {Type IO LastRead 10 FirstWrite 11}
		sext_ln755 {Type I LastRead 0 FirstWrite -1}
		sext_ln897 {Type I LastRead 0 FirstWrite -1}
		v944 {Type I LastRead 0 FirstWrite -1}}
	kernel44 {
		g0 {Type IO LastRead 11 FirstWrite 10}
		v242 {Type I LastRead 0 FirstWrite -1}
		v243 {Type I LastRead 0 FirstWrite -1}}
	kernel53 {
		g0 {Type IO LastRead 14 FirstWrite 13}
		v293 {Type I LastRead 0 FirstWrite -1}}
	kernel46 {
		g0 {Type IO LastRead 10 FirstWrite 15}
		v254 {Type I LastRead 1 FirstWrite -1}
		v255 {Type I LastRead 1 FirstWrite -1}
		v256 {Type I LastRead 0 FirstWrite -1}}
	kernel46_Pipeline_VITIS_LOOP_633_1_VITIS_LOOP_634_2 {
		g0 {Type IO LastRead 10 FirstWrite 15}
		sext_ln636 {Type I LastRead 0 FirstWrite -1}
		sext_ln633 {Type I LastRead 0 FirstWrite -1}
		sext_ln638 {Type I LastRead 0 FirstWrite -1}
		v255 {Type I LastRead 0 FirstWrite -1}
		v254 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_736_1_VITIS_LOOP_737_2 {
		g0 {Type IO LastRead 9 FirstWrite 10}
		sext_ln897 {Type I LastRead 0 FirstWrite -1}
		sext_ln736 {Type I LastRead 0 FirstWrite -1}
		v1013 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_703_1_VITIS_LOOP_704_2 {
		g0 {Type IO LastRead 10 FirstWrite 15}
		sext_ln703 {Type I LastRead 0 FirstWrite -1}
		sext_ln703_1 {Type I LastRead 0 FirstWrite -1}
		sext_ln736 {Type I LastRead 0 FirstWrite -1}
		sext_ln703_5 {Type I LastRead 0 FirstWrite -1}
		sext_ln736_1 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_687_1_VITIS_LOOP_688_2 {
		g0 {Type IO LastRead 15 FirstWrite 14}
		sext_ln736 {Type I LastRead 0 FirstWrite -1}
		v1007 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_671_1_VITIS_LOOP_672_2 {
		g0 {Type IO LastRead 13 FirstWrite 12}
		sext_ln674 {Type I LastRead 0 FirstWrite -1}
		v1035 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_652_1_VITIS_LOOP_653_2 {
		g0 {Type IO LastRead 13 FirstWrite 12}
		sext_ln736 {Type I LastRead 0 FirstWrite -1}
		sext_ln703_1 {Type I LastRead 0 FirstWrite -1}
		v1007 {Type I LastRead 0 FirstWrite -1}
		sext_ln703_6 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_615_1_VITIS_LOOP_616_2 {
		g0 {Type IO LastRead 16 FirstWrite 15}
		sext_ln615 {Type I LastRead 0 FirstWrite -1}
		sext_ln736 {Type I LastRead 0 FirstWrite -1}
		sext_ln615_3 {Type I LastRead 0 FirstWrite -1}
		v1007 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_588_1_VITIS_LOOP_589_2 {
		g0 {Type IO LastRead 9 FirstWrite 10}
		sext_ln703_1 {Type I LastRead 0 FirstWrite -1}
		v1035 {Type I LastRead 0 FirstWrite -1}}
	kernel41 {
		g0 {Type IO LastRead 18 FirstWrite 17}
		v219 {Type I LastRead 0 FirstWrite -1}
		v220 {Type I LastRead 0 FirstWrite -1}
		v221 {Type I LastRead 0 FirstWrite -1}}
	kernel41_Pipeline_VITIS_LOOP_549_3 {
		g0 {Type IO LastRead 18 FirstWrite 17}
		sext_ln551 {Type I LastRead 0 FirstWrite -1}
		sext_ln552 {Type I LastRead 0 FirstWrite -1}
		sext_ln553 {Type I LastRead 0 FirstWrite -1}
		v219 {Type I LastRead 0 FirstWrite -1}
		zext_ln548 {Type I LastRead 0 FirstWrite -1}
		v221 {Type I LastRead 0 FirstWrite -1}
		zext_ln549 {Type I LastRead 0 FirstWrite -1}
		v227 {Type I LastRead 0 FirstWrite -1}}
	kernel40 {
		g0 {Type IO LastRead 11 FirstWrite 16}
		v210 {Type I LastRead 1 FirstWrite -1}
		v211 {Type I LastRead 1 FirstWrite -1}
		v212 {Type I LastRead 0 FirstWrite -1}}
	kernel40_Pipeline_VITIS_LOOP_524_1_VITIS_LOOP_525_2_VITIS_LOOP_526_3 {
		g0 {Type IO LastRead 11 FirstWrite 16}
		sext_ln524 {Type I LastRead 0 FirstWrite -1}
		sext_ln524_2 {Type I LastRead 0 FirstWrite -1}
		sext_ln524_1 {Type I LastRead 0 FirstWrite -1}
		sext_ln524_3 {Type I LastRead 0 FirstWrite -1}
		sext_ln524_4 {Type I LastRead 0 FirstWrite -1}}
	kernel25 {
		g0 {Type IO LastRead 13 FirstWrite -1}
		v146 {Type I LastRead 0 FirstWrite -1}
		v147 {Type I LastRead 10 FirstWrite -1}}
	kernel25_Pipeline_1 {
		g0 {Type I LastRead 1 FirstWrite -1}
		sext_ln371 {Type I LastRead 0 FirstWrite -1}
		v148 {Type O LastRead -1 FirstWrite 2}}
	kernel25_Pipeline_VITIS_LOOP_373_1_VITIS_LOOP_374_2_VITIS_LOOP_375_3 {
		g0 {Type O LastRead -1 FirstWrite 3}
		sext_ln373 {Type I LastRead 0 FirstWrite -1}
		v148 {Type I LastRead 1 FirstWrite -1}}
	kernel24 {
		g0 {Type IO LastRead 18 FirstWrite 17}
		v133 {Type I LastRead 0 FirstWrite -1}
		v134 {Type I LastRead 0 FirstWrite -1}
		v135 {Type I LastRead 0 FirstWrite -1}}
	kernel24_Pipeline_VITIS_LOOP_347_3_VITIS_LOOP_348_4 {
		g0 {Type IO LastRead 18 FirstWrite 17}
		sext_ln350 {Type I LastRead 0 FirstWrite -1}
		sext_ln351 {Type I LastRead 0 FirstWrite -1}
		sext_ln352 {Type I LastRead 0 FirstWrite -1}
		zext_ln346 {Type I LastRead 0 FirstWrite -1}
		v133 {Type I LastRead 0 FirstWrite -1}
		zext_ln347 {Type I LastRead 0 FirstWrite -1}
		v135 {Type I LastRead 0 FirstWrite -1}
		v142 {Type I LastRead 0 FirstWrite -1}}
	kernel10 {
		g0 {Type IO LastRead 12 FirstWrite 11}
		v68 {Type I LastRead 0 FirstWrite -1}
		v69 {Type I LastRead 0 FirstWrite -1}}
	kernel19 {
		g0 {Type IO LastRead 15 FirstWrite 14}
		v126 {Type I LastRead 0 FirstWrite -1}}
	kernel12 {
		g0 {Type IO LastRead 17 FirstWrite 16}
		v82 {Type I LastRead 0 FirstWrite -1}
		v83 {Type I LastRead 0 FirstWrite -1}
		v84 {Type I LastRead 0 FirstWrite -1}}
	kernel18 {
		g0 {Type IO LastRead 17 FirstWrite 16}
		v117 {Type I LastRead 0 FirstWrite -1}
		v118 {Type I LastRead 0 FirstWrite -1}
		v119 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_287_1_VITIS_LOOP_288_2_VITIS_LOOP_289_3 {
		g0 {Type IO LastRead 16 FirstWrite 15}
		sext_ln2159 {Type I LastRead 0 FirstWrite -1}
		v1050 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_269_1_VITIS_LOOP_270_2_VITIS_LOOP_271_3 {
		g0 {Type IO LastRead 14 FirstWrite 13}
		sext_ln273 {Type I LastRead 0 FirstWrite -1}
		v1117 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_248_1_VITIS_LOOP_249_2_VITIS_LOOP_250_3 {
		g0 {Type IO LastRead 14 FirstWrite 13}
		sext_ln2159 {Type I LastRead 0 FirstWrite -1}
		sext_ln703_1 {Type I LastRead 0 FirstWrite -1}
		v1050 {Type I LastRead 0 FirstWrite -1}
		sext_ln703_6 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_207_1_VITIS_LOOP_208_2_VITIS_LOOP_209_3 {
		g0 {Type IO LastRead 17 FirstWrite 16}
		sext_ln207 {Type I LastRead 0 FirstWrite -1}
		sext_ln2159 {Type I LastRead 0 FirstWrite -1}
		sext_ln207_1 {Type I LastRead 0 FirstWrite -1}
		v1050 {Type I LastRead 0 FirstWrite -1}}
	kernel8 {
		g0 {Type IO LastRead 18 FirstWrite 17}
		v48 {Type I LastRead 0 FirstWrite -1}
		v49 {Type I LastRead 0 FirstWrite -1}
		v50 {Type I LastRead 0 FirstWrite -1}}
	kernel8_Pipeline_VITIS_LOOP_147_3_VITIS_LOOP_148_4 {
		g0 {Type IO LastRead 18 FirstWrite 17}
		sext_ln150 {Type I LastRead 0 FirstWrite -1}
		sext_ln151 {Type I LastRead 0 FirstWrite -1}
		sext_ln152 {Type I LastRead 0 FirstWrite -1}
		sext_ln146 {Type I LastRead 0 FirstWrite -1}
		zext_ln147_1 {Type I LastRead 0 FirstWrite -1}
		v50 {Type I LastRead 0 FirstWrite -1}
		v57 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_897_1_VITIS_LOOP_898_2_VITIS_LOOP_899_39 {
		g0 {Type IO LastRead 10 FirstWrite 11}
		sext_ln897_1 {Type I LastRead 0 FirstWrite -1}
		v1059 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_880_1_VITIS_LOOP_881_2_VITIS_LOOP_882_310 {
		g0 {Type IO LastRead 12 FirstWrite 11}
		sext_ln897_1 {Type I LastRead 0 FirstWrite -1}
		sext_ln880 {Type I LastRead 0 FirstWrite -1}
		v944 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1118_1_VITIS_LOOP_1119_2_VITIS_LOOP_1120_311 {
		g0 {Type IO LastRead 12 FirstWrite 11}
		sext_ln1150 {Type I LastRead 0 FirstWrite -1}
		sext_ln1123 {Type I LastRead 0 FirstWrite -1}
		v944 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_836_1_VITIS_LOOP_837_2_VITIS_LOOP_838_312 {
		g0 {Type IO LastRead 1 FirstWrite 2}
		sext_ln1123 {Type I LastRead 0 FirstWrite -1}
		sext_ln841 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1101_1_VITIS_LOOP_1102_2_VITIS_LOOP_1103_313 {
		g0 {Type IO LastRead 1 FirstWrite 2}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		sext_ln703 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_751_1_VITIS_LOOP_752_2_VITIS_LOOP_753_314 {
		g0 {Type IO LastRead 10 FirstWrite 11}
		sext_ln755 {Type I LastRead 0 FirstWrite -1}
		sext_ln897 {Type I LastRead 0 FirstWrite -1}
		v944 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_736_1_VITIS_LOOP_737_215 {
		g0 {Type IO LastRead 9 FirstWrite 10}
		sext_ln897 {Type I LastRead 0 FirstWrite -1}
		sext_ln736 {Type I LastRead 0 FirstWrite -1}
		v1013 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_703_1_VITIS_LOOP_704_216 {
		g0 {Type IO LastRead 10 FirstWrite 15}
		sext_ln703_2 {Type I LastRead 0 FirstWrite -1}
		sext_ln615 {Type I LastRead 0 FirstWrite -1}
		sext_ln736 {Type I LastRead 0 FirstWrite -1}
		sext_ln703_7 {Type I LastRead 0 FirstWrite -1}
		sext_ln736_1 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_687_1_VITIS_LOOP_688_217 {
		g0 {Type IO LastRead 15 FirstWrite 14}
		sext_ln736 {Type I LastRead 0 FirstWrite -1}
		v1007 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_671_1_VITIS_LOOP_672_218 {
		g0 {Type IO LastRead 13 FirstWrite 12}
		sext_ln703_2 {Type I LastRead 0 FirstWrite -1}
		v1057 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_652_1_VITIS_LOOP_653_219 {
		g0 {Type IO LastRead 13 FirstWrite 12}
		sext_ln736 {Type I LastRead 0 FirstWrite -1}
		sext_ln615 {Type I LastRead 0 FirstWrite -1}
		v1007 {Type I LastRead 0 FirstWrite -1}
		sext_ln615_3 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_615_1_VITIS_LOOP_616_220 {
		g0 {Type IO LastRead 16 FirstWrite 15}
		sext_ln615_1 {Type I LastRead 0 FirstWrite -1}
		sext_ln736 {Type I LastRead 0 FirstWrite -1}
		sext_ln615_4 {Type I LastRead 0 FirstWrite -1}
		v1007 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_588_1_VITIS_LOOP_589_221 {
		g0 {Type IO LastRead 9 FirstWrite 10}
		sext_ln1123 {Type I LastRead 0 FirstWrite -1}
		v1057 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_287_1_VITIS_LOOP_288_2_VITIS_LOOP_289_322 {
		g0 {Type IO LastRead 16 FirstWrite 15}
		sext_ln2159 {Type I LastRead 0 FirstWrite -1}
		v1050 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_269_1_VITIS_LOOP_270_2_VITIS_LOOP_271_323 {
		g0 {Type IO LastRead 14 FirstWrite 13}
		sext_ln703_1 {Type I LastRead 0 FirstWrite -1}
		v1046 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_248_1_VITIS_LOOP_249_2_VITIS_LOOP_250_324 {
		g0 {Type IO LastRead 14 FirstWrite 13}
		sext_ln2159 {Type I LastRead 0 FirstWrite -1}
		sext_ln273 {Type I LastRead 0 FirstWrite -1}
		v1050 {Type I LastRead 0 FirstWrite -1}
		sext_ln273_1 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_207_1_VITIS_LOOP_208_2_VITIS_LOOP_209_325 {
		g0 {Type IO LastRead 17 FirstWrite 16}
		sext_ln207 {Type I LastRead 0 FirstWrite -1}
		sext_ln2159 {Type I LastRead 0 FirstWrite -1}
		sext_ln207_1 {Type I LastRead 0 FirstWrite -1}
		v1050 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_897_1_VITIS_LOOP_898_2_VITIS_LOOP_899_326 {
		g0 {Type IO LastRead 10 FirstWrite 11}
		sext_ln897_2 {Type I LastRead 0 FirstWrite -1}
		v1104 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_880_1_VITIS_LOOP_881_2_VITIS_LOOP_882_327 {
		g0 {Type IO LastRead 1 FirstWrite 2}
		sext_ln897_2 {Type I LastRead 0 FirstWrite -1}
		sext_ln880 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1118_1_VITIS_LOOP_1119_2_VITIS_LOOP_1120_328 {
		g0 {Type IO LastRead 1 FirstWrite 2}
		sext_ln1150 {Type I LastRead 0 FirstWrite -1}
		sext_ln273 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_836_1_VITIS_LOOP_837_2_VITIS_LOOP_838_329 {
		g0 {Type IO LastRead 12 FirstWrite 11}
		sext_ln273 {Type I LastRead 0 FirstWrite -1}
		sext_ln841 {Type I LastRead 0 FirstWrite -1}
		v945 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_1101_1_VITIS_LOOP_1102_2_VITIS_LOOP_1103_330 {
		g0 {Type IO LastRead 1 FirstWrite 2}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		sext_ln703_2 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_751_1_VITIS_LOOP_752_2_VITIS_LOOP_753_331 {
		g0 {Type IO LastRead 10 FirstWrite 11}
		sext_ln755 {Type I LastRead 0 FirstWrite -1}
		sext_ln897 {Type I LastRead 0 FirstWrite -1}
		v944 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_736_1_VITIS_LOOP_737_232 {
		g0 {Type IO LastRead 9 FirstWrite 10}
		sext_ln897 {Type I LastRead 0 FirstWrite -1}
		sext_ln736 {Type I LastRead 0 FirstWrite -1}
		v1013 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_703_1_VITIS_LOOP_704_233 {
		g0 {Type IO LastRead 16 FirstWrite 15}
		v1057 {Type I LastRead 0 FirstWrite -1}
		sext_ln736_1 {Type I LastRead 0 FirstWrite -1}
		sext_ln703_2 {Type I LastRead 0 FirstWrite -1}
		sext_ln273 {Type I LastRead 0 FirstWrite -1}
		sext_ln736 {Type I LastRead 0 FirstWrite -1}
		v1117 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_687_1_VITIS_LOOP_688_234 {
		g0 {Type IO LastRead 15 FirstWrite 14}
		sext_ln736 {Type I LastRead 0 FirstWrite -1}
		v1007 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_671_1_VITIS_LOOP_672_235 {
		g0 {Type IO LastRead 13 FirstWrite 12}
		sext_ln674 {Type I LastRead 0 FirstWrite -1}
		v1035 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_652_1_VITIS_LOOP_653_236 {
		g0 {Type IO LastRead 13 FirstWrite 12}
		sext_ln736 {Type I LastRead 0 FirstWrite -1}
		sext_ln273 {Type I LastRead 0 FirstWrite -1}
		v1007 {Type I LastRead 0 FirstWrite -1}
		sext_ln273_1 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_615_1_VITIS_LOOP_616_237 {
		g0 {Type IO LastRead 16 FirstWrite 15}
		sext_ln207 {Type I LastRead 0 FirstWrite -1}
		sext_ln736 {Type I LastRead 0 FirstWrite -1}
		sext_ln207_1 {Type I LastRead 0 FirstWrite -1}
		v1007 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_588_1_VITIS_LOOP_589_238 {
		g0 {Type IO LastRead 9 FirstWrite 10}
		sext_ln273 {Type I LastRead 0 FirstWrite -1}
		v1035 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_287_1_VITIS_LOOP_288_2_VITIS_LOOP_289_339 {
		g0 {Type IO LastRead 16 FirstWrite 15}
		sext_ln2159 {Type I LastRead 0 FirstWrite -1}
		v1050 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_269_1_VITIS_LOOP_270_2_VITIS_LOOP_271_340 {
		g0 {Type IO LastRead 14 FirstWrite 13}
		sext_ln703_1 {Type I LastRead 0 FirstWrite -1}
		v1046 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_248_1_VITIS_LOOP_249_2_VITIS_LOOP_250_341 {
		g0 {Type IO LastRead 14 FirstWrite 13}
		sext_ln2159 {Type I LastRead 0 FirstWrite -1}
		sext_ln273 {Type I LastRead 0 FirstWrite -1}
		v1050 {Type I LastRead 0 FirstWrite -1}
		sext_ln273_1 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_207_1_VITIS_LOOP_208_2_VITIS_LOOP_209_342 {
		g0 {Type IO LastRead 17 FirstWrite 16}
		sext_ln615_1 {Type I LastRead 0 FirstWrite -1}
		sext_ln2159 {Type I LastRead 0 FirstWrite -1}
		sext_ln615_4 {Type I LastRead 0 FirstWrite -1}
		v1050 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_897_1_VITIS_LOOP_898_2_VITIS_LOOP_899_343 {
		g0 {Type IO LastRead 10 FirstWrite 11}
		sext_ln897_2 {Type I LastRead 0 FirstWrite -1}
		v1059 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_880_1_VITIS_LOOP_881_2_VITIS_LOOP_882_344 {
		g0 {Type IO LastRead 1 FirstWrite 2}
		sext_ln897_2 {Type I LastRead 0 FirstWrite -1}
		sext_ln880 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_836_1_VITIS_LOOP_837_2_VITIS_LOOP_838_345 {
		g0 {Type IO LastRead 1 FirstWrite 2}
		sext_ln1150 {Type I LastRead 0 FirstWrite -1}
		sext_ln841 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_751_1_VITIS_LOOP_752_2_VITIS_LOOP_753_346 {
		g0 {Type IO LastRead 10 FirstWrite 11}
		sext_ln755 {Type I LastRead 0 FirstWrite -1}
		sext_ln897 {Type I LastRead 0 FirstWrite -1}
		v944 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_736_1_VITIS_LOOP_737_247 {
		g0 {Type IO LastRead 9 FirstWrite 10}
		sext_ln897 {Type I LastRead 0 FirstWrite -1}
		sext_ln736 {Type I LastRead 0 FirstWrite -1}
		v1013 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_703_1_VITIS_LOOP_704_248 {
		g0 {Type IO LastRead 10 FirstWrite 15}
		sext_ln703_3 {Type I LastRead 0 FirstWrite -1}
		sext_ln703_4 {Type I LastRead 0 FirstWrite -1}
		sext_ln736 {Type I LastRead 0 FirstWrite -1}
		sext_ln703_8 {Type I LastRead 0 FirstWrite -1}
		sext_ln736_1 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_687_1_VITIS_LOOP_688_249 {
		g0 {Type IO LastRead 15 FirstWrite 14}
		sext_ln736 {Type I LastRead 0 FirstWrite -1}
		v1007 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_671_1_VITIS_LOOP_672_250 {
		g0 {Type IO LastRead 13 FirstWrite 12}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		v1159 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_652_1_VITIS_LOOP_653_251 {
		g0 {Type IO LastRead 13 FirstWrite 12}
		sext_ln736 {Type I LastRead 0 FirstWrite -1}
		sext_ln703_4 {Type I LastRead 0 FirstWrite -1}
		v1007 {Type I LastRead 0 FirstWrite -1}
		sext_ln703_9 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_615_1_VITIS_LOOP_616_252 {
		g0 {Type IO LastRead 16 FirstWrite 15}
		sext_ln615_2 {Type I LastRead 0 FirstWrite -1}
		sext_ln736 {Type I LastRead 0 FirstWrite -1}
		sext_ln615_5 {Type I LastRead 0 FirstWrite -1}
		v1007 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_588_1_VITIS_LOOP_589_253 {
		g0 {Type IO LastRead 9 FirstWrite 10}
		sext_ln1882 {Type I LastRead 0 FirstWrite -1}
		v1159 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_287_1_VITIS_LOOP_288_2_VITIS_LOOP_289_354 {
		g0 {Type IO LastRead 16 FirstWrite 15}
		sext_ln2159 {Type I LastRead 0 FirstWrite -1}
		v1050 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_269_1_VITIS_LOOP_270_2_VITIS_LOOP_271_355 {
		g0 {Type IO LastRead 14 FirstWrite 13}
		sext_ln1882 {Type I LastRead 0 FirstWrite -1}
		v1154 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_248_1_VITIS_LOOP_249_2_VITIS_LOOP_250_356 {
		g0 {Type IO LastRead 14 FirstWrite 13}
		sext_ln2159 {Type I LastRead 0 FirstWrite -1}
		sext_ln248 {Type I LastRead 0 FirstWrite -1}
		v1050 {Type I LastRead 0 FirstWrite -1}
		sext_ln248_1 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_207_1_VITIS_LOOP_208_2_VITIS_LOOP_209_357 {
		g0 {Type IO LastRead 17 FirstWrite 16}
		sext_ln703_4 {Type I LastRead 0 FirstWrite -1}
		sext_ln2159 {Type I LastRead 0 FirstWrite -1}
		sext_ln703_9 {Type I LastRead 0 FirstWrite -1}
		v1050 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_112_1 {
		g0 {Type O LastRead -1 FirstWrite 1}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_99_2 {
		g0 {Type IO LastRead 16 FirstWrite 15}
		zext_ln100 {Type I LastRead 0 FirstWrite -1}
		v958 {Type I LastRead 0 FirstWrite -1}
		empty {Type I LastRead 0 FirstWrite -1}
		v1159 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_85_1 {
		g0 {Type IO LastRead 14 FirstWrite 13}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		v1159 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_73_1_VITIS_LOOP_74_2 {
		g0 {Type IO LastRead 9 FirstWrite 10}
		sext_ln2027 {Type I LastRead 0 FirstWrite -1}
		v946 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_62_1 {
		g0 {Type O LastRead -1 FirstWrite 1}
		sext_ln62 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_142 {
		g0 {Type I LastRead 1 FirstWrite -1}
		sext_ln2299 {Type I LastRead 0 FirstWrite -1}
		v9 {Type O LastRead -1 FirstWrite 2}}
	control_Pipeline_VITIS_LOOP_42_1_VITIS_LOOP_43_2 {
		g0 {Type IO LastRead 18 FirstWrite 17}
		sext_ln2027 {Type I LastRead 0 FirstWrite -1}
		sext_ln62 {Type I LastRead 0 FirstWrite -1}
		v9 {Type I LastRead 0 FirstWrite -1}
		sext_ln2027_1 {Type I LastRead 0 FirstWrite -1}
		v1162 {Type I LastRead 0 FirstWrite -1}}
	control_Pipeline_VITIS_LOOP_22_1 {
		g0 {Type IO LastRead 16 FirstWrite 15}
		sext_ln62 {Type I LastRead 0 FirstWrite -1}
		sext_ln22 {Type I LastRead 0 FirstWrite -1}
		v1162 {Type I LastRead 0 FirstWrite -1}
		sext_ln22_1 {Type I LastRead 0 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "2233777717", "Max" : "2233777717"}
	, {"Name" : "Interval", "Min" : "2233777718", "Max" : "2233777718"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	g0 { m_axi {  { m_axi_g0_AWVALID VALID 1 1 }  { m_axi_g0_AWREADY READY 0 1 }  { m_axi_g0_AWADDR ADDR 1 64 }  { m_axi_g0_AWID ID 1 1 }  { m_axi_g0_AWLEN SIZE 1 8 }  { m_axi_g0_AWSIZE BURST 1 3 }  { m_axi_g0_AWBURST LOCK 1 2 }  { m_axi_g0_AWLOCK CACHE 1 2 }  { m_axi_g0_AWCACHE PROT 1 4 }  { m_axi_g0_AWPROT QOS 1 3 }  { m_axi_g0_AWQOS REGION 1 4 }  { m_axi_g0_AWREGION USER 1 4 }  { m_axi_g0_AWUSER DATA 1 1 }  { m_axi_g0_WVALID VALID 1 1 }  { m_axi_g0_WREADY READY 0 1 }  { m_axi_g0_WDATA FIFONUM 1 32 }  { m_axi_g0_WSTRB STRB 1 4 }  { m_axi_g0_WLAST LAST 1 1 }  { m_axi_g0_WID ID 1 1 }  { m_axi_g0_WUSER DATA 1 1 }  { m_axi_g0_ARVALID VALID 1 1 }  { m_axi_g0_ARREADY READY 0 1 }  { m_axi_g0_ARADDR ADDR 1 64 }  { m_axi_g0_ARID ID 1 1 }  { m_axi_g0_ARLEN SIZE 1 8 }  { m_axi_g0_ARSIZE BURST 1 3 }  { m_axi_g0_ARBURST LOCK 1 2 }  { m_axi_g0_ARLOCK CACHE 1 2 }  { m_axi_g0_ARCACHE PROT 1 4 }  { m_axi_g0_ARPROT QOS 1 3 }  { m_axi_g0_ARQOS REGION 1 4 }  { m_axi_g0_ARREGION USER 1 4 }  { m_axi_g0_ARUSER DATA 1 1 }  { m_axi_g0_RVALID VALID 0 1 }  { m_axi_g0_RREADY READY 1 1 }  { m_axi_g0_RDATA FIFONUM 0 32 }  { m_axi_g0_RLAST LAST 0 1 }  { m_axi_g0_RID ID 0 1 }  { m_axi_g0_RUSER DATA 0 1 }  { m_axi_g0_RRESP RESP 0 2 }  { m_axi_g0_BVALID VALID 0 1 }  { m_axi_g0_BREADY READY 1 1 }  { m_axi_g0_BRESP RESP 0 2 }  { m_axi_g0_BID ID 0 1 }  { m_axi_g0_BUSER DATA 0 1 } } }
	v944 { ap_none {  { v944 in_data 0 64 } } }
	v945 { ap_none {  { v945 in_data 0 64 } } }
	v946 { ap_none {  { v946 in_data 0 64 } } }
}

set maxi_interface_dict [dict create]
dict set maxi_interface_dict g0 { CHANNEL_NUM 0 BUNDLE g0 NUM_READ_OUTSTANDING 16 NUM_WRITE_OUTSTANDING 16 MAX_READ_BURST_LENGTH 16 MAX_WRITE_BURST_LENGTH 16 READ_WRITE_MODE READ_WRITE}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
	{ g0 1 }
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
	{ g0 1 }
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
