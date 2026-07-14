# Auto-generated Vitis HLS TCL for spikformer_cifar10
open_project "${topname}_proj"
set_top control
add_files spikformer_cifar10.cpp
add_files -tb tb_spikformer_cifar10.cpp

open_solution "solution1"
set_part {xczu15eg-ffvb1156-2-i}
create_clock -period 10 -name default

# Uncomment to run:
# csim_design
# csynth_design
# export_design -format ip_catalog -output ./${topname}_ip

exit
