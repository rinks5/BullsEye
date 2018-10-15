#ifndef FPSCONTROLLER_H
#define FPSCONTROLLER_H

class CFPSController
{
public:
				CFPSController(int nDesiredFPS);
				~CFPSController();

	double		Update();

private:
	int			m_nDesiredFPS;
};

#endif // !FPSCONTROLLER_H
