require Modello-Multimediaplayer.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Multimediaplayer;tag=0ec7168712a008ba2d2e828baf2e1e3645bc2be4;nobranch=1"

BBCLASSEXTEND += " native "

