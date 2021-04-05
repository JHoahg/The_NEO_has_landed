# The_NEO_has_landed
# A cross OS implementation of the NEO keboard layout[1] for the Moonlander Mk I[2]

This layout has been inspired by other peoples work [3]:\
• My Neo2 by eikek \
• Neo2 - normal by magnum\
• Ultimate functional Neo2 by relbeoh\
• Neo2 Inspiration by dlmsr\
• neo2 Linux & Mac (German) by prefectAtEarth\
• neo2-us by wlard

# Featuring:
• Multi OS Support for Unicode characters (see FN layer)\
• command/ctrl - key switch to switch e.g. from CTRL + C to CMD + C (see FN layer)\
• Full implementation of  Neo layer 5 and 6

# How to:
Download the binary or compile the layout from source, than flash with Wally (other flashing utilities haven't been tested).
The OS (Linux/Win10/MacOS) should be configured to use the US International keyboard layout.\
To fully enable the input of unicode characters in MacOS set your input device to »Unicode Hex Input«. The built-in unicode suppot of windows is not great. Thus QMK documentation recommends to use WinCompose [4] to achieve unicode character input on windows.\
A keymap generated by Oryx is included in the repo.

# Why did I do it this way? „Design idea“
I would describe myself as a lazy typist and not really fast.
I chose to put most of the modifiers on the left half and on the thumb pad. This way you can activate all layers with the left hand while you operate the mouse with your right hand (in these situations Neo layer 4 comes in very handy as well). This is also the reason why the function keys are all placed on the left on the FN layer.
I learned to love Auto Shift, it is enabled by default and can be adjusted via the FN layer.
Following that line all special characters of the second layer like ^§ℓ»« etc. can currently only reached via an "On Hold" function of a tap	dance.
Of course you can add a MO modifier to reach this layer, but if you look at other people's solution then layer 2 seems to be a bit awkward to implement.
There are more tap dances hidden on layer 1: on x v c a z. Single tap sends the character, hold gives the shifted version and double tap triggers the CTRL/CMD + letter action.
The CTRL/CMD mode is toggled on the FN layer with the »CtrlTog« key in the outer left column. Hitting the key will send a string with the activated mode(MacOS or Lnx).
On layer 5 and 6 you'll find all the symbols we love Neo for. Depending on your OS you have to change the unicode mode of the keyboard. This can be achieved via the three unicode mode keys (from top to bottom: Mac,Linux,Win) on the far right of the FN-layer.
I wanted a proper arrow key alignment so I switched J and Up-arrow. So far I like it that way.
For the layers 7 and 8, I havent tested these really in game, so there will be probably changes. But I guess a „clean“ layer for gaming would be nice.
If you have ideas or find bugs, drop me a line.\
Have Phun.

# ToDo:
• figure out gaming layers\
• macro key sendinge "sudo rm -rf ." and play the imperial march
while deleting\
• implent a frog pad layer [5] :D or a neo frogpad...


# Documentation
- Use the documentation at [https://docs.qmk.fm/](https://docs.qmk.fm/) to set up your environment for building your firmware.\
- Build your layout against [https://github.com/zsa/qmk_firmware/](https://github.com/zsa/qmk_firmware/) which is our QMK fork (instead of qmk/qmk_firmware).

[1] https://www.neo-layout.org, https://git.neo-layout.org/neo/neo-layout \
[2] https://www.zsa.io/moonlander/ \
[3] https://configure.zsa.io/moonlander/search \
[4] https://github.com/samhocevar/wincompose \
[5] https://github.com/clarkm/dupepad
