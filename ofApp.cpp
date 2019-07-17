#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	auto width = 40;
	for (auto len = 100; len < ofGetWidth(); len += width) {

		vector<glm::vec2> vertices;
		for (auto param = 0; param < 100; param++) {

			vertices.push_back(this->make_point(len, param));
		}

		ofNoFill();
		ofBeginShape();
		ofVertices(vertices);
		ofEndShape(true);

		auto param_start = ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.003), 0, 1, 0, 200);
		vector<glm::vec2> in;
		vector<glm::vec2> out;
		for (auto param = param_start; param < param_start + 30; param++) {

			in.push_back(this->make_point(len + width * 0.2, param));
			out.push_back(this->make_point(len + width * 0.8, param));
		}

		reverse(out.begin(), out.end());

		ofFill();
		ofBeginShape();
		ofVertices(in);
		ofVertices(out);
		ofEndShape(true);
	}
}

//--------------------------------------------------------------
glm::vec2 ofApp::make_point(int len, int param) {

	param = param % 100;
	if (param < 25) {

		return glm::vec2(ofMap(param, 0, 25, -len * 0.5, len * 0.5), -len * 0.5);
	}
	else if (param < 50) {

		return glm::vec2(len * 0.5, ofMap(param, 25, 50, -len * 0.5, len * 0.5));
	}
	else if (param < 75) {

		return glm::vec2(ofMap(param, 50, 75, len * 0.5, -len * 0.5), len * 0.5);
	}
	else {

		return glm::vec2(-len * 0.5, ofMap(param, 75, 100, len * 0.5, -len * 0.5));
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}