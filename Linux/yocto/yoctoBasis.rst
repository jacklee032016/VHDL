Read me for Yocto 
################################
Fev. Sept, 2019

Structure
============================

* meta-openembedded

   * collection of layers of OE core, used by openembedded-core and poky;
   * "meta-": means it is a layer
   
* openembedded-core

   * an independent layer, used to build distro-less image;
   * basic directory structure: scripts|meta|meta-selftest|meta-skeleton;
   * like poky;

* poky

   * contains openembedded-core, eg. use to build image;

* at91

   * contains poky(layers), meta-openembedded (layers), meta-qt(one layer), and meta-atmel(one layer);
   

core-image-minimal is name of recipe, exists in poky/meta/recipes-core/images

MACHINE: layer/conf/machine

DISTRO: layer/conf/distro

layers:

* distro: policies, top level layer
* sw: 
* machine: yocto-bsp


* image-mklibs: reduce shared lib;
* image-prelink: prelink fs image;


* layer: 
* Recipe: one package;
* classes: shared and used by recipes;

