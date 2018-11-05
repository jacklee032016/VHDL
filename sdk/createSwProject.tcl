
# command in vivado to start HSI

# common::load_feature hsi
# hsi::open_hw_design 

# create bit/mmi from hdf file
openhw vMicroBlaze_wrapper.hdf 

# help
help repo
help getlibs

# repo : look up info in repository
repo -libs|-os

hsi get_ports/get_nets|get_pins/get_cells
# list HSI commandshist
hsi ?  


# create a directory of 'workspace';

setws ./workspace  


createhw -name hwProject -hwspec vMicroBlaze_wrapper.hdf 

# hw project and processor must be defined
# specify a processor instance or a mss file to create a BSP project
# processor instance can be gotten with 'hsi get_cells'
# xparameters.h is created
createbsp -name firstBsp -hwproject hwProj -proc microblaze_0

# add library into BSP
setlib -bsp firstBsp -lib xilisf

# BSP must be regenratte after settings are changed
regenbsp -bsp firstBsp

# 
createapp -name hello -hwproject hwProj -proc microblaze_0 -app "lwIP Echo Server" 

# build all projects

projects -build 

