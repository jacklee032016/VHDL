ubuntu Usage
####################################
Oct.20, 2018

add awk
::

    apt-get install gawk
	ln -s /usr/bin/awk /bin/awk : symbol link to /bin/awk to support Makefile of rtosLwip


Windows client to Samba server
--------------------------------------
Dev.29, 2019
After configured and run Samba server, and disable firmware (sudo ufw disable/sudo ufw status);

On ubuntu, connect Samba service, everything is OK

On windows, using:
::

   net use k: \\lzj-ubuntu\works password /user:lzj
   net use k: \\lzj-ubuntu\works password /user:workgroup\lzj   : when Windows host is belong to domain
   system error 53 has occurred. the network path was not found

On ubuntu, use    
::
   
   smbclient -L //192.168.168.8 -U lzj 
   
   alerts:
   
   NetBIOS over TCP disabled -- no workgroup available

Then on Windows, start the service of 'TCP/IP NetBIOS Helper', then everything is OK


Samba shared file from ubuntu guest
--------------------------------------
Dec.28, 2018

Installation:
::

   sudo apt install samba
  
   whereis samba

Configuration:
::

	 /etc/samba/smb.conf: add following lines:
  
   [yoctoShare]
   comment=Yocto Share
   path=/home/lzj/yocto
   read only = no
   browsable = yes

   [PetaLinux]
   comment=PetaLinux
   path=/opt
   read only = no
   browsable = yes

samba account: add user 'lzj'
::

   sudo smbpasswd -a lzj

samba service:
::

   sudo service smbd restart

Tests:
In ``File Manager``, and ``Connect to Server..``, input following
::

	smb://10.0.2.15/

	smbclient -L //192.168.168.8 -U lzj : with username 'lzj'

	
Ubuntu and Vivado
------------------------

/bin/sh link to /bin/dash, it is not bash
     
     sudo rm -rf /bin/sh
     sudo ln -s /bin/bash /bin/sh

Install Xlinx Tools and initializing

add following lines in ~/.profile

    XILINX_VIVADO_HOME=/opt/WebPack/Vivado/2017.4

    cd $XILINX_VIVADO_HOME
    source settings64.sh

petalinux only been source by command line in terminal window
cd /opt/peta

source settings.sh


Ubuntun merge terminal windows into tab
----------------------------------------
    Press 'Ctrl+Shift+T' to create terminal in tab options;

**Install and use minicom**

  sudo apt-get install minicom
  minicom -s: setup and begin to use;
  device name: ttyUSB0 (from dmesg)


Install `vim`
--------------
Resolve the problem of 4 arrow keye in edit mode, displaying A|B|C|D;
sudo apt-get install vim
=======
Add packages
-----------------------
Nov. 2018

=======
Install `vim`
--------------
Resolve the problem of 4 arrow keye in edit mode, displaying A|B|C|D;

::

  sudo apt-get install device-tree-compiler


PetaLinux
===================

Pre-requirements
-------------------
 
 tftpd
 
 zlib1g-dev and zlib1g-dev:i386


 petalinux-v2017.4-final-installer.run /opt/peta
 
    Installing PetaLinux zynqMP Yocto SDK to "/opt/peta/./components/yocto/source/aarch64
    Each time you wish to use the SDK in a new shell session, you need to source the environment setup script e.g.
       $ . /opt/peta/components/yocto/source/aarch64/environment-setup-aarch64-xilinx-linux

    Installing PetaLinux zynq Yocto SDK to "/opt/peta/./components/yocto/source/arm
    Each time you wish to use the SDK in a new shell session, you need to source the environment setup script e.g.
       $ . /opt/peta/components/yocto/source/arm/environment-setup-cortexa9hf-neon-xilinx-linux-gnueabi

    Installing PetaLinux microblaze (Full) Yocto SDK to "/opt/peta/./components/yocto/source/microblaze_full
    Each time you wish to use the SDK in a new shell session, you need to source the environment setup script e.g.
       $ . /opt/peta/components/yocto/source/microblaze_full/environment-setup-microblazeel-v10.0-bs-cmp-mh-div-xilinx-linux

    Installing PetaLinux microblaze (Lite) Yocto SDK to "/opt/peta/./components/yocto/source/microblaze_lite
    Each time you wish to use the SDK in a new shell session, you need to source the environment setup script e.g.
       $ . /opt/peta/components/yocto/source/microblaze_lite/environment-setup-microblazeel-v10.0-bs-cmp-ml-xilinx-linux

 
 or when in /opt/peta
 ../petalinux-v2017.4-final-installer.run


SDK Installation
===================

Run mb-gcc
^^^^^^^^^^^^^^^
``mb-gcc`` can't run: bash: no such file or directory:

``file mb-gcc`` : ELF 32-bit LSB executable;

To run 32bit executable file in a 64 bit multi-arch Ubuntu system, you have to add i386 architecture and also you have to install libc6:i386,libncurses5:i386,libstdc++6:i386 these three library packages.

::

  sudo dpkg --add-architecture i386
  sudo apt-get update
  sudo apt-get install libc6:i386 libncurses5:i386 libstdc++6:i386
  ./file-name

Add shared directories
^^^^^^^^^^^^^^^^^^^^^^^^
In virtualbox, add shared library and poste board support, etc. now.


VirtualBox Plugins in Ubuntu
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Frist run VBoxLinuxAddions.run, but prompts: "modprobe vboxfs failed";

Install from Ubuntu repository:

::
 
  sudo apt-get install virtualbox-guest-dkms

Make it again

::

  apt-get gcc make 
  Run virtualbox iso VBoxLinuxAddtions.run: this time everything is OK!
  reboot:
  sudo adduser your_username vboxsf: add user into group vbosf
  logout and login to make the group effective;
  


Enable root
^^^^^^^^^^^^^^^^^

::
  
  sudo -i : sudo as login in as root
  id: dispay user/group id of current user
  passwd root : input new password for root


Open Terminal
^^^^^^^^^^^^^^^^^^^^^^^^^^^^
``CTL+ALT+T`` : Open Terminal
