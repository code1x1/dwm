
static const char *keyboardlayouts[][3] = {
    { "setxkbmap", "us", NULL },
    { "setxkbmap", "de", NULL }
};

static void
update_status(const char *text)
{
    char cmd[256];
    snprintf(cmd, sizeof(cmd), "xsetroot -name \"%s\"", text);
    system(cmd);
}

static void
togglekblayout(const Arg *arg)
{
    static int current = 0;
    
    current = !current;
    
    Arg layoutchange = {.v = keyboardlayouts[current]};
    spawn(&layoutchange);
}
