//#ifdef _DEBUG
//#pragma comment(lib,"../x64/Debug/osgAddDepen.lib")
//#else
//#pragma comment(lib,"../x64/Release/osgAddDepen.lib")
//#endif // _DEBUG
#include "../OSGStudyProject/comdepen.h"

#include<osgViewer/Viewer>
#include<osgDB/ReadFile>
#include<osgViewer/ViewerEventHandlers>

int main() {
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	viewer->setSceneData(osgDB::readNodeFile("glider.osg"));

	viewer->addEventHandler(new osgViewer::StatsHandler);
	return viewer->run();
}


