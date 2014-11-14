#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetDataPathRoot("../Resources/data/");
    vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(WIDTH, HEIGHT);
    colorLargeImage.allocate(WIDTH, HEIGHT);
    colorSmallImage.allocate(SAMPLE_WIDTH, SAMPLE_HEIGHT);
    grayLargeImage.allocate(WIDTH, HEIGHT);
    graySmallImage.allocate(SAMPLE_WIDTH, SAMPLE_HEIGHT);
    sourceToSampleScale = WIDTH / SAMPLE_WIDTH;
    sampleToSourceScale	= SAMPLE_WIDTH / (float)WIDTH;
    haarFinder.setup("haarcascade_frontalface_default.xml");
    haarTracker.setup(&haarFinder);
    showRectangles = false;
    showMasks = true;
    showInfo = false;
    speakNoEvil.loadImage("mouth.png");
    hearNoEvil.loadImage("ears.png");
    seeNoEvil.loadImage("eyes.png");
}

//--------------------------------------------------------------
void ofApp::update()
{
    ofBackground( 10, 10, 10 );
    bool newGrabberFrame = false;
    vidGrabber.update();
    newGrabberFrame = vidGrabber.isFrameNew();
    if(newGrabberFrame)
    {
        colorLargeImage.setFromPixels(vidGrabber.getPixels(), WIDTH, HEIGHT);
        colorLargeImage.mirror(false, true);
        colorSmallImage.scaleIntoMe(colorLargeImage);
        grayLargeImage	= colorLargeImage;
        graySmallImage	= colorSmallImage;
        haarTracker.findHaarObjects(graySmallImage);
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    int i;
    float x, y, w, h;
    float wRatio, hRatio, scale;
    int faceID;
    float faceMode;
    wRatio = ofGetWidth() / (float)WIDTH;
    hRatio = ofGetHeight() / (float)HEIGHT;
    scale = MIN( wRatio, hRatio );
    glPushMatrix();
    glTranslatef
    (
     (int)( ( ofGetWidth() - ( WIDTH * scale ) ) * 0.5f ),
     (int)( ( ofGetHeight() - ( HEIGHT * scale ) ) * 0.5f ),
     0
     );
    glScalef(scale, scale, 0);
    ofSetHexColor(0xFFFFFF);
    
    // SET COLOR OR BLACK AND WHITE
    colorLargeImage.draw(0, 0);
    
    while( haarTracker.hasNextHaarItem() )
    {
        faceID		= haarTracker.getHaarItemID();
        faceMode	= (faceID % 10) / 10.0f;
        haarTracker.getHaarItemPropertiesEased(&x, &y, &w, &h);
        x	*= sourceToSampleScale;
        y	*= sourceToSampleScale;
        w	*= sourceToSampleScale;
        h	*= sourceToSampleScale;
        ofNoFill();
        if( faceMode > 0.66 )
        {
            if(showMasks == true){
                seeNoEvil.draw(x, y, w, h);
            }
            if(showRectangles == true){
                ofSetHexColor( 0xFF0000 );
            }
        }
        else if( faceMode > 0.33 )
        {
            if(showMasks == true){
                speakNoEvil.draw(x, y, w, h);
            }
            if(showRectangles == true){
                ofSetHexColor( 0x00FF00 );
            }
        }
        else
        {
            if(showMasks == true){
                hearNoEvil.draw(x, y, w, h);
            }
            if(showRectangles == true){
                ofSetHexColor( 0x0000FF );
            }
        }
        if(showRectangles == true){
            ofSetLineWidth(5);
            ofRect(x, y, w, h);
        }
        
    }
    glPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'r'){
        showRectangles = !showRectangles;
    }
    if(key == 's'){
        showMasks = !showMasks;
    }
    if(key == 'i'){
        showInfo = !showInfo;
    }
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
