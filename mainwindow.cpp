#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ejecutar_clicked()
{
    QString text,password,cifra,final;  //texto sin cifrar, contraseña, texto cifrado, resultado operaciones
    int longitudClave = 0;

    // definir variables
    text = ui->texto->toPlainText();
    cifra = ui->cifrado->toPlainText();
    password = ui->pass->toPlainText();
    longitudClave = password.size();   //bloques segun longitud de la clave

    //transformar entradas
    text = text.toUpper();  //convertir a mayusculas
    text = text.simplified();  //eliminar espacios en blanco
    password = password.toUpper();  //convertir a mayusculas
    password = password.simplified();  //eliminar espacios en blanco




    if(cifra.isEmpty() && !password.isEmpty() && !text.isEmpty())  //ciframos texto
    {
        for(int i = 0, j = 0;i<text.size();++i)
        {
                if(text.at(i) >= QChar('A') && text.at(i) <= QChar('Z') && text.at(i) != QChar('Ñ'))  //alfabeto de la A-Z sin Ñ
                {
                        final.append((text[i].toLatin1()+password[j].toLatin1())%26+'A');
                    j = (j + 1) % longitudClave;
                }
        }  //QALMARZASRSFQIMBCQQALZIVDI ABCDEFGHIJKLMNOPQRSTVWYZ

        ui->cifrado->setPlainText(final);
        ui->cifrado->show();
    }
    else if(!cifra.isEmpty() && !password.isEmpty() && text.isEmpty()) //desciframos texto
    {
        for(int i = 0, j = 0;i<cifra.size();++i)
        {
                if(cifra.at(i) >= QChar('A') && cifra.at(i) <= QChar('Z') && cifra.at(i) != QChar('Ñ'))  //alfabeto de la A-Z sin Ñ
                {
                    final.append((cifra[i].toLatin1()-password[j].toLatin1()+2*'A')%26+'A');
                    j = (j + 1) % longitudClave;
                }
        }

        ui->texto->setPlainText(final);
        ui->texto->show();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.information(this,"RECUERDE","El campo contraseña no puede estar vacio, asi como los dos campos de texto."
                           "Al igual que los dos campos de texto, no pueden tener texto al mismo tiempo, borre texto o  texto cifrado para continuar operando.");
        msgBox.exec();
    }
}

void MainWindow::on_salir_clicked()
{
    close();
}

void MainWindow::on_actionAYUDA_triggered()
{
    QMessageBox msgBox;
    msgBox.information(this,"AYUDA","Inserte el texto a cifrar en el recuadro texto a cifrar,"
                       "luego debe teclear una contraseña, en el recuadro contraseña y presionar botón ejecutar.\nDebes tener "
                       "en cuenta, que solo se usará letras que estén entre la A y la Z, sin incluir la letra Ñ\n"
                       "Para descifrar un texto, situar texto a descifrar en caja de texto cifrado, poner constraseña "
                       "y presionar boton ejecutar.");
    msgBox.exec();
}

void MainWindow::on_actionACERCA_DE_triggered()
{
    QMessageBox msgBox;
    msgBox.information(this,"ACERCA","Practica uno, de seguridad informática.\nUniversidad de la Laguna.\n\n"
                       "\nTITULO: Algoritmo Vigenere."
                       "\nAUTOR: José Antonio Rodríguez Leandro.\n"
                       "FECHA: 30 DE ENERO DE 2014.");
    msgBox.exec();
}


//MENU
void MainWindow::on_actionEJECUTAR_2_triggered()
{
     ui->ejecutar->click();
}

void MainWindow::on_actionSALIR_2_triggered()
{
    close();
}


