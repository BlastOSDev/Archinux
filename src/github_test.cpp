#include <X11/Xlib.h>

int main() {
    // Initialize Xlib
    Display* display = XOpenDisplay(nullptr);
    if (!display) {
        // Handle the error if XOpenDisplay fails
        return 1;
    }

    // Create a basic X11 window
    int screen = DefaultScreen(display);
    Window root = RootWindow(display, screen);

    Window window = XCreateSimpleWindow(
        display, root,
        100, 100, // x, y
        400, 400, // width, height
        1,        // border width
        BlackPixel(display, screen),
        WhitePixel(display, screen)
    );

    XMapWindow(display, window);
    XFlush(display);

    // Event loop (you can add event handling logic here)
    XEvent event;
    while (true) {
        XNextEvent(display, &event);
        // Handle X11 events here
    }

    // Cleanup and close the X11 display
    XCloseDisplay(display);

    return 0;
}
