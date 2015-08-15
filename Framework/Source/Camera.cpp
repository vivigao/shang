//
// COMP 371 Assignment Framework
//
// Created by Nicolas Bergeron on 8/7/14.
// Updated by Gary Chang on 14/1/15
//
// Copyright (c) 2014-2015 Concordia University. All rights reserved.
//

#include "Camera.h"
#include <GLM/gtx/transform.hpp>
#include <iostream>

using namespace glm;
using namespace std;

Camera::Camera(){}

Camera::~Camera(){}

mat4 Camera::GetViewProjectionMatrix() const{
	// @TODO 1 - Calculate View Projection Matrix
	//           The projection matrix is hardcoded below
	//           The view matrix is set in the derived camera classes.
	return GetProjectionMatrix() * GetViewMatrix();

/*   mat4 viewProjection(1.0f);
        
    return viewProjection;//*/
}

mat4 Camera::GetProjectionMatrix() const
{	return perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);}
