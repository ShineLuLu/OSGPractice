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
#include<osgDB/Registry>
#include<osg/PositionAttitudeTransform>

osg::ref_ptr<osg::Node> MatrixOperate();
void ExportANode();
osg::ref_ptr<osg::PositionAttitudeTransform> TransformTrCow();

int main() {
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	/*osg::ref_ptr<osg::Group> group = new osg::Group;
	group->addChild(osgDB::readNodeFile("glider.osg"));*/
    /*viewer->setSceneData(group);*/

	/*viewer->setSceneData(MatrixOperate().get());*/
	viewer->addEventHandler(new osgViewer::StatsHandler);

	/*ExportANode();*/

	osg::ref_ptr<osg::Group> group = new osg::Group;
	group->addChild(MatrixOperate().get());
	//group->addChild(osgDB::readNodeFile("cow.osg"));
	group->addChild(osgDB::readNodeFile("trcow.osg"));
	group->addChild(TransformTrCow().get());

	viewer->setSceneData(group.get());

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
	/*subnode->setMatrix(osg::Matrix::translate(5.0, 0.0, 0.0));*/
	subnode->addUpdateCallback(new osg::AnimationPathCallback(osg::Vec3(0.0, 0.0, 0.0), osg::X_AXIS, 1.0));

	transf->addChild(subnode.get());
	transf->addUpdateCallback(new osg::AnimationPathCallback(osg::Vec3(5.0, 0.0, 0.0), osg::Z_AXIS, 1.0));

	transf2->addChild(subnode.get());
	transf2->addUpdateCallback(new osg::AnimationPathCallback(osg::Vec3(-5.0, 0.0, 0.0), osg::Z_AXIS, 1.0));


	group->addChild(node.get());
	group->addChild(transf.get());
	group->addChild(transf2.get());

	return group;
}

//导出一条x轴移动50的牛模型
void ExportANode()
{
	osg::ref_ptr<osg::Node> node = osgDB::readNodeFile("cow.osg");
	osg::ref_ptr<osg::MatrixTransform> tranode = new osg::MatrixTransform;
	tranode->addChild(node.get());
	tranode->setMatrix(osg::Matrix::translate(50.0, 0.0, 0.0));

	osgDB::ReaderWriter::WriteResult reslut = 
		osgDB::Registry::instance()->writeNode(*tranode.get(), "trcow.osg", osgDB::Registry::instance()->getOptions());

	if (reslut.success()) {
		std::cout << "执行成功！" << std::endl;
		osg::notify(osg::NOTICE) << "excute seccuse !" << std::endl;
	}
}

osg::ref_ptr<osg::PositionAttitudeTransform> TransformTrCow()
{
	osg::ref_ptr<osg::PositionAttitudeTransform> transcow = new osg::PositionAttitudeTransform;
	transcow->addChild(osgDB::readNodeFile("trcow.osg"));
	transcow->setPosition(osg::Vec3(-50.0, 0.0, 0.0));
	return transcow;
}
