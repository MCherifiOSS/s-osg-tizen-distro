LICENSE = "GPL"
inherit gnome
inherit autotools_stage
PR = "r2"

SRC_URI += "file://pkgconfig.patch;patch=1"

DEPENDS += "shared-mime-info intltool-native"
RDEPENDS = "shared-mime-info"
