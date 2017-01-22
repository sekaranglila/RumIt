#include "decompress.h"
#include "ui_decompress.h"
#include "rumit.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QFileInfo>

decompress::decompress(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::decompress)
{
    ui->setupUi(this);
    ui->pushButton->setEnabled(false);
}

decompress::~decompress()
{
    delete ui;
}

//cancel button
void decompress::on_pushButton_2_clicked()
{
    reject();
}

//Browse
void decompress::on_pushButton_3_clicked()
{
    //Algoritma
    dPath = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                             "C://",
                                             QFileDialog::ShowDirsOnly
                                             | QFileDialog::DontResolveSymlinks);
    ui->lineEdit->setText(dPath);
    decompress::check();
}

void decompress::on_lineEdit_textEdited(const QString &arg1)
{
    //Kamus Lokal
    dPath = arg1;

    //Algoritma
    decompress::check();
}

void decompress::on_folder_textEdited(const QString &arg1)
{
    //Kamus Lokal
    folder = arg1;

    //Algoritma
    decompress::check();

}

//Mengecek tombol
void decompress::check(){
    QDir dir(dPath);

    //Algoritma
    if ((dPath != "") && (folder != "")){
        ui->pushButton->setEnabled(true);
    }

}

//ok button
void decompress::on_pushButton_clicked()
{
    //Kamus Lokal
    QString path = decompress::paths();
    QDir dir(path);
    QDir dirp (dPath);

    //Algoritma
    //Mengecek keberadaan direktori
    if (!dirp.exists()){//direktori tidak ada
        QMessageBox::information(this, tr("Error"), "Rum It can't do this action!");
        ui->lineEdit->setText("");
        ui->pushButton->setEnabled(false);
    } else {//Mengecek keberadaan folder yang akan dibuat
        if (dir.exists()){//folder ada
            QMessageBox::information(this, tr("Error"), "This directory already exists!");
            ui->lineEdit->setText("");
            ui->folder->setText("");
            ui->pushButton->setEnabled(false);
        } else { //folder tidak ada
            decompress::makeFolder();
            accept();
        }
    }
}

//Buat folder
void decompress::makeFolder(){
    //Kamus Lokal
    QDir dir(dPath);

    //Algoritma
    dir.mkpath(folder);

}

//Menggabungkan path dengan nama file
QString decompress::paths(){

    //Algoritma
    return dPath+"/"+folder;
}
