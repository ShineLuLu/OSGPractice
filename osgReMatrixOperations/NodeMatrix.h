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
	/*将模型移到目的点*/
	void toPosition(const osg::Vec3& pos);
	/*重写的addchild方法*/
	void addChilds(osg::Node* node);
	/*调整模型大小*/
	void adapt(const osg::BoundingSphere area);
	/*调整模型大小*/
	void adapt(osg::Node* node);

private:
	osg::ref_ptr<osg::MatrixTransform> instance;
	osg::BoundingSphere lastChildBound;
	osg::ref_ptr<osg::Node> lastAddedNode;
	float lastScale;
};


