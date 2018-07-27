#include "TravelManipulator.h"


int main() {
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	/*osg::ref_ptr<osg::Node> node = osgDB::readNodeFile("cow.osg");*/
	/*viewer->setSceneData(node.get());*/
	osg::ref_ptr<NodeMatrix> ceepNode = new NodeMatrix;
	ceepNode->addChilds(osgDB::readNodeFile("ceep.ive"));
	viewer->setCameraManipulator(new TravelManipulator());
	ceepNode->toPosition(osg::Vec3(0.0, 0.0, 0.0));

	viewer->setSceneData(ceepNode.get());
	/*viewer->addEventHandler(new osgViewer::StatsHandler);*/
	return viewer->run();
}

