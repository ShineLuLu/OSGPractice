#include "TravelManipulator.h"



TravelManipulator::TravelManipulator()
{
	m_vPosition = osg::Vec3(0.0, 0.0, 0.0);
	m_vRotate = osg::Vec3(osg::PI_2, 0.0, 0.0);
	m_vStep = 1;
	m_vRotateStep = 0.01;
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
	return mat * osg::Matrixd::rotate(m_vRotate[0], osg::X_AXIS, m_vRotate[1], osg::Y_AXIS, m_vRotate[2], osg::Z_AXIS);
}

osg::Matrixd TravelManipulator::getInverseMatrix() const
{
	/*osg::Matrixd mat;
	mat.makeTranslate(m_vPosition);*/
	osg::Matrixd mat = osg::Matrixd::translate(m_vPosition);
	return osg::Matrixd::inverse(mat*osg::Matrixd::rotate(m_vRotate[0], osg::X_AXIS, m_vRotate[1], osg::Y_AXIS, m_vRotate[2], osg::Z_AXIS));
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
		switch (ea.getKey()) {
		case 'w':
			changePostion(osg::Vec3(m_vStep*cosf(osg::PI_2 + m_vRotate._v[1]), 0.0, -m_vStep * sinf(osg::PI_2 + m_vRotate._v[1])));
			break;
		case 's':
			changePostion(osg::Vec3(-m_vStep * cosf(osg::PI_2 + m_vRotate._v[1]), 0.0, m_vStep * sinf(osg::PI_2 + m_vRotate._v[1])));
			break;
		case 'q':
			changePostion(osg::Vec3(m_vStep*cosf(osg::PI + m_vRotate._v[1]), 0.0, -m_vStep * sinf(osg::PI + m_vRotate._v[1])));
			break;
		case 'e':
			changePostion(osg::Vec3(-m_vStep * cosf(osg::PI + m_vRotate._v[1]), 0.0, m_vStep * sinf(osg::PI + m_vRotate._v[1])));
			break;
		case 'a':
			changeViewAngle(osg::Vec3(0.0, 0.0, m_vRotateStep));
			break;
		case 'd':
			changeViewAngle(osg::Vec3(0.0, 0.0, -m_vRotateStep));
			break;
		}
		break;
	case osgGA::GUIEventAdapter::PUSH:
		if (ea.getKey() == osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON) {
			m_iLeftX = ea.getX();
			m_iLeftY = ea.getY();
		}
		break;
	case osgGA::GUIEventAdapter::DRAG:
		int deltX = ea.getX();
		break;
	case osgGA::GUIEventAdapter::RELEASE:
		break;
	default:
		break;
	}
	return false;
}

void TravelManipulator::changePostion(const osg::Vec3 & step)
{
	m_vPosition += step;
}

void TravelManipulator::changeViewAngle(const osg::Vec3 & angle)
{
	m_vRotate += angle;
}
