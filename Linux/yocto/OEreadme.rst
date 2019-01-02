Read me for OpenEmbedded 
################################
Jan. 1st, 2019

The targets prompted after oe-init-build-env has been finished are recipe files, and which are come from OE/meta/conf/conf-notes.txt;

In OE build environment, only one layer exists, eg. OE/meta/;

All bb files are parsed in this layer (or in this directory), without hiearchi relationship. Using command ``bitbake -s -DD`` can check all the recipes;

``bitbake -e -DD`` show environment;

core-image-minimal, core-image-base, core-image-sat are some top level targets for images, which are also recipe files, eg. ***.bb; 
So you can build images with these target, or build any package directory with ``bitbake BB.bb``;

The 'core-image' package which is inherited by core-image-minimal, core-image-base, and core-image-sat, are class file defined in 'classes' directory;

'packagegroup.bbclass' is also inherited by packagegroup_***.bb files;

   