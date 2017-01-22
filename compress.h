#ifndef COMPRESS_H
#define COMPRESS_H

#include <QDialog>
#include "tree.h"
#include "huffman.h"

namespace Ui {
class compress;
}

class compress : public QDialog
{
    Q_OBJECT

public:
    explicit compress(QWidget *parent = 0);
    ~compress();
    QString paths();
    //Menggabungkan path dan output dan menghasilkan direktori lengkap

private slots:
    void check();
    //Mengecek apakah tombol Ok sudah boleh di Enable

    void on_lineEdit_textEdited(const QString &arg1);
    //Mengisi variabel output dengan QString yang diketik pada lineEdit

    void on_pushButton_clicked();
    //Implementasi ketika tombol Browse ditekan

    void on_pushButton_2_clicked();
    //Implementasi ketika tombol Ok ditekan

    void on_pushButton_3_clicked();
    //Implementasi ketika tombol Cancel ditekan

    void on_lineEdit_2_textEdited(const QString &arg1);
    //Mengisi variabel path dengan QString yang telah diketik pada lineEdit_2

private:
    Ui::compress *ui;
    QString output, path;
};

#endif // COMPRESS_H
