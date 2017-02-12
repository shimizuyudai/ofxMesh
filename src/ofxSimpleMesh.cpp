#include "ofxSimpleMesh.h"

void ofxSimpleMesh::setup(string filePath)
{
    bool result = json.open(filePath);
    if (result) {
        //cout << json.getRawString() << endl;
        
        //vertices
        auto vertices = json["Vertices"];
        for (auto i = 0; i < vertices.size(); i++) {
            auto vertex = vertices[i];
            mesh.addVertex(ofVec3f(vertex["X"].asFloat(), vertex["Y"].asFloat(), vertex["Z"].asFloat()));
        }
        
        //normals
        auto normals = json["Normals"];
        for (auto i = 0; i < normals.size(); i++) {
            auto normal = normals[i];
            mesh.addNormal(ofVec3f(normal["X"].asFloat(), normal["Y"].asFloat(), normal["Z"].asFloat()));
        }
        
        //indices
        auto indices = json["Indices"];
        for (auto i = 0; i < indices.size(); i++) {
            mesh.addIndex(indices[i].asInt());
        }
        
        //UV
        auto uv = json["UV"];
        for (auto i = 0; i < uv.size(); i++) {
            mesh.addTexCoord(ofVec2f(uv[i]["X"].asFloat(), uv[i]["Y"].asFloat()));
        }
        
    }
    else {
        return;
    }
    
}

ofMesh & ofxSimpleMesh::getMesh()
{
    return mesh;
}
