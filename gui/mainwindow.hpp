#pragma once

#include <QMainWindow>

namespace Rendering
{
class Scene;
}

class MainWindow : public QMainWindow
{
public:
    MainWindow(QWidget* parent = nullptr);

    virtual ~MainWindow();
};
