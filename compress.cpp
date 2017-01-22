#include "compress.h"
#include "ui_compress.h"
#include "rumit.h"
#include "tree.h"
#include "huffman.h"
#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>
#include <QDir>

compress::compress(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::compress)
{
    ui->setupUi(this);
    ui->pushButton_2->setEnabled(false);
}

compress::~compress()
{
    delete ui;
}

//Mengecek button
void compress::check(){
    if ((output != "") && (path != "")){
        ui->pushButton_2->setEnabled(true);
    }
}

void compress::on_lineEdit_textEdited(const QString &arg1)
{
    output = arg1;
    compress::check();
}

//Browse button
void compress::on_pushButton_clicked()
{
    //Algoritma
    path = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                             "C://",
                                             QFileDialog::ShowDirsOnly
                                             | QFileDialog::DontResolveSymlinks);
    ui->lineEdit_2->setText(path);
    compress::check();
}

//Ok Button
void compress::on_pushButton_2_clicked()
{
    //Kamus Lokal
    QString f = paths();
    QFileInfo checkfile(f);
    QDir dir(path);

    //Algoritma
    //Mengecek keberadaan direktori
    if (!dir.exists()){//direktori tidak ada
        QMessageBox::information(this, tr("Error"), "This directory does not exist!");
    } else {//direktori ada
        //Mengecek keberadaan file
        if (checkfile.exists() && checkfile.isFile()) {//file sudah ada
            output = "";
            QMessageBox::information(this, tr("Error"), "This file already exists!");
            ui->lineEdit->setText("");
            ui->pushButton_2->setEnabled(false);
        } else {//file tidak ada
            accept();
        }
   }
}

//cancel button
void compress::on_pushButton_3_clicked()
{
    reject();
}

//Menggabungkan path dengan nama file
QString compress::paths(){
    return path+"/"+output+".rum";
}


void compress::on_lineEdit_2_textEdited(const QString &arg1)
{
    //Kamus Lokal
    path = arg1;

    //Algoritma
    compress::check();
}
