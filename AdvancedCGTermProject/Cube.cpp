//
//  Cube.cpp
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 9..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#include "Cube.h"

using namespace std;


Cube::Cube(float length)
: ::Cube(0, length)
{
    
}

Cube::Cube(GLuint texture, float length)
: _texture(texture)
, _length(length)
, _color(glm::vec3(1.0f))
{
    InitWithLength(length);
}

Cube::~Cube()
{
    
}

void Cube::InitWithLength(float length)
{
    _vertices.clear();

    _vertices.push_back( glm::vec3(-1 * length / 2, -1 * length / 2, length / 2) );
    _vertices.push_back( glm::vec3(1 * length / 2, -1 * length / 2, length / 2) );
    _vertices.push_back( glm::vec3(1 * length / 2, 1 * length / 2, length / 2) );
    _vertices.push_back( glm::vec3(-1 * length / 2, 1 * length / 2, length / 2) );
    
    _vertices.push_back( glm::vec3(-1 * length / 2, -1 * length / 2, -1 * length / 2) );
    _vertices.push_back( glm::vec3(1 * length / 2, -1 * length / 2, -1 * length / 2) );
    _vertices.push_back( glm::vec3(1 * length / 2, 1 * length / 2, -1 * length / 2) );
    _vertices.push_back( glm::vec3(-1 * length / 2, 1 * length / 2, -1 * length / 2) );
}

void Cube::Draw()
{
    bool isEnabledTexture = glIsEnabled(GL_TEXTURE_2D);
    
    glColor3f(_color.x, _color.y, _color.z);
    
    if( _texture != 0 ) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _texture);
        DrawTextureBinded();
    }
    else {
        DrawTextureUnbinded();
    }
    
    
    if( isEnabledTexture ) {
        glEnable(GL_TEXTURE_2D);
    }
    else {
        glDisable(GL_TEXTURE_2D);
    }
}

void Cube::DrawTextureBinded()
{
    glBegin(GL_QUADS);
    {
        // Front Face
        glNormal3f( 0.0f, 0.0f, 1.0f); // Normal Pointing Towards Viewer
        glTexCoord2f(0.0f, 0.0f); VertexByVector3( _vertices[0] );
        glTexCoord2f(1.0f, 0.0f); VertexByVector3( _vertices[1] );
        glTexCoord2f(1.0f, 1.0f); VertexByVector3( _vertices[2] );
        glTexCoord2f(0.0f, 1.0f); VertexByVector3( _vertices[3] );
        // Back Face
        glNormal3f( 0.0f, 0.0f,-1.0f); // Normal Pointing Away From Viewer
        glTexCoord2f(1.0f, 0.0f); VertexByVector3( _vertices[4] );
        glTexCoord2f(1.0f, 1.0f); VertexByVector3( _vertices[5] );
        glTexCoord2f(0.0f, 1.0f); VertexByVector3( _vertices[6] );
        glTexCoord2f(0.0f, 0.0f); VertexByVector3( _vertices[7] );
        // Top Face
        glNormal3f( 0.0f, 1.0f, 0.0f); // Normal Pointing Up
        glTexCoord2f(0.0f, 1.0f); VertexByVector3( _vertices[3] );
        glTexCoord2f(0.0f, 0.0f); VertexByVector3( _vertices[2] );
        glTexCoord2f(1.0f, 0.0f); VertexByVector3( _vertices[6] );
        glTexCoord2f(1.0f, 1.0f); VertexByVector3( _vertices[7] );
        // Bottom Face
        glNormal3f( 0.0f,-1.0f, 0.0f); // Normal Pointing Down
        glTexCoord2f(1.0f, 1.0f); VertexByVector3( _vertices[0] );
        glTexCoord2f(0.0f, 1.0f); VertexByVector3( _vertices[1] );
        glTexCoord2f(0.0f, 0.0f); VertexByVector3( _vertices[5] );
        glTexCoord2f(1.0f, 0.0f); VertexByVector3( _vertices[4] );
        // Right face
        glNormal3f( 1.0f, 0.0f, 0.0f); // Normal Pointing Right
        glTexCoord2f(1.0f, 0.0f); VertexByVector3( _vertices[5] );
        glTexCoord2f(1.0f, 1.0f); VertexByVector3( _vertices[1] );
        glTexCoord2f(0.0f, 1.0f); VertexByVector3( _vertices[2] );
        glTexCoord2f(0.0f, 0.0f); VertexByVector3( _vertices[6] );
        // Left Face
        glNormal3f(-1.0f, 0.0f, 0.0f); // Normal Pointing Left
        glTexCoord2f(0.0f, 0.0f); VertexByVector3( _vertices[0] );
        glTexCoord2f(1.0f, 0.0f); VertexByVector3( _vertices[4] );
        glTexCoord2f(1.0f, 1.0f); VertexByVector3( _vertices[7] );
        glTexCoord2f(0.0f, 1.0f); VertexByVector3( _vertices[3] );
    }
    glEnd(); // Done Drawing Quads

}

void Cube::DrawTextureUnbinded()
{
    glBegin(GL_QUADS);
    {
        // Front Face
        glNormal3f( 0.0f, 0.0f, 1.0f); // Normal Pointing Towards Viewer
        VertexByVector3( _vertices[0] );
        VertexByVector3( _vertices[1] );
        VertexByVector3( _vertices[2] );
        VertexByVector3( _vertices[3] );
        // Back Face
        glNormal3f( 0.0f, 0.0f,-1.0f); // Normal Pointing Away From Viewer
        VertexByVector3( _vertices[4] );
        VertexByVector3( _vertices[5] );
        VertexByVector3( _vertices[6] );
        VertexByVector3( _vertices[7] );
        // Top Face
        glNormal3f( 0.0f, 1.0f, 0.0f); // Normal Pointing Up
        VertexByVector3( _vertices[3] );
        VertexByVector3( _vertices[2] );
        VertexByVector3( _vertices[6] );
        VertexByVector3( _vertices[7] );
        // Bottom Face
        glNormal3f( 0.0f,-1.0f, 0.0f); // Normal Pointing Down
        VertexByVector3( _vertices[0] );
        VertexByVector3( _vertices[1] );
        VertexByVector3( _vertices[5] );
        VertexByVector3( _vertices[4] );
        // Right face
        glNormal3f( 1.0f, 0.0f, 0.0f); // Normal Pointing Right
        VertexByVector3( _vertices[5] );
        VertexByVector3( _vertices[1] );
        VertexByVector3( _vertices[2] );
        VertexByVector3( _vertices[6] );
        // Left Face
        glNormal3f(-1.0f, 0.0f, 0.0f); // Normal Pointing Left
        VertexByVector3( _vertices[0] );
        VertexByVector3( _vertices[4] );
        VertexByVector3( _vertices[7] );
        VertexByVector3( _vertices[3] );
    }
    glEnd(); // Done Drawing Quads
}

void Cube::VertexByVector3(const glm::vec3& pos)
{
    glVertex3f( pos.x, pos.y, pos.z );
}

void Cube::SetTexture(GLuint texture)
{
    _texture = texture;
}

void Cube::SetColor(const glm::vec3& color)
{
    _color = color;
}