//
// COMP 371 Assignment Framework
//
// Created by Nicolas Bergeron on 8/7/14.
// Updated by Gary Chang on 14/1/15
//
// Copyright (c) 2014-2015 Concordia University. All rights reserved.
//

#include "Collision.h"
#include "Animation.h"
#include "World.h"
#include "ParticleEmitter.h"
#include "ParticleDescriptor.h"
#include "ParticleSystem.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/common.hpp>

using namespace std;
using namespace glm;

Collision::Collision() 
: mModel(), cPosition(), mAnimation(nullptr), mParticleSystem(nullptr)
{
}

Collision::~Collision()
{
}

bool Collision::emitParticle(vec3 p){
vec3 cPosition = vec3(-9.999999, -5.458333, 0.907292 );
	
	if (p.x == cPosition.x)
	{
	return true;
	}
	else 
		return false;

	
}


