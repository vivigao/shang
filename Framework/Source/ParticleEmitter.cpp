// COMP 371 Assignment Framework
//
// Created by Nicolas Bergeron on 15/7/15.
//         with help from Jordan Rutty
//
// Copyright (c) 2014-2015 Concordia University. All rights reserved.

#include "ParticleEmitter.h"
#include "Model.h"

using namespace glm;

ParticleEmitter::ParticleEmitter(glm::vec3 position, const Model* parent)
: mpParent(parent), mPosition(position)
{}

// This is a point emitter, nothing is random
// As a small extra task, you could create derived classes
// for more interesting emitters such as line emitters or circular emitters
// In these cases, you would sample a random point on these shapes
glm::vec3 ParticleEmitter::GetRandomPosition(){
    // @TODO 7 - Position from Parented Emitter
    //
    // Return the position where the particle is emitted.
    // If the emitter is parented, the position is relative to its parent
	
	vec3 position;
	
    glm::vec4 positionVec = vec4 (mPosition,1);
	if(mpParent){
		positionVec = mpParent->GetWorldMatrix() * positionVec;}

	position = vec3(positionVec[0],positionVec[1],positionVec[2]);
    
    return position;
	
}




