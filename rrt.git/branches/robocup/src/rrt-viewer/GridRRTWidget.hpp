#pragma once

#include "RRTWidget.hpp"
#include <BiRRT.hpp>
#include <2dplane/GridStateSpace.hpp>
#include <Eigen/Dense>


/**
 * This widget creates an RRT tree for searching a 2d space and draws it.
 * It has methods (slots) for stepping and resetting tree growth.
 * You can also draw and erase obstacles for by clicking and dragging.
 */
class GridRRTWidget : public RRTWidget {
    Q_OBJECT

public:
    GridRRTWidget();

    bool hasSolution() const;


private slots:
    void slot_reset();
    void slot_clearObstacles();
    void slot_setGoalBias(int bias);        //  bias is from 0 to 100
    void slot_setWaypointBias(int bias);    //  bias is from 0 to 100
    void slot_setStepSize(double step);

signals:
    void signal_stepped(int iterationCount);


protected:
    void paintEvent(QPaintEvent *p);
    void drawTree(QPainter &painter,
        const RRT::Tree<Eigen::Vector2f> &rrt,
        const RRT::Node<Eigen::Vector2f> *solutionNode = NULL,
        QColor treeColor = Qt::blue,
        QColor solutionColor = Qt::red);

    QPointF pointFromNode(const RRT::Node<Eigen::Vector2f> *n);

    void step(int numTimes);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    static bool mouseInGrabbingRange(QMouseEvent *event, const Eigen::Vector2f &pt);


private:
    std::shared_ptr<GridStateSpace> _stateSpace;
    RRT::BiRRT<Eigen::Vector2f> *_biRRT;

    //  if you click down on an obstacle, you enter erase mode
    //  if you click down where there's no obstacle, you enter draw mode
    bool _editingObstacles, _erasingObstacles;
    bool _draggingStart, _draggingGoal;

    int _waypointCacheMaxSize;

    vector<Eigen::Vector2f> _previousSolution;
};