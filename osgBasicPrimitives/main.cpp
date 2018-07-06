#include"../OSGStudyProject/comdepen.h"
#ifdef _DEBUG
#pragma comment(lib,"../x64/Debug/osgAddDepen.lib")
#else
#pragma comment(lib,"../x64/Release/osgAddDepen.lib")
#endif // _DEBUG

#include<osgViewer/Viewer>
#include<osgDB/ReadFile>
#include<osg/Geode>
#include<osg/ShapeDrawable>
#include<osg/Material>
#include<osgViewer/ViewerEventHandlers>
#include<osg/LineWidth>


osg::ref_ptr<osg::Geode> CreateBox();
osg::ref_ptr<osg::Node> CreateSimpleNode();

int main() {
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;

	viewer->addEventHandler(new osgViewer::StatsHandler);

	/*osg::ref_ptr<osg::Node> node = new osg::Node;
	node = osgDB::readNodeFile("skydome.osgt");
	viewer->setSceneData(node);*/

	/*viewer->setSceneData(osgDB::readNodeFile("skydome.osgt"));*/

	//viewer->setSceneData(CreateBox());

	//viewer->setSceneData(CreateSimpleNode());

	osg::ref_ptr<osg::Group> group = new osg::Group;
	group->addChild(CreateBox());
	group->addChild(CreateSimpleNode());
	group->addChild(osgDB::readNodeFile("glider.osg"));

	viewer->setSceneData(group.get());

	return viewer->run();
}

osg::ref_ptr<osg::Geode> CreateBox() {
	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	osg::ref_ptr<osg::TessellationHints> hints = new osg::TessellationHints;
	osg::ref_ptr<osg::Material> material = new osg::Material;
	osg::ref_ptr<osg::Image> image;
	osg::ref_ptr<osg::Texture2D> t2d = new osg::Texture2D;

	osg::ref_ptr<osg::ShapeDrawable> drawable = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0.0f,0.0f,0.0f),1.0f,1.0f,1.0f), hints.get());
	/*drawable->setColor(osg::Vec4(0.5, 0.5, 0.5, 0.5));*/
	drawable->setColor(osg::Vec4(1.0, 1.0, 1.0, 0.4));
	hints->setDetailRatio(0.5);
	material->setAmbient(osg::Material::FRONT_AND_BACK, osg::Vec4(1.0, 0.0, 0.0, 1.0));
	material->setDiffuse(osg::Material::FRONT_AND_BACK, osg::Vec4(0.0, 1.0, 0.0, 0.2));
	material->setSpecular(osg::Material::FRONT_AND_BACK, osg::Vec4(1.0, 0.0, 0.0, 0.0));
	material->setShininess(osg::Material::FRONT_AND_BACK, 64.0);
	geode->getOrCreateStateSet()->setAttributeAndModes(material.get(), osg::StateAttribute::ON);
	geode->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::ON);
	geode->getOrCreateStateSet()->setMode(GL_DEPTH_TEST, osg::StateAttribute::ON);

	image = osgDB::readImageFile("Images/AoiImage/chinawords.jpeg");
	if (image.valid()) {
		t2d->setImage(0, image.get());
	}

	/*使用下面注释掉的方法会出现warning*/
	geode->getOrCreateStateSet()->setTextureAttributeAndModes(0, t2d.get(), osg::StateAttribute::ON);
	/*geode->getOrCreateStateSet()->setAttributeAndModes(t2d.get(),osg::StateAttribute::ON);*/

	geode->addDrawable(drawable.get());

	return geode;
}

osg::ref_ptr<osg::Node> CreateSimpleNode()
{
	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	osg::ref_ptr<osg::Geometry> geome = new osg::Geometry;
	osg::ref_ptr<osg::Image> image;
	osg::ref_ptr<osg::Texture2D> t2d = new osg::Texture2D;
	osg::ref_ptr<osg::Material> material = new osg::Material;
	osg::ref_ptr<osg::Vec3Array> coord = new osg::Vec3Array;
	osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
	osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array;
	osg::ref_ptr<osg::LineWidth> width = new osg::LineWidth;

	/*设置线宽*/
	width->setWidth(5.0);

	/*设置光照*/
	material->setDiffuse(osg::Material::Face::FRONT_AND_BACK, osg::Vec4(0.4, 0.5, 0.6, 0.3));
	material->setSpecular(osg::Material::Face::FRONT_AND_BACK, osg::Vec4(0.6, 0.5, 0.4, 0.3));
	material->setShininess(osg::Material::Face::FRONT_AND_BACK, 64.0);

	/*设置图片*/
	image = osgDB::readImageFile("Images/AoiImage/chinawords.jpeg");
	if (image.valid()) {
		t2d->setImage(0, image.get());
	}

	geome->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::Mode::LINE_LOOP, 0, 4));
	geome->setVertexArray(coord.get());
	geome->setColorArray(colors.get(), osg::Array::Binding::BIND_PER_VERTEX);
	geome->setNormalArray(normals, osg::Array::Binding::BIND_OVERALL);

	/*设置顶点*/
	coord->push_back(osg::Vec3(0.0, -10.0, 0.0));
	coord->push_back(osg::Vec3(10.0, -10.0, 0.0));
	coord->push_back(osg::Vec3(10.0, -10.0, 10.0));
	coord->push_back(osg::Vec3(0.0, -10.0, 10.0));

	/*设置颜色*/
	colors->push_back(osg::Vec4(1.0, 0.0, 0.0, 0.4));
	colors->push_back(osg::Vec4(1.0, 1.0, 0.0, 0.4));
	colors->push_back(osg::Vec4(1.0, 0.0, 1.0, 0.4));
	colors->push_back(osg::Vec4(1.0, 1.0, 1.0, 0.4));

	/*设置的为自身的法线？ 光照向y轴负轴，y取-1反转图形，将照亮的面置于前面*/
	normals->push_back(osg::Vec3(0.0, -1.0, 0.0));


	geode->getOrCreateStateSet()->setAttribute(width.get(), osg::StateAttribute::ON);
	//geode->getOrCreateStateSet()->setAttributeAndModes(material.get(), osg::StateAttribute::ON);
	geode->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::ON);
	//geode->getOrCreateStateSet()->setTextureAttributeAndModes(0, t2d.get(), osg::StateAttribute::ON);
	geode->addDrawable(geome.get());

	return geode;
}
