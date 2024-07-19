Dynamic Window Manager
============================
DWM is an extremely fast, small, and dynamic window manager for X

This is my personal fork with following patches:

| Patch name | Description |
| ---------- | ----------- |
| alwayscenter | All floating windows are centered, like the center patch, but without a rule |
| alwaysfullscreen | Do not allow the focus to drift from the active fullscreen client when using focusstack() |
| auto start | This patch will make dwm run "~/.dwm/autostart_blocking.sh" and "~/.dwm/autostart.sh &" before entering the handler loop
| cfacts | Provides the ability to assign different weights to clients in their respective stack |
| chatterino bottom | None |
| cool autostart | Privides the ability to start things along with dwm |
| fakefullscreen client | Resizes the window to fit the whole screen |
| multikeycode | This patch allows you to use a single key combination to trigger different functions based on the number of times you press the key combination consecutively within a short period of time |
| movestack | Allows you to move clients around in the stack and swap them with the master |
| noborder | Remove the border when there is only one window visible |
| pertag | Limit the maximum number of visible clients per tag |
| placemouse | Implementation of a cursor teleportation @see 'warp v2' |
| resizepoint | Allows to resize a window in multiple directions, depends on initial position of resize point |
| statuscmd | Adds the ability to signal a status monitor program such as dwmblocks |
| swallow | Patch introduces window swallowing to dwm |
| switchtag | None |
| systray | A simple system tray implementation; Multi-monitor is also supported; The tray follows the selected monitor; |
| true fullscreen | Makes window trully fullscreen |
| hide vacant tags | None |
| warp v2 | Warps the mouse cursor to the center of a focused window |
| winicon | Shows a window icon on slstatus |

Some patches are rewritten or modified to work together.


Requirements
-------------
In order to build dwm you need the Xlib header files, see [setup.sh](setup.sh)



Installation
------------
Edit config.mk to match your local setup (dwm is installed into
the /usr/local namespace by default)

Afterwards enter the following command to build and install dwm (if
necessary as root):

```
make clean install
```


Running dwm
-----------
Add the following line to your .xinitrc to start dwm using startx:
```
exec dwm
```

In order to connect dwm to a specific display, make sure that
the DISPLAY environment variable is set correctly, e.g.:
```
 DISPLAY=foo.bar:1 exec dwm
```

(This will start dwm on display :1 of the host foo.bar.)

In order to display status info in the bar, you can do something
like this in your .xinitrc:
```
while xsetroot -name "`date` `uptime | sed 's/.*,//'`"
do
    sleep 1
done &
exec dwm
```

Configuration
-------------
The configuration of dwm is done by creating a custom config.h
and (re)compiling the source code.

>[!TIP]
> Create a convenient alias for recompiling dwm. This alias will clean up your build directory by removing unnecessary files if the build command succeeds
> ```bash
> alias smci="sudo make clean install && rm *.o && rm *.orig"
> ```