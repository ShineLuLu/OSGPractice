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
					std::cout << "是否具有边框\t" << (*iter)->getWindowDecoration();
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
	//	std::cout << "获取系统交互成功！" << std::endl;
	//	winInterface->getScreenResolution(graphTraits, width, height);
	//	std::cout << "系统的分辨率（宽长）为：" << width << " * " << height << std::endl;
	//	std::cout << "图形特性的宽长为：" << graphTraits.width << " * " << graphTraits.height << std::endl;
	//	std::cout << "图形特性的x*y为：" << graphTraits.x << " * " << graphTraits.y << std::endl;
	//	std::cout << "系统边框：" << graphTraits.windowDecoration << std::endl;
	//	/*graphTraits.x = 0;
	//	graphTraits.y = 0;
	//	graphTraits.width = 800;
	//	graphTraits.height = 600;*/
	//	winInterface->setScreenResolution(graphTraits, 1920, 1080);

	//}
	//else
	//	std::cout << "获取系统交互失败！" << std::endl;

	//std::cin.get();
	return 0;
}
