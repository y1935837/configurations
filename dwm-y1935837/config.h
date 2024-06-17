/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 5;        /* border pixel of windows */
static const int startwithgaps	    = 1;	/* 1 means gaps are used by default */
static const unsigned int gappx     = 60;       /* default gap between windows in pixels */
static const unsigned int snap      = 10;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "jetbrains mono:size=15" };
static const char dmenufont[]       = "jetbrains mono:size=15";
static const char col_gray[]        = "#2c2c2c";
static const char col_cyan[]        = "#adbdc3";
static const char col_green[]       = "#b3b078";
static const char *colors[][3]      = {
	/*               fg          bg         border    */
	[SchemeNorm] = { col_cyan,   col_gray,  col_gray  },
	[SchemeSel]  = { col_green,  col_gray,  col_gray  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Firefox",  NULL,       NULL,       2,            0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.4925; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;      /* number of clients in master area */
static const int resizehints = 1;      /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1;   /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[t]",      tile },    /* first entry is default */
	{ "[f]",      NULL },    /* no layout function means floating behavior */
	{ "[m]",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", col_gray, "-nf", col_cyan, "-sb", col_gray, "-sf", col_green, NULL };
static const char *termcmd[] = { "kitty", NULL };
static const char *suspend[] = { "sudo", "/usr/bin/zzz", NULL };
static const char *screenshot[] = { "/usr/local/bin/screenshot", NULL };

static const Key keys[] = {
  /* modifier                     key        function        argument */
  { MODKEY|ShiftMask,	          XK_s,      spawn,	     {.v = suspend } },
  { MODKEY,                       XK_a,      spawn,          {.v = dmenucmd } },
  { MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
  { MODKEY,                       XK_m,      spawn,          {.v = screenshot } },
  { MODKEY,                       XK_b,      togglebar,      {0} },
  { MODKEY,                       XK_h,      focusstack,     {.i = +1 } },
  { MODKEY,                       XK_j,      focusstack,     {.i = -1 } },
  { MODKEY,                       XK_k,      incnmaster,     {.i = +1 } },
  { MODKEY,                       XK_l,      incnmaster,     {.i = -1 } },
  { MODKEY,                       XK_o,      setmfact,       {.f = -0.05} },
  { MODKEY,                       XK_p,      setmfact,       {.f = +0.05} },
  { MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
  { MODKEY,                       XK_Tab,    view,           {0} },
  { MODKEY,  		          XK_c,      killclient,     {0} },
  { MODKEY,                       XK_y,      setlayout,      {.v = &layouts[0]} },
  { MODKEY,                       XK_u,      setlayout,      {.v = &layouts[1]} },
  { MODKEY,                       XK_i,      setlayout,      {.v = &layouts[2]} },
  { MODKEY,                       XK_space,  setlayout,      {0} },
  { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
  { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
  { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
  { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
  { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
  { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
  { MODKEY,                       XK_minus,  setgaps,        {.i = -5 } },
  { MODKEY,                       XK_equal,  setgaps,        {.i = +5 } },
  { MODKEY|ShiftMask,             XK_minus,  setgaps,        {.i = GAP_RESET } },
  { MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = GAP_TOGGLE} },
  TAGKEYS(                        XK_1,                      0)
  TAGKEYS(                        XK_2,                      1)
  TAGKEYS(                        XK_3,                      2)
  TAGKEYS(                        XK_4,                      3)
  TAGKEYS(                        XK_5,                      4)
  TAGKEYS(                        XK_6,                      5)
  TAGKEYS(                        XK_7,                      6)
  TAGKEYS(                        XK_8,                      7)
  TAGKEYS(                        XK_9,                      8)
  { MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

