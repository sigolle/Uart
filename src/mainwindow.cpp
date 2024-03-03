#include "../include/mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVBoxLayout *vblUart = new QVBoxLayout(this);

    QStringList lbNames{"串口","波特率","数据位","校验位","停止位"};
    QLabel *lbUartSetting = new QLabel("串口设置");
    unsigned char cbbIndex=0;
    vblUart->addWidget(lbUartSetting);
    for(const QString &name : lbNames)
    {
        QLabel *label = new QLabel(name);
        cbbUart[cbbIndex] = new QComboBox;
        cbbUart[cbbIndex]->setEditable(true);
        QHBoxLayout *hblUart = new QHBoxLayout(this);
        hblUart->addWidget(label);
        hblUart->addWidget(cbbUart[cbbIndex++]);
        vblUart->addLayout(hblUart);
    }
    ui->centralwidget->setLayout(vblUart);
    addComboBoxContent();

}

void MainWindow::addComboBoxContent()
{
    cbbUart[1]->addItem("9600");
    cbbUart[1]->addItem("19200");
    cbbUart[1]->addItem("115200");
}

MainWindow::~MainWindow()
{
    delete ui;
}
