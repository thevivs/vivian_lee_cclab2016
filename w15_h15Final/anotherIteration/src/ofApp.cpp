#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    //    particleParameters.add(noiseNum.set("multiplyNoise",25.0,0.00,100.0));
    //    particleParameters.add(noiseX.set("multiplyNoiseX",0.005, 0.000, 0.01));
    //    particleParameters.add(noiseY.set("multiplyNoiseY",0.005, 0.000, 0.01));
    //    particleParameters.add(cosNoise.set("multipleCos", 1.0, 0.0, 1.0));
    //    particleParameters.add(sinNoise.set("multipleSin", 1.0, 0.0, 1.0));
    //    particleParameters.add(num.set("particleAmount", 1000, 100, 2500));
    
    sound.load("bells_30sec.wav");
    sound.play();
    sound.setLoop(true);
    sound.setVolume(1.0);
    
    fftSmooth = new float [8192];
    for (int i = 0; i < 8192; i++) {
        fftSmooth[i] = 0;
    }
    
    bands = 64;
    
    circle.load("bigCircle.png");
    
    ofSetWindowShape(960, 540);
    ofSetBackgroundAuto(false);
    ofBackground(0, 100);
    //    ofEnableAlphaBlending();
    //    ofSetFrameRate(160);
    
    num = 15000;
    
    for(int i = 0; i < num; i++){
        addParticles();
    }


    

    
    //    maskFbo.allocate(ofGetWidth(), ofGetHeight());
    //
    //    maskFbo.begin();
    //    ofClear(255, 255, 255, 70);
    //    maskFbo.end();
    
    //    gui.setup(particleParameters);
    
}
//--------------------------------------------------------------
void ofApp::addParticles(){
    
    Particle p;
    ofVec2f rVel = ofVec2f(ofRandom(-5.0 , 5.0), ofRandom(-5.0, 5.0));
    p.setup(rVel);
    particles.push_back(p);
    
}


//--------------------------------------------------------------
void ofApp::update(){
    
    ofSoundUpdate();
    
    float *value = ofSoundGetSpectrum(bands);
    for(int i = 0; i < bands; i++){
        fftSmooth[i] *= 0.6f;
        if(fftSmooth[i]< value[i]){
            fftSmooth[i] = value[i];
        }
    }
    
    for(int i = 0; i < num; i++){
        particles[i].update(-(fftSmooth[i]*.12));
        //        particles[i].update(noiseNum, noiseX, noiseY, cosNoise, sinNoise);
        particles[i].addRepulsion(particles[i].getPosition(),
                                  particles[i].getRadius()*10.0, 0.1);
        particles[i].addAttraction(particles[i].getPosition(),
                                   particles[i].getRadius()*1.0, 100.1);
        
    }

    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for(int i = 0; i < num; i++){
        for(int j = 0; i <bands; i++){
        particles[i].draw(-(fftSmooth[i]*10));
        particles[i].bounding();
    }
    }
    
    circle.draw(0, 0);
    
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
