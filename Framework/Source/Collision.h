
#pragma once

#include "ParsingHelper.h"
//#include "Model.h"

#include <vector>

#include <GLM/glm.hpp>

class Animation;
class ParticleSystem;
class Model;

class Collision
{
public:
	Collision();
	virtual ~Collision();
	Model *mModel;
	glm::vec3 cPosition;
	bool emitParticle(glm::vec3 p);
	glm::vec3 GetPosition() const		{ return cPosition; }


protected:
	//virtual bool ParseLine(const std::vector<ci_string> &token) = 0;

    // Makes the model follow a list of Animation Keys so it's world transform changes over time
    Animation *mAnimation;
    ParticleSystem *mParticleSystem;
    
	friend class Animation;
};
