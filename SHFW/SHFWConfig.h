#ifndef SHFWCONFIG_H
#define SHFWCONFIG_H

#include <iostream>

#define USE3D true
#define SHFWTITLE "SpaceHorizons Framework"
#define FULLSCREEN false
#define MINWINDOWWIDTH 640
#define MINWINDOWHEIGHT 480
#define MAXWINDOWWIDTH GLFW_DONT_CARE
#define MAXWINDOWHEIGHT GLFW_DONT_CARE

#define VSYNC false

#define DEFAULTVERTEXSHADERPATH "shaders/sprite.vert"
#define DEFAULTFRAGMENTSHADERPATH "shaders/sprite.frag"

#define AUTOGENWHITE "#autogen-white-TGA#"

#define DEFAULTFILTER 3 ///< texture filter
#define DEFAULTWRAP 1 ///< texture wraping [0:repeat, 1:mirror, 2:clamp] // Default:1 so we can easily see when we screw up.

#define CLEARCOLOR_RED 0.4f ///< The red component of the color of the window
#define CLEARCOLOR_GREEN 0.4f ///< The green component of the color of the window
#define CLEARCOLOR_BLUE 0.4f ///< The blue component of the color of the window

#ifdef _WIN32
static std::string _prefix = "";
#endif

#ifdef __APPLE__
static std::string _prefix = "";
#endif

#ifdef __linux__
static std::string _prefix = "";
#endif

#endif // !SHFWCONFIG_H