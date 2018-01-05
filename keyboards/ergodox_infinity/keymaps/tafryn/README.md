# Tafryn's ErgoDox Infinity Layout

A basic ErgoDox layout with Planck-like tri-layer support heavily inspired by DudeOfAwesome's layout.

![ErgoDox Layout]()

## Features

- Planck-like tri-layer
- Workman layout
- In-progress gaming layer
- Numpad
- LCD colors are linked together, like the default KLL firmware

## Building and flashing

1. Connect the left-hand side of the ErgoDox to your computer
2. Put the board in DFU mode with either the reset button on the bottom of the board, or with a software key in your current firmware
3. Flash left half:
    ```bash
    $ make ergodox_infinity:dudeofawesome:dfu-util MASTER=left
    ```
4. Disconnect the left-hand side of the ErgoDox from your computer
5. Connect the right-hand side of the ErgoDox to your computer
6. Put the board in DFU mode with either the reset button on the bottom of the board, or with a software key in your current firmware
7. Flash right half:
    ```bash
    $ make ergodox_infinity:dudeofawesome:dfu-util MASTER=right
    ```
