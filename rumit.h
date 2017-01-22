#ifndef RUMIT_H
#define RUMIT_H

#include <QMainWindow>
#include "tree.h"
#include "huffman.h"

namespace Ui {
class RumIt;
}

class RumIt : public QMainWindow
{
    Q_OBJECT

public:
    explicit RumIt(QWidget *parent = 0);
    ~RumIt();

private slots:
    //Menghitung Size
    QString size_read(qint64 Size);
    //Merubah size file input dari browse menjadi QString yang human readable

    QString size_table(int Size);
    //Merubah size file hasil kompresi  menjadi QString yang human readable


    //Kondisi Awal
    void KondisiAwal();
    //Kondisi awal GUI

    //Menu Bar
    //Implementasi ketika menu-menu dalam menu bar dipilih
    void on_actionNew_triggered();
    //Menu New

    void on_actionAdd_File_s_triggered();
    //Menu Add File(s)

    void on_actionRemove_triggered();
    //Menu Remove

    void on_actionExit_triggered();
    //Menu Exit

    void on_actionAbout_triggered();
    //Menu About

    void on_actionCompress_triggered();
    //Menu Compress

    void on_actionDecompress_triggered();
    //Menu Decompress

    void on_actionOpen_triggered();
    //Menu Open


    //Push Buttons
    void on_pushButton_clicked();
    //Implementasi ketika tombol Browse ditekan

    void on_pushButton_6_clicked();
    //Implementasi ketika tombol Add File(s) yang akan dikompresi ditekan

    void on_pushButton_3_clicked();
    //Implementasi ketika tombol Remove File(s) ditekan

    void on_lineEdit_textEdited(const QString &arg1);
    //Memasukkan direktori yang telah diketik pada lineEdit ke variabel FileName

    void on_pushButton_4_clicked();
    //Implementasi ketika tombol Compress ditekan

    void on_pushButton_5_clicked();
    //Implementasi ketika tombol Dekompresi ditekan

    void on_pushButton_10_clicked();
    //Merubah penampilan GUI menjadi penampilan untuk mengkompresi file

    void on_pushButton_11_clicked();
    //Merubah penampilan GUI menjadi penampilan untuk mendekompresi file

    void on_pushButton_7_clicked();
    //Implementasi ketika tombol Add File(s) Decompress ditekan


    //Compressor Decompressor
    void compressor (string in[], int count, string out, double *entropi, double *bitPerSimbol, double *timer, int **sizeOut, double **rata, double *nisbah, int *prog);
    // prosedur untuk melakukan kompresi satu atau beberapa file

    void decompressor (string in, string pathOut, double *timer, int *prog);
    // prosedur untuk melakukan dekompresi


private:
    Ui::RumIt *ui;
    QString FileName, FileNameD;
    enum Column{
        NAME, SIZE, PACKED, PERCENTAGE
    };
    enum Column_2 {
        PATH
    };
    int row, prog;
    double timer, entropi, bps, nisbah;
    int* sizeout = new int [100];
    double* rata = new double [100];
    std::string path [100];
};

#endif // RUMIT_H
