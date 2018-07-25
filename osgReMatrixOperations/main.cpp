#include "NodeMatrix.h"

int main() {
	osg::ref_ptr<osgViewer::Viewer> view = new osgViewer::Viewer;

	view->addEventHandler(new osgViewer::StatsHandler);

	osg::ref_ptr<osg::Group> group = new osg::Group;
	osg::ref_ptr<osg::Node> glider = osgDB::readNodeFile("glider.osg");
	osg::ref_ptr<NodeMatrix> cow = new NodeMatrix;
	cow->addChilds(osgDB::readNodeFile("cow.osg"));
	cow->rotating(osg::Vec3(10.0, 0.0, 0.0), osg::Z_AXIS, 1.0);
	//cow->toRotate(osg::Matrix::translate(10.0, 0.0, 0.0));
	cow->toRotate(10.0, osg::Y_AXIS);

	group->addChild(cow.get());
	group->addChild(glider.get());

	view->setSceneData(group.get());
	return view->run();

	/*osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	osg::ref_ptr<osg::Node> node = osgDB::readNodeFile("cow.osg");
	viewer->setSceneData(node.get());
	return viewer->run();*/
}