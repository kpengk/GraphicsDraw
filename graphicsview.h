#pragma once

#include <QWidget>
#include <QGraphicsView>

class GraphicsView : public QGraphicsView
{
	Q_OBJECT
public:
	explicit GraphicsView(QWidget* parent = nullptr);
	GraphicsView(QGraphicsScene* scene, QWidget* parent = nullptr);
	~GraphicsView();

protected:
	void wheelEvent(QWheelEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;

public slots:
	void zoomIn(int level = 1);
	void zoomOut(int level = 1);
	void resetView();
	void setupMatrix();

private:
	int zoomValue_;
};