set moduleName kernel83_Pipeline_VITIS_LOOP_1081_3
set isTopModule 0
set isCombinational 0
set isDatapathOnly 0
set isPipelined 1
set isPipelined_legacy 1
set pipeline_type loop_auto_rewind
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
set C_modelName {kernel83_Pipeline_VITIS_LOOP_1081_3}
set C_modelType { void 0 }
set ap_memory_interface_dict [dict create]
set C_modelArgList {
	{ g0 int 32 regular {axi_master 2 stable }  }
	{ sext_ln1083 int 62 regular  }
	{ sext_ln1084 int 62 regular  }
	{ sext_ln1085 int 62 regular  }
	{ zext_ln1080 int 17 regular  }
	{ v438 int 64 regular  }
	{ v440 int 64 regular  }
	{ zext_ln1081 int 17 regular  }
	{ v446 float 32 regular  }
}
set hasAXIMCache 0
set l_AXIML2Cache [list]
set AXIMCacheInstDict [dict create]
set C_modelArgMapList {[ 
	{ "Name" : "g0", "interface" : "axi_master", "bitwidth" : 32, "direction" : "READWRITE", "id_num" : 0, "bitSlice":[ {"cElement": [{"cName": "v944","offset": { "type": "dynamic","port_name": "v944"},"direction": "READWRITE"},{"cName": "v945","offset": { "type": "dynamic","port_name": "v945"},"direction": "READWRITE"},{"cName": "v946","offset": { "type": "dynamic","port_name": "v946"},"direction": "READWRITE"}]}]} , 
 	{ "Name" : "sext_ln1083", "interface" : "wire", "bitwidth" : 62, "direction" : "READONLY"} , 
 	{ "Name" : "sext_ln1084", "interface" : "wire", "bitwidth" : 62, "direction" : "READONLY"} , 
 	{ "Name" : "sext_ln1085", "interface" : "wire", "bitwidth" : 62, "direction" : "READONLY"} , 
 	{ "Name" : "zext_ln1080", "interface" : "wire", "bitwidth" : 17, "direction" : "READONLY"} , 
 	{ "Name" : "v438", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "v440", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "zext_ln1081", "interface" : "wire", "bitwidth" : 17, "direction" : "READONLY"} , 
 	{ "Name" : "v446", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY"} ]}
# RTL Port declarations: 
set portNum 60
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ m_axi_g0_0_AWVALID sc_out sc_logic 1 signal 0 } 
	{ m_axi_g0_0_AWREADY sc_in sc_logic 1 signal 0 } 
	{ m_axi_g0_0_AWADDR sc_out sc_lv 64 signal 0 } 
	{ m_axi_g0_0_AWID sc_out sc_lv 1 signal 0 } 
	{ m_axi_g0_0_AWLEN sc_out sc_lv 32 signal 0 } 
	{ m_axi_g0_0_AWSIZE sc_out sc_lv 3 signal 0 } 
	{ m_axi_g0_0_AWBURST sc_out sc_lv 2 signal 0 } 
	{ m_axi_g0_0_AWLOCK sc_out sc_lv 2 signal 0 } 
	{ m_axi_g0_0_AWCACHE sc_out sc_lv 4 signal 0 } 
	{ m_axi_g0_0_AWPROT sc_out sc_lv 3 signal 0 } 
	{ m_axi_g0_0_AWQOS sc_out sc_lv 4 signal 0 } 
	{ m_axi_g0_0_AWREGION sc_out sc_lv 4 signal 0 } 
	{ m_axi_g0_0_AWUSER sc_out sc_lv 1 signal 0 } 
	{ m_axi_g0_0_WVALID sc_out sc_logic 1 signal 0 } 
	{ m_axi_g0_0_WREADY sc_in sc_logic 1 signal 0 } 
	{ m_axi_g0_0_WDATA sc_out sc_lv 32 signal 0 } 
	{ m_axi_g0_0_WSTRB sc_out sc_lv 4 signal 0 } 
	{ m_axi_g0_0_WLAST sc_out sc_logic 1 signal 0 } 
	{ m_axi_g0_0_WID sc_out sc_lv 1 signal 0 } 
	{ m_axi_g0_0_WUSER sc_out sc_lv 1 signal 0 } 
	{ m_axi_g0_0_ARVALID sc_out sc_logic 1 signal 0 } 
	{ m_axi_g0_0_ARREADY sc_in sc_logic 1 signal 0 } 
	{ m_axi_g0_0_ARADDR sc_out sc_lv 64 signal 0 } 
	{ m_axi_g0_0_ARID sc_out sc_lv 1 signal 0 } 
	{ m_axi_g0_0_ARLEN sc_out sc_lv 32 signal 0 } 
	{ m_axi_g0_0_ARSIZE sc_out sc_lv 3 signal 0 } 
	{ m_axi_g0_0_ARBURST sc_out sc_lv 2 signal 0 } 
	{ m_axi_g0_0_ARLOCK sc_out sc_lv 2 signal 0 } 
	{ m_axi_g0_0_ARCACHE sc_out sc_lv 4 signal 0 } 
	{ m_axi_g0_0_ARPROT sc_out sc_lv 3 signal 0 } 
	{ m_axi_g0_0_ARQOS sc_out sc_lv 4 signal 0 } 
	{ m_axi_g0_0_ARREGION sc_out sc_lv 4 signal 0 } 
	{ m_axi_g0_0_ARUSER sc_out sc_lv 1 signal 0 } 
	{ m_axi_g0_0_RVALID sc_in sc_logic 1 signal 0 } 
	{ m_axi_g0_0_RREADY sc_out sc_logic 1 signal 0 } 
	{ m_axi_g0_0_RDATA sc_in sc_lv 32 signal 0 } 
	{ m_axi_g0_0_RLAST sc_in sc_logic 1 signal 0 } 
	{ m_axi_g0_0_RID sc_in sc_lv 1 signal 0 } 
	{ m_axi_g0_0_RFIFONUM sc_in sc_lv 9 signal 0 } 
	{ m_axi_g0_0_RUSER sc_in sc_lv 1 signal 0 } 
	{ m_axi_g0_0_RRESP sc_in sc_lv 2 signal 0 } 
	{ m_axi_g0_0_BVALID sc_in sc_logic 1 signal 0 } 
	{ m_axi_g0_0_BREADY sc_out sc_logic 1 signal 0 } 
	{ m_axi_g0_0_BRESP sc_in sc_lv 2 signal 0 } 
	{ m_axi_g0_0_BID sc_in sc_lv 1 signal 0 } 
	{ m_axi_g0_0_BUSER sc_in sc_lv 1 signal 0 } 
	{ sext_ln1083 sc_in sc_lv 62 signal 1 } 
	{ sext_ln1084 sc_in sc_lv 62 signal 2 } 
	{ sext_ln1085 sc_in sc_lv 62 signal 3 } 
	{ zext_ln1080 sc_in sc_lv 17 signal 4 } 
	{ v438 sc_in sc_lv 64 signal 5 } 
	{ v440 sc_in sc_lv 64 signal 6 } 
	{ zext_ln1081 sc_in sc_lv 17 signal 7 } 
	{ v446 sc_in sc_lv 32 signal 8 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "m_axi_g0_0_AWVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "0_AWVALID" }} , 
 	{ "name": "m_axi_g0_0_AWREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "0_AWREADY" }} , 
 	{ "name": "m_axi_g0_0_AWADDR", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "g0", "role": "0_AWADDR" }} , 
 	{ "name": "m_axi_g0_0_AWID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "0_AWID" }} , 
 	{ "name": "m_axi_g0_0_AWLEN", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "g0", "role": "0_AWLEN" }} , 
 	{ "name": "m_axi_g0_0_AWSIZE", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "g0", "role": "0_AWSIZE" }} , 
 	{ "name": "m_axi_g0_0_AWBURST", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "g0", "role": "0_AWBURST" }} , 
 	{ "name": "m_axi_g0_0_AWLOCK", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "g0", "role": "0_AWLOCK" }} , 
 	{ "name": "m_axi_g0_0_AWCACHE", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "g0", "role": "0_AWCACHE" }} , 
 	{ "name": "m_axi_g0_0_AWPROT", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "g0", "role": "0_AWPROT" }} , 
 	{ "name": "m_axi_g0_0_AWQOS", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "g0", "role": "0_AWQOS" }} , 
 	{ "name": "m_axi_g0_0_AWREGION", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "g0", "role": "0_AWREGION" }} , 
 	{ "name": "m_axi_g0_0_AWUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "0_AWUSER" }} , 
 	{ "name": "m_axi_g0_0_WVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "0_WVALID" }} , 
 	{ "name": "m_axi_g0_0_WREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "0_WREADY" }} , 
 	{ "name": "m_axi_g0_0_WDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "g0", "role": "0_WDATA" }} , 
 	{ "name": "m_axi_g0_0_WSTRB", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "g0", "role": "0_WSTRB" }} , 
 	{ "name": "m_axi_g0_0_WLAST", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "0_WLAST" }} , 
 	{ "name": "m_axi_g0_0_WID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "0_WID" }} , 
 	{ "name": "m_axi_g0_0_WUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "0_WUSER" }} , 
 	{ "name": "m_axi_g0_0_ARVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "0_ARVALID" }} , 
 	{ "name": "m_axi_g0_0_ARREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "0_ARREADY" }} , 
 	{ "name": "m_axi_g0_0_ARADDR", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "g0", "role": "0_ARADDR" }} , 
 	{ "name": "m_axi_g0_0_ARID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "0_ARID" }} , 
 	{ "name": "m_axi_g0_0_ARLEN", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "g0", "role": "0_ARLEN" }} , 
 	{ "name": "m_axi_g0_0_ARSIZE", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "g0", "role": "0_ARSIZE" }} , 
 	{ "name": "m_axi_g0_0_ARBURST", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "g0", "role": "0_ARBURST" }} , 
 	{ "name": "m_axi_g0_0_ARLOCK", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "g0", "role": "0_ARLOCK" }} , 
 	{ "name": "m_axi_g0_0_ARCACHE", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "g0", "role": "0_ARCACHE" }} , 
 	{ "name": "m_axi_g0_0_ARPROT", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "g0", "role": "0_ARPROT" }} , 
 	{ "name": "m_axi_g0_0_ARQOS", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "g0", "role": "0_ARQOS" }} , 
 	{ "name": "m_axi_g0_0_ARREGION", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "g0", "role": "0_ARREGION" }} , 
 	{ "name": "m_axi_g0_0_ARUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "0_ARUSER" }} , 
 	{ "name": "m_axi_g0_0_RVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "0_RVALID" }} , 
 	{ "name": "m_axi_g0_0_RREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "0_RREADY" }} , 
 	{ "name": "m_axi_g0_0_RDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "g0", "role": "0_RDATA" }} , 
 	{ "name": "m_axi_g0_0_RLAST", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "0_RLAST" }} , 
 	{ "name": "m_axi_g0_0_RID", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "0_RID" }} , 
 	{ "name": "m_axi_g0_0_RFIFONUM", "direction": "in", "datatype": "sc_lv", "bitwidth":9, "type": "signal", "bundle":{"name": "g0", "role": "0_RFIFONUM" }} , 
 	{ "name": "m_axi_g0_0_RUSER", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "0_RUSER" }} , 
 	{ "name": "m_axi_g0_0_RRESP", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "g0", "role": "0_RRESP" }} , 
 	{ "name": "m_axi_g0_0_BVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "0_BVALID" }} , 
 	{ "name": "m_axi_g0_0_BREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "0_BREADY" }} , 
 	{ "name": "m_axi_g0_0_BRESP", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "g0", "role": "0_BRESP" }} , 
 	{ "name": "m_axi_g0_0_BID", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "0_BID" }} , 
 	{ "name": "m_axi_g0_0_BUSER", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "g0", "role": "0_BUSER" }} , 
 	{ "name": "sext_ln1083", "direction": "in", "datatype": "sc_lv", "bitwidth":62, "type": "signal", "bundle":{"name": "sext_ln1083", "role": "default" }} , 
 	{ "name": "sext_ln1084", "direction": "in", "datatype": "sc_lv", "bitwidth":62, "type": "signal", "bundle":{"name": "sext_ln1084", "role": "default" }} , 
 	{ "name": "sext_ln1085", "direction": "in", "datatype": "sc_lv", "bitwidth":62, "type": "signal", "bundle":{"name": "sext_ln1085", "role": "default" }} , 
 	{ "name": "zext_ln1080", "direction": "in", "datatype": "sc_lv", "bitwidth":17, "type": "signal", "bundle":{"name": "zext_ln1080", "role": "default" }} , 
 	{ "name": "v438", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "v438", "role": "default" }} , 
 	{ "name": "v440", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "v440", "role": "default" }} , 
 	{ "name": "zext_ln1081", "direction": "in", "datatype": "sc_lv", "bitwidth":17, "type": "signal", "bundle":{"name": "zext_ln1081", "role": "default" }} , 
 	{ "name": "v446", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v446", "role": "default" }}  ]}

set ArgLastReadFirstWriteLatency {
	kernel83_Pipeline_VITIS_LOOP_1081_3 {
		g0 {Type IO LastRead 18 FirstWrite 17}
		sext_ln1083 {Type I LastRead 0 FirstWrite -1}
		sext_ln1084 {Type I LastRead 0 FirstWrite -1}
		sext_ln1085 {Type I LastRead 0 FirstWrite -1}
		zext_ln1080 {Type I LastRead 0 FirstWrite -1}
		v438 {Type I LastRead 0 FirstWrite -1}
		v440 {Type I LastRead 0 FirstWrite -1}
		zext_ln1081 {Type I LastRead 0 FirstWrite -1}
		v446 {Type I LastRead 0 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "150", "Max" : "150"}
	, {"Name" : "Interval", "Min" : "130", "Max" : "130"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	 { m_axi {  { m_axi_g0_0_AWVALID VALID 1 1 }  { m_axi_g0_0_AWREADY READY 0 1 }  { m_axi_g0_0_AWADDR ADDR 1 64 }  { m_axi_g0_0_AWID ID 1 1 }  { m_axi_g0_0_AWLEN SIZE 1 32 }  { m_axi_g0_0_AWSIZE BURST 1 3 }  { m_axi_g0_0_AWBURST LOCK 1 2 }  { m_axi_g0_0_AWLOCK CACHE 1 2 }  { m_axi_g0_0_AWCACHE PROT 1 4 }  { m_axi_g0_0_AWPROT QOS 1 3 }  { m_axi_g0_0_AWQOS REGION 1 4 }  { m_axi_g0_0_AWREGION USER 1 4 }  { m_axi_g0_0_AWUSER DATA 1 1 }  { m_axi_g0_0_WVALID VALID 1 1 }  { m_axi_g0_0_WREADY READY 0 1 }  { m_axi_g0_0_WDATA FIFONUM 1 32 }  { m_axi_g0_0_WSTRB STRB 1 4 }  { m_axi_g0_0_WLAST LAST 1 1 }  { m_axi_g0_0_WID ID 1 1 }  { m_axi_g0_0_WUSER DATA 1 1 }  { m_axi_g0_0_ARVALID VALID 1 1 }  { m_axi_g0_0_ARREADY READY 0 1 }  { m_axi_g0_0_ARADDR ADDR 1 64 }  { m_axi_g0_0_ARID ID 1 1 }  { m_axi_g0_0_ARLEN SIZE 1 32 }  { m_axi_g0_0_ARSIZE BURST 1 3 }  { m_axi_g0_0_ARBURST LOCK 1 2 }  { m_axi_g0_0_ARLOCK CACHE 1 2 }  { m_axi_g0_0_ARCACHE PROT 1 4 }  { m_axi_g0_0_ARPROT QOS 1 3 }  { m_axi_g0_0_ARQOS REGION 1 4 }  { m_axi_g0_0_ARREGION USER 1 4 }  { m_axi_g0_0_ARUSER DATA 1 1 }  { m_axi_g0_0_RVALID VALID 0 1 }  { m_axi_g0_0_RREADY READY 1 1 }  { m_axi_g0_0_RDATA FIFONUM 0 32 }  { m_axi_g0_0_RLAST LAST 0 1 }  { m_axi_g0_0_RID ID 0 1 }  { m_axi_g0_0_RFIFONUM LEN 0 9 }  { m_axi_g0_0_RUSER DATA 0 1 }  { m_axi_g0_0_RRESP RESP 0 2 }  { m_axi_g0_0_BVALID VALID 0 1 }  { m_axi_g0_0_BREADY READY 1 1 }  { m_axi_g0_0_BRESP RESP 0 2 }  { m_axi_g0_0_BID ID 0 1 }  { m_axi_g0_0_BUSER DATA 0 1 } } }
	sext_ln1083 { ap_none {  { sext_ln1083 in_data 0 62 } } }
	sext_ln1084 { ap_none {  { sext_ln1084 in_data 0 62 } } }
	sext_ln1085 { ap_none {  { sext_ln1085 in_data 0 62 } } }
	zext_ln1080 { ap_none {  { zext_ln1080 in_data 0 17 } } }
	v438 { ap_none {  { v438 in_data 0 64 } } }
	v440 { ap_none {  { v440 in_data 0 64 } } }
	zext_ln1081 { ap_none {  { zext_ln1081 in_data 0 17 } } }
	v446 { ap_none {  { v446 in_data 0 32 } } }
}
