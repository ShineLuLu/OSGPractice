#pragma once

#include"../OSGStudyProject/comdepen.h"
#ifdef _DEBUG
#pragma comment(lib,"../x64/Debug/osgAddDepen.lib")
#else
#pragma comment(lib,"../x64/Release/osgAddDepen.lib")
#endif // _DEBUG

#  if defined( OSG_LIBRARY_STATIC )
#    define NODE_MATRIX
#  elif defined( OSG_LIBRARY )
#    define NODE_MATRIX   __declspec(dllexport)
#  else
#    define NODE_MATRIX   __declspec(dllimport)
#endif // NODE_MATRIX


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
	/*��ģ���Ƶ�Ŀ�ĵ�*/
	void toPosition(const osg::Vec3& pos);
	/*��д��addchild����*/
	void addChilds(osg::Node* node);
	/*����ģ�ʹ�С*/
	void adapt(const osg::BoundingSphere area);
	/*����ģ�ʹ�С*/
	void adapt(osg::Node* node);

private:
	osg::ref_ptr<osg::MatrixTransform> instance;
	osg::BoundingSphere lastChildBound;
	osg::ref_ptr<osg::Node> lastAddedNode;
	float lastScale;
};


