#pragma once

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

class NodeMatrix :public osg::MatrixTransform 
{
public:
	NodeMatrix();
	~NodeMatrix();

public:
	/*自定义旋转的方式*/
	void rotating(const osg::Vec3d& pivot, const osg::Vec3d& axis, float angularVelocity);
	/*旋转模型*/
	void toRotate(const osg::Matrix& mat);
	/*旋转模型*/
	void toRotate(float angularVelocity, const osg::Vec3 &axis);
	/*缩放模型*/
	void toScale(const osg::Matrix& mat);
	/*缩放模型*/
	void toScale(float scale);
	/*重写的addchild方法*/
	void addChilds(osg::Node* node);

private:
	osg::ref_ptr<osg::MatrixTransform> instance;
};


