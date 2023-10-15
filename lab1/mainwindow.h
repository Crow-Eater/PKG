
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QErrorMessage>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_doubleSpinBox_2_valueChanged(double arg1);

    void on_doubleSpinBox_3_valueChanged(double arg1);

    void on_comboBox_3_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(int index);

    void on_comboBox_currentIndexChanged(int index);


    /*void on_lineEdit_textEdited(const QString &arg1);*/

    void on_doubleSpinBox_4_valueChanged(double arg1);

    void on_doubleSpinBox_6_valueChanged(double arg1);

    void on_doubleSpinBox_5_valueChanged(double arg1);

    void on_doubleSpinBox_7_valueChanged(double arg1);

    void on_doubleSpinBox_8_valueChanged(double arg1);

    void on_doubleSpinBox_9_valueChanged(double arg1);

    void on_lineEdit_editingFinished();

private:
    Ui::MainWindow *ui;
    QString str;
    QLabel* ql;
    QDoubleSpinBox* qdsp;
    int Index1, Index2, Index3;
    double r, g, b;
    bool ch;
    double c, m, y, k;

    double h, s, v, l, A, B;

    double X, Y, Z;

    double f(double x);
    double f1(double x);
    double F(double x);
    void updateSpinBox(QObject* obj);

    void RGB_To_CMYK();
    void RGB_To_XYZ();
    void RGB_To_HLS();
    void RGB_To_HSV();
    void XYZ_To_LAB();

    void XYZ_To_RGB();
    void HSV_To_RGB();
    void HSV_To_HLS();
    void HLS_To_RGB();
    void LAB_To_XYZ();
    void CMYK_To_RGB();


};

#endif // MAINWINDOW_H
