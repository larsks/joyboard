#!/bin/bash

if ! [[ -f qmk_firmware/joyboard_default.uf2 ]]; then
  echo "joyboard firmware is missing (maybe you need to run compile.sh)" >&2
  exit 1
fi

sudo mount LABEL=RPI-RP2 /mnt &&
  sudo cp qmk_firmware/joyboard_default.uf2 /mnt
sudo umount /mnt
