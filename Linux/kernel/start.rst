
Start first versoin of kernel onboard
########################################


QEMU debugging:

qemu-system-microblazeel -M microblaze-fdt-plnx -m 256 -serial mon:stdio -display none \
 	-dtb /media/sf_vivados/Linux/images/system.dtb -kernel /media/sf_vivados/Linux/images/vmlinux
 	
qemu-system-microblazeel -M microblaze-fdt-plnx -m 256 -serial mon:stdio -display none \
 	-dtb /media/sf_vivados/Linux/images/system.dtb -kernel vmlinux
 	

Kernel and DTB
================
When qemu is used, kernel get dtb from qemu (outside of kernel);

 	