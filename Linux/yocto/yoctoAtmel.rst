Read me for OpenEmbedded 
################################
Fev. Sept, 2019

Build
============================

Download files
----------------------
::

    git clone git://git.yoctoproject.org/poky -b sumo

    git clone git://git.openembedded.org/meta-openembedded -b sumo
	
	    git://github.com/openembedded/openembedded-core 


    git clone git://code.qt.io/yocto/meta-qt5.git : QT is optional


    git clone git://github.com/linux4sam/meta-atmel.git -b sumo  

    cd poky

    source oe-init-build-env build-microchip : build-microchip is build directory



Command line
---------------
::

   oe-init-build-env   <builddir> build-microchip

It calls following 2 scripts:
::
   
   oe-buildenv-internal: build environment for yocto project
   
   oe-setup-builddir: create BUILD directory, and create conf/local.conf and conf/bblayers.conf


Configuration
-----------------

local.conf
++++++++++++++++++++++++

MARCHINE
DL_DIR
PACKAGE_CLASSES
USER_CLASSES
DISTRO="poky-atmel"


bblayers.conf
++++++++++++++++++++++++

  ${BSPDIR}/poky/meta \
  ${BSPDIR}/poky/meta-poky \
  ${BSPDIR}/poky/meta-yocto-bsp \
  ${BSPDIR}/meta-atmel \
  ${BSPDIR}/meta-openembedded/meta-oe \
  ${BSPDIR}/meta-openembedded/meta-networking \
  ${BSPDIR}/meta-openembedded/meta-python \
  ${BSPDIR}/meta-openembedded/meta-multimedia \
   

   