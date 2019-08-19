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

class Snake{
private:
    int x;
    int y;
    int xSpeed;
    int ySpeed;
    int scale;
    int total;
    bool gotLonger;
    std::vector<ofVec2f> tail;
    
    
    int width = ofGetWidth();
    int height = ofGetHeight();
    
public:
    
    
    Snake(){
        x = 0;
        y = 0;
        xSpeed = 1;
        ySpeed = 0;
        scale = 20;
        total = 0;
        gotLonger = false;
        
        ofVec2f vec(0, 0);
        tail.push_back(vec);
    }
    
    void direction(int x, int y){
        xSpeed = x;
        ySpeed = y;
    }
    
    void getLonger(){
        total += 1;
        gotLonger = true;
		cout << "GOT LONGER!!! " << total << endl;
    }
    
    void update() {
        for(int i = 0; i < total-1; i++){
            tail[i] = tail[i + 1];
        }
        
        ofVec2f vec(x, y);
		if (total > 0) {
			if (gotLonger) {
				//tail.pop_back();
				tail.push_back(vec);
				cout << "got longer  " << vec << "  " << tail.size() << endl;
				cout << "got longer last index " << tail[tail.size() - 1] << "  " << endl;
				gotLonger = false;
			}
			tail[total - 1] = vec;
			cout << "added last index  " << tail[total - 1] << endl;
		}
		for (int i = 0; i <= total; i++) {
			cout << "from update  " << total << "  " << i << "  " << tail[i].x << "  " << tail[i].y << endl;
			//tail[i] = tail[i + 1];
		}

		cout << endl;
            
        x += xSpeed * scale;
        y += ySpeed * scale;
        
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
    
    bool eat(Food food){
        float distance = ofDist(x, y, food.getX(), food.getY());
        
        if(distance < 1){
            return true;
        }else {
            return false;
        }
        
    }
};

