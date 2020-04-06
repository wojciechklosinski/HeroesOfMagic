#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include "pacyfista.h"
#include "agresor.h"
#include "skiller.h"
#include "hazardzista.h"
#include <QLabel>
#include <sstream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public: Magik *wskMoj;
        Magik *wskPrzeciwnik;
        string nazwaGracza1 = "Gracz 1";
        string nazwaGracza2 = "Gracz 2";

    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    

private slots:
    void wypisanieMoje(Magik *wsk, QLabel *pierwszy, QLabel *drugi, QLabel *trzeci, QLabel *czwarty);

    void czy_koniec(Magik *wsk, Magik *wsk2,QLabel *krzyz1, QLabel *krzyz2, QLabel *kto, QWidget *pierwszy, QWidget *drugi);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

    void on_lineEdit_2_returnPressed();

    void on_gracz_specjalny_clicked();

    void on_gracz_nasiebie_clicked();

    void on_gracz_naprzeciwnika_clicked();

    void on_gracz_nasiebie_2_clicked();

    void on_gracz_naprzeciwnika_2_clicked();

    void on_gracz_specjalny_2_clicked();

    void on_gracz_atak_clicked();

    void on_gracz_atak_2_clicked();

    void on_pb_wstecz_clicked();

    void on_pb_zw_hp_clicked();

    void on_pb_zm_hp_clicked();

    void on_pb_zw_damage_clicked();

    void on_pb_zm_damage_clicked();

    void on_pb_zw_mana_clicked();

    void on_pb_zm_mana_clicked();

    void on_pb_zw_obr_clicked();

    void on_pb_zmni_ob_clicked();

private:
    Ui::MainWindow *ui;

    int licznik;
};

#endif // MAINWINDOW_H
