#include"../OSGStudyProject/comdepen.h"
#ifdef _DEBUG
#pragma comment(lib,"../x64/Debug/osgAddDepen.lib")
#else
#pragma comment(lib,"../x64/Release/osgAddDepen.lib")
#endif // _DEBUG

#include<osgViewer/Viewer>
#include<osgDB/ReadFile>
#include<osgViewer/ViewerEventHandlers>

osg::ref_ptr<osg::Node> MatrixOperate();

int main() {
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	osg::ref_ptr<osg::Group> group = new osg::Group;

	group->addChild(osgDB::readNodeFile("glider.osg"));

	viewer->setSceneData(group);
	viewer->addEventHandler(new osgViewer::StatsHandler);

	return viewer->run();
}

osg::ref_ptr<osg::Node> MatrixOperate()
{

	return osg::ref_ptr<osg::Node>();
}
