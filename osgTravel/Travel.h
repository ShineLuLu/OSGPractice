#pragma once
#include"../OSGStudyProject/comdepen.h"
#ifdef _DEBUG
#pragma comment(lib,"../x64/Debug/osgAddDepen.lib")
#else
#pragma comment(lib,"../x64/Release/osgAddDepen.lib")
#endif // _DEBUG

#include<osgGA/StandardManipulator>
#include<osgViewer/Viewer>
#include<osgDB/ReadFile>
#include<osgViewer/ViewerEventHandlers>

class Travel :osgGA::StandardManipulator
{
public:
	Travel();
	~Travel();
public:
	/*用一个4x4矩阵来设置矩阵操作器的位置*/
	virtual void setByMatrix(const osg::Matrixd& matrix);
	/*用一个4x4逆矩阵来设置矩阵操作器的位置*/
	virtual void setByInverseMatrix(const osg::Matrixd& matrix);
	/*获取矩阵操作器4x4逆矩阵*/
	virtual osg::Matrixd getMatrix() const;
	/*获取矩阵操作器4x4逆矩阵*/
	virtual osg::Matrixd getInverseMatrix() const;

private:
	/*视点*/
	osg::Vec3 viewpoint;
	/*朝向*/
	osg::Vec3 orientaion;
};

