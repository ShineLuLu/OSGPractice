#include"../OSGStudyProject/comdepen.h"
#ifdef _DEBUG
#pragma comment(lib,"../x64/Debug/osgAddDepen.lib")
#else
#pragma comment(lib,"../x64/Release/osgAddDepen.lib")
#endif // _DEBUG

#include<osgViewer/Viewer>
#include<osgDB/ReadFile>
#include<osgViewer/ViewerEventHandlers>
#include<osg/MatrixTransform>

osg::ref_ptr<osg::Node> MatrixOperate();

int main() {
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	/*osg::ref_ptr<osg::Group> group = new osg::Group;
	group->addChild(osgDB::readNodeFile("glider.osg"));*/
    /*viewer->setSceneData(group);*/

	viewer->setSceneData(MatrixOperate().get());
	viewer->addEventHandler(new osgViewer::StatsHandler);

	return viewer->run();
}

osg::ref_ptr<osg::Node> MatrixOperate()
{
	osg::ref_ptr<osg::Group> group = new osg::Group;
	osg::ref_ptr<osg::MatrixTransform> transf = new osg::MatrixTransform;
	osg::ref_ptr<osg::MatrixTransform> transf2 = new osg::MatrixTransform;
	osg::ref_ptr<osg::Node> node = osgDB::readNodeFile("glider.osg"); 
	osg::ref_ptr<osg::MatrixTransform> subnode = new osg::MatrixTransform;
	/*subnode->addChild(node.get());
	transf->addChild(subnode.get());
	transf2->addChild(node.get());
	transf->setMatrix(osg::Matrix::translate(5.0, 0.0, 0.0));
	transf2->setMatrix(osg::Matrix::translate(5.0, -5.0, 0.0));

	subnode->addUpdateCallback(new osg::AnimationPathCallback(osg::Vec3(5.0, 0.0, 0.0), osg::X_AXIS, 1.0));*/

	subnode->addChild(node.get());
	subnode->setMatrix(osg::Matrix::translate(5.0, 0.0, 0.0));
	transf->addChild(subnode.get());
	transf->addUpdateCallback(new osg::AnimationPathCallback(osg::Vec3(0.0, 0.0, 0.0), osg::Z_AXIS, 1.0));

	transf2->addChild(node.get());


	group->addChild(node.get());
	group->addChild(transf.get());
	group->addChild(transf2.get());

	return group;
}
