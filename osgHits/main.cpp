#include"../OSGStudyProject/comdepen.h"

#ifdef _DEBUG
#pragma comment(lib,"../x64/Debug/osgAddDepen.lib")
#else
#pragma comment(lib,"../x64/Release/osgAddDepen.lib")
#endif // _DEBUG

#include<osgViewer/Viewer>
#include<osgDB/ReadFile>
#include<osg/ShapeDrawable>
#include<osg/LineSegment>

osg::ref_ptr<osg::Geode> CreateSquareBox();

int main() {
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	osg::ref_ptr<osg::Group> group = new osg::Group;

	osgUtil::LineSegmentIntersector::Intersections intersections;
	osg::ref_ptr<osgUtil::LineSegmentIntersector> lineInter = new osgUtil::LineSegmentIntersector(osg::Vec3(-5.0, 0.0, 0.0), osg::Vec3(5.0, 0.0, 0.0));
	osg::ref_ptr<osgUtil::IntersectionVisitor> inVisitor = new osgUtil::IntersectionVisitor(lineInter.get());

	/*group->addChild(osgDB::readNodeFile("glider.osg"));*/
	group->addChild(CreateSquareBox().get());

	/*�ο�acceptԴ�뷽��*/
	group->accept(*inVisitor.get());
	/*������еĽ���*/
	if (lineInter->containsIntersections()) {
		intersections = lineInter->getIntersections();
		for (osgUtil::LineSegmentIntersector::Intersections::iterator iter = intersections.begin(); iter != intersections.end(); iter++) {
			/*��������*/
			std::cout << iter->getWorldIntersectPoint().x() << "\t" << iter->getWorldIntersectPoint().y() << "\t" << iter->getWorldIntersectPoint().z() << std::endl;
			/*���㵥λ����*/
			std::cout << iter->getWorldIntersectNormal().x() << "\t" << iter->getWorldIntersectNormal().y() << "\t" << iter->getWorldIntersectNormal().z() << std::endl;
		}
	}

	viewer->setSceneData(group.get());

	return viewer->run();
}

osg::ref_ptr<osg::Geode> CreateSquareBox()
{
	osg::ref_ptr<osg::Geode> box = new osg::Geode;

	osg::ref_ptr<osg::Geometry> geo = new osg::Geometry;
	osg::ref_ptr<osg::Vec3Array> lineArray = new osg::Vec3Array;

	geo->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::LINES, 0, 2));
	geo->setVertexArray(lineArray.get());
	lineArray->push_back(osg::Vec3(-5.0, 0.0, 0.0));
	lineArray->push_back(osg::Vec3(5.0, 0.0, 0.0));

	box->addDrawable(new osg::ShapeDrawable(new osg::Box(osg::Vec3(00, 0.0, 0.0), 6.0)));
	box->addDrawable(geo.get());

	return box;
}
