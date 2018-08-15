#include"../OSGStudyProject/comdepen.h"
#include<osgViewer/Viewer>
#include<iostream>
#include<osgViewer/ViewerEventHandlers>
#include<osgDB/ReadFile>

class ChangeWindow :public osgGA::GUIEventHandler {
public:
	ChangeWindow() {
		loaded = false;
	}
	bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa) {
		if (!loaded) {
			osgViewer::Viewer* viewer = dynamic_cast<osgViewer::Viewer*>(&aa);
			osgViewer::Viewer::Windows wins;
			viewer->getWindows(wins);
			if (!wins.empty()) {
				osgViewer::Viewer::Windows::iterator iter = wins.begin();
				for (; iter != wins.end(); iter++) {
					(*iter)->setWindowRectangle(350, 30, 1280, 960);
					std::cout << "�Ƿ���б߿�\t" << (*iter)->getWindowDecoration();
					(*iter)->setCursor(osgViewer::GraphicsWindow::MouseCursor::HandCursor);
				}
			}
			loaded = true;
		}
		return false;
	}
private:
	bool loaded;
};

int main() {
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;

	viewer->setSceneData(osgDB::readNodeFile("cow.osg"));

	viewer->addEventHandler(new ChangeWindow);
	viewer->run();



	///*osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;*/
	//osg::ref_ptr<osgViewer::HelpHandler> help = new osgViewer::HelpHandler;
	//
	//osg::GraphicsContext::Traits graphTraits;
	//unsigned int width, height;

	//osg::GraphicsContext::WindowingSystemInterface* winInterface = osg::GraphicsContext::getWindowingSystemInterface();
	//if (winInterface) {
	//	std::cout << "��ȡϵͳ�����ɹ���" << std::endl;
	//	winInterface->getScreenResolution(graphTraits, width, height);
	//	std::cout << "ϵͳ�ķֱ��ʣ�����Ϊ��" << width << " * " << height << std::endl;
	//	std::cout << "ͼ�����ԵĿ�Ϊ��" << graphTraits.width << " * " << graphTraits.height << std::endl;
	//	std::cout << "ͼ�����Ե�x*yΪ��" << graphTraits.x << " * " << graphTraits.y << std::endl;
	//	std::cout << "ϵͳ�߿�" << graphTraits.windowDecoration << std::endl;
	//	/*graphTraits.x = 0;
	//	graphTraits.y = 0;
	//	graphTraits.width = 800;
	//	graphTraits.height = 600;*/
	//	winInterface->setScreenResolution(graphTraits, 1920, 1080);

	//}
	//else
	//	std::cout << "��ȡϵͳ����ʧ�ܣ�" << std::endl;

	//std::cin.get();
	return 0;
}
