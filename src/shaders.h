#ifndef SHADERS_H
#define SHADERS_H

#include <string>

namespace shaders{
	std::string vertex_shader =
	 	"#version 450 core                      \n"
     	"                                       \n"
     	"layout(location = 0) in vec4 positions;\n"
     	"void main()                            \n"
     	"{                                      \n"
     	"   gl_Position =  positions;           \n"
     	"}                                      \n";
	std::string fragment_shader =
	 	"#version 450 core                      \n"
     	"                                       \n"
     	"layout(location = 0) out vec4 color;   \n"
     	"void main()                            \n"
     	"{                                      \n"
     	"   color = vec4(1.0, 0.0, 0.0, 1.0);   \n"
     	"}                                      \n";
}

#endif