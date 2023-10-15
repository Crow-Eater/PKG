
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QRect"
#include "QColorDialog"
//#include "QtCore"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Index1 = 0;
    Index2 = 0;
    Index3 = 0;
    ui->setupUi(this);
    ui->centralwidget->setFixedSize(800, 550);
    ui->horizontalLayout_3->setGeometry(QRect(0, 0, 800, 200));
    ui->pushButton->setFixedSize(100, 100);
    ui->horizontalLayout_2->setGeometry(QRect(0, 0, 800, 100));
    ui->horizontalLayout->setGeometry(QRect(0, 0, 800, 400));
    ui->label_4->setFixedSize(40, 40);
    ui->label_5->setFixedSize(40, 40);
    ui->label_6->setFixedSize(40, 40);
    ui->label_7->setFixedSize(40, 40);
    ui->label_8->setFixedSize(40, 40);
    ui->label_9->setFixedSize(40, 40);
    ui->label_10->setFixedSize(40, 40);
    ui->label_11->setFixedSize(40, 40);
    ui->label_12->setFixedSize(40, 40);
    ui->pushButton->setText("");
    ui->pushButton->setStyleSheet("background-color: rgb(0,0,0)");
    ch = false;
    r = 0;
    g = 0;
    b = 0;
    str = QColor::fromRgb(r, g, b).name();
    RGB_To_CMYK();
    RGB_To_XYZ();
    RGB_To_HLS();
    RGB_To_HSV();
    XYZ_To_LAB();

    //ui->lineEdit->setText(str);

    ui->label_7->setText("R");
    ui->label_9->setText("G");
    ui->label_8->setText("B");

    ui->doubleSpinBox->setValue(r);
    ui->doubleSpinBox->setMaximum(255);
    ui->doubleSpinBox->setMinimum(0);
    ui->doubleSpinBox_2->setValue(g);
    ui->doubleSpinBox_2->setMaximum(255);
    ui->doubleSpinBox_2->setMinimum(0);
    ui->doubleSpinBox_3->setValue(b);
    ui->doubleSpinBox_3->setMaximum(255);
    ui->doubleSpinBox_3->setMinimum(0);

    ui->doubleSpinBox_4->setValue(X);
    ui->doubleSpinBox_5->setValue(Y);
    ui->doubleSpinBox_6->setValue(Z);

    ui->label_4->setText("X");
    ui->label_5->setText("Y");
    ui->label_6->setText("Z");

    ui->doubleSpinBox_4->setRange(0, 95);
    ui->doubleSpinBox_5->setRange(0, 100);
    ui->doubleSpinBox_6->setRange(0, 108);

    ui->doubleSpinBox_7->setValue(h);
    ui->doubleSpinBox_8->setValue(v);
    ui->doubleSpinBox_9->setValue(s);

    ui->label_10->setText("H");
    ui->label_11->setText("V");
    ui->label_12->setText("S");

    ui->doubleSpinBox_7->setMinimum(0);
    ui->doubleSpinBox_7->setMaximum(360);
    ui->doubleSpinBox_8->setRange(0, 1);
    ui->doubleSpinBox_9->setRange(0, 1);

    //ui->doubleSpinBox_7->setRange(0, 360);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    QColor clr = QColorDialog::getColor();
    r = clr.red();
    g = clr.green();
    b = clr.blue();
    ui->pushButton->setStyleSheet("background-color: rgb("+QString::number(r)+","+QString::number(g)+","+QString::number(b)+")");
    RGB_To_CMYK();
    RGB_To_XYZ();
    RGB_To_HLS();
    RGB_To_HSV();
    XYZ_To_LAB();

    ui->statusbar->showMessage(QString::number(h));
    updateSpinBox(ui->doubleSpinBox);
}

void MainWindow::RGB_To_CMYK()
{
    if(1.0 - r/255.0 <= 1.0 - g/255.0 && 1.0 - r/255.0 <= 1.0 - b/255.0)
    {
        k = 1.0 - r/255.0;
    }
    else if(1.0 - g/255.0 <= 1.0 - b/255.0)
    {
        k = 1.0 - g/255.0;
    }
    else
    {
        k = 1.0 - b/255.0;
    }

    if(k == 1.0)
    {
        c = 0;
        m = 0;
        y = 0;
    }
    else
    {
        c = (1.0 - r/255.0 - k)/(1.0 - k);
        m = (1.0 - g/255.0 - k)/(1.0 - k);
        y = (1.0 - b/255.0 - k)/(1.0 - k);
    }
}

void MainWindow::CMYK_To_RGB()
{
    r = 255.0 * (1.0 - c) * (1.0 - k);
    g = 255.0 * (1.0 - m) * (1.0 - k);
    b = 255.0 * (1.0 - Y) * (1.0 - k);

    if((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
    {
        QErrorMessage msg(this);
        msg.showMessage("out of range");
        msg.exec();
    }
}

void MainWindow::RGB_To_XYZ()
{
    X = 0.4124453 * f(r/255) * 100 + 0.357580 * f(g/255) * 100 + 0.180423 * f(b/255) * 100;
    Y = 0.212671 * f(r/255) * 100 + 0.715160 * f(g/255) * 100 + 0.072169 * f(b/255) * 100;
    Z = 0.019334 * f(r/255) * 100 + 0.119193 * f(g/255) * 100 + 0.950227 * f(b/255) * 100;
}

void MainWindow::LAB_To_XYZ()
{
    short t_L = l, t_a = A, t_b = B;
    if(t_a > 127.0) t_a -= 256.0;
    if(t_b > 127.0) t_b -= 256.0;

    float t_P;

    t_P = ((float)t_L/2.55 + 16.0) / 116.0;

    float t_X, t_Y, t_Z;

    t_X = pow(t_P + (float)t_a * 0.002, 3.0);
    t_Y = pow(t_P, 3.0);
    t_Z = pow(t_P - (float)t_b * 0.005, 3.0);

    t_X *= 0.95047;
    t_Z *= 1.0883;

    X = t_X;
    Y = t_Y;
    Z = t_Z;

}

void MainWindow::XYZ_To_RGB()
{
    r = 255.0 * f1(3.2406 * X / 100.0 - 1.5372 * Y / 100.0 - 0.4986 * Z / 100.0);
    g = 255.0 * f1((-0.9689) * X / 100.0 + 1.8758  * Y / 100.0 + 0.0415 * Z / 100.0);
    b = 255.0 * f1(0.0557 * X / 100.0 - 0.2040 * Y / 100.0 + 1.0570 * Z / 100.0 );
    if((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
    {
        QErrorMessage msg(this);
        msg.showMessage("out of range");
        msg.exec();
    }
}

void MainWindow::RGB_To_HLS()
{
    double Cmax = std::max(r/255.0, g/255.0);
    Cmax = std::max(Cmax, b/255.0);

    double Cmin = std::min(r/255.0, g/255.0);
    Cmin = std::min(Cmin, b/255.0);

    double delta = Cmax - Cmin;

    if(delta == 0)
    {
        h = 0;
    }
    else if(Cmax == r/255.0 && g/255.0 >= b/255.0)
    {
        h = 60 * ((g / 255.0 - b/255.0) / delta) + 0;
    }
    else if(Cmax == r/255 && g/255 < b/255)
    {
        h = 60 * ((g / 255.0 - b/255.0) / delta) + 360;
    }
    else if(Cmax == g/255.0)
    {
        h = 60 * ((b / 255.0 - r/255.0) / delta) + 2;
    }
    else if(Cmax == b/255)
    {
        h = 60 * (r / 255.0 - g/255.0) / delta + 4;
    }

    l = (Cmax + Cmin) / 2;

    if(delta == 0)
    {
        s = 0;
    }
    else
    {
        s = delta / (1.0 - abs(2.0 * l - 1.0));
    }
}

void MainWindow::RGB_To_HSV()
{
    double Cmax = std::max(r/255.0, g/255.0);
    Cmax = std::max(Cmax, b/255.0);

    double Cmin = std::min(r/255.0, g/255.0);
    Cmin = std::min(Cmin, b/255.0);

    double delta = Cmax - Cmin;

    if(delta == 0)
    {
        h = 0;
    }
    else if(Cmax == r/255.0 && g/255.0 >= b/255.0)
    {
        h = 60 * (g / 255.0 - b/255.0) / delta + 0;
    }
    else if(Cmax == r/255.0 && g/255.0 < b/255.0)
    {
        h = 60 * ((g / 255.0 - b/255.0) / delta) + 360;
    }
    else if(Cmax == g/255.0)
    {
        h = 60 * (b / 255.0 - r/255.0) / delta + 2;
    }
    else if(Cmax == b/255.0)
    {
        h = 60 * (r / 255.0 - g/255.0) / delta + 4;
    }

    v = Cmax;

    if(Cmax == 0)
    {
        s = 0;
    }
    else
    {
        s = delta / (1.0 - abs(2.0*l - 1.0));
    }
}

void MainWindow::XYZ_To_LAB()
{
    l = 116 * F(Y / 100.0) - 16;
    A = 500 * (F(X / 95.047) - F(Y / 100.0));
    B = 200 * (F(Y / 100) - F(Z / 108.883));
}

void MainWindow::HSV_To_HLS()
{
    double c = v * s;
    double x = c * (1 - abs(static_cast<int>(h / 60.0) % 2 - 1));
    double m = v - c;
    double r1, g1, b1;
    if(h>=0 && h <60)
    {
        r1 = (c + m) * 255;
        g1 = (x + m) * 255;
        b1 = m * 255;
    }
    else if(h >= 60 && h < 120)
    {
        r1 = (x + m) * 255;
        g1 = (c + m) * 255;
        b1 = m * 255;
    }
    else if(h >= 120 && h < 180)
    {
        r1 = (0 + m) * 255;
        g1 = (c + m) * 255;
        b1 = (x + m) * 255;
    }
    else if(h >= 180 && h < 240)
    {
        r1 = (0 + m) * 255;
        g1 = (x + m) * 255;
        b1 = (c + m) * 255;
    }
    else if(h >= 240 && h < 300)
    {
        r1 = (x + m) * 255;
        g1 = (0 + m) * 255;
        b1 = (c + m) * 255;
    }
    else if(h >= 300 && h < 360)
    {
        r1 = (c + m) * 255;
        g1 = (0 + m) * 255;
        b1 = (x + m) * 255;
    }
    double Cmax = std::max(r1/255.0, g1/255.0);
    Cmax = std::max(Cmax, b1/255.0);

    double Cmin = std::min(r1/255.0, g1/255.0);
    Cmin = std::min(Cmin, b1/255.0);

    l = (Cmax + Cmin) / 2.0;
}

void MainWindow::HSV_To_RGB()
{
    double c = v * s;
    double x = c * (1 - abs(static_cast<int>(h / 60) % 2 - 1));
    double m = v - c;

    if(h>=0 && h <60)
    {
        r = (c + m) * 255;
        g = (x + m) * 255;
        b = m * 255;
    }
    else if(h >= 60 && h < 120)
    {
        r = (x + m) * 255;
        g = (c + m) * 255;
        b = m * 255;
    }
    else if(h >= 120 && h < 180)
    {
        r = (0 + m) * 255;
        g = (c + m) * 255;
        b = (x + m) * 255;
    }
    else if(h >= 180 && h < 240)
    {
        r = (0 + m) * 255;
        g = (x + m) * 255;
        b = (c + m) * 255;
    }
    else if(h >= 240 && h < 300)
    {
        r = (x + m) * 255;
        g = (0 + m) * 255;
        b = (c + m) * 255;
    }
    else if(h >= 300 && h < 360)
    {
        r = (c + m) * 255;
        g = (0 + m) * 255;
        b = (x + m) * 255;
    }
    if((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
    {
        QErrorMessage msg(this);
        msg.showMessage("out of range");
        msg.exec();
    }
}

void MainWindow::HLS_To_RGB()
{
    double c = (1 - abs(2 * l - 1)) * s;
    double x = c * (1 - abs(static_cast<int>(h / 60) % 2 - 1));
    double m = l - c / 2;

    if(h>=0 && h <60)
    {
        r = (c + m) * 255;
        g = (x + m) * 255;
        b = m * 255;
    }
    else if(h >= 60 && h < 120)
    {
        r = (x + m) * 255;
        g = (c + m) * 255;
        b = m * 255;
    }
    else if(h >= 120 && h < 180)
    {
        r = (0 + m) * 255;
        g = (c + m) * 255;
        b = (x + m) * 255;
    }
    else if(h >= 180 && h < 240)
    {
        r = (0 + m) * 255;
        g = (x + m) * 255;
        b = (c + m) * 255;
    }
    else if(h >= 240 && h < 300)
    {
        r = (x + m) * 255;
        g = (0 + m) * 255;
        b = (c + m) * 255;
    }
    else if(h >= 300 && h < 360)
    {
        r = (c + m) * 255;
        g = (0 + m) * 255;
        b = (x + m) * 255;
    }
    if((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
    {
        QErrorMessage msg(this);
        msg.showMessage("out of range");
        msg.exec();
    }
}

double MainWindow::f(double x)
{
    if(x >= 0.04045)
    {
        return qPow((x+0.055)/1.055, 2.4);
    }
    else
    {
        return x/12.92;
    }
}

double MainWindow::f1(double x)
{
    if(x >= 0.0031308)
    {
        return 1.055 * qPow(x, 1/2.4) - 0.055;
    }
    else
    {
        return x * 12.92;
    }
}

double MainWindow::F(double x)
{
    if(x > 216/24389)
    {
        return qPow(x, 0.3333);
    }
    else
    {
        return (24389 / 27 * x + 16) / 116;
    }
}

void MainWindow::updateSpinBox(QObject* obj)
{

    ui->doubleSpinBox->blockSignals(true);
    ui->doubleSpinBox_2->blockSignals(true);
    ui->doubleSpinBox_3->blockSignals(true);
    ui->doubleSpinBox_4->blockSignals(true);
    ui->doubleSpinBox_5->blockSignals(true);
    ui->doubleSpinBox_6->blockSignals(true);
    ui->doubleSpinBox_7->blockSignals(true);
    ui->doubleSpinBox_8->blockSignals(true);
    ui->doubleSpinBox_9->blockSignals(true);
    //qdsp->blockSignals(true);

    if(ui->comboBox_3->currentIndex() == 0)
    {
        ui->doubleSpinBox->setValue(r);
        ui->doubleSpinBox_2->setValue(g);
        ui->doubleSpinBox_3->setValue(b);
    }
    else if(ui->comboBox_3->currentIndex() == 1)
    {
        ui->doubleSpinBox->setValue(X);
        ui->doubleSpinBox_2->setValue(Y);
        ui->doubleSpinBox_3->setValue(Z);
    }
    else if(ui->comboBox_3->currentIndex() == 2)
    {
        ui->doubleSpinBox->setValue(h);
        ui->doubleSpinBox_2->setValue(s);
        ui->doubleSpinBox_3->setValue(v);
    }
    else if(ui->comboBox_3->currentIndex() == 3)
    {
        ui->doubleSpinBox->setValue(l);
        ui->doubleSpinBox_2->setValue(A);
        ui->doubleSpinBox_3->setValue(B);
    }
    else if(ui->comboBox_3->currentIndex() == 4)
    {
        ui->doubleSpinBox->setValue(h);
        ui->doubleSpinBox_2->setValue(l);
        ui->doubleSpinBox_3->setValue(s);
    }
    else if(ui->comboBox_3->currentIndex() == 5)
    {
        ui->doubleSpinBox->setValue(c);
        ui->doubleSpinBox_2->setValue(m);
        ui->doubleSpinBox_3->setValue(y);
        qdsp->setValue(k);
    }


    if(ui->comboBox_2->currentIndex() == 1)
    {
        ui->doubleSpinBox_4->setValue(r);
        ui->doubleSpinBox_6->setValue(g);
        ui->doubleSpinBox_5->setValue(b);
    }
    else if(ui->comboBox_2->currentIndex() == 0)
    {
        ui->doubleSpinBox_4->setValue(X);
        ui->doubleSpinBox_6->setValue(Y);
        ui->doubleSpinBox_5->setValue(Z);
    }
    else if(ui->comboBox_2->currentIndex() == 2)
    {
        ui->doubleSpinBox_4->setValue(h);
        ui->doubleSpinBox_6->setValue(s);
        ui->doubleSpinBox_5->setValue(v);
    }
    else if(ui->comboBox_2->currentIndex() == 3)
    {
        ui->doubleSpinBox_4->setValue(l);
        ui->doubleSpinBox_6->setValue(A);
        ui->doubleSpinBox_5->setValue(B);
    }
    else if(ui->comboBox_2->currentIndex() == 4)
    {
        ui->doubleSpinBox_4->setValue(h);
        ui->doubleSpinBox_6->setValue(l);
        ui->doubleSpinBox_5->setValue(s);
    }
    else if(ui->comboBox_2->currentIndex() == 5)
    {
        ui->doubleSpinBox_4->setValue(c);
        ui->doubleSpinBox_6->setValue(m);
        ui->doubleSpinBox_5->setValue(y);
        qdsp->setValue(k);
    }

    if(ui->comboBox->currentIndex() == 1)
    {
        ui->doubleSpinBox_7->setValue(r);
        ui->doubleSpinBox_8->setValue(g);
        ui->doubleSpinBox_9->setValue(b);
    }
    else if(ui->comboBox->currentIndex() == 2)
    {
        ui->doubleSpinBox_7->setValue(X);
        ui->doubleSpinBox_8->setValue(Y);
        ui->doubleSpinBox_9->setValue(Z);
    }
    else if(ui->comboBox->currentIndex() == 0)
    {
        ui->doubleSpinBox_7->setValue(h);
        ui->doubleSpinBox_8->setValue(s);
        ui->doubleSpinBox_9->setValue(v);
    }
    else if(ui->comboBox->currentIndex() == 3)
    {
        ui->doubleSpinBox_7->setValue(l);
        ui->doubleSpinBox_8->setValue(A);
        ui->doubleSpinBox_9->setValue(B);
    }
    else if(ui->comboBox->currentIndex() == 4)
    {
        ui->doubleSpinBox_7->setValue(h);
        ui->doubleSpinBox_8->setValue(l);
        ui->doubleSpinBox_9->setValue(s);
    }
    else if(ui->comboBox->currentIndex() == 5)
    {
        ui->doubleSpinBox_7->setValue(c);
        ui->doubleSpinBox_8->setValue(m);
        ui->doubleSpinBox_9->setValue(y);
        qdsp->setValue(k);
    }

    ui->doubleSpinBox->blockSignals(false);
    ui->doubleSpinBox_2->blockSignals(false);
    ui->doubleSpinBox_3->blockSignals(false);
    ui->doubleSpinBox_4->blockSignals(false);
    ui->doubleSpinBox_5->blockSignals(false);
    ui->doubleSpinBox_6->blockSignals(false);
    ui->doubleSpinBox_7->blockSignals(false);
    ui->doubleSpinBox_8->blockSignals(false);
    ui->doubleSpinBox_9->blockSignals(false);
    //qdsp->blockSignals(false);
    ui->pushButton->setStyleSheet("background-color: rgb("+ QString::number(r) +"," + QString::number(g) + "," + QString::number(b) + ")");
    ui->statusbar->showMessage("background-color: rgb("+ QString::number(r) +"," + QString::number(g) + "," + QString::number(b) + ")");
}

void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    if(ui->label_7->text() == "R")
    {
        r = arg1;
        RGB_To_CMYK();
        RGB_To_XYZ();
        RGB_To_HLS();
        RGB_To_HSV();
        XYZ_To_LAB();
    }
    else if(ui->label_7->text() == "H")
    {
        h = arg1;
        HSV_To_RGB();
        RGB_To_CMYK();
        RGB_To_XYZ();
        HSV_To_HLS();
        XYZ_To_LAB();
    }
    else if(ui->label_7->text() == "C")
    {
        c = arg1;
        CMYK_To_RGB();
        RGB_To_XYZ();
        RGB_To_HLS();
        RGB_To_HSV();
        XYZ_To_LAB();
    }
    else if(ui->label_7->text() == "X")
    {
        X = arg1;
        XYZ_To_LAB();
        XYZ_To_RGB();
        RGB_To_CMYK();
        RGB_To_HLS();
        RGB_To_HSV();
    }
    else if(ui->label_7->text() == "L")
    {
        l = arg1;
        LAB_To_XYZ();
        XYZ_To_RGB();
        RGB_To_CMYK();
        RGB_To_HLS();
        RGB_To_HSV();
    }

    updateSpinBox(ui->doubleSpinBox);
}


void MainWindow::on_doubleSpinBox_2_valueChanged(double arg1)
{
    if(ui->label_9->text() == "G")
    {
        g = arg1;
        RGB_To_CMYK();
        RGB_To_XYZ();
        RGB_To_HLS();
        RGB_To_HSV();
    }
    else if(ui->label_9->text() == "S")
    {
        s = arg1;
        HSV_To_RGB();
        RGB_To_CMYK();
        RGB_To_XYZ();
        HSV_To_HLS();
        XYZ_To_LAB();
    }
    else if(ui->label_9->text() == "L")
    {
        l = arg1;
        HLS_To_RGB();
        RGB_To_XYZ();
        RGB_To_CMYK();
        RGB_To_HSV();
        XYZ_To_LAB();
    }
    else if(ui->label_9->text() == "M")
    {
        m = arg1;
        CMYK_To_RGB();
        RGB_To_XYZ();
        RGB_To_HLS();
        RGB_To_HSV();
        XYZ_To_LAB();
    }
    else if(ui->label_9->text() == "Y")
    {
        Y = arg1;
        XYZ_To_LAB();
        XYZ_To_RGB();
        RGB_To_CMYK();
        RGB_To_HLS();
        RGB_To_HSV();
    }
    else if(ui->label_9->text() == "A")
    {
        A = arg1;
        LAB_To_XYZ();
        XYZ_To_RGB();
        RGB_To_CMYK();
        RGB_To_HLS();
        RGB_To_HSV();
    }

    ui->statusbar->showMessage(QString::number(h));
    updateSpinBox(ui->doubleSpinBox_2);
}


void MainWindow::on_doubleSpinBox_3_valueChanged(double arg1)
{
    if(ui->label_8->text() == "B" && ui->label_7->text() == "R")
    {
        b = arg1;
        RGB_To_CMYK();
        RGB_To_XYZ();
        RGB_To_HLS();
        RGB_To_HSV();
        XYZ_To_LAB();
    }
    else if(ui->label_8->text() == "V")
    {
        v = arg1;
        HSV_To_RGB();
        RGB_To_CMYK();
        RGB_To_XYZ();
        HSV_To_HLS();
        XYZ_To_LAB();
    }
    else if(ui->label_8->text() == "Y")
    {
        Y = arg1;
        CMYK_To_RGB();
        RGB_To_XYZ();
        RGB_To_HLS();
        RGB_To_HSV();
    }
    else if(ui->label_8->text() == "S")
    {
        s = arg1;
        HLS_To_RGB();
        RGB_To_XYZ();
        RGB_To_CMYK();
        RGB_To_HSV();
        XYZ_To_LAB();

    }
    else if(ui->label_8->text() == "Z")
    {
        Z = arg1;
        XYZ_To_LAB();
        XYZ_To_RGB();
        RGB_To_CMYK();
        RGB_To_HLS();
        RGB_To_HSV();
    }
    else if(ui->label_8->text() == "B" && ui->label_7->text() == "L")
    {
        B = arg1;
        LAB_To_XYZ();
        XYZ_To_RGB();
        RGB_To_CMYK();
        RGB_To_HLS();
        RGB_To_HSV();
    }

    ui->statusbar->showMessage(QString::number(h));
    updateSpinBox(ui->doubleSpinBox_3);
}


void MainWindow::on_comboBox_3_currentIndexChanged(int index)
{
    switch(index)
    {
    case 0:
    {
        ui->label_7->setText("R");
        ui->label_9->setText("G");
        ui->label_8->setText("B");
        ui->doubleSpinBox->setValue(r);
        ui->doubleSpinBox_2->setValue(g);
        ui->doubleSpinBox_3->setValue(b);
        ui->doubleSpinBox->setRange(0,255);
        ui->doubleSpinBox_2->setRange(0,255);
        ui->doubleSpinBox_3->setRange(0,255);
        if(Index1 == 5)
        {
            delete ql;
            delete qdsp;
        }
        Index1 = 0;
        break;
    }
    case 1:
    {
        ui->label_7->setText("X");
        ui->label_9->setText("Y");
        ui->label_8->setText("Z");
        ui->doubleSpinBox->setValue(X);
        ui->doubleSpinBox_2->setValue(Y);
        ui->doubleSpinBox_3->setValue(Z);
        ui->doubleSpinBox->setRange(0,95);
        ui->doubleSpinBox_2->setRange(0,100);
        ui->doubleSpinBox_3->setRange(0,108);
        if(Index1 == 5)
        {
            delete ql;
            delete qdsp;
        }
        Index1 = 1;
        break;
    }
    case 2:
    {
        ui->label_7->setText("H");
        ui->label_9->setText("S");
        ui->label_8->setText("V");
        ui->doubleSpinBox->setValue(h);
        ui->doubleSpinBox_2->setValue(s);
        ui->doubleSpinBox_3->setValue(v);
        ui->doubleSpinBox->setRange(0,360);
        ui->doubleSpinBox_2->setRange(0,1);
        ui->doubleSpinBox_3->setRange(0,1);
        if(Index1 == 5)
        {
            delete ql;
            delete qdsp;
        }
        Index1 = 2;
        break;
    }
    case 3:
    {
        ui->label_7->setText("L");
        ui->label_9->setText("A");
        ui->label_8->setText("B");
        ui->doubleSpinBox->setValue(l);
        ui->doubleSpinBox_2->setValue(A);
        ui->doubleSpinBox_3->setValue(B);
        ui->doubleSpinBox->setRange(0,100);
        ui->doubleSpinBox_2->setRange(-86.185, 98.254);
        ui->doubleSpinBox_3->setRange(-107.815, 94.482);
        if(Index1 == 5)
        {
            delete ql;
            delete qdsp;
        }
        Index1 = 3;
        break;
    }
    case 4:
    {
        ui->label_7->setText("H");
        ui->label_9->setText("L");
        ui->label_8->setText("S");
        ui->doubleSpinBox->setValue(h);
        ui->doubleSpinBox_2->setValue(l);
        ui->doubleSpinBox_3->setValue(s);
        ui->doubleSpinBox->setRange(0,360);
        ui->doubleSpinBox_2->setRange(0,100);
        ui->doubleSpinBox_3->setRange(0, 1);
        if(Index1 == 5)
        {
            delete ql;
            delete qdsp;
        }
        Index1 = 4;
        break;
    }
    case 5:
    {
        if(Index1 == 5)
        {
            delete ql;
            delete qdsp;
        }
        Index1 = 5;
        ui->label_7->setText("C");
        ui->label_9->setText("M");
        ui->label_8->setText("Y");
        ql = new QLabel("K");
        ui->verticalLayout_5->addWidget(ql);
        qdsp = new QDoubleSpinBox();
        ui->verticalLayout_2->addWidget(qdsp);
        ui->doubleSpinBox->setRange(0,360);
        ui->doubleSpinBox_2->setRange(0,1);
        ui->doubleSpinBox_3->setRange(0, 1);
        qdsp->setRange(0, 1);
        break;
    }
    }
    //updateSpinBox(ui->doubleSpinBox);
}


void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    switch(index)
    {
    case 1:
    {
        ui->label_4->setText("R");
        ui->label_5->setText("G");
        ui->label_6->setText("B");
        ui->doubleSpinBox_4->setRange(0,255);
        ui->doubleSpinBox_6->setRange(0,255);
        ui->doubleSpinBox_5->setRange(0,255);
        if(Index2 == 5)
        {
            delete ql;
            delete qdsp;
        }
        Index2 = 1;
        break;
    }
    case 0:
    {
        ui->label_4->setText("X");
        ui->label_5->setText("Y");
        ui->label_6->setText("Z");
        ui->doubleSpinBox_4->setRange(0,95);
        ui->doubleSpinBox_6->setRange(0,100);
        ui->doubleSpinBox_5->setRange(0,108);
        if(Index2 == 5)
        {
            delete ql;
            delete qdsp;
        }
        Index2 = 0;
        break;
    }
    case 2:
    {
        ui->label_4->setText("H");
        ui->label_5->setText("S");
        ui->label_6->setText("V");
        ui->doubleSpinBox_4->setRange(0,360);
        ui->doubleSpinBox_6->setRange(0,1);
        ui->doubleSpinBox_5->setRange(0,1);
        if(Index2 == 5)
        {
            delete ql;
            delete qdsp;
        }
        Index2 = 2;
        break;
    }
    case 3:
    {
        ui->label_4->setText("L");
        ui->label_5->setText("A");
        ui->label_6->setText("B");
        ui->doubleSpinBox_4->setRange(0,100);
        ui->doubleSpinBox_6->setRange(-86.185, 98.254);
        ui->doubleSpinBox_5->setRange(-107.815, 94.482);
        if(Index2 == 5)
        {
            delete ql;
            delete qdsp;
        }
        Index2 = 3;
        break;
    }
    case 4:
    {
        ui->label_4->setText("H");
        ui->label_5->setText("L");
        ui->label_6->setText("S");
        ui->doubleSpinBox_4->setRange(0,360);
        ui->doubleSpinBox_6->setRange(0,100);
        ui->doubleSpinBox_5->setRange(0, 1);
        if(Index2 == 5)
        {
            delete ql;
            delete qdsp;
        }
        Index2 = 4;
        break;
    }
    case 5:
    {
        if(Index2 == 5)
        {
            delete ql;
            delete qdsp;
        }
        Index2 = 5;
        ui->label_4->setText("C");
        ui->label_5->setText("M");
        ui->label_6->setText("Y");
        ql = new QLabel("K");
        ui->verticalLayout_4->addWidget(ql);
        qdsp = new QDoubleSpinBox();
        ui->verticalLayout->addWidget(qdsp);
        ui->doubleSpinBox_4->setRange(0,360);
        ui->doubleSpinBox_6->setRange(0,1);
        ui->doubleSpinBox_5->setRange(0, 1);
        qdsp->setRange(0, 1);
        break;
    }
    }
    //updateSpinBox(ui->doubleSpinBox_4);
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    switch(index)
    {
    case 1:
    {
        ui->label_10->setText("R");
        ui->label_11->setText("G");
        ui->label_12->setText("B");
        ui->doubleSpinBox_7->setRange(0,255);
        ui->doubleSpinBox_8->setRange(0,255);
        ui->doubleSpinBox_9->setRange(0,255);
        if(Index3 == 5)
        {
            delete ql;
            delete qdsp;
        }
        Index3 = 1;
        break;

    }
    case 2:
    {
        ui->label_10->setText("X");
        ui->label_11->setText("Y");
        ui->label_12->setText("Z");
        ui->doubleSpinBox_7->setRange(0,95);
        ui->doubleSpinBox_8->setRange(0,100);
        ui->doubleSpinBox_9->setRange(0,108);
        if(Index3 == 5)
        {
            delete ql;
            delete qdsp;
        }
        Index3 = 2;
        break;
    }
    case 0:
    {
        ui->label_10->setText("H");
        ui->label_11->setText("V");
        ui->label_12->setText("S");
        ui->doubleSpinBox_7->setRange(0,360);
        ui->doubleSpinBox_8->setRange(0,1);
        ui->doubleSpinBox_9->setRange(0,1);
        if(Index3 == 5)
        {
            delete ql;
            delete qdsp;
        }
        Index3 = 0;
        break;
    }
    case 3:
    {
        ui->label_10->setText("L");
        ui->label_11->setText("A");
        ui->label_12->setText("B");
        ui->doubleSpinBox_7->setRange(0,100);
        ui->doubleSpinBox_8->setRange(-86.185, 98.254);
        ui->doubleSpinBox_9->setRange(-107.815, 94.482);
        if(Index3 == 5)
        {
            delete ql;
            delete qdsp;
        }
        Index3 = 3;
        break;
    }
    case 4:
    {
        ui->label_10->setText("H");
        ui->label_11->setText("S");
        ui->label_12->setText("L");
        ui->doubleSpinBox_7->setRange(0,360);
        ui->doubleSpinBox_8->setRange(0,100);
        ui->doubleSpinBox_9->setRange(0, 1);
        if(Index3 == 5)
        {
            delete ql;
            delete qdsp;
        }
        Index3 = 4;
        break;
    }
    case 5:
    {
        if(Index3 == 5)
        {
            delete ql;
            delete qdsp;
        }
        Index3 = 5;
        ui->label_10->setText("C");
        ui->label_11->setText("M");
        ui->label_12->setText("Y");
        ql = new QLabel("K");
        ui->verticalLayout_6->addWidget(ql);
        qdsp = new QDoubleSpinBox();
        ui->verticalLayout_3->addWidget(qdsp);
        ui->doubleSpinBox_7->setRange(0,360);
        ui->doubleSpinBox_8->setRange(0,1);
        ui->doubleSpinBox_9->setRange(0, 1);
        qdsp->setRange(0, 1);
        break;
    }
    }
    //updateSpinBox(ui->doubleSpinBox_7);
}



/*void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    if(ch)
    {
        str = arg1;
        bool check = true;
        if(str.size() == 7)
        {
            if(str[0] == '#')
            {
                for(int i = 1; i < 7; ++i)
                {
                    if(str[i] != '0' || str[i] != '1' || str[i] != '2' || str[i] != '3' || str[i] != '4' || str[i] != '5'
                        || str[i] != '6' || str[i] != '7' || str[i] != '8' || str[i] != '9' || str[i] != 'a' || str[i] != 'b'
                        || str[i] != 'c' || str[i] != 'd' || str[i] != 'e' || str[i] != 'f')
                    {
                        check = false;
                    }
                }
            }
        }
        if(check)
        {
            QColor* clr = new QColor();
            clr->setNamedColor(str);
            r = clr->red();
            g = clr->green();
            b = clr->blue();

            RGB_To_CMYK();
            RGB_To_XYZ();
            RGB_To_HLS();
            RGB_To_HSV();
            XYZ_To_LAB();

            updateSpinBox();
        }
    }
    ch = false;
}*/


void MainWindow::on_doubleSpinBox_4_valueChanged(double arg1)
{
    if(ui->label_4->text() == "R")
    {
        r = arg1;
        RGB_To_CMYK();
        RGB_To_XYZ();
        RGB_To_HLS();
        RGB_To_HSV();
        XYZ_To_LAB();
    }
    else if(ui->label_4->text() == "H")
    {
        h = arg1;
        HSV_To_RGB();
        RGB_To_CMYK();
        RGB_To_XYZ();
        HSV_To_HLS();
        XYZ_To_LAB();
    }
    else if(ui->label_4->text() == "C")
    {
        c = arg1;
        CMYK_To_RGB();
        RGB_To_XYZ();
        RGB_To_HLS();
        RGB_To_HSV();
        XYZ_To_LAB();
    }
    else if(ui->label_4->text() == "X")
    {
        X = arg1;
        XYZ_To_LAB();
        XYZ_To_RGB();
        RGB_To_CMYK();
        RGB_To_HLS();
        RGB_To_HSV();

    }
    else if(ui->label_4->text() == "L")
    {
        l = arg1;
        HLS_To_RGB();
        RGB_To_XYZ();
        RGB_To_CMYK();
        RGB_To_HSV();
        XYZ_To_LAB();
    }

    updateSpinBox(ui->doubleSpinBox_4);
}


void MainWindow::on_doubleSpinBox_6_valueChanged(double arg1)
{
    if(ui->label_5->text() == "G")
    {
        g = arg1;
        RGB_To_CMYK();
        RGB_To_XYZ();
        RGB_To_HLS();
        RGB_To_HSV();
        XYZ_To_LAB();
    }
    else if(ui->label_5->text() == "S")
    {
        s = arg1;
        HSV_To_RGB();
        RGB_To_CMYK();
        RGB_To_XYZ();
        HSV_To_HLS();
        XYZ_To_LAB();
    }
    else if(ui->label_5->text() == "L")
    {
        l = arg1;
        HLS_To_RGB();
        RGB_To_XYZ();
        RGB_To_CMYK();
        RGB_To_HSV();
        XYZ_To_LAB();
    }
    else if(ui->label_5->text() == "M")
    {
        m = arg1;
        c = arg1;
        CMYK_To_RGB();
        RGB_To_XYZ();
        RGB_To_HLS();
        RGB_To_HSV();
        XYZ_To_LAB();
    }
    else if(ui->label_5->text() == "Y")
    {
        Y = arg1;
        XYZ_To_LAB();
        XYZ_To_RGB();
        RGB_To_CMYK();
        RGB_To_HLS();
        RGB_To_HSV();
    }
    else if(ui->label_5->text() == "A")
    {
        A = arg1;
        LAB_To_XYZ();
        XYZ_To_RGB();
        RGB_To_CMYK();
        RGB_To_HLS();
        RGB_To_HSV();
    }

    ui->statusbar->showMessage(QString::number(h));
    updateSpinBox(ui->doubleSpinBox_6);
}


void MainWindow::on_doubleSpinBox_5_valueChanged(double arg1)
{
    if(ui->label_6->text() == "B" && ui->label_4->text() == "R")
    {
        b = arg1;
        RGB_To_CMYK();
        RGB_To_XYZ();
        RGB_To_HLS();
        RGB_To_HSV();
        XYZ_To_LAB();
    }
    else if(ui->label_6->text() == "V")
    {
        v = arg1;
        HSV_To_RGB();
        RGB_To_CMYK();
        RGB_To_XYZ();
        HSV_To_HLS();
        XYZ_To_LAB();
    }
    else if(ui->label_6->text() == "Y")
    {
        Y = arg1;
        c = arg1;
        CMYK_To_RGB();
        RGB_To_XYZ();
        RGB_To_HLS();
        RGB_To_HSV();
        XYZ_To_LAB();
    }
    else if(ui->label_6->text() == "S")
    {
        s = arg1;
        HLS_To_RGB();
        RGB_To_XYZ();
        RGB_To_CMYK();
        RGB_To_HSV();
        XYZ_To_LAB();
    }
    else if(ui->label_6->text() == "Z")
    {
        Z = arg1;
        XYZ_To_LAB();
        XYZ_To_RGB();
        RGB_To_CMYK();
        RGB_To_HLS();
        RGB_To_HSV();
    }
    else if(ui->label_6->text() == "B" && ui->label_4->text() == "L")
    {
        B = arg1;
        LAB_To_XYZ();
        XYZ_To_RGB();
        RGB_To_CMYK();
        RGB_To_HLS();
        RGB_To_HSV();
    }

    ui->statusbar->showMessage(QString::number(h));
    updateSpinBox(ui->doubleSpinBox_5);
}


void MainWindow::on_doubleSpinBox_7_valueChanged(double arg1)
{
    if(ui->label_10->text() == "R")
    {
        r = arg1;
        RGB_To_CMYK();
        RGB_To_XYZ();
        RGB_To_HLS();
        RGB_To_HSV();
        XYZ_To_LAB();
    }
    else if(ui->label_10->text() == "H")
    {
        h = arg1;
        HSV_To_RGB();
        RGB_To_CMYK();
        RGB_To_XYZ();
        HSV_To_HLS();
        XYZ_To_LAB();
    }
    else if(ui->label_10->text() == "C")
    {
        c = arg1;
        c = arg1;
        CMYK_To_RGB();
        RGB_To_XYZ();
        RGB_To_HLS();
        RGB_To_HSV();
        XYZ_To_LAB();
    }
    else if(ui->label_10->text() == "X")
    {
        X = arg1;
        XYZ_To_LAB();
        XYZ_To_RGB();
        RGB_To_CMYK();
        RGB_To_HLS();
        RGB_To_HSV();
    }
    else if(ui->label_10->text() == "L")
    {
        l = arg1;
        LAB_To_XYZ();
        XYZ_To_RGB();
        RGB_To_CMYK();
        RGB_To_HLS();
        RGB_To_HSV();
    }


    updateSpinBox(ui->doubleSpinBox_7);
}


void MainWindow::on_doubleSpinBox_8_valueChanged(double arg1)
{
    if(ui->label_12->text() == "G")
    {
        g = arg1;
        RGB_To_CMYK();
        RGB_To_XYZ();
        RGB_To_HLS();
        RGB_To_HSV();
        XYZ_To_LAB();
    }
    else if(ui->label_12->text() == "S")
    {
        s = arg1;
        HSV_To_RGB();
        RGB_To_CMYK();
        RGB_To_XYZ();
        HSV_To_HLS();
        XYZ_To_LAB();
    }
    else if(ui->label_12->text() == "L")
    {
        l = arg1;
        HLS_To_RGB();
        RGB_To_XYZ();
        RGB_To_CMYK();
        RGB_To_HSV();
        XYZ_To_LAB();
    }
    else if(ui->label_12->text() == "M")
    {
        m = arg1;
        c = arg1;
        CMYK_To_RGB();
        RGB_To_XYZ();
        RGB_To_HLS();
        RGB_To_HSV();
        XYZ_To_LAB();
    }
    else if(ui->label_12->text() == "Y")
    {
        Y = arg1;
        XYZ_To_LAB();
        XYZ_To_RGB();
        RGB_To_CMYK();
        RGB_To_HLS();
        RGB_To_HSV();
    }
    else if(ui->label_12->text() == "A")
    {
        A = arg1;
        LAB_To_XYZ();
        XYZ_To_RGB();
        RGB_To_CMYK();
        RGB_To_HLS();
        RGB_To_HSV();
    }

    ui->statusbar->showMessage(QString::number(h));
    updateSpinBox(ui->doubleSpinBox_8);
}


void MainWindow::on_doubleSpinBox_9_valueChanged(double arg1)
{
    if(ui->label_11->text() == "B" && ui->label_10->text() == "R")
    {
        b = arg1;
        RGB_To_CMYK();
        RGB_To_XYZ();
        RGB_To_HLS();
        RGB_To_HSV();
        XYZ_To_LAB();
    }
    else if(ui->label_11->text() == "V")
    {
        v = arg1;
        HSV_To_RGB();
        RGB_To_CMYK();
        RGB_To_XYZ();
        HSV_To_HLS();
        XYZ_To_LAB();
    }
    else if(ui->label_11->text() == "Y")
    {
        Y = arg1;
        c = arg1;
        CMYK_To_RGB();
        RGB_To_XYZ();
        RGB_To_HLS();
        RGB_To_HSV();
        XYZ_To_LAB();
    }
    else if(ui->label_11->text() == "S")
    {
        s = arg1;
        HLS_To_RGB();
        RGB_To_XYZ();
        RGB_To_CMYK();
        RGB_To_HSV();
        XYZ_To_LAB();
    }
    else if(ui->label_11->text() == "Z")
    {
        Z = arg1;
        XYZ_To_LAB();
        XYZ_To_RGB();
        RGB_To_CMYK();
        RGB_To_HLS();
        RGB_To_HSV();
    }
    else if(ui->label_11->text() == "B" && ui->label_10->text() == "L")
    {
        B = arg1;
        LAB_To_XYZ();
        XYZ_To_RGB();
        RGB_To_CMYK();
        RGB_To_HLS();
        RGB_To_HSV();
    }

    ui->statusbar->showMessage(QString::number(h));
    updateSpinBox(ui->doubleSpinBox_9);
}


void MainWindow::on_lineEdit_editingFinished()
{
    ch = true;
}

