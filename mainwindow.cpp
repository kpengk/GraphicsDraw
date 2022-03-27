#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPainterPath>
#include <QDebug>

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow{ parent }
	, ui{ new Ui::MainWindow }
	, scene_{ new QGraphicsScene }
{
	ui->setupUi(this);

	ui->graphicsView->setScene(scene_);
	scene_->addLine(-999, 0, 999, 0);
	scene_->addLine(0, -999, 0, 999);

	connect(ui->actionLine, &QAction::triggered, this, &MainWindow::onActionLine);
	connect(ui->actionArc, &QAction::triggered, this, &MainWindow::onActionArc);
	connect(ui->actionMark, &QAction::triggered, this, &MainWindow::onActionMark);
	connect(ui->actionText, &QAction::triggered, this, &MainWindow::onActionText);

	ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::onActionLine()
{
	ui->stackedWidget->setCurrentIndex(0);

	scene_->addLine(-99, -99, 99, 99);
}

void MainWindow::onActionArc()
{
	ui->stackedWidget->setCurrentIndex(1);

	QPainterPath path(QPointF{ 50 * qCos(qDegreesToRadians(45)), -50 * qSin(qDegreesToRadians(45)) });
	path.arcTo(-50, -50, 100, 100, 45, 270);
	scene_->addPath(path);
}

void MainWindow::onActionMark()
{
	ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::onActionText()
{
	ui->stackedWidget->setCurrentIndex(3);
	scene_->addText("Hello");
}

