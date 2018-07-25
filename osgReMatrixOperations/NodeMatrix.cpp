#include "NodeMatrix.h"

NodeMatrix::NodeMatrix()
{
	instance = new osg::MatrixTransform;
	addChild(instance);
	lastScale = 1.0;
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

void NodeMatrix::toPosition(const osg::Vec3 & pos)
{
	osg::Vec3 curpos;
	curpos.set(-lastChildBound.center().x()*lastScale, -lastChildBound.center().y()*lastScale, -lastChildBound.center().z()*lastScale);
	instance->setMatrix(osg::Matrix::translate(curpos)*osg::Matrix::translate(pos));
}

void NodeMatrix::addChilds(osg::Node * node)
{
	instance->addChild(node);
	lastAddedNode = node;
	lastChildBound = node->getBound();
	osg::notify(osg::NOTICE) << lastChildBound.center().x() << " " << lastChildBound.center().y() << " " << lastChildBound.center().z() << std::endl;
}

void NodeMatrix::adapt(const osg::BoundingSphere area)
{
	float scale = area.radius() / lastChildBound.radius();
	instance->setMatrix(osg::Matrix::scale(scale, scale, scale));
}

void NodeMatrix::adapt(osg::Node * node)
{
	osg::BoundingSphere tempBound = node->getBound();
	float scale = tempBound.radius() / lastChildBound.radius();
	instance->setMatrix(osg::Matrix::scale(scale, scale, scale));
}
