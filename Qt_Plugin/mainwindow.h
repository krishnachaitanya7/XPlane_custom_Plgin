#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QGroupBox>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonBox_accepted();
    void on_radioButton_clicked();
private:
    Ui::MainWindow *ui;
    QGroupBox *createFirstQuestion();
    QGroupBox *createSecondQuestion();
};

#endif // MAINWINDOW_H
