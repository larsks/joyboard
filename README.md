# QMK configuration for joystick input device.

This project implements the QMK firmware configuration for the "joyboard" custom input device.

## Overview

The joyboard consists of a joystick, two rotary encoders (with pushbuttons), four arcade buttons, and two 3-way rocker switches.

## Parts list

- [160mmx110mmx90mm project box](https://a.co/d/0czWrPIz)
- [Snap-in round momentary rocker switch](https://a.co/d/0cHW5Blm)
- [EC11 rotary encoder](https://a.co/d/08Swv7bY)
- [24mm arcade buttons](https://a.co/d/00qQOsl5)
- [Seimitsu LS-40 Joystick](https://paradisearcadeshop.com/collections/seimitsu-ls-40-series/products/seimitsu-ls-40-01-se-joystick-black)
- [Waveshare RP2040-Zero](https://www.waveshare.com/rp2040-zero.htm)
- [D-type USB C panel mount](https://a.co/d/0aqtTgPk)

## Pin assignments

```
                      ┌───┐
            5V ─── ┌──└───┘──┐ ─── GP0 BUTTON3
           GND ─── │   USB   │ ─── GP1 BUTTON2
            3V ─── │         │ ─── GP2 ENC0-A
BUTTON1   GP29 ─── │         │ ─── GP3 ENC0-B
BUTTON0   GP28 ─── │         │ ─── GP4 ENC0-Switch
TOGGLE1-A GP27 ─── │         │ ─── GP5 ENC1-A
TOGGLE1-B GP26 ─── │         │ ─── GP6 ENC1-B
TOGGLE0-A GP15 ─── │         │ ─── GP7 ENC1-Switch
TOGGLE0-B GP14 ─── └┬─┬─┬─┬─┬┘ ────GP8
                    │ │ │ │ │
                    │ │ │ │ │
                    G G G G G
                    P P P P P
                    1 1 1 1 9
                    3 2 1 0

           JOYSTICK   U D R L        
```

## Layouts

### Joystick on the side

![CAD drawing with joystick on the left](panel/control_layout_joystick_left.png)

### Joystick centered

![CAD drawing with joystick in the center](panel/control_layout_joystick_center.png)

## Rendered images

![Rendered image showing both panel layouts](panel/panel-rendered.png)
