/* See LICENSE file for copyright and license details. */
#include "keycodes.h"

/* appearance */
static const unsigned int refresh_rate    = 60;	 /* matches dwm's mouse event processing to your monitor's refresh rate for smoother window interactions */
static const unsigned int enable_noborder = 1;   /* toggles noborder feature (0=disabled, 1=enabled) */
static const unsigned int borderpx        = 1;   /* border pixel of windows */
static const unsigned int snap            = 26;  /* snap pixel */
static const int swallowfloating          = 1;   /* 1 means swallow floating windows by default */
static const unsigned int systraypinning  = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft   = 0;   /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing  = 5;   /* systray spacing */
static const int systraypinningfailfirst  = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor */
static const int showsystray              = 1;   /* 0 means no systray */
static const int showbar                  = 1;   /* 0 means no bar */
static const int topbar                   = 1;   /* 0 means bottom bar */
#define ICONSIZE                          20     /* icon size */
#define ICONSPACING                       10     /* space between icon and title */
#define SHOWWINICON                       1      /* 0 means no winicon */
static const char *fonts[]                = { "JetBrains Mono:size=16" };
static const char normbordercolor[]       = "#3B4252";
static const char normbgcolor[]           = "#0F0F0F";
static const char normfgcolor[]           = "#D8DEE9";
static const char selbordercolor[]        = "#434C5E";
static const char selbgcolor[]            = "#000000";
static const char selfgcolor[]            = "#ECEFF4";

static const char *colors[][3] = {
    /*               fg           bg           border   */
    [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
    [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor },
};

static const char *const autostart[] = {
    "xset", "s", "off", NULL,
    "xset", "s", "noblank", NULL,
    "xset", "-dpms", NULL,
    "xset", "r", "rate", "150", "30", NULL,
    "dbus-update-activation-environment", "--systemd", "--all", NULL,
    "sh", "-c", "/home/aasda/.scripts/screenlayout/Main.sh", NULL,
    "sh", "-c", "feh --randomize --bg-fill ~/Pictures/Wallpapers/*", NULL,
    "picom", "-b", "--animations", NULL,
    NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5" };
static const char ptagf[] = "[%s %s]"; /* format of a tag label */
static const char etagf[] = "[%s]";    /* format of an empty tag */
static const int lcaselbl = 0;         /* 1 means make tag label lowercase */

static const Rule rules[] = {
    /* class                instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
    { "St",                 NULL,     NULL,           0,         0,          1,          0,         0 },
    { "kitty",              NULL,     NULL,           0,         0,          1,          0,         0 },
    { "lutris",             NULL,     NULL,           0,         1,          0,          0,         0 },
    { "steam_app_default",  NULL,     NULL,           0,         1,          0,          0,         0 },
    { NULL,                 NULL,     "Event Tester", 0,         0,          0,          1,        -1 }, /* xev */
};

/* layout(s) */
static const float mfact = 0.6;      /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;        /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "MODE: TILE",  tile    },   /* first entry is default */
    { "MODE: FLOAT", NULL    },   /* no layout function means floating behavior */
    { "MODE: MONO",  monocle },
};

/* key definitions */
#define ALTKEY Mod1Mask
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define STATUSBAR "dwmblocks"

/* commands */
static const char *launchercmd[] = { "rofi", "-show", "drun", NULL };
static const char *termcmd[]     = { "kitty", NULL };

static Key keys[] = {
    /* mod                          key                        function        argument */
    { MODKEY,                       KEY_R,                      spawn,          {.v = launchercmd} },
    { MODKEY,                       KEY_X,                      spawn,          {.v = termcmd } },
    { MODKEY|ShiftMask|ControlMask, KEY_W,                      spawn,          SHCMD ("feh --randomize --bg-fill ~/Pictures/Wallpapers/*")},
    { MODKEY|ShiftMask|ControlMask, KEY_S,                      spawn,          SHCMD ("~/.scripts/screenshot/screenshot-save.sh")},
    { MODKEY|ShiftMask,             KEY_S,                      spawn,          SHCMD ("~/.scripts/screenshot/screenshot.sh area")},
    { ALTKEY,                       KEY_SHIFT_L,                spawn,          SHCMD ("~/.scripts/keyboardlayout/switch.sh")},
    //{ 0,                            KEY_BRIGHTNESSUP,           spawn,          SHCMD ("xbacklight -inc 10")},
    //{ 0,                            KEY_BRIGHTNESSDOWN,         spawn,          SHCMD ("xbacklight -dec 10")},
    //{ 0,                            XF86XK_AudioLowerVolume,   spawn,          SHCMD ("amixer sset Master 5%- unmute")},
    //{ 0,                            XF86XK_AudioMute,          spawn,          SHCMD ("amixer sset Master $(amixer get Master | grep -q '\\[on\\]' && echo 'mute' || echo 'unmute')")},
    //{ 0,                            XF86XK_AudioRaiseVolume,   spawn,          SHCMD ("amixer sset Master 5%+ unmute")},
    { MODKEY|ShiftMask,             KEY_LEFT,                   setmfact,       {.f = -0.05} },
    { MODKEY|ShiftMask,             KEY_RIGHT,                  setmfact,       {.f = +0.05} },
    { MODKEY|ShiftMask,             KEY_UP,                     setcfact,       {.f = +0.25} },
    { MODKEY|ShiftMask,             KEY_DOWN,                   setcfact,       {.f = -0.25} },
    { MODKEY|ShiftMask,             KEY_B,                      togglebar,      {0} },
    { ALTKEY,                       KEY_TAB,                    focusstack,     {.i = +1 } },
    { MODKEY,			    KEY_LEFT,                   movestack,      {.i = +1 } },
    { MODKEY,			    KEY_RIGHT,                  movestack,      {.i = -1 } },
    { MODKEY,                       KEY_EQUAL,                  incnmaster,     {.i = +1 } },
    { MODKEY,                       KEY_MINUS,                  incnmaster,     {.i = -1 } },
    { MODKEY,                       KEY_RETURN,                 zoom,           {0} },
    { MODKEY,                       KEY_Q,                      killclient,     {0} },
    { MODKEY,                       KEY_T,                      setlayout,      {.v = &layouts[0]} },
    { MODKEY,                       KEY_F,                      setlayout,      {.v = &layouts[1]} },
    { MODKEY,                       KEY_M,                      fullscreen,     {0} },
    { MODKEY,                       KEY_SPACE,                  setlayout,      {0} },
    { MODKEY|ShiftMask,             KEY_M,                      togglefloating, {0} },
    { MODKEY|ShiftMask,             KEY_Y,                      togglefakefullscreen, {0} },
    { MODKEY|ShiftMask,             KEY_Q,                      quit,           {0} },
    TAGKEYS(                        KEY_1,                      0)
    TAGKEYS(                        KEY_2,                      1)
    TAGKEYS(                        KEY_3,                      2)
    TAGKEYS(                        KEY_4,                      3)
    TAGKEYS(                        KEY_5,                      4)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkTagBar,            MODKEY,         MOUSE_LEFT,        tag,            {0} },
    { ClkTagBar,            MODKEY,         MOUSE_RIGHT,       toggletag,      {0} },
    { ClkClientWin,         MODKEY,         MOUSE_LEFT,        moveorplace,    {.i = 2} },
    { ClkClientWin,         MODKEY,         MOUSE_RIGHT,       resizemouse,    {0} },
    { ClkTagBar,            0,              MOUSE_LEFT,        view,           {0} },
    { ClkTagBar,            0,              MOUSE_RIGHT,       toggleview,     {0} },
    { ClkTagBar,            MODKEY,         MOUSE_LEFT,        tag,            {0} },
    { ClkTagBar,            MODKEY,         MOUSE_RIGHT,       toggletag,      {0} },
    { ClkClientWin,         MODKEY,         MOUSE_MIDDLE,      togglefloating, {0} },
    { ClkStatusText,        0,              MOUSE_MIDDLE,      sigstatusbar,   {.i = 2} },
    { ClkWinTitle,          0,              MOUSE_MIDDLE,      zoom,           {0} },
};
