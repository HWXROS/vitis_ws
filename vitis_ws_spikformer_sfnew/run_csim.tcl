open_project -reset spikformer_sfnew_test
set_top control
add_files hls.cpp
add_files -tb tb_run.cpp
open_solution solution1
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default
set csim_build [pwd]/spikformer_sfnew_test/solution1/csim/build
file mkdir $csim_build/data
file mkdir $csim_build/test_images
foreach f [glob -nocomplain [pwd]/data/*.bin] {
    file copy -force $f $csim_build/data/
}
foreach f [glob -nocomplain [pwd]/test_images/*.bin] {
    file copy -force $f $csim_build/test_images/
}
csim_design
exit
