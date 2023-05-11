#version 330 core

layout (location = 0) in vec3 inPos;
layout (location = 1) in vec3 inNormal;
layout (location = 2) in vec2 inTexCoord;

//out vec4 finalColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 worldPos;		//Position
out vec3 normal;
out vec2 texCoord;

void main()
{

	//T R S
	gl_Position = projection * view * model * vec4(inPos, 1.0);

	worldPos = vec3(model * vec4(inPos, 1.0));

	normal = mat3(transpose(inverse(model))) * inNormal;	//normal = normalize( model * inNormal );
	texCoord = inTexCoord;

	// White Pot
	//finalColor = vec4(1.0);

/*TEXTURE CODE*/
//	//T R S
//	gl_Position = projection * view * model * inPos;
//	worldPos = (model * inPos).xyz;
//
//	normal = normalize( model * inNormal );
//
//	// White Pot
//	finalColor = vec4(texCoord, 0.0, 1);
//	texCoord = inTexCoord;
}