#pragma once

#include "ofMain.h"
#include "ofxGui.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofVideoPlayer inked;
    ofFbo fbo;
    ofMesh mesh;
    
    ofImage image;
    ofPixels fboPixels;
    
    ofEasyCam cam;
    
    int videoWidth = 480;
    int videoHeight = 270;
    
    //    int w;
    //    int h;
    
    //    int meshSize = 6;
    float distortion = 2;
    
    ofxPanel gui;
    ofParameterGroup meshParameters;
    ofParameter<float> w;
    ofParameter<float> h;
    ofParameter<float> meshSize;
    

		
};
