open_project -reset sf_xxx
set_top control
add_files spikingformer_official.cpp
add_files -tb tb_gen.cpp
open_solution solution1
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default
csim_design
exit
