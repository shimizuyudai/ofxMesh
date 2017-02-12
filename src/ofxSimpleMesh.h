#pragma once
#include "ofMain.h"
#include "ofxJSONElement.h"

class ofxSimpleMesh {
public:
    void setup(string filePath);
    ofMesh& getMesh();
    
private:
    ofMesh mesh;
    ofxJSONElement json;
};
