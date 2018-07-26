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
	/*��һ��4x4���������þ����������λ��*/
	virtual void setByMatrix(const osg::Matrixd& matrix);
	/*��һ��4x4����������þ����������λ��*/
	virtual void setByInverseMatrix(const osg::Matrixd& matrix);
	/*��ȡ���������4x4�����*/
	virtual osg::Matrixd getMatrix() const;
	/*��ȡ���������4x4�����*/
	virtual osg::Matrixd getInverseMatrix() const;

private:
	/*�ӵ�*/
	osg::Vec3 viewpoint;
	/*����*/
	osg::Vec3 orientaion;
};

