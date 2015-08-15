// COMP 371 Assignment Framework
//
// Created by Nicolas Bergeron on 8/7/14.
// Updated by Gary Chang on 14/1/15
//
// Copyright (c) 2014-2015 Concordia University. All rights reserved.

#include "Renderer.h"
#include "World.h"
#include "EventManager.h"
#include "Billboard.h"
#include "TextureLoader.h"
#include "BSpline.h"

#include "shader.hpp"
#include "texture.hpp"
#include "controls.hpp"
#include "objloader.hpp"
#include "vboindexer.hpp"

int main(int argc, char*argv[]){
	EventManager::Initialize();
	Renderer::Initialize();
	World world;

/*	// Create and compile our GLSL program from the shaders
	GLuint depthProgramID = LoadShaders( "../Assets/Shaders/DepthRTT.vertexshader", "../Assets/Shaders/DepthRTT.fragmentshader" );

	// Get a handle for our "MVP" uniform
	GLuint depthMatrixID = glGetUniformLocation(depthProgramID, "depthMVP");

	// Load the texture
	GLuint Texture = loadDDS("../Assets/Objects/uvmap.DDS");


	// ---------------------------------------------
	// Render to Texture - specific code begins here
	// ---------------------------------------------

	// The framebuffer, which regroups 0, 1, or more textures, and 0 or 1 depth buffer.
	GLuint FramebufferName = 0;
	glGenFramebuffers(1, &FramebufferName);
	glBindFramebuffer(GL_FRAMEBUFFER, FramebufferName);

	// Depth texture. Slower than a depth buffer, but you can sample it later in your shader
	GLuint depthTexture;
	glGenTextures(1, &depthTexture);
	glBindTexture(GL_TEXTURE_2D, depthTexture);
	glTexImage2D(GL_TEXTURE_2D, 0,GL_DEPTH_COMPONENT16, 1024, 1024, 0,GL_DEPTH_COMPONENT, GL_FLOAT, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_R_TO_TEXTURE);

	glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, depthTexture, 0);

	// No color output in the bound framebuffer, only depth.
	glDrawBuffer(GL_NONE);

	// Always check that our framebuffer is ok
	if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		return false;

	// The quad's FBO. Used only for visualizing the shadowmap.
	static const GLfloat g_quad_vertex_buffer_data[] = { 
		-1.0f, -1.0f, 0.0f,
		 1.0f, -1.0f, 0.0f,
		-1.0f,  1.0f, 0.0f,
		-1.0f,  1.0f, 0.0f,
		 1.0f, -1.0f, 0.0f,
		 1.0f,  1.0f, 0.0f,
	};
	GLuint quad_vertexbuffer;
	glGenBuffers(1, &quad_vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, quad_vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_quad_vertex_buffer_data), g_quad_vertex_buffer_data, GL_STATIC_DRAW);

	// Create and compile our GLSL program from the shaders
	GLuint quad_programID = LoadShaders( "../Assets/Shaders/Passthrough.vertexshader", "../Assets/Shaders/SimpleTexture.fragmentshader" );
	GLuint texID = glGetUniformLocation(quad_programID, "texture");


	// Create and compile our GLSL program from the shaders
	GLuint programID = LoadShaders( "../Assets/Shaders/ShadowMapping.vertexshader", "../Assets/Shaders/ShadowMapping.fragmentshader" );

	// Get a handle for our "myTextureSampler" uniform
	GLuint TextureID  = glGetUniformLocation(programID, "myTextureSampler");

	// Get a handle for our "MVP" uniform
	GLuint MatrixID = glGetUniformLocation(programID, "MVP");
	GLuint ViewMatrixID = glGetUniformLocation(programID, "V");
	GLuint ModelMatrixID = glGetUniformLocation(programID, "M");
	GLuint DepthBiasID = glGetUniformLocation(programID, "DepthBiasMVP");
	GLuint ShadowMapID = glGetUniformLocation(programID, "shadowMap");
	
	// Get a handle for our "LightPosition" uniform
	GLuint lightInvDirID = glGetUniformLocation(programID, "LightInvDirection_worldspace");//*/

	if (argc > 1)
		world.LoadScene(argv[1]);
	else{
		// TODO - You can alternate between different scenes for testing different things
		// Static Scene contains no animation
		// Animated Scene does
#if defined(PLATFORM_OSX)	
		//world.LoadScene("Scenes/AnimatedSceneWithParticles.scene");
		world.LoadScene("Scenes/project.scene");
		world.LoadScene("Scenes/spline.scene");
		//		world.LoadScene("Scenes/AnimatedScene.scene");
		//		world.LoadScene("Scenes/StaticScene.scene");
		//		world.LoadScene("Scenes/CoordinateSystem.scene");
#else
		//world.LoadScene("../Assets/Scenes/AnimatedSceneWithParticles.scene");
		world.LoadScene("../Assets/Scenes/project.scene");
		world.LoadScene("../Assets/Scenes/spline.scene");
		//		world.LoadScene("../Assets/Scenes/AnimatedScene.scene");
		//		world.LoadScene("../Assets/Scenes/StaticScene.scene");
		//		world.LoadScene("../Assets/Scenes/CoordinateSystem.scene");
#endif
	}

	// Main Loop
	do{
		// Render to our framebuffer
/*		glBindFramebuffer(GL_FRAMEBUFFER, FramebufferName);
		glViewport(0,0,1024,1024); // Render on the whole framebuffer, complete from the lower left corner to the upper right*/
		// Update Event Manager - Frame time / input / events processing 
		EventManager::Update();

		// Update World
		float dt = EventManager::GetFrameTime();
		world.Update(dt);

		// Draw World
		world.Draw();

	} while (EventManager::ExitRequested() == false);





/*	glDeleteProgram(depthProgramID);
	
	glDeleteTextures(1, &Texture);

	glDeleteFramebuffers(1, &FramebufferName);
	glDeleteTextures(1, &depthTexture);
	glDeleteBuffers(1, &quad_vertexbuffer);//*/

	Renderer::Shutdown();
	EventManager::Shutdown();

	return 0;
}