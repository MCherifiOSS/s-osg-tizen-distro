require pkgmgr.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/slp-pkgmgr;tag=ceb738c1b4e04b9b07cbbc87ec0f4c949e4fbab3;nobranch=1"

BBCLASSEXTEND += " native "

