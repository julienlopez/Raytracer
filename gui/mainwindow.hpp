#pragma once

#include <QMainWindow>

class MainWindow : public QMainWindow
{
public:
    MainWindow(QWidget* parent = nullptr);

    virtual ~MainWindow() = default;
};
