# Tafryn's ErgoDox Infinity Layout

A basic ErgoDox layout with Planck-like tri-layer support heavily inspired by DudeOfAwesome's layout.

![ErgoDox Layout](https://i.imgur.com/6GPqfx9.jpg)

## Features

- Planck-like tri-layer
- Qwerty, Dvorak, Colemak, and Workman default layouts
- Mouse layer
- Gamepad layer with quick chat access to default layout
- Numpad layer
- LCD colors are linked together, like the default KLL firmware

## Building and flashing

1. Connect the left-hand side of the ErgoDox to your computer
2. Put the board in DFU mode with either the reset button on the bottom of the board, or with a software key in your current firmware
3. Flash left half:
    ```bash
    $ make ergodox_infinity:tafryn:dfu-util MASTER=left
    ```
4. Disconnect the left-hand side of the ErgoDox from your computer
5. Connect the right-hand side of the ErgoDox to your computer
6. Put the board in DFU mode with either the reset button on the bottom of the board, or with a software key in your current firmware
7. Flash right half:
    ```bash
    $ make ergodox_infinity:tafryn:dfu-util MASTER=right
    ```
