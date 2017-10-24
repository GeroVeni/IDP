#ifndef __CORE_H__
#define __CORE_H__

// Enum describing the mechaical arm motion
enum ArmType
{
	PICK,
	DROP
};

void    Initialise();
void    LineTracking(int);
void    ArmMove(ArmType);
int     Identify();

#endif // __CORE_H__
