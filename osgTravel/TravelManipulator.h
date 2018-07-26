#pragma once
#include"../OSGStudyProject/comdepen.h"
#ifdef _DEBUG
#pragma comment(lib,"../x64/Debug/osgAddDepen.lib")
#else
#pragma comment(lib,"../x64/Release/osgAddDepen.lib")
#endif // _DEBUG

#include<osgGA/StandardManipulator>
#include<osgViewer/Viewer>
#include<osgViewer/ViewerEventHandlers>
#include<osgDB/ReadFile>

class TravelManipulator :public osgGA::StandardManipulator
{
public:
	TravelManipulator();
	~TravelManipulator();
public:
	// Í¨¹ý StandardManipulator ¼Ì³Ð
	virtual void setByMatrix(const osg::Matrixd & matrix) override;
	virtual void setByInverseMatrix(const osg::Matrixd & matrix) override;
	virtual osg::Matrixd getMatrix() const override;
	virtual osg::Matrixd getInverseMatrix() const override;
	virtual void setTransformation(const osg::Vec3d & eye, const osg::Quat & rotation) override;
	virtual void setTransformation(const osg::Vec3d & eye, const osg::Vec3d & center, const osg::Vec3d & up) override;
	virtual void getTransformation(osg::Vec3d & eye, osg::Quat & rotation) const override;
	virtual void getTransformation(osg::Vec3d & eye, osg::Vec3d & center, osg::Vec3d & up) const override;
	virtual bool  handle(const osgGA::GUIEventAdapter &ea, osgGA::GUIActionAdapter &us);
private:
	osg::Vec3 m_vPosition;
	osg::Vec3 orientation;
	int steplength;
	float rotatelength;
};

