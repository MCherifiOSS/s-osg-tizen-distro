DESCRIPTION = "Tizen Buffer Manager Library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by libtbm


#PROVIDES by libtbm-dev
PROVIDES += "libtbm-dev"


RDEPENDS = ""
#RDEPENDS of libtbm-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "libtbm"
RDEPENDS_${PN}-dev += "libdrm"


DEPENDS = ""
#DEPENDS of libtbm
DEPENDS += "libdrm"
DEPENDS += "libpthread-stubs"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libtbm.manifest .
 
 
}
do_patch_append() {
    bb.build.exec_func('do_prep', d)
}

do_configure() {
}

do_compile() {
 cd ${S}
  LANG=C
  export LANG
  unset DISPLAY
  LD_AS_NEEDED=1; export LD_AS_NEEDED ;
  
  
  
  autotools_do_configure
  
  make -j16
  
  
  
}
EXTRA_OECONF += " --prefix=${prefix} CFLAGS="${CFLAGS} -Wall -Werror" LDFLAGS="${LDFLAGS} -Wl,--hash-style=both -Wl,--as-needed""

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 rm -rf ${D}
 mkdir -p ${D}/usr/share/license
 cp -af COPYING ${D}/usr/share/license/libtbm
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " libtbm "
PACKAGES += " libtbm-dev "

libtbm_files = ""
libtbm_files += "/usr/share/license/libtbm"
libtbm_files += "${prefix}/lib/libtbm.so.*"
libtbm_files += "${prefix}/lib/libdrm_slp.so.*"
MANIFESTFILES_${PN} = "libtbm.manifest"

libtbm-dev_files = ""
libtbm-dev_files += "${prefix}/include"
libtbm-dev_files += "${prefix}/include/tbm_bufmgr.h"
libtbm-dev_files += "${prefix}/include/tbm_bufmgr_backend.h"
libtbm-dev_files += "${prefix}/lib/libtbm.so"
libtbm-dev_files += "${prefix}/lib/libdrm_slp.so"
libtbm-dev_files += "${prefix}/lib/pkgconfig/libtbm.pc"
MANIFESTFILES_${PN}-dev = "libtbm.manifest"
DIRFILES_${PN}-dev = ""
DIRFILES_${PN}-dev += "${prefix}/include"

FILES_${PN} = "${libtbm_files}"
FILES_${PN}-dev = "${libtbm-dev_files}"

PKG_libtbm= "libtbm"
PKG_libtbm-dev= "libtbm-dev"

require libtbm-extraconf.inc
