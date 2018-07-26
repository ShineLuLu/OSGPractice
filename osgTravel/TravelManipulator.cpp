#include "TravelManipulator.h"



TravelManipulator::TravelManipulator()
{
	viewPoint = osg::Vec3(0.0, 0.0, 0.0);
	orientation = osg::Vec3(0.0, 0.0, 0.0);
}


TravelManipulator::~TravelManipulator()
{
}

void TravelManipulator::setByMatrix(const osg::Matrixd & matrix)
{
}

void TravelManipulator::setByInverseMatrix(const osg::Matrixd & matrix)
{
}

osg::Matrixd TravelManipulator::getMatrix() const
{
	osg::Matrixd mat;
	mat.makeTranslate(viewPoint);
	return mat * osg::Matrixd::rotate(orientation[0], osg::X_AXIS, orientation[1], osg::Y_AXIS, orientation[2], osg::Z_AXIS);
}

osg::Matrixd TravelManipulator::getInverseMatrix() const
{
	osg::Matrixd mat;
	mat.makeTranslate(viewPoint);
	return osg::Matrixd::inverse(mat*osg::Matrixd::rotate(orientation[0], osg::X_AXIS, orientation[1], osg::Y_AXIS, orientation[2], osg::Z_AXIS));
}

void TravelManipulator::setTransformation(const osg::Vec3d & eye, const osg::Quat & rotation)
{
}

void TravelManipulator::setTransformation(const osg::Vec3d & eye, const osg::Vec3d & center, const osg::Vec3d & up)
{
}

void TravelManipulator::getTransformation(osg::Vec3d & eye, osg::Quat & rotation) const
{
}

void TravelManipulator::getTransformation(osg::Vec3d & eye, osg::Vec3d & center, osg::Vec3d & up) const
{
}
