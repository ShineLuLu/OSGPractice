#include"../OSGStudyProject/comdepen.h"
#ifdef _DEBUG
#pragma comment(lib,"../x64/Debug/osgAddDepen.lib")
#else
#pragma comment(lib,"../x64/Release/osgAddDepen.lib")
#endif // _DEBUG
#include<osgViewer/Viewer>
#include<osgDB/ReadFile>

int main() {
	osgViewer::Viewer viewer;
	viewer.setSceneData(osgDB::readNodeFile("spaceship.osgt"));
	return viewer.run();
}