# QMK configuration for joystick input device.

## Overview

The joyboard consists of a joystick, two encoders (with pushbuttons), four arcade buttons, and two 3-way rocker switches.

## Parts list

| Item           | Detail                                                                                                                          |
| -------------- | ------------------------------------------------------------------------------------------------------------------------------- |
| Enclosure      | [Otdorpatio 160x110x90 mm project box](https://a.co/d/0czWrPIz)                                                                 |
| Rocker switch  | [mxuteuk snap-in round momentary rocker switch](https://a.co/d/0cHW5Blm)                                                        |
| Rotary encoder | [Taiss EC11 rotary encoder](https://a.co/d/08Swv7bY)                                                                            |
| Knobs          | [Tais 20mm black aluminum knob](https://a.co/d/0dfDT7EH)                                                                        |
| Arcade buttons | [EG STARTS 24mm arcade buttons](https://a.co/d/00qQOsl5)                                                                        |
| Joystick       | [Seimitsu LS-40](https://paradisearcadeshop.com/collections/seimitsu-ls-40-series/products/seimitsu-ls-40-01-se-joystick-black) |
| Controller     | [Waveshare RP2040-Zero](https://www.waveshare.com/rp2040-zero.htm)                                                              |

## Pin assignments

| GPIO | Connection  |
| ---- | ----------- |
| 0    | BTN0        |
| 1    | BTN1        |
| 2    | BTN2        |
| 3    | BTN3        |
| 4    | ENC0-Switch |
| 5    | ENC0-A      |
| 6    | ENC0-B      |
| 7    | TGL0-A      |
| 8    | TGL0-B      |
| 9    | JOYX+       |
| 10   | JOYX-       |
| 11   | JOYY+       |
| 12   | JOYY-       |
| 14   | ENC1-Switch |
| 15   | ENC1-A      |
| 26   | ENC1-B      |
| 27   | TGL1-A      |
| 28   | TGL1-B      |

## Layouts

### Joystick on the side

![CAD drawing with joystick on the left](panel/control_layout_joystick_left.png)

### Joystick centered

![CAD drawing with joystick in the center](panel/control_layout_joystick_center.png)

## Rendered images

![Rendered image showing both panel layouts](panel/panel-rendered.png)
