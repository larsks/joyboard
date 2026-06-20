#!/bin/sh

sudo mount LABEL=RPI-RP2 /mnt &&
    sudo cp joyboard_default.uf2 /mnt
sudo umount /mnt
