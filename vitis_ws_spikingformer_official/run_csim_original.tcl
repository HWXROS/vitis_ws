open_project spikingformer_csim_orig_proj
set_top control
add_files spikingformer_official_original.cpp
add_files -tb tb_spikingformer_official.cpp
open_solution "solution1"
set_part xczu7ev-ffvc1156-2-e
create_clock -period 10 -name default
csim_design
exit
