# macrokeeb

<center>Simple 10-key Arduino-based macropad with OLED screen and rotary encoder I did for my high school final project.</center>

<br>

![macrokeeb](/images/macrokeeb_final_3.jpg)

## Features

- 10 programmable keys
- 5 layers/modes (General, Windows, Linux, VSCode, Other) which can be switched by pressing the button on the rotary encoder
- Rotary encoder knob changes the audio volume
- OLED screen shows current layer and its predefined macros

## Parts

- 1x Arduino Pro Micro
- 1x I2C OLED display, 128x64, 0.96 inch
- 1x Rotary encoder KY-040
- 10x Mechanical switches, red (any Cherry MX compatible will do)
- 10x Keycaps (any Cherry MX compatible will do)
- 10x Standard signal diodes 1N4148
- 10x LED lights, red, 3mm
- Wires (reused from old Christmas lights)
- 3D printed case

### Tools

- 3D printer
- Soldering iron and solder
- Wire cutters
- Hot glue gun
- Sandpaper

## Case

I used the following and modified it a bit (removed the logo, added hex mesh on the side, added hole...): 
[CODEK - Configurable OLED Display Extension Keyboard](https://www.thingiverse.com/thing:4539723)

![case](/images/macrokeeb_3d_printed_case.jpg)

> ### :bulb: Pro tip:
>
> Use sandpaper to smoothen rough edges, read more [here](https://www.3dsourced.com/guides/sanding-pla/) on how to do it.

## Assembly

![diagram1](/diagrams/assembly_diagram.jpg)

![diagram2](/diagrams/electric_diagram.jpg)

> ### :bulb: Pro tip:
>
> Before putting it all together, test all of your components separately to ensure they all work.

### Steps:

1. Slide the OLED display holder into the top plate. Install the switches into the top plate. Both can be a tight fit, but that shouldn't be a problem. In that case, apply more pressure or sand down the tight parts.

![step1](/images/macrokeeb_assembly_1.jpg)

2. For wiring, refer to the diagrams. Basically, you have to wire the keys in a matrix. For soldering, you can do the following: cut the wires in smaller ones, long enough to wire up one switch with the next one; use one wire per row/column and remove the coating where needed; use one wire per row/column and solder through the coating. I suggest that you use your own technique.

![step2](/images/macrokeeb_assembly_2.jpg)

3. Add signal diodes on all the keys, it will ensure that the microcotroller doesn't read key presses wrong when pressing several keys at once.

![step3](/images/macrokeeb_assembly_3.jpg)

4. Adding LEDs is purely for aesthetics.

![step4](/images/macrokeeb_assembly_4.jpg)

5. Solder wires to the OLED display and rotary encoder too.

![step5](/images/macrokeeb_assembly_5.jpg)

6. Solder everything to the Pro Micro.

![step6](/images/macrokeeb_assembly_6.jpg)

7. Now is the time to load the firmware onto the Pro Micro and test it out and make adjustments as needed before closing the case.

![step7](/images/macrokeeb_assembly_7.jpg)

8. At last, put hot glue on the LEDs, between the base plate and rotary encoder (make sure it will later fit through the hole), between OLED display and OLED display holder, between the Pro Micro and its holder. Basically, put hot glue on every component/piece that you don't want to hear rattling in the case later.

![step8](/images/macrokeeb_final_1.jpg)

9. That's it! Now take a step back and admire your work.

![step9](/images/macrokeeb_final_2.jpg)

## Suggestions, improvements, ideas:

- Add layer with keys F13-F22 and map them with a key mapper software like [AutoHotKey](https://www.autohotkey.com/)
- Add simple games like tetris or pong on the screen and control it with the keys
- Add "gaming" layer where the keys can be w, a, s, d, space etc. and add multi-key press, key press and hold etc.

## Links

- [Pro Micro & Fio V3 Hookup Guide](https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide/all)
- [CODEK - Configurable OLED Display Extension Keyboard](https://www.thingiverse.com/thing:4539723)
- [Programmable Macropad V2](https://www.instructables.com/Programmable-Macropad-V2/)
- [Designing and Building a Macro Pad](https://codevember.org/projects/designing-and-building-a-macro-pad/)
- [Custom Macro Mechanical Keypad](https://www.instructables.com/Custom-Macro-Mechanical-Keypad/)
- [HID library](https://github.com/NicoHood/HID)
- [Adafruit SSD1306 library](https://github.com/adafruit/Adafruit_SSD1306)
- [Adafruit GFX library](https://github.com/adafruit/Adafruit-GFX-Library)