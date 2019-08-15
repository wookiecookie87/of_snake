
#include <stdio.h>
#include "ofMain.h"

class Food {
private:
    int x;
    int y;
    int scale;
    
public:
    Food() {
        scale = 20;
        
    }
    
    void setLocation() {
        int cols = floor(ofGetWidth()/scale);
        int rows =  floor(ofGetHeight()/scale);
        
        
        x = int(ofRandom(cols)) * scale;
        y = int(ofRandom(rows)) * scale;
    }
    
    int getX(){
        return x;
    }
    
    int getY() {
        return y;
    }
    
    void show() {
        ofSetColor(255, 0, 100);
        ofDrawRectangle(x, y, scale, scale);
    }
    
};
