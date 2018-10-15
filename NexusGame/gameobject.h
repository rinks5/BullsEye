#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class CGameObject
{
public:
					CGameObject();
	virtual			~CGameObject();

	virtual void	Update(double timeElapsed);
	virtual bool	IsCollidingObj(CGameObject & gameObject);
	double			Distance(int xSource, int ySource, int xDest, int yDest) const;

	int				GetPosX() const;
	int 			GetPosY() const;
	int 			GetRadius() const;

protected:
	int				m_iPosX;
	int				m_iPosY;
	int				m_iRadius;

	double			m_timeTotalElapsed;
};

#endif // !GAMEOBJECT_H
