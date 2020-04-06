#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <string>
#include <sstream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    wskMoj = NULL;
    wskPrzeciwnik = NULL;

    ui->label->setText("<font color='black'>Witaj w grze Heroes of Magic</font>"); //powitanie graczy

//wczytanie obrazka krzyzyka do etykiety ktory pojawia sie po porazce lewego gracza
    QPixmap postac1("://obrazy/krzyz.png");
    ui->gracz1koniec->setPixmap(postac1.scaled(300,300,Qt::KeepAspectRatio));

//wczytanie obrazka krzyzyka do etykiety ktory pojawia sie po porazce prawego gracza
    QPixmap postac2("://obrazy/krzyz.png");
    ui->gracz2koniec->setPixmap(postac2.scaled(300,300,Qt::KeepAspectRatio));

//schowanie wszystkich etykiet niepotrzebnych na ekranie startowym
    ui->label_gracz1->hide();
    ui->label_gracz2->hide();
    ui->Gracz1_stat->hide();
    ui->gracz2_stst->hide();
    ui->gracz_ataki->hide();
    ui->gracz_ataki2->hide();
    ui->koniec->hide();
    ui->gracz1koniec->hide();
    ui->gracz2koniec->hide();
    ui->podstawowe_ataki->hide();

//wczytanie tla
    QPixmap bkgnd("://obrazy/chmura.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

//funkcja ktora aktualizuje statystyki graczy
void MainWindow::wypisanieMoje(Magik *wsk, QLabel *pierwszy, QLabel *drugi, QLabel *trzeci, QLabel *czwarty)
{
    std::ostringstream strs1;
    strs1 << wsk->hp;
    std::string str = strs1.str();
    pierwszy->setText(QString::fromStdString(str));

    std::ostringstream strs2;
    strs2 << wsk->damage;
    std::string stre = strs2.str();
    drugi->setText(QString::fromStdString(stre));

    std::ostringstream strs3;
    strs3 << wsk->skillPoints;
    std::string stres = strs3.str();
    trzeci->setText(QString::fromStdString(stres));

    std::ostringstream strs4;
    strs4 << wsk->prawdopodobienstwoSkutecznejObrony;
    std::string stred = strs4.str();
    czwarty->setText(QString::fromStdString(stred));

}

//funkcja sprawdzajaca czy to koniec rozgrywki
void MainWindow::czy_koniec(Magik *wsk, Magik *wsk2, QLabel *krzyz1, QLabel *krzyz2, QLabel *kto, QWidget *pierwszy, QWidget *drugi)
{
    if(wsk->hp <= 0 && wsk2->hp <= 0)
    {
        krzyz1->show();
        krzyz2->show();
        kto->show();
        kto->setText("REMIS");
        ui->pushButton_2->show();
    }
    else if(wsk->hp <= 0)
    {
        krzyz1->show();
        kto->show();
        kto->setText("VICTORY");
        ui->pushButton_2->show();
    }
    else if(wsk2->hp <= 0)
    {
        krzyz2->show();
        kto->show();
        kto->setText("VICTORY");
        ui->pushButton_2->show();
    }
    else
    {
        pierwszy->hide();
        drugi->show();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete wskMoj;
    delete wskPrzeciwnik;
}


void MainWindow::on_pushButton_2_clicked()
{
    exit(0);
    delete wskMoj;
    delete wskPrzeciwnik;
}


void MainWindow::on_pushButton_clicked()
{
    if((ui->radioButton_2->isChecked()||ui->radioButton_3->isChecked()||ui->radioButton_4->isChecked()||ui->radioButton_5->isChecked())&&(ui->radioButton_6->isChecked()||ui->radioButton_7->isChecked()||ui->radioButton_8->isChecked()||ui->radioButton_9->isChecked()))
    {
        ui->label_gracz1->show();
        ui->label_gracz2->show();

        if(ui->radioButton_2->isChecked())
        {
            wskMoj = new Agresor();
            QPixmap postac_moja("://obrazy/ag.png");
            ui->label_gracz1->setPixmap(postac_moja.scaled(300,300,Qt::KeepAspectRatio));

            ui->gracz_naprzeciwnika->setText("Ukłucie. (min 10 many");
            ui->gracz_naprzeciwnika->setToolTip("Zmniejsza poziom hp przeciwnika o 25%");
            ui->gracz_nasiebie->setText("Szkolenie. (min 10 many)");
            ui->gracz_nasiebie->setToolTip("Powoduje zwiekszenie ilosci many o 50%.");
            ui->gracz_specjalny->setText("Ogniste uderzenie. (min 30 many)");
            ui->gracz_specjalny->setToolTip("Powododuje zwiekszenie damage o 30, zaatakowanie przeciwnika i powrot do dawnego poziomu damage.");
        }
        if(ui->radioButton_3->isChecked())
        {
            wskMoj = new Pacyfista();
            QPixmap postac_moja("://obrazy/pa.png");
            ui->label_gracz1->setPixmap(postac_moja.scaled(300,300,Qt::KeepAspectRatio));

            ui->gracz_naprzeciwnika->setText("Pstryczek. (min 10 many");
            ui->gracz_naprzeciwnika->setToolTip("Dodanie przeciwnikowi 2pkt damage i zabranie 25pkt hp");
            ui->gracz_nasiebie->setText("Cierpliwości. (min 10 many)");
            ui->gracz_nasiebie->setToolTip("zbiera punkty do ataku ostatecznego, ktory powoduje smierc przeciwnika + zwieksza prawdopodobienstwo obrony o 20%.");
            ui->gracz_specjalny->setText("Łyk mleka. (min 30 many)");
            ui->gracz_specjalny->setToolTip("Zwieksz ilosc pkt hp o 100.");
        }
        if(ui->radioButton_4->isChecked())
        {
            wskMoj = new Hazardzista();
            QPixmap postac_moja("://obrazy/ha.png");
            ui->label_gracz1->setPixmap(postac_moja.scaled(300,300,Qt::KeepAspectRatio));

            ui->gracz_naprzeciwnika->setText("Bum. (min 10 many");
            ui->gracz_naprzeciwnika->setToolTip("zabiera przeciwnikowi zycie w zakresie 10-40%.");
            ui->gracz_nasiebie->setText("Wzmocnienie. (min 10 many)");
            ui->gracz_nasiebie->setToolTip("Dodaje zycie w zakresie 10-40%.");
            ui->gracz_specjalny->setText("Raz się żyje. (min 30 many)");
            ui->gracz_specjalny->setToolTip("50% szans na zabicie przeciwnika, jeśli nie to nic się nie dzieje.");
        }
        if(ui->radioButton_5->isChecked())
        {
            wskMoj = new Skiller();
            QPixmap postac_moja("://obrazy/sk.png");
            ui->label_gracz1->setPixmap(postac_moja.scaled(300,300,Qt::KeepAspectRatio));

            ui->gracz_naprzeciwnika->setText("Co dwa to nie jeden. (min 10 many");
            ui->gracz_naprzeciwnika->setToolTip("Pozwala wykonac 2 zwykle ataki.");
            ui->gracz_nasiebie->setText("Monce kości. (min 10 many)");
            ui->gracz_nasiebie->setToolTip("Zwieksza swoj poziom zycia o 50%.");
            ui->gracz_specjalny->setText("Przykro mi. (min 30 many)");
            ui->gracz_specjalny->setToolTip("Zabiera przeciwnikowi hp z przedzialu <20,100>.");
        }

        if(ui->radioButton_6->isChecked())
        {
            wskPrzeciwnik = new Agresor();
            QPixmap postac_przeciwnika("://obrazy/ag.png");
            ui->label_gracz2->setPixmap(postac_przeciwnika.scaled(300,300,Qt::KeepAspectRatio));

            ui->gracz_naprzeciwnika_2->setText("Ukłucie. (min 10 many");
            ui->gracz_naprzeciwnika_2->setToolTip("Zmniejsza poziom hp przeciwnika o 25%");
            ui->gracz_nasiebie_2->setText("Szkolenie. (min 10 many)");
            ui->gracz_nasiebie_2->setToolTip("Powoduje zwiekszenie ilosci many o 50%.");
            ui->gracz_specjalny_2->setText("Ogniste uderzenie. (min 30 many)");
            ui->gracz_specjalny_2->setToolTip("Powododuje zwiekszenie damage o 30, zaatakowanie przeciwnika i powrot do dawnego poziomu damage.");
        }
        if(ui->radioButton_7->isChecked())
        {
            wskPrzeciwnik = new Pacyfista();
            QPixmap postac_przeciwnika("://obrazy/pa.png");
            ui->label_gracz2->setPixmap(postac_przeciwnika.scaled(300,300,Qt::KeepAspectRatio));

            ui->gracz_naprzeciwnika_2->setText("Pstryczek. (min 10 many");
            ui->gracz_naprzeciwnika_2->setToolTip("Dodanie przeciwnikowi 2pkt damage i zabranie 25pkt hp");
            ui->gracz_nasiebie_2->setText("Cierpliwości. (min 10 many)");
            ui->gracz_nasiebie_2->setToolTip("zbiera punkty do ataku ostatecznego, ktory powoduje smierc przeciwnika + zwieksza prawdopodobienstwo obrony o 20%.");
            ui->gracz_specjalny_2->setText("Łyk mleka. (min 30 many)");
            ui->gracz_specjalny_2->setToolTip("Zwieksz ilosc pkt hp o 100.");
        }
        if(ui->radioButton_8->isChecked())
        {
            wskPrzeciwnik = new Hazardzista();
            QPixmap postac_przeciwnika("://obrazy/ha.png");
            ui->label_gracz2->setPixmap(postac_przeciwnika.scaled(300,300,Qt::KeepAspectRatio));

            ui->gracz_naprzeciwnika_2->setText("Bum. (min 10 many");
            ui->gracz_naprzeciwnika_2->setToolTip("zabiera przeciwnikowi zycie w zakresie 10-40%.");
            ui->gracz_nasiebie_2->setText("Wzmocnienie. (min 10 many)");
            ui->gracz_nasiebie_2->setToolTip("Dodaje zycie w zakresie 10-40%.");
            ui->gracz_specjalny_2->setText("Raz się żyje. (min 30 many)");
            ui->gracz_specjalny_2->setToolTip("50% szans na zabicie przeciwnika, jeśli nie to nic się nie dzieje.");
        }
        if(ui->radioButton_9->isChecked())
        {
            wskPrzeciwnik = new Skiller();
            QPixmap postac_przeciwnika("://obrazy/sk.png");
            ui->label_gracz2->setPixmap(postac_przeciwnika.scaled(300,300,Qt::KeepAspectRatio));

            ui->gracz_naprzeciwnika_2->setText("Co dwa to nie jeden. (min 10 many");
            ui->gracz_naprzeciwnika_2->setToolTip("Pozwala wykonac 2 zwykle ataki.");
            ui->gracz_nasiebie_2->setText("Monce kości. (min 10 many)");
            ui->gracz_nasiebie_2->setToolTip("Zwieksza swoj poziom zycia o 50%.");
            ui->gracz_specjalny_2->setText("Przykro mi. (min 30 many)");
            ui->gracz_specjalny_2->setToolTip("Zabiera przeciwnikowi hp z przedzialu <20,100>.");
        }

        ui->pierwszyWidget->hide();
        ui->drugiWidget->hide();
        ui->pushButton->hide();
        ui->pushButton_2->hide();


        ui->label->hide();


        wskMoj->name = nazwaGracza1;
        wskPrzeciwnik->name = nazwaGracza2;

        ui->label_4->setText(QString::fromStdString(nazwaGracza1));
        ui->label_5->setText(QString::fromStdString(nazwaGracza2));

        QPixmap bkgnd("://obrazy/dymy.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);

        MainWindow::wypisanieMoje(wskMoj,ui->label_gracz1_hp,ui->label_gracz1_damage,ui->label_gracz1_mana,ui->label_gracz1_prawdo_obrony);
        MainWindow::wypisanieMoje(wskPrzeciwnik,ui->label_gracz1_hp_2,ui->label_gracz1_damage_2,ui->label_gracz1_mana_2,ui->label_gracz1_prawdo_obrony_2);

        ui->Gracz1_stat->show();
        ui->gracz2_stst->show();
        ui->gracz_ataki->show();

        licznik = 0;

    }
}


void MainWindow::on_lineEdit_returnPressed()
{
    QString napis = ui->lineEdit->text();
    nazwaGracza1 = napis.toLocal8Bit().constData();
    ui->label_4->setText(QString::fromStdString(nazwaGracza1));
}

void MainWindow::on_lineEdit_2_returnPressed()
{
    QString napis = ui->lineEdit_2->text();
    nazwaGracza2 = napis.toLocal8Bit().constData();
    ui->label_5->setText(QString::fromStdString(nazwaGracza2));
}

void MainWindow::on_gracz_specjalny_clicked()
{
    if(wskMoj->skillPoints>=30)
    {
        wskMoj->atakSpecjalny(wskPrzeciwnik);
        wskMoj->skillPoints-=30;
        wskMoj->sprawdzenie();
        wskPrzeciwnik->sprawdzenie();
        wskMoj->skillPoints+=1;

        licznik = 1;

        ui->podstawowe_ataki->hide();

        MainWindow::czy_koniec(wskMoj,wskPrzeciwnik,ui->gracz1koniec,ui->gracz2koniec,ui->koniec,ui->gracz_ataki,ui->gracz_ataki2);

        MainWindow::wypisanieMoje(wskMoj,ui->label_gracz1_hp,ui->label_gracz1_damage,ui->label_gracz1_mana,ui->label_gracz1_prawdo_obrony);
        MainWindow::wypisanieMoje(wskPrzeciwnik,ui->label_gracz1_hp_2,ui->label_gracz1_damage_2,ui->label_gracz1_mana_2,ui->label_gracz1_prawdo_obrony_2);
    }

}


void MainWindow::on_gracz_nasiebie_clicked()
{
    if(wskMoj->skillPoints>=10)
    {
        wskMoj->zaklecieNaSiebie(wskPrzeciwnik);
        wskMoj->skillPoints-=10;
        wskMoj->sprawdzenie();
        wskPrzeciwnik->sprawdzenie();
        wskMoj->skillPoints+=1;

        licznik = 1;

        ui->podstawowe_ataki->hide();


        MainWindow::czy_koniec(wskMoj,wskPrzeciwnik,ui->gracz1koniec,ui->gracz2koniec,ui->koniec,ui->gracz_ataki,ui->gracz_ataki2);

        MainWindow::wypisanieMoje(wskMoj,ui->label_gracz1_hp,ui->label_gracz1_damage,ui->label_gracz1_mana,ui->label_gracz1_prawdo_obrony);
        MainWindow::wypisanieMoje(wskPrzeciwnik,ui->label_gracz1_hp_2,ui->label_gracz1_damage_2,ui->label_gracz1_mana_2,ui->label_gracz1_prawdo_obrony_2);
    }
}



void MainWindow::on_gracz_naprzeciwnika_clicked()
{
    if(wskMoj->skillPoints>=10)
    {
        wskMoj->zaklecieNaPrzeciwnika(wskPrzeciwnik);
        wskMoj->skillPoints-=10;
        wskMoj->sprawdzenie();
        wskPrzeciwnik->sprawdzenie();
        wskMoj->skillPoints+=1;

        licznik = 1;

        ui->podstawowe_ataki->hide();

        MainWindow::czy_koniec(wskMoj,wskPrzeciwnik,ui->gracz1koniec,ui->gracz2koniec,ui->koniec,ui->gracz_ataki,ui->gracz_ataki2);

        MainWindow::wypisanieMoje(wskMoj,ui->label_gracz1_hp,ui->label_gracz1_damage,ui->label_gracz1_mana,ui->label_gracz1_prawdo_obrony);
        MainWindow::wypisanieMoje(wskPrzeciwnik,ui->label_gracz1_hp_2,ui->label_gracz1_damage_2,ui->label_gracz1_mana_2,ui->label_gracz1_prawdo_obrony_2);
    }
}

void MainWindow::on_gracz_nasiebie_2_clicked()
{
    if(wskPrzeciwnik->skillPoints>=10)
    {
        wskPrzeciwnik->zaklecieNaSiebie(wskMoj);
        wskPrzeciwnik->skillPoints-=10;
        wskMoj->sprawdzenie();
        wskPrzeciwnik->sprawdzenie();
        wskPrzeciwnik->skillPoints+=1;

        licznik = 0;

        ui->podstawowe_ataki->hide();

        MainWindow::czy_koniec(wskPrzeciwnik,wskMoj,ui->gracz2koniec,ui->gracz1koniec,ui->koniec,ui->gracz_ataki2,ui->gracz_ataki);

        MainWindow::wypisanieMoje(wskMoj,ui->label_gracz1_hp,ui->label_gracz1_damage,ui->label_gracz1_mana,ui->label_gracz1_prawdo_obrony);
        MainWindow::wypisanieMoje(wskPrzeciwnik,ui->label_gracz1_hp_2,ui->label_gracz1_damage_2,ui->label_gracz1_mana_2,ui->label_gracz1_prawdo_obrony_2);
    }
}

void MainWindow::on_gracz_naprzeciwnika_2_clicked()
{
    if(wskPrzeciwnik->skillPoints>=10)
    {
        wskPrzeciwnik->zaklecieNaPrzeciwnika(wskMoj);
        wskPrzeciwnik->skillPoints-=10;
        wskMoj->sprawdzenie();
        wskPrzeciwnik->sprawdzenie();
        wskPrzeciwnik->skillPoints+=1;

        licznik = 0;

        ui->podstawowe_ataki->hide();

        MainWindow::czy_koniec(wskPrzeciwnik,wskMoj,ui->gracz2koniec,ui->gracz1koniec,ui->koniec,ui->gracz_ataki2,ui->gracz_ataki);

        MainWindow::wypisanieMoje(wskMoj,ui->label_gracz1_hp,ui->label_gracz1_damage,ui->label_gracz1_mana,ui->label_gracz1_prawdo_obrony);
        MainWindow::wypisanieMoje(wskPrzeciwnik,ui->label_gracz1_hp_2,ui->label_gracz1_damage_2,ui->label_gracz1_mana_2,ui->label_gracz1_prawdo_obrony_2);
    }
}

void MainWindow::on_gracz_specjalny_2_clicked()
{
    if(wskPrzeciwnik->skillPoints>=30)
    {
        wskPrzeciwnik->atakSpecjalny(wskMoj);
        wskPrzeciwnik->skillPoints-=30;
        wskMoj->sprawdzenie();
        wskPrzeciwnik->sprawdzenie();
        wskPrzeciwnik->skillPoints+=1;

        licznik = 0;

        ui->podstawowe_ataki->hide();

        MainWindow::czy_koniec(wskPrzeciwnik,wskMoj,ui->gracz2koniec,ui->gracz1koniec,ui->koniec,ui->gracz_ataki2,ui->gracz_ataki);

        MainWindow::wypisanieMoje(wskMoj,ui->label_gracz1_hp,ui->label_gracz1_damage,ui->label_gracz1_mana,ui->label_gracz1_prawdo_obrony);
        MainWindow::wypisanieMoje(wskPrzeciwnik,ui->label_gracz1_hp_2,ui->label_gracz1_damage_2,ui->label_gracz1_mana_2,ui->label_gracz1_prawdo_obrony_2);
    }
}

void MainWindow::on_gracz_atak_clicked()
{
    ui->podstawowe_ataki->show();
    ui->gracz_ataki->hide();
}



void MainWindow::on_gracz_atak_2_clicked()
{
    ui->podstawowe_ataki->show();
    ui->gracz_ataki2->hide();
}

void MainWindow::on_pb_wstecz_clicked()
{
    if(licznik == 0)
    {
        ui->gracz_ataki->show();
    }
    if(licznik == 1)
    {
        ui->gracz_ataki2->show();
    }
    ui->podstawowe_ataki->hide();
}

void MainWindow::on_pb_zw_hp_clicked()
{
    if(licznik == 0)
    {
        wskMoj->zwiekszenieHP();
        wskMoj->skillPoints+=1;
        licznik = 1;
        MainWindow::czy_koniec(wskMoj,wskPrzeciwnik,ui->gracz1koniec,ui->gracz2koniec,ui->koniec,ui->gracz_ataki,ui->gracz_ataki2);

    }
    else if(licznik == 1)
    {
        wskPrzeciwnik->zwiekszenieHP();
        wskPrzeciwnik->skillPoints+=1;
        licznik = 0;
        MainWindow::czy_koniec(wskPrzeciwnik,wskMoj,ui->gracz2koniec,ui->gracz1koniec,ui->koniec,ui->gracz_ataki2,ui->gracz_ataki);
    }

    ui->podstawowe_ataki->hide();
    wskMoj->sprawdzenie();
    wskPrzeciwnik->sprawdzenie();
    MainWindow::wypisanieMoje(wskMoj,ui->label_gracz1_hp,ui->label_gracz1_damage,ui->label_gracz1_mana,ui->label_gracz1_prawdo_obrony);
    MainWindow::wypisanieMoje(wskPrzeciwnik,ui->label_gracz1_hp_2,ui->label_gracz1_damage_2,ui->label_gracz1_mana_2,ui->label_gracz1_prawdo_obrony_2);
}

void MainWindow::on_pb_zm_hp_clicked()
{
    if(licznik == 0)
    {
        wskMoj->atak(wskPrzeciwnik);
        wskMoj->skillPoints+=1;
        licznik = 1;
        MainWindow::czy_koniec(wskMoj,wskPrzeciwnik,ui->gracz1koniec,ui->gracz2koniec,ui->koniec,ui->gracz_ataki,ui->gracz_ataki2);

    }
    else if(licznik == 1)
    {
        wskPrzeciwnik->atak(wskMoj);
        wskPrzeciwnik->skillPoints+=1;
        licznik = 0;
        MainWindow::czy_koniec(wskPrzeciwnik,wskMoj,ui->gracz2koniec,ui->gracz1koniec,ui->koniec,ui->gracz_ataki2,ui->gracz_ataki);
    }

    ui->podstawowe_ataki->hide();
    wskMoj->sprawdzenie();
    wskPrzeciwnik->sprawdzenie();
    MainWindow::wypisanieMoje(wskMoj,ui->label_gracz1_hp,ui->label_gracz1_damage,ui->label_gracz1_mana,ui->label_gracz1_prawdo_obrony);
    MainWindow::wypisanieMoje(wskPrzeciwnik,ui->label_gracz1_hp_2,ui->label_gracz1_damage_2,ui->label_gracz1_mana_2,ui->label_gracz1_prawdo_obrony_2);
}

void MainWindow::on_pb_zw_damage_clicked()
{
    if(licznik == 0)
    {
        wskMoj->zwiekszenieDamage();
        wskMoj->skillPoints+=1;
        licznik = 1;
        MainWindow::czy_koniec(wskMoj,wskPrzeciwnik,ui->gracz1koniec,ui->gracz2koniec,ui->koniec,ui->gracz_ataki,ui->gracz_ataki2);

    }
    else if(licznik == 1)
    {
        wskPrzeciwnik->zwiekszenieDamage();
        wskPrzeciwnik->skillPoints+=1;
        licznik = 0;
        MainWindow::czy_koniec(wskPrzeciwnik,wskMoj,ui->gracz2koniec,ui->gracz1koniec,ui->koniec,ui->gracz_ataki2,ui->gracz_ataki);
    }

    ui->podstawowe_ataki->hide();
    wskMoj->sprawdzenie();
    wskPrzeciwnik->sprawdzenie();
    MainWindow::wypisanieMoje(wskMoj,ui->label_gracz1_hp,ui->label_gracz1_damage,ui->label_gracz1_mana,ui->label_gracz1_prawdo_obrony);
    MainWindow::wypisanieMoje(wskPrzeciwnik,ui->label_gracz1_hp_2,ui->label_gracz1_damage_2,ui->label_gracz1_mana_2,ui->label_gracz1_prawdo_obrony_2);
}

void MainWindow::on_pb_zm_damage_clicked()
{
    if(licznik == 0)
    {
        wskMoj->zmniejszenieDamage(wskPrzeciwnik);
        wskMoj->skillPoints+=1;
        licznik = 1;
        MainWindow::czy_koniec(wskMoj,wskPrzeciwnik,ui->gracz1koniec,ui->gracz2koniec,ui->koniec,ui->gracz_ataki,ui->gracz_ataki2);

    }
    else if(licznik == 1)
    {
        wskPrzeciwnik->zmniejszenieDamage(wskMoj);
        wskPrzeciwnik->skillPoints+=1;
        licznik = 0;
        MainWindow::czy_koniec(wskPrzeciwnik,wskMoj,ui->gracz2koniec,ui->gracz1koniec,ui->koniec,ui->gracz_ataki2,ui->gracz_ataki);
    }

    ui->podstawowe_ataki->hide();
    wskMoj->sprawdzenie();
    wskPrzeciwnik->sprawdzenie();
    MainWindow::wypisanieMoje(wskMoj,ui->label_gracz1_hp,ui->label_gracz1_damage,ui->label_gracz1_mana,ui->label_gracz1_prawdo_obrony);
    MainWindow::wypisanieMoje(wskPrzeciwnik,ui->label_gracz1_hp_2,ui->label_gracz1_damage_2,ui->label_gracz1_mana_2,ui->label_gracz1_prawdo_obrony_2);
}



void MainWindow::on_pb_zw_mana_clicked()
{
    if(licznik == 0)
    {
        wskMoj->zwiekszenieMany();
        wskMoj->skillPoints+=1;
        licznik = 1;
        MainWindow::czy_koniec(wskMoj,wskPrzeciwnik,ui->gracz1koniec,ui->gracz2koniec,ui->koniec,ui->gracz_ataki,ui->gracz_ataki2);

    }
    else if(licznik == 1)
    {
        wskPrzeciwnik->zwiekszenieMany();
        wskPrzeciwnik->skillPoints+=1;
        licznik = 0;
        MainWindow::czy_koniec(wskPrzeciwnik,wskMoj,ui->gracz2koniec,ui->gracz1koniec,ui->koniec,ui->gracz_ataki2,ui->gracz_ataki);
    }

    ui->podstawowe_ataki->hide();
    wskMoj->sprawdzenie();
    wskPrzeciwnik->sprawdzenie();
    MainWindow::wypisanieMoje(wskMoj,ui->label_gracz1_hp,ui->label_gracz1_damage,ui->label_gracz1_mana,ui->label_gracz1_prawdo_obrony);
    MainWindow::wypisanieMoje(wskPrzeciwnik,ui->label_gracz1_hp_2,ui->label_gracz1_damage_2,ui->label_gracz1_mana_2,ui->label_gracz1_prawdo_obrony_2);
}



void MainWindow::on_pb_zm_mana_clicked()
{
    if(licznik == 0)
    {
        wskMoj->zmniejszenieMany(wskPrzeciwnik);
        wskMoj->skillPoints+=1;
        licznik = 1;
        MainWindow::czy_koniec(wskMoj,wskPrzeciwnik,ui->gracz1koniec,ui->gracz2koniec,ui->koniec,ui->gracz_ataki,ui->gracz_ataki2);

    }
    else if(licznik == 1)
    {
        wskPrzeciwnik->zmniejszenieMany(wskMoj);
        wskPrzeciwnik->skillPoints+=1;
        licznik = 0;
        MainWindow::czy_koniec(wskPrzeciwnik,wskMoj,ui->gracz2koniec,ui->gracz1koniec,ui->koniec,ui->gracz_ataki2,ui->gracz_ataki);
    }

    ui->podstawowe_ataki->hide();
    wskMoj->sprawdzenie();
    wskPrzeciwnik->sprawdzenie();
    MainWindow::wypisanieMoje(wskMoj,ui->label_gracz1_hp,ui->label_gracz1_damage,ui->label_gracz1_mana,ui->label_gracz1_prawdo_obrony);
    MainWindow::wypisanieMoje(wskPrzeciwnik,ui->label_gracz1_hp_2,ui->label_gracz1_damage_2,ui->label_gracz1_mana_2,ui->label_gracz1_prawdo_obrony_2);
}



void MainWindow::on_pb_zw_obr_clicked()
{
    if(licznik == 0)
    {
        wskMoj->zwiekszeniePrawdopodobienstwaSkutecznejObrony();
        wskMoj->skillPoints+=1;
        licznik = 1;
        MainWindow::czy_koniec(wskMoj,wskPrzeciwnik,ui->gracz1koniec,ui->gracz2koniec,ui->koniec,ui->gracz_ataki,ui->gracz_ataki2);

    }
    else if(licznik == 1)
    {
        wskPrzeciwnik->zwiekszeniePrawdopodobienstwaSkutecznejObrony();
        wskPrzeciwnik->skillPoints+=1;
        licznik = 0;
        MainWindow::czy_koniec(wskPrzeciwnik,wskMoj,ui->gracz2koniec,ui->gracz1koniec,ui->koniec,ui->gracz_ataki2,ui->gracz_ataki);
    }

    ui->podstawowe_ataki->hide();
    wskMoj->sprawdzenie();
    wskPrzeciwnik->sprawdzenie();
    MainWindow::wypisanieMoje(wskMoj,ui->label_gracz1_hp,ui->label_gracz1_damage,ui->label_gracz1_mana,ui->label_gracz1_prawdo_obrony);
    MainWindow::wypisanieMoje(wskPrzeciwnik,ui->label_gracz1_hp_2,ui->label_gracz1_damage_2,ui->label_gracz1_mana_2,ui->label_gracz1_prawdo_obrony_2);
}

void MainWindow::on_pb_zmni_ob_clicked()
{
    if(licznik == 0)
    {
        wskMoj->zmniejszenieprawdopodobienstwaSkutecznejObrony(wskPrzeciwnik);
        wskMoj->skillPoints+=1;
        licznik = 1;
        MainWindow::czy_koniec(wskMoj,wskPrzeciwnik,ui->gracz1koniec,ui->gracz2koniec,ui->koniec,ui->gracz_ataki,ui->gracz_ataki2);

    }
    else if(licznik == 1)
    {
        wskPrzeciwnik->zmniejszenieprawdopodobienstwaSkutecznejObrony(wskMoj);
        wskPrzeciwnik->skillPoints+=1;
        licznik = 0;
        MainWindow::czy_koniec(wskPrzeciwnik,wskMoj,ui->gracz2koniec,ui->gracz1koniec,ui->koniec,ui->gracz_ataki2,ui->gracz_ataki);
    }

    ui->podstawowe_ataki->hide();
    wskMoj->sprawdzenie();
    wskPrzeciwnik->sprawdzenie();
    MainWindow::wypisanieMoje(wskMoj,ui->label_gracz1_hp,ui->label_gracz1_damage,ui->label_gracz1_mana,ui->label_gracz1_prawdo_obrony);
    MainWindow::wypisanieMoje(wskPrzeciwnik,ui->label_gracz1_hp_2,ui->label_gracz1_damage_2,ui->label_gracz1_mana_2,ui->label_gracz1_prawdo_obrony_2);
}
