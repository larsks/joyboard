#!/bin/sh
set -e
qmk compile -kb joyboard -km default &&
    cp "$(qmk env QMK_HOME)/joyboard_default.uf2" ./
