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
	//����һ����ʱ����
	osg::Timer *timer = new osg::Timer;
	osg::Timer_t start_time = 0;
	osg::Timer_t end_time = 0;
	osg::Timer_t viewer_start_time = 0;
	osg::Timer_t viewer_end_time = 0;
	osg::Timer_t frame_start_time = 0;
	osg::Timer_t frame_end_time = 0;
	//����ƽ��frame_count֡��ƽ��֡��
	int frame_count = 0;
	//�������֡�����Ϊ35֡ʱ��˯��ʱ�䣬���뼶
	float frame_sleep_time = 0.0;
	
	//��ȡosgһ��tick��x��
	std::cout << "osgÿ��tick��ʱ��" << timer->getSecondsPerTick() << std::endl;

	start_time = timer->tick();
	viewer_start_time = viewer->elapsedTime();
	timer->setStartTick();
	
	//��ȡģ��
	node = osgDB::readNodeFile("glider.osg");
	end_time = timer->tick();
	viewer_end_time = viewer->elapsedTime();

	std::cout << "���ö�ȡģ��ʱ��" << timer->time_m() << std::endl;
	std::cout << "�Զ���startʱ��" << start_time << std::endl;
	std::cout << "v�Զ���endʱ��" << end_time << std::endl;
	std::cout << "�Զ�������ֵ" << timer->delta_m(start_time, end_time) << std::endl;
	std::cout << "viewer����startʱ��" << viewer_start_time << std::endl;
	std::cout << "viewer����endʱ��" << viewer_end_time << std::endl;
	std::cout << "viewer���ö�ȡģ��ʱ��" << osg::Timer::instance()->delta_m(viewer_start_time, viewer_end_time) << std::endl;

	//��Ӱ����¼�
	//viewer->addEventHandler(new osgGA::EventHandler);   //����ķ���
	viewer->addEventHandler(new PrintMessageHandler);
	viewer->addEventHandler(new osgViewer::HelpHandler);
	viewer->addEventHandler(new osgViewer::StatsHandler);
	viewer->addEventHandler(new osgViewer::WindowSizeHandler);
	viewer->addEventHandler(new osgViewer::ScreenCaptureHandler);
	viewer->addEventHandler(new osgViewer::RecordCameraPathHandler);

	viewer->setSceneData(node.get());

	//�Զ��������
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
		//	std::cout << "����һ֡ƽ������ĺ�����" << timer->delta_m(frame_start_time, frame_end_time) / 10 << "\t";
		//	std::cout << "��ǰ֡��ƽ��Ϊ" << 10000 / (timer->delta_m(frame_start_time, frame_end_time)) << "\n";
		//	float temp_sleep_time = (1000.0 / 10.0 - timer->delta_m(frame_start_time, frame_end_time) / 10);
		//	frame_sleep_time = temp_sleep_time < 0 ? 0.9*frame_sleep_time : temp_sleep_time;
		//	/*if (frame_sleep_time < 0)
		//		frame_sleep_time = 0;*/
		//	std::cout << "��ǰ˯��ʱ��" << frame_sleep_time << "����" << std::endl;
		//}
		frame_end_time = timer->tick();
		float temp_sleep_time = (1000.0 / 35.0 - timer->delta_m(frame_start_time, frame_end_time));
		frame_sleep_time = temp_sleep_time < 0 ? 0.9*frame_sleep_time : temp_sleep_time;
		/*std::cout << "����һ֡����ĺ�����" << timer->delta_m(frame_start_time, frame_end_time) << "\t";
		std::cout << "��ǰ֡��Ϊ" << 1000 / (timer->delta_m(frame_start_time, frame_end_time)) << "\n";*/
	}


	return 0;
	//return viewer->run();
}
