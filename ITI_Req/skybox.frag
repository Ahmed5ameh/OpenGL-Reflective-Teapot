#version 330 core

out vec4 FragColor;
	
in vec3 worldPos;

uniform samplerCube cubemap;	//skybox

void main()
{
	FragColor = texture(cubemap, worldPos); //vec4(0, abs(worldPos.y), 0, 1.0);
}