#ifndef NAVIGATION_H
#define NAVIGATION_H

int chooseDirection(bool legal[4], struct Cell &c);
void markSelection(struct Cell &c, int dir);
void updatePosition(int relDir);
void detectBranches(bool legal[4]);

#endif
