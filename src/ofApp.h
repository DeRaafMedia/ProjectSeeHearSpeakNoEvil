#pragma once

#include "ofMain.h"
#include "ofxCvHaarTracker.h"

#define WIDTH				1280
#define HEIGHT				800
#define SAMPLE_WIDTH		320
#define SAMPLE_HEIGHT		200

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofVideoGrabber vidGrabber;
    ofxCvColorImage colorLargeImage;
    ofxCvColorImage	colorSmallImage;
    ofxCvGrayscaleImage grayLargeImage;
    ofxCvGrayscaleImage graySmallImage;
    ofxCvHaarFinder	haarFinder;
    ofxCvHaarTracker haarTracker;
    float sourceToSampleScale;
    float sampleToSourceScale;
    bool showRectangles;
    bool showMasks;
    bool showInfo;
    ofImage seeNoEvil;
    ofImage speakNoEvil;
    ofImage hearNoEvil;
		
};
