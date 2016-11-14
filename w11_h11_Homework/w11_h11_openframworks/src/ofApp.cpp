#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    meshParameters.add(w.set("Width Number", 50, 1, 100));
    meshParameters.add(h.set("Height Number", 50, 1, 100));
    meshParameters.add(meshSize.set("Mesh Size", 6, 1, 20));
    
    inked.load("inked.mp4");
    inked.play();
    inked.setVolume(0);
    
    fbo.allocate(videoWidth, videoHeight);
    
    fbo.begin();
    ofClear(255, 255, 255, 0);
    fbo.end();
    
    for(int y= 0; y < h; y++){
        for(int x =0; x < w; x++){
            mesh.addVertex(ofPoint(
                                   (x-w/2)*meshSize,
                                   (y-h/2)*meshSize,
                                   0));
            
            mesh.addTexCoord(ofPoint(
                                     x * (videoWidth/w),
                                     y * (videoHeight/h)
                                     ));
            
            mesh.addColor(ofColor(255, 255, 255));
            
        }
    }
    
    for(int y = 0; y < h-1; y++){
        for(int x = 0; x < w-1; x++){
            
            int i1 = x + w *y;
            int i2 = x+1 + w *y;
            int i3 = x + w * (y+1);
            int i4 = x+1 + w * (y+1);
            
            mesh.addTriangle(i1, i2, i3);
            mesh.addTriangle(i2, i3, i4);
        }
    }
    
    gui.setup(meshParameters);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    inked.update();
    
    if(inked.isFrameNew()){
        fbo.begin();
        int alpha = 200;
        
        ofEnableAlphaBlending();
        ofSetColor(255, 255, 255, alpha);
        inked.draw(0, 0);
        ofDisableAlphaBlending();
        
        fbo.end();
    }
    
    fbo.readToPixels(fboPixels);
    image.setFromPixels(fboPixels);
    
    float time = ofGetElapsedTimef();
    
    for(int y = 0; y < h-1; y++){
        for(int x = 0; x< w-1; x++){
            
            int i = x + w * y;
            ofPoint p = mesh.getVertex(i);
            
            float perlin = ofNoise(x*0.5, y*0.5, time *0.05);
            
            
            float scaleX = videoWidth/ w;
            float scaleY = videoHeight/ h;
            
            int index = ((x * scaleX) + videoWidth * (y * scaleY)) * 4;
            
            int brightness = fboPixels[index] / distortion;
            
            p.z = perlin * brightness;
            
            mesh.setVertex(i, p);
            
            mesh.setColor(i, ofColor(perlin*255, perlin*255, perlin*255));
            
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    
    ofBackground(0);
    
    image.bind();
    ofRotate(180);
    mesh.draw();
    
    image.unbind();
    
    cam.end();
    
    gui.draw();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
