#include "pchNexusGame.h"
#include "fpscontroller.h"


CFPSController::CFPSController(int nDesiredFPS)
{
    m_nDesiredFPS = nDesiredFPS;
}

CFPSController::~CFPSController()
{

}

double CFPSController::Update()
{
    delay(1000/m_nDesiredFPS);
    return 1.0/m_nDesiredFPS;
}
