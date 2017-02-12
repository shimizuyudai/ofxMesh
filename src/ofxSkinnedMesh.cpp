#include "ofxSkinnedMesh.h"
using namespace cpplinq;

void ofxSkinnedMesh::setup(string filePath)
{
    bool result = json.open(filePath);
    if (result) {
        //cout << json.getRawString() << endl;
        auto meshInfomation = json["Mesh"];
        //vertices
        auto vertices = meshInfomation["Vertices"];
        for (auto i = 0; i < vertices.size(); i++) {
            auto vertex = vertices[i];
            mesh.addVertex(ofVec3f(vertex["X"].asFloat(), vertex["Y"].asFloat(), vertex["Z"].asFloat()));
        }
        
        //normals
        auto normals = meshInfomation["Normals"];
        for (auto i = 0; i < normals.size(); i++) {
            auto normal = normals[i];
            mesh.addNormal(ofVec3f(normal["X"].asFloat(), normal["Y"].asFloat(), normal["Z"].asFloat()));
        }
        
        //indices
        auto indices = meshInfomation["Indices"];
        for (auto i = 0; i < indices.size(); i++) {
            mesh.addIndex(indices[i].asInt());
        }
        
        //UV
        auto uv = meshInfomation["UV"];
        for (auto i = 0; i < uv.size(); i++) {
            mesh.addTexCoord(ofVec2f(uv[i]["X"].asFloat(), uv[i]["Y"].asFloat()));
        }
        
    }
    else {
        return;
    }
    
    auto anim = (json["Animation"]);
    for(auto i = 0; i < anim.size(); i++){
        auto animationInfomation = new AnimationInfomation();
        animationInfomation->frame = anim["Frame"].asInt();
        auto verts = anim["Vertices"];
        for(auto j = 0; j < verts.size(); j++){
            animationInfomation->vertices.push_back(ofVec3f(verts["X"].asFloat(),verts["Y"].asFloat(),verts["Z"].asFloat()));
        }
        animation.push_back(animationInfomation);
    }
    
}

void ofxSkinnedMesh::update(){
}

void ofxSkinnedMesh::setFrame(int frameNumber){
   // frameNumber = min();
}

ofMesh & ofxSkinnedMesh::getMesh()
{
    return mesh;
}
