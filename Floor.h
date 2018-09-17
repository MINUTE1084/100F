#pragma once

void Floor(Entity *player, Entity monster[], int minMob, int maxMob, int floor, int &whoPlayer);
void BossFloor(Entity* player, Entity *Boss, int whoBoss, int &whoPlayer, int bossPower);