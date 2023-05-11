#version 330 core

out vec4 FragColor;

in vec3 worldPos;
in vec3 normal;
in vec2 texCoord;

uniform vec3 lightDirection;
uniform vec3 lightPosition;

uniform vec3 cameraPosition;
uniform samplerCube cubemap;	//skybox

uniform float ambientCoeff;
uniform float diffuseCoeff;
uniform float specularCoeff;

uniform vec4 ambientColor;
uniform vec4 diffuseColor;
uniform vec4 specularColor;

uniform sampler2D diffuseTex;
uniform sampler2D specularTex;

void main()
{
	vec3 normalizedNormal = normalize(normal);
	vec3 normalizeLightDirection = normalize(lightDirection);
	float ndotL = max(dot(normalizedNormal, normalizeLightDirection), 0.0);
	
	vec4 lightValue = vec4(0.0, 0.0, 0.0, 0.0);

	lightValue += ambientCoeff * ambientColor;
	lightValue += diffuseCoeff * ndotL * diffuseColor * texture(diffuseTex, texCoord);

	vec3 directionVec = normalize(worldPos - cameraPosition);		//I
	vec3 viewDir = normalize(cameraPosition - worldPos);	
	vec3 reflectedVec = reflect(directionVec /*ONLY*/, normalize(normal));	//R
	vec3 reflectedRay = normalize(reflect(-normalizeLightDirection, normalizedNormal)).xyz;	

	vec4 cubemapTex = texture(cubemap, reflectedVec) * texture(specularTex, texCoord);

	lightValue += specularColor * specularCoeff * pow( max( dot(reflectedRay, viewDir) , 0.0), 32.0) * texture(specularTex, texCoord);	//de el sa7?

	FragColor = mix(cubemapTex, lightValue, 0.5);


	
	/*MID CODE*/
//	vec4 normalizedNormal = normalize(normal);
//	vec4 normalizeLightDirection = normalize( lightDirection );
//	float ndotL = max(dot(normalizedNormal, normalizeLightDirection), 0.0); 
//	vec4 lightValue = vec4(0.0, 0.0, 0.0, 0.0);
//	lightValue += ambientCoeff * ambientColor;
//	lightValue += diffuseCoeff * ndotL * diffuseColor;
//	vec3 viewDir = normalize(cameraPosition - worldPos);
//	//vec3 reflectedRay = normalize( reflect(-normalizeLightDirection, normalizedNormal) ).xyz;
//	vec3 directionVec = normalize(worldPos - cameraPosition);
//	vec3 reflectedVec = normalize(reflect(directionVec, normalize(normal.xyz)));
//	lightValue += specularColor * specularCoeff * pow( max( dot(reflectedVec, viewDir) , 0.0), 32.0);
//	FragColor = lightValue + vec4(texture(cubemap, reflectedVec).rgb, 1.0);



	//OLD CODE *WORKING*
//	vec3 directionVec = normalize(worldPos - cameraPosition);
//	vec3 reflectedVec = reflect(directionVec, normalize(normal.xyz));
//	//float res = texture(cubemap, reflectedVec);
//	FragColor += vec4(texture(cubemap, reflectedVec).rgb, 1.0);
}