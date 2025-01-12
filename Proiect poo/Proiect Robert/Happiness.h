#ifndef HAPPINESS_H
#define HAPPINESS_H

class Happiness
{
private:
	int& happinesTotal;
public:
	Happiness(int& happines);
	virtual ~Happiness();

	void addHappiness(int happines);
	void removeHappiness(int happines);

	int returnHappiness();
};

#endif // HAPPINES_H