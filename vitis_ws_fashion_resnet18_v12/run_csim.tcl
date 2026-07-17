open_project -reset fashion_resnet18_spikingmlir_csim_proj
set_top control
add_files hls.cpp
add_files -tb tb_run.cpp
open_solution "solution1"
set_part xczu7ev-ffvc1156-2-e
create_clock -period 10 -name default

# Source of weight data: FHCA output (single source of truth)
set fhca_bins [pwd]/../../FastHCA/gen-mlir2hls/fashion_resnet18_spikingmlir/output/gen/bins
set csim_build [pwd]/fashion_resnet18_spikingmlir_csim_proj/solution1/csim/build
file mkdir $csim_build/data
foreach f [glob -nocomplain $fhca_bins/*.bin] {
    file copy -force $f $csim_build/data/
}

file mkdir $csim_build/test_images
foreach f [glob -nocomplain [pwd]/test_images/*.bin] {
    file copy -force $f $csim_build/test_images/
}

csim_design
exit
