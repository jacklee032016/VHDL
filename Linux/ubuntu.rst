ubuntu Usage
####################################
Oct.20, 2018


PetaLinux
===================

Pre-requirements
-------------------
 tftpd
 zlib1g-dev and zlib1g-dev:i386


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
