//
//  main.cpp
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 9..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#include <GL/glew.h>
#include <GLUT/GLUT.h>
#include <IL/il.h>
#include <IL/ilu.h>
#include <IL/ilut.h>


#include <iostream>
#include <fstream>

using namespace std;


void render() {
    glClearColor(0.0f, 0.0f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void update_fade_factor() {
    
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(400, 300);
    glutCreateWindow("Hello World");
    glutDisplayFunc(&render);
    glutIdleFunc(&update_fade_factor);
    
    GLenum err = glewInit();
    if (GLEW_OK != err) {
        cout << glewGetErrorString(err) << endl;
    }
    cout << "Status: Using GLEW " << glewGetString(GLEW_VERSION) << endl;
    if (!GLEW_VERSION_2_0) {
        cout << "OpenGL 2.0 not available" << endl;
        return 1;
    }
    
    ofstream ofs("test");
    ofs << "hello world" << endl;
    
    glutMainLoop();
    
    return 0;
}
