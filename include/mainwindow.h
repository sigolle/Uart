#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QComboBox *cbbUart[5];
    void addComboBoxContent();

//UI
private:
    QLabel *lbUartSetting;
    QLabel *lbUart;
    QLabel *lbBaud;
    QLabel *lbData;
    QLabel *lbCheck;
    QLabel *lbStop;
};
#endif // MAINWINDOW_H
