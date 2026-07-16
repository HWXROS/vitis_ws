# Vitis HLS TCL for Fashion-ResNet18 v1.2
open_project "fashion_resnet18_proj"
set_top control
add_files fashion_resnet18.cpp
add_files -tb tb_fashion_resnet18.cpp

open_solution "solution1"
set_part {xczu15eg-ffvb1156-2-i}
create_clock -period 10 -name default

csim_design -clean
csynth_design

exit
