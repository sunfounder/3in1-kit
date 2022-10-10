@REM esptool.exe --chip esp8266 --before no_reset_no_sync erase_flash

@REM esptool.exe --chip esp8266 --before no_reset_no_sync write_flash 0 "v0.9.2.4 AT Firmware-ESPFIX.bin"

esptool.exe --chip esp8266 --before default_reset erase_flash

esptool.exe --chip esp8266 --before default_reset write_flash 0 "BAT_AT_V1.7.1.0_1M.bin"


pause