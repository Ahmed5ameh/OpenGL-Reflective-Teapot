#version 330 core

layout (location = 0) in vec3 inPos;
layout (location = 1) in vec3 inNormal;
layout (location = 2) in vec2 inTexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 worldPos;		//out vec3 TexCoords;

void main()
{
	//T R S
	gl_Position = (projection * view * model * vec4(inPos, 1.0))/*.xyzw*/;
	worldPos = inPos;		//TexCoords = aPos;

//	worldPos = inPos;
//    vec4 pos = projection * view * vec4(inPos, 1.0);
//    gl_Position = pos.xyww;
}