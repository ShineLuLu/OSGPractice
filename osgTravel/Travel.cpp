#include "Travel.h"



Travel::Travel()
{
	viewpoint = osg::Vec3(0.0, 0.0, 0.0);
	orientaion = osg::Vec3(0.0, 0.0, 0.0);
}


Travel::~Travel()
{
}

void Travel::setByMatrix(const osg::Matrixd & matrix)
{
}

void Travel::setByInverseMatrix(const osg::Matrixd & matrix)
{
}

osg::Matrixd Travel::getMatrix() const
{
	osg::Matrixd mat;
	mat.makeTranslate(viewpoint);
	return mat * osg::Matrixd::rotate(orientaion[0], osg::X_AXIS, orientaion[1], osg::Y_AXIS, orientaion[3], osg::Z_AXIS);
}

osg::Matrixd Travel::getInverseMatrix() const
{
	osg::Matrixd mat;
	mat.makeTranslate(viewpoint);
	return osg::Matrixd::inverse(mat * osg::Matrixd::rotate(orientaion[0], osg::X_AXIS, orientaion[1], osg::Y_AXIS, orientaion[3], osg::Z_AXIS));

}
