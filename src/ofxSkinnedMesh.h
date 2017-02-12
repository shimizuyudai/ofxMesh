#pragma once
#include "ofMain.h"
#include "ofxJSONElement.h"
#include "cpplinq.hpp"
class ofxSkinnedMesh{
public:
    void setup(string filePath);
    void update();
    void setFrame(int frameNumber);
    ofMesh& getMesh();
    
private:
    ofMesh mesh;
    ofxJSONElement json;
    int frameCount;
    
    class AnimationInfomation{
    public:
        int frame;
        vector<ofVec3f> vertices;
    };
    vector<AnimationInfomation*> animation;
};
