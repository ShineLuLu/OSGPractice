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
	/*�Զ�����ת�ķ�ʽ*/
	void rotating(const osg::Vec3d& pivot, const osg::Vec3d& axis, float angularVelocity);
	/*��תģ��*/
	void toRotate(const osg::Matrix& mat);
	/*��תģ��*/
	void toRotate(float angularVelocity, const osg::Vec3 &axis);
	/*����ģ��*/
	void toScale(const osg::Matrix& mat);
	/*����ģ��*/
	void toScale(float scale);
	/*��д��addchild����*/
	void addChilds(osg::Node* node);

private:
	osg::ref_ptr<osg::MatrixTransform> instance;
};


