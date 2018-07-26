#include "TravelManipulator.h"

int main() {
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	osg::ref_ptr<osg::Node> node = osgDB::readNodeFile("cow.osg");

	viewer->setSceneData(node.get());
	/*viewer->addEventHandler(new osgViewer::StatsHandler);*/
	viewer->setCameraManipulator(new TravelManipulator());
	return viewer->run();
}

