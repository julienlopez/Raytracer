#include "mainwindow.hpp"

#include "rendering/primitive/sphere.hpp"
#include "rendering/raytracer.hpp"
#include "rendering/scene.hpp"

#include <memory>

#include <QLabel>
#include <QTime>
#include <QVBoxLayout>

#include <QDebug>

namespace
{

QColor colorToQColor(const Rendering::Color& color)
{
    return QColor(255 * color(0), 255 * color(1), 255 * color(2));
}

QImage imageToQImage(const Rendering::Image& image)
{
    QImage res(image.cols(), image.rows(), QImage::Format_RGB32);
    for(int x = 0; x < res.width(); x++)
        for(int y = 0; y < res.height(); y++)
            res.setPixelColor(x, y, colorToQColor(image(y, x)));
    return res;
}
}

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    Rendering::Scene scene;
    scene.addPrimitive(
        std::make_unique<Rendering::Primitive::Sphere>(Math::createPoint(0, 0, 80), 2, Math::createPoint(0, 0, 1)));
    scene.addPrimitive(
        std::make_unique<Rendering::Primitive::Sphere>(Math::createPoint(2, 1, 60), 1, Math::createPoint(1, 0, 0)));
    scene.addPrimitive(
        std::make_unique<Rendering::Primitive::Sphere>(Math::createPoint(-2, -1, 60), 1, Math::createPoint(0, 1, 0)));
    Rendering::RayTracer rt(800, 600, 8., 6., 40.);
    rt.setScene(&scene);
    const auto start = QTime::currentTime();
    const auto image = rt.draw();
    const auto end = QTime::currentTime();
    qDebug() << "rendered in " << start.msecsTo(end) << "ms";

    auto* l = new QLabel();
    l->setFixedSize(1000, 1000);
    l->setPixmap(QPixmap::fromImage(imageToQImage(image)));

    auto* w = new QWidget;
    auto* hl = new QVBoxLayout;
    hl->addWidget(l, 0, Qt::AlignCenter | Qt::AlignHCenter);
    w->setLayout(hl);
    setCentralWidget(w);
}

MainWindow::~MainWindow() = default;
