#include "glibby/convex_hull/convex_hull2D.h"

namespace glibby
{
    std::vector<Point2D> Jarvis_March2D(const std::vector<Point2D>& pointSet)
    {
        if(pointSet.size() == 0 or pointSet.size() == 1)
        {
            return;
        }
        std::vector<Point2D> PointsOnHull(1);
        PointsOnHull[0].x = pointSet[0].x;
        PointsOnHull[0].y = pointSet[0].y;
        unsigned indexOfStartPoint = 0;
        unsigned indexOfLastPoint = 0;
        for (unsigned i = 0; i < pointSet.size(); i++)
        {
            if (pointSet[i].x < PointsOnHull[0].x)
            {
                PointsOnHull[0].x = pointSet[i].x;
                PointsOnHull[0].y = pointSet[i].y;
                indexOfStartPoint = i;
                indexOfLastPoint = i;
            }
        }
        while (true)
        {
            unsigned indexOfTargetPoint = 0;
            if (indexOfLastPoint == 0)
            {
                indexOfTargetPoint = 1;
            }
            for (unsigned i = 0; i < pointSet.size(); i++)
            {
                if (i == indexOfLastPoint)
                {
                    continue;
                }
                double sideIndicator = (pointSet[indexOfTargetPoint].x - pointSet[indexOfLastPoint].x) * (pointSet[i].y - pointSet[indexOfLastPoint].y)
                                        - (pointSet[indexOfTargetPoint].y - pointSet[indexOfLastPoint].y) * (pointSet[i].x - -pointSet[indexOfLastPoint].x);
                if (sideIndicator > 0)
                {
                    indexOfTargetPoint = i;
                }
                if (sideIndicator == 0) 
                {
                    if (abs(pointSet[i].x - pointSet[indexOfLastPoint].x) < abs(pointSet[indexOfTargetPoint].x - pointSet[indexOfLastPoint].x) 
                        || abs(pointSet[i].y - pointSet[indexOfLastPoint].y) < abs(pointSet[indexOfTargetPoint].y - pointSet[indexOfLastPoint].y))
                    {
                        indexOfTargetPoint = i;
                    }
                }                
            }
            if (indexOfTargetPoint == indexOfStartPoint)
            {
                break;
            }
        }
    }
}