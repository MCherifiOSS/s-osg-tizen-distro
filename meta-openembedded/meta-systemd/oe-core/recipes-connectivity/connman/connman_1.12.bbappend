PRINC := "${@int(PRINC) + 2}"

RPROVIDES_${PN} += "${PN}-systemd"
SYSTEMD_SERVICE_${PN} = "connman.service"
