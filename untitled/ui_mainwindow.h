/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox_3;
    QComboBox *comboBox_2;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_2;
    QDoubleSpinBox *doubleSpinBox;
    QSlider *horizontalSlider;
    QDoubleSpinBox *doubleSpinBox_2;
    QSlider *horizontalSlider_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QSlider *horizontalSlider_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QVBoxLayout *verticalLayout;
    QDoubleSpinBox *doubleSpinBox_4;
    QSlider *horizontalSlider_4;
    QDoubleSpinBox *doubleSpinBox_6;
    QSlider *horizontalSlider_5;
    QDoubleSpinBox *doubleSpinBox_5;
    QSlider *horizontalSlider_6;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *label_11;
    QVBoxLayout *verticalLayout_3;
    QDoubleSpinBox *doubleSpinBox_7;
    QSlider *horizontalSlider_7;
    QDoubleSpinBox *doubleSpinBox_8;
    QSlider *horizontalSlider_8;
    QDoubleSpinBox *doubleSpinBox_9;
    QSlider *horizontalSlider_9;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 800);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 800));
        MainWindow->setMaximumSize(QSize(800, 800));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setMinimumSize(QSize(800, 600));
        centralwidget->setMaximumSize(QSize(800, 600));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        comboBox_3 = new QComboBox(centralwidget);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");

        horizontalLayout_2->addWidget(comboBox_3);

        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");

        horizontalLayout_2->addWidget(comboBox_2);

        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        horizontalLayout_2->addWidget(comboBox);


        gridLayout_2->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(200);
        sizePolicy1.setVerticalStretch(200);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setSizeConstraint(QLayout::SetFixedSize);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");

        verticalLayout_5->addWidget(label_7);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");

        verticalLayout_5->addWidget(label_9);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");

        verticalLayout_5->addWidget(label_8);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        doubleSpinBox = new QDoubleSpinBox(centralwidget);
        doubleSpinBox->setObjectName("doubleSpinBox");

        verticalLayout_2->addWidget(doubleSpinBox);

        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider);

        doubleSpinBox_2 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_2->setObjectName("doubleSpinBox_2");

        verticalLayout_2->addWidget(doubleSpinBox_2);

        horizontalSlider_2 = new QSlider(centralwidget);
        horizontalSlider_2->setObjectName("horizontalSlider_2");
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider_2);

        doubleSpinBox_3 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_3->setObjectName("doubleSpinBox_3");

        verticalLayout_2->addWidget(doubleSpinBox_3);

        horizontalSlider_3 = new QSlider(centralwidget);
        horizontalSlider_3->setObjectName("horizontalSlider_3");
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider_3);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        verticalLayout_4->addWidget(label_4);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");

        verticalLayout_4->addWidget(label_5);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");

        verticalLayout_4->addWidget(label_6);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        doubleSpinBox_4 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_4->setObjectName("doubleSpinBox_4");

        verticalLayout->addWidget(doubleSpinBox_4);

        horizontalSlider_4 = new QSlider(centralwidget);
        horizontalSlider_4->setObjectName("horizontalSlider_4");
        horizontalSlider_4->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_4);

        doubleSpinBox_6 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_6->setObjectName("doubleSpinBox_6");

        verticalLayout->addWidget(doubleSpinBox_6);

        horizontalSlider_5 = new QSlider(centralwidget);
        horizontalSlider_5->setObjectName("horizontalSlider_5");
        horizontalSlider_5->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_5);

        doubleSpinBox_5 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_5->setObjectName("doubleSpinBox_5");

        verticalLayout->addWidget(doubleSpinBox_5);

        horizontalSlider_6 = new QSlider(centralwidget);
        horizontalSlider_6->setObjectName("horizontalSlider_6");
        horizontalSlider_6->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_6);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");

        verticalLayout_6->addWidget(label_10);

        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");

        verticalLayout_6->addWidget(label_12);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");

        verticalLayout_6->addWidget(label_11);


        horizontalLayout->addLayout(verticalLayout_6);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        doubleSpinBox_7 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_7->setObjectName("doubleSpinBox_7");

        verticalLayout_3->addWidget(doubleSpinBox_7);

        horizontalSlider_7 = new QSlider(centralwidget);
        horizontalSlider_7->setObjectName("horizontalSlider_7");
        horizontalSlider_7->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(horizontalSlider_7);

        doubleSpinBox_8 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_8->setObjectName("doubleSpinBox_8");

        verticalLayout_3->addWidget(doubleSpinBox_8);

        horizontalSlider_8 = new QSlider(centralwidget);
        horizontalSlider_8->setObjectName("horizontalSlider_8");
        horizontalSlider_8->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(horizontalSlider_8);

        doubleSpinBox_9 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_9->setObjectName("doubleSpinBox_9");

        verticalLayout_3->addWidget(doubleSpinBox_9);

        horizontalSlider_9 = new QSlider(centralwidget);
        horizontalSlider_9->setObjectName("horizontalSlider_9");
        horizontalSlider_9->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(horizontalSlider_9);


        horizontalLayout->addLayout(verticalLayout_3);


        gridLayout_2->addLayout(horizontalLayout, 5, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_2, 4, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("MainWindow", "RGB", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("MainWindow", "XYZ", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("MainWindow", "HSV", nullptr));
        comboBox_3->setItemText(3, QCoreApplication::translate("MainWindow", "LAB", nullptr));
        comboBox_3->setItemText(4, QCoreApplication::translate("MainWindow", "HLS", nullptr));
        comboBox_3->setItemText(5, QCoreApplication::translate("MainWindow", "CMYK", nullptr));

        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "XYZ", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "RGB", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "HSV", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("MainWindow", "LAB", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("MainWindow", "HLS", nullptr));
        comboBox_2->setItemText(5, QCoreApplication::translate("MainWindow", "CMYK", nullptr));

        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "HSV", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "RGB", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "XYZ", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "LAB", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "HLS", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "CMYK", nullptr));

        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
