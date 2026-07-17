open_project -reset resnet18_csynth_proj
set_top control
add_files hls.cpp
open_solution "solution1"
set_part xczu7ev-ffvc1156-2-e
create_clock -period 10 -name default
csynth_design
exit
