; ModuleID = '/home/hwx/HCA/FPGA-SNN/vitis_ws/vitis_ws_spikingformer_official/spikingformer_proj/solution1/.autopilot/db/a.g.ld.5.gdce.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-i64:64-i128:128-i256:256-i512:512-i1024:1024-i2048:2048-i4096:4096-n8:16:32:64-S128-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024"
target triple = "fpga64-xilinx-none"

%"struct.ap_int<32>" = type { %"struct.ap_int_base<32, true>" }
%"struct.ap_int_base<32, true>" = type { %"struct.ssdm_int<32, true>" }
%"struct.ssdm_int<32, true>" = type { i32 }

; Function Attrs: noinline
define void @apatb_control_ir(%"struct.ap_int<32>"* noalias nonnull "fpga.decayed.dim.hint"="91189248" "maxi" %v944, %"struct.ap_int<32>"* noalias nonnull "fpga.decayed.dim.hint"="91189248" "maxi" %v945, %"struct.ap_int<32>"* noalias nonnull "fpga.decayed.dim.hint"="91189248" "maxi" %v946) local_unnamed_addr #0 {
entry:
  %0 = bitcast %"struct.ap_int<32>"* %v944 to [91189248 x %"struct.ap_int<32>"]*
  %1 = call i8* @malloc(i64 364756992)
  %v944_copy = bitcast i8* %1 to [91189248 x %"struct.ap_int<32>"]*
  %2 = bitcast %"struct.ap_int<32>"* %v945 to [91189248 x %"struct.ap_int<32>"]*
  %3 = call i8* @malloc(i64 364756992)
  %v945_copy = bitcast i8* %3 to [91189248 x %"struct.ap_int<32>"]*
  %4 = bitcast %"struct.ap_int<32>"* %v946 to [91189248 x %"struct.ap_int<32>"]*
  %5 = call i8* @malloc(i64 364756992)
  %v946_copy = bitcast i8* %5 to [91189248 x %"struct.ap_int<32>"]*
  call fastcc void @copy_in([91189248 x %"struct.ap_int<32>"]* nonnull %0, [91189248 x %"struct.ap_int<32>"]* %v944_copy, [91189248 x %"struct.ap_int<32>"]* nonnull %2, [91189248 x %"struct.ap_int<32>"]* %v945_copy, [91189248 x %"struct.ap_int<32>"]* nonnull %4, [91189248 x %"struct.ap_int<32>"]* %v946_copy)
  call void @apatb_control_hw([91189248 x %"struct.ap_int<32>"]* %v944_copy, [91189248 x %"struct.ap_int<32>"]* %v945_copy, [91189248 x %"struct.ap_int<32>"]* %v946_copy)
  call void @copy_back([91189248 x %"struct.ap_int<32>"]* %0, [91189248 x %"struct.ap_int<32>"]* %v944_copy, [91189248 x %"struct.ap_int<32>"]* %2, [91189248 x %"struct.ap_int<32>"]* %v945_copy, [91189248 x %"struct.ap_int<32>"]* %4, [91189248 x %"struct.ap_int<32>"]* %v946_copy)
  tail call void @free(i8* %1)
  tail call void @free(i8* %3)
  tail call void @free(i8* %5)
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @copy_in([91189248 x %"struct.ap_int<32>"]* readonly, [91189248 x %"struct.ap_int<32>"]*, [91189248 x %"struct.ap_int<32>"]* readonly, [91189248 x %"struct.ap_int<32>"]*, [91189248 x %"struct.ap_int<32>"]* readonly, [91189248 x %"struct.ap_int<32>"]*) unnamed_addr #1 {
entry:
  call fastcc void @"onebyonecpy_hls.p0a91189248struct.ap_int<32>"([91189248 x %"struct.ap_int<32>"]* %1, [91189248 x %"struct.ap_int<32>"]* %0)
  call fastcc void @"onebyonecpy_hls.p0a91189248struct.ap_int<32>"([91189248 x %"struct.ap_int<32>"]* %3, [91189248 x %"struct.ap_int<32>"]* %2)
  call fastcc void @"onebyonecpy_hls.p0a91189248struct.ap_int<32>"([91189248 x %"struct.ap_int<32>"]* %5, [91189248 x %"struct.ap_int<32>"]* %4)
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @"onebyonecpy_hls.p0a91189248struct.ap_int<32>"([91189248 x %"struct.ap_int<32>"]* %dst, [91189248 x %"struct.ap_int<32>"]* readonly %src) unnamed_addr #2 {
entry:
  %0 = icmp eq [91189248 x %"struct.ap_int<32>"]* %dst, null
  %1 = icmp eq [91189248 x %"struct.ap_int<32>"]* %src, null
  %2 = or i1 %0, %1
  br i1 %2, label %ret, label %copy

copy:                                             ; preds = %entry
  call void @"arraycpy_hls.p0a91189248struct.ap_int<32>"([91189248 x %"struct.ap_int<32>"]* nonnull %dst, [91189248 x %"struct.ap_int<32>"]* nonnull %src, i64 91189248)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define void @"arraycpy_hls.p0a91189248struct.ap_int<32>"([91189248 x %"struct.ap_int<32>"]* %dst, [91189248 x %"struct.ap_int<32>"]* readonly %src, i64 %num) local_unnamed_addr #3 {
entry:
  %0 = icmp eq [91189248 x %"struct.ap_int<32>"]* %src, null
  %1 = icmp eq [91189248 x %"struct.ap_int<32>"]* %dst, null
  %2 = or i1 %1, %0
  br i1 %2, label %ret, label %copy

copy:                                             ; preds = %entry
  %for.loop.cond7 = icmp sgt i64 %num, 0
  br i1 %for.loop.cond7, label %for.loop.lr.ph, label %copy.split

for.loop.lr.ph:                                   ; preds = %copy
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %for.loop.lr.ph
  %for.loop.idx8 = phi i64 [ 0, %for.loop.lr.ph ], [ %for.loop.idx.next, %for.loop ]
  %src.addr.0.0.05 = getelementptr [91189248 x %"struct.ap_int<32>"], [91189248 x %"struct.ap_int<32>"]* %src, i64 0, i64 %for.loop.idx8, i32 0, i32 0, i32 0
  %dst.addr.0.0.06 = getelementptr [91189248 x %"struct.ap_int<32>"], [91189248 x %"struct.ap_int<32>"]* %dst, i64 0, i64 %for.loop.idx8, i32 0, i32 0, i32 0
  %3 = load i32, i32* %src.addr.0.0.05, align 4
  store i32 %3, i32* %dst.addr.0.0.06, align 4
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx8, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, %num
  br i1 %exitcond, label %for.loop, label %copy.split

copy.split:                                       ; preds = %for.loop, %copy
  br label %ret

ret:                                              ; preds = %copy.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @copy_out([91189248 x %"struct.ap_int<32>"]*, [91189248 x %"struct.ap_int<32>"]* readonly, [91189248 x %"struct.ap_int<32>"]*, [91189248 x %"struct.ap_int<32>"]* readonly, [91189248 x %"struct.ap_int<32>"]*, [91189248 x %"struct.ap_int<32>"]* readonly) unnamed_addr #4 {
entry:
  call fastcc void @"onebyonecpy_hls.p0a91189248struct.ap_int<32>"([91189248 x %"struct.ap_int<32>"]* %0, [91189248 x %"struct.ap_int<32>"]* %1)
  call fastcc void @"onebyonecpy_hls.p0a91189248struct.ap_int<32>"([91189248 x %"struct.ap_int<32>"]* %2, [91189248 x %"struct.ap_int<32>"]* %3)
  call fastcc void @"onebyonecpy_hls.p0a91189248struct.ap_int<32>"([91189248 x %"struct.ap_int<32>"]* %4, [91189248 x %"struct.ap_int<32>"]* %5)
  ret void
}

declare i8* @malloc(i64) local_unnamed_addr

declare void @free(i8*) local_unnamed_addr

declare void @apatb_control_hw([91189248 x %"struct.ap_int<32>"]*, [91189248 x %"struct.ap_int<32>"]*, [91189248 x %"struct.ap_int<32>"]*)

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @copy_back([91189248 x %"struct.ap_int<32>"]*, [91189248 x %"struct.ap_int<32>"]* readonly, [91189248 x %"struct.ap_int<32>"]*, [91189248 x %"struct.ap_int<32>"]* readonly, [91189248 x %"struct.ap_int<32>"]*, [91189248 x %"struct.ap_int<32>"]* readonly) unnamed_addr #4 {
entry:
  call fastcc void @"onebyonecpy_hls.p0a91189248struct.ap_int<32>"([91189248 x %"struct.ap_int<32>"]* %0, [91189248 x %"struct.ap_int<32>"]* %1)
  call fastcc void @"onebyonecpy_hls.p0a91189248struct.ap_int<32>"([91189248 x %"struct.ap_int<32>"]* %2, [91189248 x %"struct.ap_int<32>"]* %3)
  call fastcc void @"onebyonecpy_hls.p0a91189248struct.ap_int<32>"([91189248 x %"struct.ap_int<32>"]* %4, [91189248 x %"struct.ap_int<32>"]* %5)
  ret void
}

declare void @control_hw_stub(%"struct.ap_int<32>"* noalias nonnull, %"struct.ap_int<32>"* noalias nonnull, %"struct.ap_int<32>"* noalias nonnull)

define void @control_hw_stub_wrapper([91189248 x %"struct.ap_int<32>"]*, [91189248 x %"struct.ap_int<32>"]*, [91189248 x %"struct.ap_int<32>"]*) #5 {
entry:
  call void @copy_out([91189248 x %"struct.ap_int<32>"]* null, [91189248 x %"struct.ap_int<32>"]* %0, [91189248 x %"struct.ap_int<32>"]* null, [91189248 x %"struct.ap_int<32>"]* %1, [91189248 x %"struct.ap_int<32>"]* null, [91189248 x %"struct.ap_int<32>"]* %2)
  %3 = bitcast [91189248 x %"struct.ap_int<32>"]* %0 to %"struct.ap_int<32>"*
  %4 = bitcast [91189248 x %"struct.ap_int<32>"]* %1 to %"struct.ap_int<32>"*
  %5 = bitcast [91189248 x %"struct.ap_int<32>"]* %2 to %"struct.ap_int<32>"*
  call void @control_hw_stub(%"struct.ap_int<32>"* %3, %"struct.ap_int<32>"* %4, %"struct.ap_int<32>"* %5)
  call void @copy_in([91189248 x %"struct.ap_int<32>"]* null, [91189248 x %"struct.ap_int<32>"]* %0, [91189248 x %"struct.ap_int<32>"]* null, [91189248 x %"struct.ap_int<32>"]* %1, [91189248 x %"struct.ap_int<32>"]* null, [91189248 x %"struct.ap_int<32>"]* %2)
  ret void
}

attributes #0 = { noinline "fpga.wrapper.func"="wrapper" }
attributes #1 = { argmemonly noinline norecurse willreturn "fpga.wrapper.func"="copyin" }
attributes #2 = { argmemonly noinline norecurse willreturn "fpga.wrapper.func"="onebyonecpy_hls" }
attributes #3 = { argmemonly noinline norecurse willreturn "fpga.wrapper.func"="arraycpy_hls" }
attributes #4 = { argmemonly noinline norecurse willreturn "fpga.wrapper.func"="copyout" }
attributes #5 = { "fpga.wrapper.func"="stub" }

!llvm.dbg.cu = !{}
!llvm.ident = !{!0, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1}
!llvm.module.flags = !{!2, !3, !4}
!blackbox_cfg = !{!5}

!0 = !{!"AMD/Xilinx clang version 16.0.6"}
!1 = !{!"clang version 7.0.0 "}
!2 = !{i32 2, !"Dwarf Version", i32 4}
!3 = !{i32 2, !"Debug Info Version", i32 3}
!4 = !{i32 1, !"wchar_size", i32 4}
!5 = !{}
