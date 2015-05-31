#ifndef OBJECT_H
# define OBJECT_H

# define OBJECT 0
# define PLAYER 1
# define ENEMY 2

class Object
{
	protected:
		int m_posX;
		int m_posY;
		int m_speed;
		int m_life;
		int m_dmg;
		std::string m_symbol;

		const int type;

	public:
		void setPosX(int newPos);
		int getPosX() const { return this->m_posX; };

		void setPosY(int newPos);
		int getPosY() const { return this->m_posY; };;

		void setSpeed(int newSpeed);
		int getSpeed() const;

		void setLife(int newLife);
		int getLife() const;

		void setDmg(int newDmg);
		int getDmg() const;

		void setSymbol(std::string newSymbol)
		std::string getSymbol() const;

		const int getType() const;
};

#endif
