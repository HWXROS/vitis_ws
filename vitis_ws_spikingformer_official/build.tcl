# Spikingformer Official HLS Build Script (BRAM-optimized)
open_project spikingformer_proj
set_top control
add_files spikingformer_official.cpp
add_files -tb tb_spikingformer_official.cpp

open_solution "solution1"
set_part xczu7ev-ffvc1156-2-e
create_clock -period 10 -name default

# Skip C-Simulation, run synthesis directly
csynth_design

# Export resource report
exit
