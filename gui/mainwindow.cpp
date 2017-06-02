#include "mainwindow.hpp"

#include "rendering/primitive/sphere.hpp"
#include "rendering/raytracer.hpp"
#include "rendering/scene.hpp"

#include <memory>

#include <QLabel>
#include <QVBoxLayout>

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
    scene.addPrimitive(std::make_unique<Rendering::Primitive::Sphere>(Math::createPoint(100, 100, 100), 50.,
                                                                      Math::createPoint(1., 0., 0.)));
    scene.addPrimitive(std::make_unique<Rendering::Primitive::Sphere>(Math::createPoint(0, 0, 50), 40.,
                                                                      Math::createPoint(0., 1., 0.)));
    scene.addPrimitive(std::make_unique<Rendering::Primitive::Sphere>(Math::createPoint(200, 0, 150), 40.,
                                                                      Math::createPoint(0., 0., 1.)));
    Rendering::RayTracer rt(1000, 1000, 100., 100., 10.);
    rt.setScene(&scene);
    const auto image = rt.draw();

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
