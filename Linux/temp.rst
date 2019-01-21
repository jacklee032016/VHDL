
sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib \
   build-essential chrpath socat cpio python python3 python3-pip python3-pexpect \
   xz-utils debianutils iputils-ping libsdl1.2-dev xterm
   
sudo ufw disable

net use k: \\lzj-ubuntu\works password /user:lzj


export OEROOT=../
source ../scripts/oe-buildenv-internal 
../bitbake/bin/bitbake core-image-minimal

   