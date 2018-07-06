#include"../OSGStudyProject/comdepen.h"
#ifdef _DEBUG
#pragma comment(lib,"../x64/Debug/osgAddDepen.lib")
#else
#pragma comment(lib,"../x64/Release/osgAddDepen.lib")
#endif // _DEBUG

#include<osgViewer/Viewer>
#include<osgDB/ReadFile>
#include<osgGA/GUIEventAdapter>
#include<osgGA/TrackballManipulator>
#include<osgViewer/ViewerEventHandlers>

class PrintMessageHandler : public osgGA::GUIEventHandler 
{
public:
	bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa) {
		return false;
	}
	virtual void getUsage(osg::ApplicationUsage& usage) const {
		usage.addKeyboardMouseBinding("------osg------", "------start to learn!------");
	}
};


int main() {
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	osg::ref_ptr<osg::Node> node = new osg::Node;
	//申请一个定时器类
	osg::Timer *timer = new osg::Timer;
	osg::Timer_t start_time = 0;
	osg::Timer_t end_time = 0;
	osg::Timer_t viewer_start_time = 0;
	osg::Timer_t viewer_end_time = 0;
	osg::Timer_t frame_start_time = 0;
	osg::Timer_t frame_end_time = 0;
	//计算平均frame_count帧的平均帧数
	int frame_count = 0;
	//计算控制帧数最高为35帧时的睡眠时间，毫秒级
	float frame_sleep_time = 0.0;
	
	//获取osg一个tick有x秒
	std::cout << "osg每个tick的时间" << timer->getSecondsPerTick() << std::endl;

	start_time = timer->tick();
	viewer_start_time = viewer->elapsedTime();
	timer->setStartTick();
	
	//读取模型
	node = osgDB::readNodeFile("glider.osg");
	end_time = timer->tick();
	viewer_end_time = viewer->elapsedTime();

	std::cout << "内置读取模型时间" << timer->time_m() << std::endl;
	std::cout << "自定义start时间" << start_time << std::endl;
	std::cout << "v自定义end时间" << end_time << std::endl;
	std::cout << "自定义计算差值" << timer->delta_m(start_time, end_time) << std::endl;
	std::cout << "viewer运行start时间" << viewer_start_time << std::endl;
	std::cout << "viewer运行end时间" << viewer_end_time << std::endl;
	std::cout << "viewer内置读取模型时间" << osg::Timer::instance()->delta_m(viewer_start_time, viewer_end_time) << std::endl;

	//添加帮助事件
	//viewer->addEventHandler(new osgGA::EventHandler);   //错误的方法
	viewer->addEventHandler(new PrintMessageHandler);
	viewer->addEventHandler(new osgViewer::HelpHandler);
	viewer->addEventHandler(new osgViewer::StatsHandler);
	viewer->addEventHandler(new osgViewer::WindowSizeHandler);
	viewer->addEventHandler(new osgViewer::ScreenCaptureHandler);
	viewer->addEventHandler(new osgViewer::RecordCameraPathHandler);

	viewer->setSceneData(node.get());

	//自定义操作器
	if (!viewer->getCameraManipulator() && viewer->getCamera()->getAllowEventFocus()) {
		viewer->setCameraManipulator(new osgGA::TrackballManipulator);
	}

	while (!viewer->done())
	{
		//if (frame_count == 0)
		frame_start_time = timer->tick();
		//frame_start_time = timer->tick();

		viewer->frame();
		OpenThreads::Thread::microSleep(1000 * frame_sleep_time);

		//frame_count++;
		//if (frame_count == 10) {
		//	frame_count = 0;
		//	frame_end_time = timer->tick();
		//	std::cout << "绘制一帧平均所需的毫秒数" << timer->delta_m(frame_start_time, frame_end_time) / 10 << "\t";
		//	std::cout << "当前帧数平均为" << 10000 / (timer->delta_m(frame_start_time, frame_end_time)) << "\n";
		//	float temp_sleep_time = (1000.0 / 10.0 - timer->delta_m(frame_start_time, frame_end_time) / 10);
		//	frame_sleep_time = temp_sleep_time < 0 ? 0.9*frame_sleep_time : temp_sleep_time;
		//	/*if (frame_sleep_time < 0)
		//		frame_sleep_time = 0;*/
		//	std::cout << "当前睡眠时间" << frame_sleep_time << "毫秒" << std::endl;
		//}
		frame_end_time = timer->tick();
		float temp_sleep_time = (1000.0 / 35.0 - timer->delta_m(frame_start_time, frame_end_time));
		frame_sleep_time = temp_sleep_time < 0 ? 0.9*frame_sleep_time : temp_sleep_time;
		/*std::cout << "绘制一帧所需的毫秒数" << timer->delta_m(frame_start_time, frame_end_time) << "\t";
		std::cout << "当前帧数为" << 1000 / (timer->delta_m(frame_start_time, frame_end_time)) << "\n";*/
	}


	return 0;
	//return viewer->run();
}
