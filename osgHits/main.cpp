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

osg::ref_ptr<osg::Geode> CreateLine(const osg::Vec3& start, const osg::Vec3& end);
osg::ref_ptr<osg::Geode> CreateSquareBox();
osg::ref_ptr<osg::Geode> CreateSphere(const osg::Vec3& center);

int main() {
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	osg::ref_ptr<osg::Group> group = new osg::Group;
	osg::Vec3 start = osg::Vec3(-10, 5, -10);
	osg::Vec3 end = osg::Vec3(5, -5, 10);

	osgUtil::LineSegmentIntersector::Intersections intersections;
	osg::ref_ptr<osgUtil::LineSegmentIntersector> lineInter = new osgUtil::LineSegmentIntersector(start, end);
	osg::ref_ptr<osgUtil::IntersectionVisitor> inVisitor = new osgUtil::IntersectionVisitor(lineInter.get());

	/*group->addChild(osgDB::readNodeFile("glider.osg"));*/
	/*创建的盒子*/
	/*group->addChild(CreateSquareBox().get());*/
	/*使用牛的模型*/
	group->addChild(osgDB::readNodeFile("cow.osg"));
	/*参考accept源码方法，使用accept方法后已经计算出了交点，之后再添加的子node不会计算*/
	group->accept(*inVisitor.get());
	/*group->addChild(osgDB::readNodeFile("glider.osg"));*/
	group->addChild(CreateLine(start, end).get());

	/*输出所有的交点*/
	if (lineInter->containsIntersections()) {
		intersections = lineInter->getIntersections();
		for (osgUtil::LineSegmentIntersector::Intersections::iterator iter = intersections.begin(); iter != intersections.end(); iter++) {
			/*交点向量*/
			std::cout << iter->getWorldIntersectPoint().x() << "\t" << iter->getWorldIntersectPoint().y() << "\t" << iter->getWorldIntersectPoint().z() << std::endl;
			/*交点单位向量*/
			std::cout << iter->getWorldIntersectNormal().x() << "\t" << iter->getWorldIntersectNormal().y() << "\t" << iter->getWorldIntersectNormal().z() << std::endl;
			group->addChild(CreateSphere(iter->getWorldIntersectPoint()));
			/*iter++;*/
		}
	}

	viewer->setSceneData(group.get());

	return viewer->run();
}

osg::ref_ptr<osg::Geode> CreateLine(const osg::Vec3 & start, const osg::Vec3 & end)
{
	osg::ref_ptr<osg::Geode> linode = new osg::Geode;
	osg::ref_ptr<osg::Geometry> linetry = new osg::Geometry;
	osg::ref_ptr<osg::Vec3Array> linearray = new osg::Vec3Array;
	linearray->push_back(start);
	linearray->push_back(end);

	linetry->setVertexArray(linearray.get());
	linetry->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::LINES, 0, 2));
	linode->addDrawable(linetry.get());

	return linode;
}

osg::ref_ptr<osg::Geode> CreateSquareBox()
{
	osg::ref_ptr<osg::Geode> box = new osg::Geode;

	/*osg::ref_ptr<osg::Geometry> geo = new osg::Geometry;
	osg::ref_ptr<osg::Vec3Array> lineArray = new osg::Vec3Array;
	osg::ref_ptr<osg::Vec4Array> colorArray = new osg::Vec4Array;

	geo->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::LINES, 0, 2));
	geo->setVertexArray(lineArray.get());
	geo->setColorArray(colorArray.get(), osg::Array::Binding::BIND_PER_VERTEX);
	lineArray->push_back(osg::Vec3(-5.0, 0.0, 0.0));
	lineArray->push_back(osg::Vec3(5.0, 0.0, 0.0));
	colorArray->push_back(osg::Vec4(1.0, 0.8, 0.7, 1.0));*/

	box->addDrawable(new osg::ShapeDrawable(new osg::Box(osg::Vec3(00, 0.0, 0.0), 6.0)));
	/*box->addDrawable(geo.get());*/
	box->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::ON);

	return box;
}

osg::ref_ptr<osg::Geode> CreateSphere(const osg::Vec3 & center)
{
	osg::ref_ptr<osg::Geode> gnode = new osg::Geode;
	gnode->addDrawable(new osg::ShapeDrawable(new osg::Sphere(center, 0.5)));
	return gnode;
}
