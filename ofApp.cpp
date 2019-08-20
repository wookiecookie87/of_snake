#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(51);
    ofSetFrameRate(10);
    food.setLocation();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    snake.update();
	snake.die();
}

//--------------------------------------------------------------
void ofApp::draw(){
    snake.show();
    food.show();
    if(snake.eat(food)){
        food.setLocation();
        snake.getLonger();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (snake.getCurrentKey() != key % 2) {
		snake.setCurrentKey(key);
		if (key == OF_KEY_LEFT) {//57356
			snake.direction(-1, 0);
		}
		else if (key == OF_KEY_RIGHT) {//57358
			snake.direction(1, 0);
		}
		else if (key == OF_KEY_UP) {//57357
			snake.direction(0, -1);
		}
		else if (key == OF_KEY_DOWN) {//57359
			snake.direction(0, 1);
		}
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
