#include "NodeMatrix.h"



NodeMatrix::NodeMatrix()
{
	instance = new osg::MatrixTransform;
	addChild(instance);
}


NodeMatrix::~NodeMatrix()
{
}

void NodeMatrix::rotating(const osg::Vec3d & pivot, const osg::Vec3d & axis, float angularVelocity)
{
	setUpdateCallback(new osg::AnimationPathCallback(pivot, axis, angularVelocity));
}

void NodeMatrix::toRotate(const osg::Matrix & mat)
{
	instance->setMatrix(mat);
}

void NodeMatrix::toRotate(float angularVelocity, const osg::Vec3 & axis)
{
	instance->setMatrix(osg::Matrix::rotate(angularVelocity,axis));
}

void NodeMatrix::toScale(const osg::Matrix & mat)
{
	instance->setMatrix(mat);
}

void NodeMatrix::toScale(float scale)
{
	instance->setMatrix(osg::Matrix::scale(scale, scale, scale));
}

void NodeMatrix::addChilds(osg::Node * node)
{
	instance->addChild(node);
}
