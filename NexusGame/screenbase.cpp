#include "pchNexusGame.h"
#include "screenbase.h"

CScreenBase::CScreenBase()
{
    m_bActive = false;
    m_timeTotalElapsed = 0.0;
}

CScreenBase::~CScreenBase()
{

}

bool CScreenBase::Activate()
{
    m_bActive = true;
    m_timeTotalElapsed = 0.0;
    return true;
}

bool CScreenBase::DeActivate()
{
    m_bActive = false;
    return false;
}

bool CScreenBase::IsActive() const
{
    return m_bActive;
}

bool CScreenBase::OnLeftMouseDown(int x, int y)
{
	cout << "Left Mouse Down x : " << x  << " " << "y : " << y << endl;
	return false;
}

bool CScreenBase::OnRightMouseDown(int x, int y)
{
	cout << "Right Mouse Down x : " << x  << " " << "y : " << y << endl;
	return false;
}

bool CScreenBase::OnLevelComplete()
{
	return false;
}

void CScreenBase::RestartLevel()
{

}

