#ifndef __POINT_H__
#define __POINT_H__

typedef struct _point
{
    int xpos;
    int ypos;
} Point;

// Point 변수 xpos, ypos 설정
void SetPointPos(Point*ppos, int xpos, int ypos);
// Point 변수 xpos, ypos 출력
void ShowPointPos(Point*ppos);
// 두 Point 변수 비교
int PointComp(Point*pos1, Point*pos2);

#endif