#ifndef DECOMPRESS_H
#define DECOMPRESS_H

#include <QDialog>
#include "tree.h"
#include "huffman.h"

namespace Ui {
class decompress;
}

class decompress : public QDialog
{
    Q_OBJECT

public:
    explicit decompress(QWidget *parent = 0);
    ~decompress();
    QString paths();
    //Menghasilkan direktori lengkap

private slots:
    void on_pushButton_2_clicked();
    //Implementasi ketika tombol Cancel ditekan

    void on_pushButton_3_clicked();
    //Implementasi ketika tombol Browse ditekan

    void on_lineEdit_textEdited(const QString &arg1);
    //Mengisi variabel dPath dengan QString yang diketik dalam lineEdit

    void check();
    //Mengecek apakah tombol Ok bisa di Enable

    void on_pushButton_clicked();
    //Implementasi ketika tombol Ok ditekan

    void on_folder_textEdited(const QString &arg1);
    //Mengisi variabel folder dengan QString yang diketik di lineEdit 'folder'

    void makeFolder();
    //Membuat folder dari direktori yang dihasilkan fungsi decompress::paths()

private:
    Ui::decompress *ui;
    QString dPath;
    QString folder;
};

#endif // DECOMPRESS_H
