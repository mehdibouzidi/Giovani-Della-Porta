#include "fenetreprincipale.h"
#include "ui_fenetreprincipale.h"

using namespace std;

FenetrePrincipale::FenetrePrincipale(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FenetrePrincipale)
{
    ui->setupUi(this);
    setWindowTitle("Crypter et Décrypter avec Giovanni Battista Della Porta V 1.0");
    setMinimumSize(1020,768);
    setWindowIcon(QIcon("iconeDelaPorta.png"));
    /********************** Widgets *********************/
    clairWidg= new QWidget();
    cipherWidg = new QWidget();
    paramWidg = new QWidget(); paramWidg->setWindowTitle("Paramétrage");
    clairWidg->setMinimumSize(492,400); cipherWidg->setMinimumSize(492,400); paramWidg->setMinimumSize(1000,220);


    /********************** Labels *********************/
    motCle1Lbl = new QLabel("<strong>Mot Clé 1 :</strong> ");
    motCle2Lbl = new QLabel("<strong>Mot Clé 2 :</strong> ");

    /********************** Lines *********************/
    motCle1Edit = new QLineEdit();
    motCle2Edit = new QLineEdit();

    /********************** Tableau *********************/
     tableau=new QTableView;
     tab=new QStandardItemModel;
     tab->setRowCount(1);
     tab->setColumnCount(1);
     tableau->setModel(tab);



    /********************** Bouttons *********************/
       QFont btnFont("Arial"); btnFont.setBold(true);
    crypterBtn = new QPushButton("Crypter"); crypterBtn->setIcon(QIcon("padlock38.png")); crypterBtn->setFont(btnFont);

    decrypterBtn = new QPushButton("Déchiffrer"); decrypterBtn->setIcon(QIcon("padlock40.png"));decrypterBtn->setFont(btnFont);

    okParamBtn = new QPushButton("Paramétrer"); okParamBtn->setIcon(QIcon("settings69.png"));okParamBtn->setFont(btnFont);

     /********************** Espaces Texte *********************/
    texteClair = new QTextEdit();
    QFont policeClair("Arial");
    policeClair.setBold(true); policeClair.setPointSize(10);
    QColor couleurClair(37,122,173);
    texteClair->setTextColor(couleurClair);
    texteClair->setFont(policeClair);

    texteCipher = new QTextEdit();
    QFont policeCipher("Arial");
    policeCipher.setBold(true);policeCipher.setPointSize(10);
    QColor couleurCipher(204,125,6);
    texteCipher->setTextColor(couleurCipher);
    texteCipher->setFont(policeCipher);

    /*********************** Compteur de lignes **********************/
    nbDiv = new QSpinBox();
    nbDiv->setMinimum(1);
    nbDiv->setMaximum(13);
    /********************** Initialisation et Paramétrage *********************/
    reference.push_back("ab");reference.push_back("cd");reference.push_back("ef");reference.push_back("gh"); reference.push_back("ij");
    reference.push_back("kl");reference.push_back("mn");reference.push_back("op");reference.push_back("qr"); reference.push_back("st");
    reference.push_back("uv");reference.push_back("wx");reference.push_back("yz");


    /********************** Layouts *********************/
    QGridLayout *layoutClair = new QGridLayout;
    QGridLayout *layoutCipher = new QGridLayout;
    QGridLayout *layoutParametrage = new QGridLayout;
    QHBoxLayout *layCle = new QHBoxLayout;
    QHBoxLayout *layBut = new QHBoxLayout;

    layCle->addWidget(motCle1Lbl); layCle->addWidget(motCle1Edit);
    layCle->addWidget(motCle2Lbl); layCle->addWidget(motCle2Edit); layoutParametrage->addLayout(layCle,0,0,1,10,Qt::AlignCenter);

    layBut->addWidget(crypterBtn); layBut->addWidget(decrypterBtn); layoutParametrage->addLayout(layBut,1,0,1,10,Qt::AlignCenter);

    layoutClair->addWidget(texteClair,0,0);
    layoutCipher->addWidget(texteCipher,0,0);

    clairWidg->setLayout(layoutClair);
    cipherWidg->setLayout(layoutCipher);
    paramWidg->setLayout(layoutParametrage);
    /********************** Zone Centrale *********************/
    zoneCentrale = new QMdiArea();
    setCentralWidget(zoneCentrale);
  clairFen = zoneCentrale->addSubWindow(clairWidg); clairFen->setWindowTitle("Texte clair");
  cipherFen = zoneCentrale->addSubWindow(cipherWidg); cipherFen->setWindowTitle("Texte chiffré");
  paramFen = zoneCentrale->addSubWindow(paramWidg);

  ui->actionParam_trage_de_la_Table->setIcon(QIcon("settings18.png"));
  ui->actionNouveau_Cryptage->setIcon(QIcon("browser82.png"));
  ui->actionQuiter->setIcon(QIcon("opened33.png"));
  ui->menuFen_tres->setEnabled(false);
  ui->actionAfficher_la_table->setEnabled(false);
  /************************** Connexions ******************************/
  connect(crypterBtn,SIGNAL(clicked()),this,SLOT(crypter()));
  connect(decrypterBtn,SIGNAL(clicked()),this,SLOT(decrypter()));
  connect(nbDiv,SIGNAL(valueChanged(int)),this,SLOT(augmenterLignes(int)));
  connect(okParamBtn,SIGNAL(clicked()),this,SLOT(okParam()));
  connect(ui->actionParam_trage_de_la_Table,SIGNAL(triggered()),this,SLOT(parametrageTable()));
  connect(ui->actionMessage_Clair,SIGNAL(triggered()),this,SLOT(afficherClair()));
  connect(ui->actionMessage_Cipher,SIGNAL(triggered()),this,SLOT(afficherChiffre()));
  connect(ui->actionParam_trage,SIGNAL(triggered()),this,SLOT(afficherParametrage()));
  connect(ui->actionQuiter,SIGNAL(triggered()),qApp,SLOT(quit()));
  connect(ui->action_propos,SIGNAL(triggered()),this,SLOT(aPropos()));
  connect(ui->actionAfficher_la_table,SIGNAL(triggered()),this,SLOT(afficheTable()));
  connect(ui->actionNouveau_Cryptage,SIGNAL(triggered()),this,SLOT(nouvauCrypto()));
}

FenetrePrincipale::~FenetrePrincipale()
{
    delete ui;
}
/**************************************** Méthodes ***********************************/
int FenetrePrincipale::indChar(const QChar &c) // retourne l'indice du caractere du mot clé 2 dans la table
{
QString inter;
    for(int i=0;i<reference.size();i++)
    {   inter=reference[i];
        for(int j=0;j<inter.size();j++)
        {
            if(c==inter[j] || c==inter[j].toUpper()) return i;
        }
    }

}
//--------------------------------------------------------------------------------------------
void FenetrePrincipale::constructionTable()
{
std::vector<std::vector<QString> >    tt;
table=tt;
    tabWidg = new QWidget;
    tabWidg->setHidden(true);

            /**** tab ****/
    tableCryDecry=new QTableView;
    tableCryDecryModel=new QStandardItemModel;

    tableCryDecry->setModel(tableCryDecryModel);
           /************/

    vector<QString> vect,init;
    QString alphabet("abcdefghijklmnopqrstuvwxyz");
    QString ligne(motCle1Edit->text().toLower());

    for(int i=0;i<ligne.size();i++)
    {
        for(int j=i+1;j<ligne.size();j++)
        {
            if(ligne[i]==ligne[j]){ligne.remove(j,1);}
        }
    }

    motCle1Edit->setText(ligne);
    QString ligne1(ligne.remove(ligne.size()/2,ligne.size()-1));
    ligne=motCle1Edit->text();
    QString ligne2(ligne.remove(0,ligne.size()/2));

    for(int i=0;i<motCle1Edit->text().size();i++)
    {
        alphabet.remove(motCle1Edit->text()[i],Qt::CaseInsensitive);
    }

    int tailleP=13-ligne1.size();
    for(int i=0;i<tailleP;i++)
    {
        ligne1.push_back(alphabet[0]);
        alphabet.remove(0,1);
    }

    tailleP=13-ligne2.size();

    for(int i=0;i<tailleP;i++)
    {
        ligne2.push_back(alphabet[0]);
        alphabet.remove(0,1);
    }

    vect.push_back(ligne1); vect.push_back(ligne2); table.push_back(vect);
    vect=init;
    int taille(ligne2.length());
    //texteClair->append(ligne1+"\n"+ligne2);


    tableCryDecryModel->setItem(0,0,new QStandardItem(reference[0]));
    tableCryDecryModel->setItem(0,1,new QStandardItem(ligne1));
    tableCryDecryModel->setItem(0,2,new QStandardItem(ligne2));

     //texteClair->append(ligne1+"\n"+ligne2);

    for(int i=1;i<reference.size();i++)
    {

        vect.push_back(ligne1);

        ligne2+=ligne2;
        ligne2.remove(ligne2.length()-1,1); ligne2.remove(0,taille-1);
        vect.push_back(ligne2);
        tableCryDecryModel->setItem(i,0,new QStandardItem(reference[i]));
        tableCryDecryModel->setItem(i,1,new QStandardItem(ligne1));
        tableCryDecryModel->setItem(i,2,new QStandardItem(ligne2));
       table.push_back(vect); vect=init;
    }
    QVBoxLayout *layTab = new QVBoxLayout;
    layTab->addWidget(tableCryDecry);
    tabWidg->setLayout(layTab);
     tableCryDecry->resizeColumnsToContents();
}
//--------------------------------------------------------------------------------------------
void FenetrePrincipale::constructionMotCle2()
{

    utilMotCle2="";
    utilMessageClair=texteClair->toPlainText();
    utilMessageClair.replace(" ","", Qt::CaseSensitive);
    utilMessageClair.toLower();
    if(utilMessageClair.size()< motCle2Edit->text().size())
    {
        QMessageBox::critical(this,"Message court","ERREUR: La taille du message doit être au moins égale à la taille du 2nd mot clé ");
    }
    else
    {
         utilMotCle2=motCle2Edit->text();
    while(utilMotCle2.size()<utilMessageClair.size())
    {
        utilMotCle2+=utilMotCle2;
    }

    if(utilMessageClair.size()!=utilMotCle2.size())
    {
        utilMotCle2.remove(utilMessageClair.size(),-utilMessageClair.size()+utilMotCle2.size());
    }
    }
}

void FenetrePrincipale::constructionMotCle2Decrypter()
{
    utilMotCle2="";
    utilCipher=texteCipher->toPlainText();
    utilCipher.replace(" ","", Qt::CaseSensitive);
    utilCipher.toLower();
    if(utilCipher.size()< motCle2Edit->text().size())
    {
        QMessageBox::critical(this,"Message court","ERREUR: La taille du message doit être au moins égale à la taille du 2nd mot clé ");
    }
    else
    {


         utilMotCle2=motCle2Edit->text();
         utilMotCle2.replace(" ","", Qt::CaseSensitive);


    while(utilMotCle2.size()<utilCipher.size())
    {
        utilMotCle2+=utilMotCle2;
    }

    if(utilCipher.size()!=utilMotCle2.size())
    {
        utilMotCle2.remove(utilCipher.size(),-utilCipher.size()+utilMotCle2.size());
    }

    }
}

/*********************************** Decryptage **********************************/
bool FenetrePrincipale::isPremier(const int &a)
{
    for(int i=2;i<a;i++)
    {
        if(a % i ==0) return false;
    }
return true;}
//---------------------------------------------------------------------------------
int FenetrePrincipale::prochainPremier(const int &a)
{
    for(int i=a+1;i<INFINITY;i++)
    {
        if(isPremier(i)) return i;
    }
}

//---------------------------------------------------------------------------------


/***************************************** Slots *************************************/
void FenetrePrincipale::crypter()
{

    if(texteClair->toPlainText()=="")
    {
        QMessageBox::critical(this,"Message Clair Non valide","ERREUR: Veuillez introduire un texte à crypter !");
    }else
    {
    ui->actionAfficher_la_table->setEnabled(true);
        constructionTable();
        constructionMotCle2();
        int ind;
        bool B(false);
        QString inter;
        utilCipher="";
        utilMessageClair=utilMessageClair.toLower();
        utilMotCle2=utilMotCle2.toLower();
        for(int i=0;i<utilMessageClair.length();i++)
        {
            ind = indChar(utilMotCle2[i]);
             inter=table[ind][0];


            for(int j=0;j<inter.length() && !B;j++)
            {
                    if(inter[j]==utilMessageClair[i])
                    {
                        inter=table[ind][1];
                        utilCipher.push_back(inter[j]);
                        B=true;

                    }
            }
                 inter=table[ind][1];

            for(int j=0;j<inter.length() && !B;j++)
            {
                if(inter[j]==utilMessageClair[i])
                {
                    inter=table[ind][0];
                    utilCipher.push_back(inter[j]);
                    B=true;

                }

            }
            B=false;
        }

       texteCipher->setText(utilCipher);
    }
}

//------------------------------------------------------------------------------------

void FenetrePrincipale::decrypter()
{
    if(texteCipher->toPlainText()=="")
    {
        QMessageBox::critical(this,"Message Chiffré Non valide","ERREUR: Veuillez introduire un texte à décrypter !");
    }else
    {
        ui->actionAfficher_la_table->setEnabled(true);
        constructionTable();
        constructionMotCle2Decrypter();
        int ind;
        bool B(false);
        QString inter;
        utilMessageClair="";
        utilMotCle2=utilMotCle2.toLower();
        utilCipher=utilCipher.toLower();
        for(int i=0;i<utilCipher.length();i++)
        {
            ind = indChar(utilMotCle2[i]);
             inter=table[ind][0];


            for(int j=0;j<inter.length() && !B;j++)
            {
                    if(inter[j]==utilCipher[i])
                    {
                        inter=table[ind][1];
                        utilMessageClair.push_back(inter[j]);
                        B=true;

                    }
            }
                 inter=table[ind][1];

            for(int j=0;j<inter.length() && !B;j++)
            {
                if(inter[j]==utilCipher[i])
                {
                    inter=table[ind][0];
                    utilMessageClair.push_back(inter[j]);
                    B=true;
                }

            }
            B=false;
        }

       texteClair->setText(utilMessageClair);
    }

    }


void FenetrePrincipale::parametrageTable()
{
    paramWidget= new QWidget(); paramWidget->setWindowTitle("Paramétrage de la table");
    paramWidget->setMinimumSize(200,520);
    paramLbl = new QLabel("Nombre de partitions de l'alphabet : ");


    QVBoxLayout *hLay  = new QVBoxLayout;
    QHBoxLayout *vLay = new QHBoxLayout;


    vLay->addWidget(paramLbl); vLay->addWidget(nbDiv);


    hLay->addLayout(vLay);
    hLay->addWidget(tableau);
    hLay->addWidget(okParamBtn);
    paramWidget->setLayout(hLay);
    paramWidget->show();
}

void FenetrePrincipale::augmenterLignes(int i)
{
    tab->setRowCount(i);

}

void FenetrePrincipale::okParam()
{

int taille(reference.size());
    for(int i=0;i<taille;i++) reference.pop_back();

for(int i=0;i<nbDiv->value();i++)
{
    reference.push_back(tab->item(i,0)->text().toLower());
}
paramWidget->setHidden(true);
}

void FenetrePrincipale::nouvauCrypto()
{
    texteClair->setText(""); texteCipher->setText("");
    motCle1Edit->setText(""); motCle2Edit->setText("");
    nbDiv->setValue(0); nbDiv->setValue(1);
std::vector<QString> init1; reference=init1;
reference.push_back("ab");reference.push_back("cd");reference.push_back("ef");reference.push_back("gh"); reference.push_back("ij");
reference.push_back("kl");reference.push_back("mn");reference.push_back("op");reference.push_back("qr"); reference.push_back("st");
reference.push_back("uv");reference.push_back("wx");reference.push_back("yz");
std::vector<std::vector<QString> >    init2; table=init2;

}

void FenetrePrincipale::afficherClair()
{
 texteClair= new QTextEdit("");
        clairWidg = new QWidget();
 clairWidg->setMinimumSize(620,400);

QGridLayout *layoutClair = new QGridLayout;
layoutClair->addWidget(texteClair,0,0);
clairWidg->setLayout(layoutClair);
 clairFen = zoneCentrale->addSubWindow(clairWidg); clairFen->setWindowTitle("Texte clair");

   clairWidg->show();
}

void FenetrePrincipale::afficherChiffre()
{
cipherWidg = new QWidget();
cipherWidg->setMinimumSize(620,400);
texteCipher = new QTextEdit();

QGridLayout *layoutCipher = new QGridLayout;

layoutCipher->addWidget(texteCipher,0,0);
cipherWidg->setLayout(layoutCipher);

cipherFen = zoneCentrale->addSubWindow(cipherWidg); cipherFen->setWindowTitle("Texte chiffré");
   cipherWidg->show();
}

void FenetrePrincipale::afficherParametrage()
{
paramWidg = new QWidget(); paramWidg->setWindowTitle("Paramétrage");
     paramWidg->setMinimumSize(1257,280);

     /********************** Labels *********************/
     motCle1Lbl = new QLabel("Mot Clé 1 : ");
     motCle2Lbl = new QLabel("Mot Clé 2 : ");

     /********************** Lines *********************/
     motCle1Edit = new QLineEdit();
     motCle2Edit = new QLineEdit();
     /********************** Bouttons *********************/
     crypterBtn = new QPushButton("Crypter"); crypterBtn->setIcon(QIcon("padlock38.png"));
     decrypterBtn = new QPushButton("Décrypter"); decrypterBtn->setIcon(QIcon("padlock40.png"));
     QGridLayout *layoutParametrage = new QGridLayout;
     QHBoxLayout *layCle = new QHBoxLayout;
     QHBoxLayout *layBut = new QHBoxLayout;

     layCle->addWidget(motCle1Lbl); layCle->addWidget(motCle1Edit);
     layCle->addWidget(motCle2Lbl); layCle->addWidget(motCle2Edit); layoutParametrage->addLayout(layCle,0,0,1,10,Qt::AlignCenter);

     layBut->addWidget(crypterBtn); layBut->addWidget(decrypterBtn); layoutParametrage->addLayout(layBut,1,0,1,10,Qt::AlignCenter);
     paramWidg->setLayout(layoutParametrage);
     paramFen = zoneCentrale->addSubWindow(paramWidg);

     paramWidg->show();

}

void FenetrePrincipale::aPropos()
{
    QString inf("<br>Cette application a été créer par l'étudiant <strong>Mehdi BOUZiDi</strong>, en master R.O <br>");
    inf+="<br>Option : <strong>METHODES ET MODELES POUR L'INGENIERIE ET LA RECHERCHE </strong>.<br> ";
    inf+="<br>Date : <strong> 20/11/2015</strong> <br>";

    QWidget *infos = new QWidget;
infos->setWindowTitle("À propos");
infos->setWindowIcon(QIcon("info2.png"));
infos->setFixedSize(500,300);
 QLabel *auteur = new QLabel(inf);
 QVBoxLayout *layoutInfo =new QVBoxLayout;
 layoutInfo->addWidget(auteur);
 infos->setLayout(layoutInfo);
 infos->setHidden(false);

}

void FenetrePrincipale::afficheTable()
{
    tabWidg->setVisible(true);
}
