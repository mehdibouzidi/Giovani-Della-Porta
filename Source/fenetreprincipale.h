#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QMainWindow>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QtGui>
#include <QGridLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QTableView>
#include <QSpinBox>

#include <vector>
#include <iostream>


namespace Ui {
class FenetrePrincipale;
}

class FenetrePrincipale : public QMainWindow
{
    Q_OBJECT

public:
    explicit FenetrePrincipale(QWidget *parent = 0);
    ~FenetrePrincipale();

    /*************** Méthodes ****************/
    int indChar(QChar const& c);//ok
    void constructionTable();//ok
    void constructionMotCle2();//ok
    void constructionMotCle2Decrypter();


    bool isPremier(int const& a);
    int prochainPremier(int const& a);
private slots:
    void crypter();
    void decrypter();
    void parametrageTable();
    void augmenterLignes(int i);
    void okParam();
    void nouvauCrypto();
    void afficherClair();
    void afficherChiffre();
    void afficherParametrage();
    void aPropos();
    void afficheTable();
    /*void destructionClair();
    void destructionChiffre();
    void destructionParam();*/
private:
    Ui::FenetrePrincipale *ui;
    QMdiArea *zoneCentrale;
    QWidget *clairWidg,*cipherWidg,*paramWidg,*paramWidget,*tabWidg;
    QMdiSubWindow *clairFen,*cipherFen,*paramFen;
    QTextEdit   *texteClair,*texteCipher;
    QLabel  *motCle1Lbl,*motCle2Lbl,*paramLbl;
    QLineEdit  *motCle1Edit,*motCle2Edit;
    QPushButton *crypterBtn,*decrypterBtn,*okParamBtn;
    QSpinBox    *nbDiv;
    QTableView *tableau,*tableCryDecry;
    QStandardItemModel *tab,*tableCryDecryModel;
    std::vector<QString>    reference;
    std::vector<std::vector<QString> >    table;
    QString utilMotCle2,utilMessageClair,utilCipher;


};

#endif // FENETREPRINCIPALE_H
