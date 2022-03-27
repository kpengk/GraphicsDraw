#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRotation>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void onActionLine();
    void onActionArc();
    void onActionMark();
    void onActionText();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene_;
};
#endif // MAINWINDOW_H
