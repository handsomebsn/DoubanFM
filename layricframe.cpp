#include "layricframe.h"

#include <QMoveEvent>
#include <QHBoxLayout>

LayricFrame::LayricFrame() : QFrame(0)
{
    layric = new QLabel;
    layric->setText("Layric");
    layric->setStyleSheet("QLabel {"
                          "font-size:18px;"
                          "color:#a42727;"
                          "}");

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(layric);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);

//    shadowEffect = new QGraphicsDropShadowEffect(layric);
//    shadowEffect->setBlurRadius(10);
//    shadowEffect->setOffset(0, 0);
//    shadowEffect->setColor(Qt::cyan);
//    layric->setGraphicsEffect(shadowEffect);

    opacityEffect = new QGraphicsOpacityEffect(this);
    opacityEffect->setOpacity(1);

    setLayout(mainLayout);
    setFixedSize(800, 50);
    setGraphicsEffect(opacityEffect);
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::X11BypassWindowManagerHint | Qt::WindowStaysOnTopHint);
}

void LayricFrame::mousePressEvent(QMouseEvent *e)
{
    mousePressPoint = e->pos();
    mousePressed = true;
}

void LayricFrame::mouseReleaseEvent(QMouseEvent *e)
{
    Q_UNUSED(e)

    mousePressed = false;
}

void LayricFrame::mouseMoveEvent(QMouseEvent *e)
{
    if (!mousePressed)
        return;

    move(e->pos() - mousePressPoint + pos());
}

void LayricFrame::enterEvent(QEvent *e)
{
    Q_UNUSED(e)

    opacityEffect->setOpacity(0.38);
}

void LayricFrame::leaveEvent(QEvent *e)
{
    Q_UNUSED(e)

    opacityEffect->setOpacity(1);
}
