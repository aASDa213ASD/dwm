/*
To generate your own keycodes since they vary from keyboard to keyboard
you can use the following command:
xev | grep --line-buffered -A 4 'KeyPress' > keycodes.txt

Now to transform it into a suitable format for a header file use:
grep "keycode" keycodes.txt | awk '{ sub(/,$/, "", $7); print "#define KEY_" toupper($7) " " $4}' | sed 's/(//g;s/)//g'

Same goes for mouse:
xev | grep --line-buffered -A 3 'ButtonPress' > keycodes.txt

grep "button" keycodes.txt | awk '{ sub(/,$/, "", $4); print "#define MOUSE_" toupper($4) }'

Dont forget to remove keycodes.txt file as you are done
*/

#define MOUSE_LEFT   1
#define MOUSE_RIGHT  3
#define MOUSE_MIDDLE 2

#define KEY_GRAVE 49
#define KEY_1 10
#define KEY_2 11
#define KEY_3 12
#define KEY_4 13
#define KEY_5 14
#define KEY_6 15
#define KEY_7 16
#define KEY_8 17
#define KEY_9 18
#define KEY_0 19
#define KEY_MINUS 20
#define KEY_EQUAL 21
#define KEY_BACKSPACE 22
#define KEY_TAB 23
#define KEY_Q 24
#define KEY_W 25
#define KEY_E 26
#define KEY_R 27
#define KEY_T 28
#define KEY_Y 29
#define KEY_U 30
#define KEY_I 31
#define KEY_O 32
#define KEY_P 33
#define KEY_BRACKETLEFT 34
#define KEY_BRACKETRIGHT 35
#define KEY_BACKSLASH 51
#define KEY_CAPS_LOCK 66
#define KEY_A 38
#define KEY_S 39
#define KEY_D 40
#define KEY_F 41
#define KEY_G 42
#define KEY_H 43
#define KEY_J 44
#define KEY_K 45
#define KEY_L 46
#define KEY_SEMICOLON 47
#define KEY_APOSTROPHE 48
#define KEY_RETURN 36
#define KEY_SHIFT_L 50
#define KEY_Z 52
#define KEY_X 53
#define KEY_C 54
#define KEY_V 55
#define KEY_B 56
#define KEY_N 57
#define KEY_M 58
#define KEY_COMMA 59
#define KEY_PERIOD 60
#define KEY_SLASH 61
#define KEY_SHIFT_R 62
#define KEY_CONTROL_L 37
#define KEY_SUPER_L 133
#define KEY_ALT_L 64
#define KEY_CONTROL_R 105
#define KEY_SUPER_R 134
#define KEY_ALT_R 108
#define KEY_SPACE 65
#define KEY_ESCAPE 9
#define KEY_F1 67
#define KEY_F2 68
#define KEY_F3 69
#define KEY_F4 70
#define KEY_F5 71
#define KEY_F6 72
#define KEY_F7 73
#define KEY_F8 74
#define KEY_F9 75
#define KEY_F10 76
#define KEY_F11 95
#define KEY_F12 96
#define KEY_PRINT 107
#define KEY_SCROLL_LOCK 78
#define KEY_PAUSE 127
#define KEY_LEFT 113
#define KEY_RIGHT 114
#define KEY_DOWN 116
#define KEY_UP 111
#define KEY_DELETE 119
#define KEY_END 115
#define KEY_NEXT 117
#define KEY_PRIOR 112
#define KEY_HOME 110
#define KEY_INSERT 118