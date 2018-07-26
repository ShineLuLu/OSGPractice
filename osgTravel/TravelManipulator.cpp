#include "TravelManipulator.h"



TravelManipulator::TravelManipulator()
{
	m_vPosition = osg::Vec3(0.0, -10.0, 50.0);
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
	//osg::Matrixd mat;
	///*mat.makeTranslate(m_vPosition);*/
	osg::Matrixd mat = osg::Matrixd::translate(m_vPosition);
	return mat * osg::Matrixd::rotate(orientation[0], osg::X_AXIS, orientation[1], osg::Y_AXIS, orientation[2], osg::Z_AXIS);
}

osg::Matrixd TravelManipulator::getInverseMatrix() const
{
	/*osg::Matrixd mat;
	mat.makeTranslate(m_vPosition);*/
	osg::Matrixd mat = osg::Matrixd::translate(m_vPosition);
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

bool TravelManipulator::handle(const osgGA::GUIEventAdapter & ea, osgGA::GUIActionAdapter & us)
{
	switch (ea.getEventType())
	{
	case osgGA::GUIEventAdapter::KEYDOWN:
		if (ea.getKey() == 'w') {
			m_vPosition[2] -= 2;
		}
		switch (ea.getKey()) {
		case 'w':
			m_vPosition[2] -= 2;
			break;
		case 's':
			m_vPosition[2] += 2;
			break;
		case 'a':
			m_vPosition[0] += 2;
			break;
		case 'd':
			m_vPosition[0] -= 2;
			break;
		}
		break;
	default:
		break;
	}
	return false;
}
