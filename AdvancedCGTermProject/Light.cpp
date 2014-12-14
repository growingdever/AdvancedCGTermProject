//
//  Light.cpp
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 9..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#include "Light.h"


Light::Light(GLuint lightID)
{
	LightID = lightID;
}

bool Light::Init() 
{
	if( ! Node::Init() ) {
		return false;
	}

	glEnable(LightID);
    glLightfv(LightID, GL_AMBIENT, LightAmbient);
    glLightfv(LightID, GL_DIFFUSE, LightDiffuse);
    glLightfv(LightID, GL_SPECULAR, LightSpecular);
    glLightfv(LightID, GL_POSITION, LightPosition);
    SetAttenuation(GL_CONSTANT_ATTENUATION, 2.0);
    SetAttenuation(GL_LINEAR_ATTENUATION, 1.0);
    SetAttenuation(GL_QUADRATIC_ATTENUATION, 0.5);
    
    SetPosition(_position);

	return true;
}

void Light::Draw()
{
    glLightfv(LightID, GL_AMBIENT, LightAmbient);
    glLightfv(LightID, GL_DIFFUSE, LightDiffuse);
    glLightfv(LightID, GL_SPECULAR, LightSpecular);
    glLightfv(LightID, GL_POSITION, LightPosition);
    glLightf(LightID, GL_CONSTANT_ATTENUATION, LightAttenuation[ATTENUATION_TYPE_CONSTANT]);
    glLightf(LightID, GL_LINEAR_ATTENUATION, LightAttenuation[ATTENUATION_TYPE_LINEAR]);
    glLightf(LightID, GL_QUADRATIC_ATTENUATION, LightAttenuation[ATTENUATION_TYPE_QUADRATIC]);
}

void Light::SetPosition(const glm::vec3& vec)
{
	Node::SetPosition(vec);

	LightPosition[0] = _position.x;
	LightPosition[1] = _position.y;
	LightPosition[2] = _position.z;
}

void Light::SetEnabled(bool enable)
{
    this->enable = enable;
    if( enable ) {
        glEnable(LightID);
    }
    else {
        glDisable(LightID);
    }
}

void Light::SetAmbient(float r, float g, float b, float a)
{
	LightAmbient[0] = r;
	LightAmbient[1] = g;
	LightAmbient[2] = b;
	LightAmbient[3] = a;
	glLightfv(LightID, GL_AMBIENT, LightAmbient);
}

void Light::SetDiffuse(float r, float g, float b, float a)
{
	LightDiffuse[0] = r;
	LightDiffuse[1] = g;
	LightDiffuse[2] = b;
	LightDiffuse[3] = a;
	glLightfv(LightID, GL_DIFFUSE, LightDiffuse);
}

void Light::SetSpecular(float r, float g, float b, float a)
{
    LightSpecular[0] = r;
    LightSpecular[1] = g;
    LightSpecular[2] = b;
    LightSpecular[3] = a;
    glLightfv(LightID, GL_SPECULAR, LightSpecular);
}

void Light::SetAttenuation(GLuint attenuationType, float d)
{
    // default type is constant
    int i = ATTENUATION_TYPE_CONSTANT;
    switch( attenuationType ) {
        case GL_CONSTANT_ATTENUATION:
            i = ATTENUATION_TYPE_CONSTANT;
            break;
        case GL_LINEAR_ATTENUATION:
            i = ATTENUATION_TYPE_LINEAR;
            break;
        case GL_QUADRATIC_ATTENUATION:
            i = ATTENUATION_TYPE_QUADRATIC;
            break;
    }
    
    LightAttenuation[i] = d;
    
    glLightf(LightID, GL_CONSTANT_ATTENUATION, LightAttenuation[ATTENUATION_TYPE_CONSTANT]);
    glLightf(LightID, GL_LINEAR_ATTENUATION, LightAttenuation[ATTENUATION_TYPE_LINEAR]);
    glLightf(LightID, GL_QUADRATIC_ATTENUATION, LightAttenuation[ATTENUATION_TYPE_QUADRATIC]);
}

GLfloat* Light::GetAmbient()
{
    return LightAmbient;
}

GLfloat* Light::GetDeffuse()
{
    return LightDiffuse;
}

GLfloat* Light::GetSpecular()
{
    return LightSpecular;
}

GLfloat Light::GetAttenuation(GLuint attenuationType)
{
    int i = ATTENUATION_TYPE_CONSTANT;
    switch( attenuationType ) {
        case GL_CONSTANT_ATTENUATION:
            i = ATTENUATION_TYPE_CONSTANT;
            break;
        case GL_LINEAR_ATTENUATION:
            i = ATTENUATION_TYPE_LINEAR;
            break;
        case GL_QUADRATIC_ATTENUATION:
            i = ATTENUATION_TYPE_QUADRATIC;
            break;
    }
    
    return LightAttenuation[i];
}