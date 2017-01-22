#include "rumit.h"
#include "ui_rumit.h"
#include "dialog.h"
#include "compress.h"
#include "decompress.h"
#include "tree.cpp"
#include "huffman.cpp"
#include <string>
#include <QFileDialog>
#include <QFile>
#include <QFileInfo>
#include <QTableWidget>
#include <QMessageBox>
#include <QStringList>
#include <QHeaderView>
#include <QTimer>

RumIt::RumIt(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RumIt)
{
    ui->setupUi(this);

    //default table
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    //ui->progressBar->setValue(prog);
    RumIt::KondisiAwal();

}

void RumIt::KondisiAwal(){
    //Kondisi Awal
    //Set Visibility
    //Browsing
    ui->lineEdit->setVisible(false);
    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(true);
    //Table
    ui->tableWidget->setVisible(false);
    ui->pathtable->setVisible(false);
    //PushButtons
    ui->pushButton_6->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->pushButton_4->setVisible(false);
    ui->pushButton_5->setVisible(false);
    ui->pushButton_7->setVisible(false);
    //Detail Bar
    ui->pushButton_8->setVisible(false);
    ui->Time->setVisible(false);
    ui->label_6->setVisible(false);
    ui->label->setVisible(false);
    ui->entropy->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->ratio->setVisible(false);
    ui->label_4->setVisible(false);
    ui->pushButton_12->setVisible(false);
    ui->pertotal->setVisible(false);
    ui->label_7->setVisible(false);
    //Progress Bar
    ui->progressBar->setVisible(false);
    ui->progressBar->reset();
    //Disable Buttons
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    prog = 0;
}

//Encode
void RumIt::on_pushButton_10_clicked()
{
    //Kamus Lokal
    int r, i, rp;

    //Algoritma
    //Set Visibility
    //Browsing
    ui->lineEdit->setVisible(true);
    ui->pushButton->setVisible(true);
    ui->pushButton_2->setVisible(false);
    //Table
    ui->tableWidget->setVisible(true);
    //PushButtons
    ui->pushButton_6->setVisible(true);
    ui->pushButton_3->setVisible(true);
    ui->pushButton_4->setVisible(true);
    ui->pushButton_5->setVisible(false);
    ui->pushButton_7->setVisible(false);
    //Detail Bar
    ui->pushButton_8->setVisible(true);
    ui->Time->setVisible(true);
    ui->label_6->setVisible(true);
    ui->label->setVisible(true);
    ui->entropy->setVisible(true);
    ui->label_2->setVisible(true);
    ui->label_3->setVisible(true);
    ui->ratio->setVisible(true);
    ui->label_4->setVisible(true);
    ui->pushButton_12->setVisible(true);
    ui->pertotal->setVisible(true);
    ui->label_7->setVisible(true);
    //Progress Bar
    ui->progressBar->setVisible(true);
    ui->progressBar->reset();
    //Set Default
    r = ui->tableWidget->rowCount();
    i = 0;
    while(r != 0){
        ui->tableWidget->removeRow(i);
        r = ui->tableWidget->rowCount();
    }
    rp = ui->pathtable->rowCount();
    i = 0;
    while(rp != 0){
        ui->pathtable->removeRow(i);
        rp = ui->pathtable->rowCount();
    }
    ui->pushButton_7->setEnabled(false);
    ui->Time->setText("");
    ui->entropy->setText("");
    ui->pertotal->setText("");
    ui->ratio->setText("");
    prog = 0;
}

//Decode
void RumIt::on_pushButton_11_clicked()
{
    //Kamus Lokal
    int r, i, rp;

    //Algoritma
    //Set Visibility
    //Browsing
    ui->lineEdit->setVisible(true);
    ui->pushButton->setVisible(true);
    ui->pushButton_2->setVisible(false);
    //Table
    ui->tableWidget->setVisible(true);
    ui->pathtable->setVisible(false);
    //PushButtons
    ui->pushButton_6->setVisible(false);
    ui->pushButton_3->setVisible(true);
    ui->pushButton_4->setVisible(false);
    ui->pushButton_5->setVisible(true);
    ui->pushButton_7->setVisible(true);
    //Detail Bar
    ui->pushButton_8->setVisible(true);
    ui->Time->setVisible(true);
    ui->label_6->setVisible(true);
    ui->label->setVisible(true);
    ui->entropy->setVisible(true);
    ui->label_2->setVisible(true);
    ui->label_3->setVisible(true);
    ui->ratio->setVisible(true);
    ui->label_4->setVisible(true);
    ui->pushButton_12->setVisible(true);
    ui->pertotal->setVisible(true);
    ui->label_7->setVisible(true);
    //Progress Bar
    ui->progressBar->setVisible(true);
    ui->progressBar->reset();
    //Mendelete isi tabel
    r = ui->tableWidget->rowCount();
    i = 0;
    while(r != 0){
        ui->tableWidget->removeRow(i);
        r = ui->tableWidget->rowCount();
    }
    rp = ui->pathtable->rowCount();
    i = 0;
    while(rp != 0){
        ui->pathtable->removeRow(i);
        rp = ui->pathtable->rowCount();
    }
    ui->Time->setText("");
    ui->entropy->setText("");
    ui->ratio->setText("");
    ui->pertotal->setText("");
    ui->pushButton_6->setEnabled(false);
    prog = 0;
}

RumIt::~RumIt()
{
    delete ui;
}

//Menghitung Size
QString RumIt::size_read(qint64 Size){
    //Kamus Lokal
    float num = Size;
    QStringList list;
    list << "KB" << "MB" << "GB" << "TB";
    QStringListIterator i(list);
    QString satuan("bytes");

    //Algoritma
    while(num >= 1024.0 && i.hasNext())
     {
        satuan = i.next();
        num /= 1024.0;
    }
    return QString().setNum(num,'f',2)+" "+satuan;
}

QString RumIt::size_table(int Size){
    //Kamus Lokal
    float num = (float) Size;
    QStringList list;
    list << "KB" << "MB" << "GB" << "TB";
    QStringListIterator i(list);
    QString satuan("bytes");

    //Algoritma
    while(num >= 1024.0 && i.hasNext())
     {
        satuan = i.next();
        num /= 1024.0;
    }
    return QString().setNum(num,'f',2)+" "+satuan;
}

//Push Buttons
//Browse
void RumIt::on_pushButton_clicked()
{
    FileName = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "C://",
                "All Files (*.*);;"
     );
    ui->lineEdit->setText(FileName);
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_7->setEnabled(true);
}

//Add File(s) Compress
void RumIt::on_pushButton_6_clicked()
{
    //Kamus Lokal
    int c, s;
    QFileInfo f(FileName);
    QString name = f.fileName();
    qint64 Size = f.size();
    QString num1 = RumIt::size_read(Size);

    //Algoritma
    //Mengecek apakah file sudah dipilih atau belum
    ui->pushButton_7->setEnabled(false);
    if (FileName == ""){
        ui->pushButton_6->setEnabled(false);
    } else {
        //Mengecek keberadaan file
        if (!(f.exists() && f.isFile())) {
            FileName = "";
            QMessageBox::information(this, tr("Error"), "File does not exist!");
            ui->lineEdit->setText("");
        } else {
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            c = ui->tableWidget->rowCount() - 1;
            ui->pathtable->insertRow(ui->pathtable->rowCount());
            s = ui->pathtable->rowCount() - 1;
            //Mengisi Tabel 1
            ui->tableWidget->setItem(c, NAME, new QTableWidgetItem(name));
            ui->tableWidget->setItem(c, SIZE, new QTableWidgetItem(num1));
            ui->tableWidget->setItem(c, PACKED, new QTableWidgetItem("0"));
            ui->tableWidget->setItem(c, PERCENTAGE, new QTableWidgetItem("0"));
            //Mengisi Tabel 2
            ui->pathtable->setItem(s, PATH, new QTableWidgetItem(FileName));
            //Mengisi Ratio, Time, Entropy, Percentage total
            ui->Time->setText("0");
            ui->ratio->setText("0");
            ui->entropy->setText("0");
            ui->pertotal->setText("0");
            //Mengembalikan ke kondisi awal
            ui->lineEdit->setText("");
            FileName = "";
            ui->pushButton_3->setEnabled(true);
            ui->pushButton_4->setEnabled(true);
            ui->pushButton_5->setEnabled(true);
        }
    }
}

//Add File(s) Decompress
void RumIt::on_pushButton_7_clicked()
{
    //Kamus Lokal
    int c, s;
    QFileInfo f(FileName);
    QString name = f.fileName();
    qint64 Size = f.size();
    QString num1 = RumIt::size_read(Size);
    QString ext = f.suffix();

    //Algoritma
    //Mengecek apakah file sudah dipilih atau belum
    ui->pushButton_6->setEnabled(false);
    s = ui->tableWidget->rowCount();
    if (s == 1){ //Mengecek apa memilih lebih dari satu file karena tidak boleh
        QMessageBox::information(this, tr("Error"), "Can't add more than one file");
        ui->pushButton_7->setEnabled(false);
        ui->lineEdit->setText("");
    } else {//Jika direktori belum ada
        if (FileName == ""){
            ui->pushButton_7->setEnabled(false);
        } else {
            //Mengecek keberadaan file
            if (!(f.exists() && f.isFile())) { //File exists
                FileName = "";
                QMessageBox::information(this, tr("Error"), "File does not exist!");
                ui->lineEdit->setText("");
            } else { //File tidak exist
                if (ext != "rum"){ //File bukan .rum
                    FileName = "";
                    QMessageBox::information(this, tr("Error"), "File must be .rum!");
                    ui->lineEdit->setText("");
                } else { //File .rum
                    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                    c = ui->tableWidget->rowCount() - 1;
                    //Mengisi Tabel 1
                    ui->tableWidget->setItem(c, NAME, new QTableWidgetItem(name));
                    ui->tableWidget->setItem(c, SIZE, new QTableWidgetItem(num1));
                    ui->tableWidget->setItem(c, PACKED, new QTableWidgetItem("-"));
                    ui->tableWidget->setItem(c, PERCENTAGE, new QTableWidgetItem("-"));
                    //Mengisi Ratio, Time, Entropy, Percentage Total
                    ui->Time->setText("0");
                    ui->entropy->setText("-");
                    ui->ratio->setText("-");
                    ui->pertotal->setText("-");
                    //Mengembalikan ke kondisi awal
                    FileNameD = FileName;
                    ui->lineEdit->setText("");
                    FileName = "";
                    ui->pushButton_3->setEnabled(true);
                    ui->pushButton_4->setEnabled(true);
                    ui->pushButton_5->setEnabled(true);
                }
            }
        }
    }
}

//Remove Files
void RumIt::on_pushButton_3_clicked()
{
    //Kamus Lokal
    int s, r, rc;
    Dialog d(this);

    //Algoritma
    rc = ui->tableWidget->rowCount();
    if (rc == 0){
        ui->pushButton_3->setEnabled(false);
    } else {
        d.setWindowTitle("Remove File");
        s = d.exec();
        if (s == QDialog::Accepted){
            return;
        } else {
            r = d.rowdel();
            ui->tableWidget->removeRow(r - 1);
            ui->pathtable->removeRow(r - 1);
            //Mengembalikan ke default
            rc = ui->tableWidget->rowCount();
            if (rc == 0){
                ui->pushButton_3->setEnabled(false);
                ui->pushButton_6->setEnabled(false);
                ui->pushButton_4->setEnabled(false);
                ui->pushButton_5->setEnabled(false);
                ui->Time->setText("");
            }
        }
    }
}

//Path directory line edit
void RumIt::on_lineEdit_textEdited(const QString &arg1)
{
    //Kamus Lokal
    FileName = arg1;

    //Algoritma
     ui->pushButton_6->setEnabled(true);
     ui->pushButton_7->setEnabled(true);
}

//Compress
void RumIt::on_pushButton_4_clicked()
{
    //Kamus Lokal
    int s, r, size;
    double percent;
    QTableWidgetItem* itemx;
    compress c(this);
    QString x;
    string w, y;

    //Algoritma
    r = ui->tableWidget->rowCount();
    if (r == 0){
        ui->pushButton_4->setEnabled(false);
    } else {
        //Mengisi array path (Table Item -> string)
        row = ui->tableWidget->rowCount();
        for(int i = 0; i < row; i++){
            itemx = ui->pathtable->item(i, 0);
            w = itemx->text().toStdString();
            path[i] = w;
        }
        //Membuka window Compress
        c.setWindowTitle("Compress File(s)");
        s = c.exec();
        //Jika cancel
        if (s == QDialog::Rejected){
            return;
        } else { //Jika Ok
            //Merubah path QString -> string
            x = c.paths();
            y = x.toStdString();
            //Mengcompress File
            RumIt::compressor(path, row, y, &entropi, &bps, &timer, &sizeout, &rata, &nisbah, &prog);
            //Mengisi detail bar
            ui->Time->setText(QString::number(timer, 'f', 7));
            ui->entropy->setText(QString::number(entropi, 'f', 7));
            ui->ratio->setText(QString::number(bps, 'f', 7));
            ui->pertotal->setText(QString::number(nisbah, 'f', 2));
            for (int i = 0; i < row; i++){
                size = sizeout[i];
                percent = rata[i];
                ui->tableWidget->setItem(i, PACKED, new QTableWidgetItem(size_table(size)));
                ui->tableWidget->setItem(i, PERCENTAGE, new QTableWidgetItem((QString::number(percent, 'f', 2) + "%")));
            }
            //Mengembalikan ke keadaan awal
            ui->pushButton_4->setEnabled(false);
        }
    }
}

//Decompress
void RumIt::on_pushButton_5_clicked()
{
    //Kamus Lokal
    int s, r;
    std::string x, w;
    QString ss;
    decompress dc(this);

    //Algoritma
    //Mengecek isi tabel
    r = ui->tableWidget->rowCount();
    if (r == 0){ //Jika tidak terisi
        ui->pushButton_5->setEnabled(false);
    } else {
        //Membuka window decompress
        dc.setWindowTitle("Decompress File(s)");
        s = dc.exec();
        //Jika Cancel
        if (s == QDialog::Rejected){
            return;
        } else {//Jika Ok
            //Mengubah path QString -> string
            ss = dc.paths();
            x = FileNameD.toStdString();
            w = ss.toStdString();
            //Decompress File
            decompressor(x, w, &timer, &prog);
            //Mengisi Detail bar
            ui->Time->setText(QString::number(timer, 'f', 7));
            //Mengembalikan ke keadaan awal
            ui->pushButton_5->setEnabled(false);
        }
    }
}


//Menu Bar
void RumIt::on_actionAdd_File_s_triggered()
{
    RumIt::on_pushButton_6_clicked();
}

void RumIt::on_actionRemove_triggered()
{
    RumIt::on_pushButton_3_clicked();
}

void RumIt::on_actionExit_triggered()
{
    close();
}

void RumIt::on_actionAbout_triggered()
{
    QMessageBox::information(this, tr("About RumIt!"), "File Compressor Decompressor \n      by Micky, Ukay, Raka");
}

void RumIt::on_actionCompress_triggered()
{
     RumIt::on_pushButton_4_clicked();
}

void RumIt::on_actionDecompress_triggered()
{
     RumIt::on_pushButton_5_clicked();
}

void RumIt::on_actionNew_triggered()
{
    RumIt::KondisiAwal();
}

void RumIt::on_actionOpen_triggered()
{
    RumIt::on_pushButton_clicked();
}

//Compressor Decompressor
void RumIt::compressor (string in[], int count, string out, double *entropi, double *bitPerSimbol, double *timer, int **sizeOut, double **rata, double *nisbah, int *prog) {
    int i, j;
    int startTimer = clock();
    *prog = 1;
    ui->progressBar->setValue(*prog);

    ifstream inFile[count];
    // membuka file input
    for (i=0; i<count; i++) {
        inFile[i].open(in[i].c_str(), ios::binary | ios::in);
    }
    *prog = 2;
    ui->progressBar->setValue(*prog);

    // membuka file output
    ofstream outFile(out.c_str(), ios::binary | ios::out);
    *prog = 3;
    ui->progressBar->setValue(*prog);
    string ins[count];
    size_t found;
    outFile.put(count); // mencetak banyaknya file yang akan dikompresi
    *prog = 4;
    ui->progressBar->setValue(*prog);
    for (i=0; i<count; i++) {
        found = in[i].find_last_of("/\\");
        ins[i] = in[i].substr(found+1);
        outFile.put(ins[i].length()); // mencetak panjang nama file
        for (j=0; j<ins[i].length(); j++) {
            outFile.put((ins[i])[j]); // mencetak nama file
        }
    }
    *prog = 5;
    ui->progressBar->setValue(*prog);

    asciiArr arr;
    for (i=0; i<256; i++) {
        arr.ascii[i] = 0;
        arr.pointing[i] = Nil;
    }
    *prog = 6;
    ui->progressBar->setValue(*prog);

    char c;
    unsigned char ch;
    // menghitung frekuensi setiap karakter dari semua file
    for (i=0; i<count; i++) {
        while (inFile[i].get(c)) {
            ch = (unsigned char) c;
            arr.ascii[ch]++;
        }
    }
    *prog = 7;
    ui->progressBar->setValue(*prog);

    string s;
    // mencetak frekuensi semua karakter ke file output
    for (i=0; i<256; i++) {
        s = IntToString(arr.ascii[i]);
        for (j=0; j<s.length(); j++) {
            outFile.put(s[j]);
        }
        outFile.put(59);
    }
    *prog = 8;
    ui->progressBar->setValue(*prog);
    s.clear();

    unsigned long long asciix[256];
    for (i=0; i<256; i++) {
        asciix[i] = arr.ascii[i];
    }
    *prog = 9;
    ui->progressBar->setValue(*prog);

    BinTree B, BL, BR;
    int min1, min2;
    unsigned int temp;
    // membentuk pohon huffman

    *prog = 10;
    ui->progressBar->setValue(*prog);
    while (!(IsAsciiOneElmt(arr))) {
        while (arr.ascii[i] == 0) {
            i++;
        }
        min1 = i;
        // mencari karakter dengan frekuensi terkecil
        for (i=0; i<256; i++) {
            if ((arr.ascii[i] < arr.ascii[min1]) && (arr.ascii[i] != 0)) {
                min1 = i;
            }
        }

        // jika frekuensi terkecil saat ini merupakan hasil penggabungan dari sebelumnya,
        // pohon BL dideklarasi dengan pohon hasil gabungan
        // jika tidak, pohon BL dibuat sebagai daun
        if (arr.pointing[min1] == Nil) {
            BL = Tree(min1, Nil, Nil);
        }
        else {
            BL = arr.pointing[min1];
        }
        temp = arr.ascii[min1];
        arr.ascii[min1] = 0;
        i = 0;

        while (arr.ascii[i] == 0) {
            i++;
        }
        min2 = i;
        // mencari karakter dengan frekuensi terkecil kedua
        for (i=0; i<256; i++) {
            if ((arr.ascii[i] < arr.ascii[min2]) && (arr.ascii[i] != 0)) {
                min2 = i;
            }
        }
        // jika frekuensi terkecil dua saat ini merupakan hasil penggabungan dari sebelumnya,
        // pohon BR dideklarasi dengan pohon hasil gabungan
        // jika tidak, pohon BR dibuat sebagai daun
        if (arr.pointing[min2] == NULL) {
            BR = Tree(min2, Nil, Nil);
        }
        else {
            BR = arr.pointing[min2];
        }
        B = Tree(256, BL, BR); // membentuk pohon dengan anak BL dan BR
        arr.ascii[min2] = arr.ascii[min2] + temp;
        arr.pointing[min2] = B;
        if (*prog <= 50) {
            *prog = *prog + 1;
            *prog = *prog + 1;
        }
        ui->progressBar->setValue(*prog);
    }

    // memasukkan bit tiap karakter dari pohon huffman yang terbentuk, 2 jika karakter tidak ada di dalam pohon
    string bitCompress[256];
    *prog = *prog + 1;
    for (i=0; i<256; i++) {
        if (!(SearchTree(B,i))) {
            bitCompress[i] = '2';
        }
        else {
            bitCompress[i] = DaunToBits(B,i);
        }
    }
    *prog = *prog + 1;
    ui->progressBar->setValue(*prog);

    *bitPerSimbol = 0.00;
    *entropi = 0.00;
    countEBPS(asciix, bitCompress, entropi, bitPerSimbol); // menghitung entropi dan R
    *prog = *prog + 1;
    ui->progressBar->setValue(*prog);

    int countDummy;
    string outChar, bits;
    unsigned int toFile;
    // menggabungkan bit hasil kompresi dan memasukkan ke dalam file
    *prog = *prog + 1;
    ui->progressBar->setValue(*prog);
    for (i=0; i<count; i++) {
        inFile[i].clear();
        inFile[i].seekg(0, ios::beg);

        countDummy = 0;
        // menghitung banyak nya dummy yang diperlukan
        while (inFile[i].get(c)) {
            ch = (unsigned char) c;
            countDummy = countDummy + bitCompress[ch].length();
        }
        countDummy = countDummy % 8;
        countDummy = 8 - countDummy;
        if (countDummy == 8) {
            countDummy = 0;
        }
        outFile.put(48+countDummy); // memasukkan jumlah dummy yang digunakan

        inFile[i].clear();
        inFile[i].seekg(0, ios::beg);
        for (j=1; j<=countDummy; j++) {
                bits = bits + '0';
        }
        (*sizeOut)[i] = 0;
        while (inFile[i].get(c)) {
            ch = (unsigned char) c;
            bits = bits + bitCompress[ch];
            while (bits.length() >= 8) {
                for (j=0; j<8; j++) {
                    outChar = outChar + bits[j];
                }
                bits.erase(0,8);
                toFile = ByteToDecimal(outChar);
                outChar.erase(0,8);
                outFile.put(toFile);
                (*sizeOut)[i] += 1;
            }
        }
        bits.erase(0,bits.length());
        inFile[i].close();
        if (*prog <= 90) {
            *prog = *prog + 1;
            *prog = *prog + 1;
        }
        ui->progressBar->setValue(*prog);
    }

    // mencetak size setiap file hasil kompresi
    *prog = *prog + 1;
    ui->progressBar->setValue(*prog);
    string s_sizeOut;
    for (i=0; i<count; i++) {
        s_sizeOut = IntToString((*sizeOut)[i]);
        outFile.put(59);
        for (j=0; j<s_sizeOut.length(); j++) {
            outFile.put(s_sizeOut[j]);
        }
    }
    *prog = *prog + 1;
    ui->progressBar->setValue(*prog);
    bits.clear();
    outChar.clear();
    outFile.close();

    int stopTimer = clock();
    int sizeIn[count], t_sizeIn = 0;
    *prog = *prog + 1;
    ui->progressBar->setValue(*prog);
    for (i=0; i<count; i++) {
        sizeIn[i] = GetFileSize(in[i]);
        t_sizeIn = t_sizeIn + sizeIn[i];
        (*rata)[i] = (double) (*sizeOut)[i] / (double) sizeIn[i] * 100;
    }
    *prog = *prog + 1;
    ui->progressBar->setValue(*prog);
    int t_sizeOut = GetFileSize(out);
    *timer = (double) (stopTimer-startTimer)/ 1000;
    *nisbah = (double) t_sizeOut / (double) t_sizeIn * 100;
    *prog = *prog + 1;
    ui->progressBar->setValue(*prog);
    while (*prog < 100) {
        *prog = *prog + 1;
    }
    ui->progressBar->setValue(*prog);
}

void RumIt::decompressor (string in, string pathOut, double *timer, int *prog) {
    int i, j;
    int startTimer = clock();
    *prog = 0;
    // membuka file yang akan dikompresi
    *prog = *prog + 1;
    ui->progressBar->setValue(*prog);
    ifstream inFile(in.c_str(), ios::binary | ios::in);
    char c;
    inFile.get(c); // mengambil banyaknya file hasil dekompresi
    int count, cint;
    count = (int) c;
    inFile.seekg(-1, ios::end);
    long long sizeOut[count];
    *prog = *prog + 1;
    ui->progressBar->setValue(*prog);
    // mengambil size dari tiap file hasil kompresi
    for (i=count-1; i>=0; i--) {
        sizeOut[i] = 0;
        j = 0;
        inFile.get(c);
        inFile.seekg(-2, ios::cur);
        while (c != 59) {
            cint = CharToInt(c);
            sizeOut[i] = sizeOut[i] + (cint * (Pow(10,j)));
            j++;
            inFile.get(c);
            inFile.seekg(-2, ios::cur);
        }
    }
    *prog = *prog + 1;
    ui->progressBar->setValue(*prog);

    inFile.clear();
    inFile.seekg(0, ios::beg);
    inFile.get(c);
    string out[count];
    int headerLength;
    for (i=0; i<count; i++) {
        inFile.get(c); // mengambil panjang nama file
        headerLength = (int) c;
        out[i] = pathOut + '\\';
        for (j=1; j<=headerLength; j++) {
            inFile.get(c); // mengambil nama file
            out[i] = out[i] + c;
        }
    }
    *prog = *prog + 1;
    ui->progressBar->setValue(*prog);

    // membuka file output
    ofstream outFile[count];
    for (i=0; i<count; i++) {
        outFile[i].open(out[i].c_str(), ios::binary | ios::out);
    }
    *prog = *prog + 1;
    ui->progressBar->setValue(*prog);

    asciiArr arr;
    for (i=0; i<256; i++) {
        arr.ascii[i] = 0;
        arr.pointing[i] = Nil;
    }
    *prog = *prog + 1;
    ui->progressBar->setValue(*prog);

    // mengambil frekuensi tiap karakter untuk membentuk pohon
    int a;
    for (i=0; i<256; i++) {
        inFile.get(c);
        if (c != 59) {
            while (c != 59) {
                a = CharToInt(c);
                arr.ascii[i] = (arr.ascii[i] * 10) + a;
                inFile.get(c);
            }
        }
    }
    *prog = *prog + 1;
    ui->progressBar->setValue(*prog);

    // membentuk pohon huffman
    BinTree B, BL, BR;
    int min1, min2;
    unsigned int temp;
    while (!(IsAsciiOneElmt(arr))) {
        i = 0;
        while (arr.ascii[i] == 0) {
            i++;
        }
        min1 = i;
        for (i=0; i<256; i++) {
            if ((arr.ascii[i] < arr.ascii[min1]) && (arr.ascii[i] != 0)) {
                min1 = i;
            }
        }
        if (arr.pointing[min1] == Nil) {
            BL = Tree(min1, Nil, Nil);
        }
        else {
            BL = arr.pointing[min1];
        }
        temp = arr.ascii[min1];
        arr.ascii[min1] = 0;
        i = 0;
        while (arr.ascii[i] == 0) {
            i++;
        }
        min2 = i;
        for (i=0; i<256; i++) {
            if ((arr.ascii[i] < arr.ascii[min2]) && (arr.ascii[i] != 0)) {
                min2 = i;
            }
        }
        if (arr.pointing[min2] == Nil) {
            BR = Tree(min2, Nil, Nil);
        }
        else {
            BR = arr.pointing[min2];
        }
        B = Tree(256, BL, BR);
        arr.ascii[min2] = arr.ascii[min2] + temp;
        arr.pointing[min2] = B;
        if (*prog < 45) {
            *prog = *prog + 1;
            *prog = *prog + 1;
        }
        ui->progressBar->setValue(*prog);
    }

    // memasukkan bit tiap karakter dari pohon huffman yang terbentuk, 2 jika karakter tidak ada di dalam pohon
    string bitCompress[256];
    for (i=0; i<256; i++) {
        if (!(SearchTree(B,i))) {
            bitCompress[i] = '2';
        }
        else {
            bitCompress[i] = DaunToBits(B,i);
        }
    }

    // melakukan dekompresi file
    int countDummy;
    string temps, bits;
    BinTree tempTree;
    int hitung = 0;
    bool selesai;
    bool delDummy;
    for (i=0; i<count; i++) {
        hitung = 0;
        inFile.get(c);
        countDummy = CharToInt (c);

        bits.erase(0, bits.length());
        delDummy = false;
        while (hitung < sizeOut[i]) {
            inFile.get(c);
            hitung = hitung + 1;
            temps = CharToBinary(c);
            bits = bits + temps;
            if (!delDummy) {
                delDummy = true;
                for (j=1; j<=countDummy; j++) {
                    bits.erase(0,1);
                }
            }
            while (bits.length() >= 20) {
                selesai = false;
                tempTree = B;
                while (!selesai) {
                    if (bits[0] == '0') {
                        tempTree = Left(tempTree);
                    }
                    else {
                        tempTree = Right(tempTree);
                    }
                    bits.erase(0,1);
                    if (IsOneElmt(tempTree)) {
                        selesai = true;
                        outFile[i].put(Akar(tempTree));
                    }
                }
            }
        }
        while (bits.length() != 0) {
            selesai = false;
            tempTree = B;
            while (!selesai) {
                if (bits[0] == '0') {
                    tempTree = Left(tempTree);
                }
                else {
                    tempTree = Right(tempTree);
                }
                bits.erase(0,1);
                if (IsOneElmt(tempTree)) {
                    selesai = true;
                    outFile[i].put(Akar(tempTree));
                }
            }
        }
        if (*prog < 99) {
            *prog = *prog + 1;
            *prog = *prog + 1;
        }
        ui->progressBar->setValue(*prog);
    }

    int stopTimer = clock();
    *timer = (double) (stopTimer-startTimer) / 1000;
    *prog = 100;
    ui->progressBar->setValue(*prog);
}
