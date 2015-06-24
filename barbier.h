#ifndef BARBIER_H
#define BARBIER_H

class Barbier
{
private:
	QQeue<Client> aCoiffer;
	QQeue<Client> aTatouer;
	
public:
	Barbier();
	~Barbier();
};

#endif // BARBIER_H
