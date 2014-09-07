#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_ejecutar_clicked();

    void on_salir_clicked();

    void on_texto_textChanged();

    void on_actionEJECUTAR_triggered();

    void on_actionSALIR_triggered();

    void on_actionAYUDA_triggered();

    void on_actionACERCA_DE_triggered();

    void on_actionEJECUTAR_2_triggered();

    void on_actionSALIR_2_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
