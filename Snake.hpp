//
//  Snake.hpp
//  of_Snake
//
//  Created by Jung-Wook Park on 10/08/2019.
//
#include <stdio.h>
#include "ofMain.h"
#include "ofMath.h"
#include "Food.hpp"

class Snake {
private:
	int x;
	int y;
	int xSpeed;
	int ySpeed;
	int scale;
	int total;
	bool gotLonger;
	int currentKey;
	std::vector<ofVec2f> tail;


	int width = ofGetWidth();
	int height = ofGetHeight();

public:


	Snake() {
		scale = 20;

		setStartLocation();

		xSpeed = 1;
		ySpeed = 0;
		
		total = 0;
		gotLonger = false;
	}

	void setStartLocation() {
		int cols = floor(ofGetWidth() / scale);
		int rows = floor(ofGetHeight() / scale);


		x = int(ofRandom(cols)) * scale;
		y = int(ofRandom(rows)) * scale;
	}

	void setCurrentKey(int key) {
		currentKey = key;
	}

	int getCurrentKey() {
		return currentKey % 2;
	}

    void direction(int x, int y){
        xSpeed = x;
        ySpeed = y;
    }
    
    void getLonger(){
        total += 1;
        gotLonger = true;
		ofVec2f vec(x, y);
		tail.push_back(vec);
    }

    
	void update() {
		if (tail.size() > 0) {
			for (int i = 0; i < total - 1; i++) {
				tail[i] = tail[i + 1];
			}

			ofVec2f vec(x, y);
			if (total > 0 && !gotLonger) {
				tail[total - 1] = vec;
				
			}
			gotLonger = false;
		}	
            
        x += xSpeed * scale;
        y += ySpeed * scale;
		cout << x << "  " << y << endl;
        x = ofClamp(x, 0, width-scale);
        y = ofClamp(y, 0, height-scale);
    }
    
    void show() {
        ofSetColor(255);
        for(int i = 0; i < total; i++){
            ofDrawRectangle(tail[i].x, tail[i].y, scale, scale);
        }
        ofDrawRectangle(x, y, scale, scale);

    }

	void die() {
		if (tail.size() > 1) {
			for (int i = 0; i < tail.size(); i++) {
				float distance = ofDist(x, y, tail[i].x, tail[i].y);
				if (distance < 1 || x < 0 || y < 0 || x > width || y > height) {
					resetGame();
				}
			}
		}
	}
 
	void resetGame() {
		setStartLocation();
		total = 0;
		tail.clear();
	}

    bool eat(Food food){
        float distance = ofDist(x, y, food.getX(), food.getY());
        
        if(distance < 1){
            return true;
        }else {
            return false;
        }
        
    }
};

