#include "ofApp.h"
#include "ofAppGlutWindow.h"

int main() {
    ofAppGlutWindow window;
    ofSetupOpenGL(&window, 1300, 700, OF_WINDOW);
    ofRunApp(new ofApp());
}
