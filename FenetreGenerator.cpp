#include "FenetreGenerator.h"
#include "CodeGenere.h"
#include <QtWidgets>

FenetreGenerator::FenetreGenerator(): QWidget()
{
    QVBoxLayout *vBoxlayout1 = new QVBoxLayout(this);

    QGroupBox *groupbox1 = new QGroupBox("Définition de la classe");
        nom = new QLineEdit;
        classeMere = new QLineEdit;
        QFormLayout *formLayout1 = new QFormLayout;
            formLayout1->addRow("Nom", nom); //Ajouter la ligne au formulaire
            formLayout1->addRow("Classe Mère", classeMere); //Ajouter la ligne au formulaire
            groupbox1->setLayout(formLayout1);
        vBoxlayout1->addWidget(groupbox1);

    QGroupBox *groupbox2 = new QGroupBox("Options");
        checkbox1 = new QCheckBox("Protéger le header contre les inclusions multiples");
        checkbox2 = new QCheckBox("Générer un constructeur par défaut");
        checkbox3 = new QCheckBox("Générer un destructeur");
        QVBoxLayout *vBoxlayout2 = new QVBoxLayout;
            vBoxlayout2->addWidget(checkbox1);
            vBoxlayout2->addWidget(checkbox2);
            vBoxlayout2->addWidget(checkbox3);
            groupbox2->setLayout(vBoxlayout2);
            vBoxlayout1->addWidget(groupbox2);

    groupbox3 = new QGroupBox("Ajouter des commentaires");
        groupbox3->setCheckable(true);
        groupbox3->setChecked(false);
        auteur = new QLineEdit;
        dateDeCreation = new QDateEdit;
        roleClasse = new QTextEdit;
        QFormLayout *formLayout2 = new QFormLayout;
            formLayout2->addRow("Auteur", auteur); //Ajouter la ligne au formulaire
            formLayout2->addRow("Date de création", dateDeCreation); //Ajouter la ligne au formulaire
            formLayout2->addRow("Rôle de la classe", roleClasse); //Ajouter la ligne au formulaire
        groupbox3->setLayout(formLayout2);
        vBoxlayout1->addWidget(groupbox3);

    QHBoxLayout *hBoxlayout1 = new QHBoxLayout();
        buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                             | QDialogButtonBox::Cancel);
        QObject::connect(buttonBox, SIGNAL(accepted()), this, SLOT(creerCode()));
        QObject::connect(buttonBox, SIGNAL(rejected()), qApp, SLOT(quit()));
        hBoxlayout1->addWidget(buttonBox);
        vBoxlayout1->addLayout(hBoxlayout1);

}

void FenetreGenerator::creerCode()
{
    if (nom->text().isEmpty())
        {
            QMessageBox::critical(this, "Erreur", "Veuillez entrer au moins un nom de classe");
            return; // Arrêt de la méthode
        }

    // Si tout va bien, on génère le code
    QString code1;
    QString code2;
    QString code3;
    QString code4;

    // Génération du code à l'aide des informations de la fenêtre
    if (!classeMere->text().isEmpty())
        code2 = " : public "+classeMere->text();

    if(checkbox2->isChecked())
        code3 = QString("\t")+QString("\t")+nom->text()+"()"+QString("\n");

    if(checkbox3->isChecked())
        code4 = QString("\t")+QString("\t")+"~"+nom->text()+"()"+QString("\n");

    code1 = "class "+nom->text()+code2+QString("\n")
            +"{"+QString("\n")
            +QString("\t")+"public : "+QString("\n")
            +code3
            +code4
            +QString("\n\n\n")
            +QString("\t")+"protected : "+QString("\n")
            +QString("\n\n\n")
            +QString("\t")+"private : "+QString("\n")
            +QString("\n\n\n")
            +"}"+QString("\n")
            ;

    if(checkbox1->isChecked())
        code1 = ("#ifndef HEADER_"+nom->text().toUpper()+QString("\n")
                +"#define HEADER_"+nom->text().toUpper()+QString("\n"))
                +code1+QString("\n")
                +("#endif"+QString("\n"));

    if(groupbox3->isChecked())
        code1=("/*"+QString("\n")+"Auteur : "+auteur->text()+QString("\n")+"Date de création : "+dateDeCreation->date().toString()+QString("\n\n")
               +"Rôle : "+QString("\n") +roleClasse->toPlainText()+QString("\n")+"*/"+QString("\n")) + code1;

    // On crée puis affiche la fenêtre qui affichera le code généré, qu'on lui envoie en paramètre
    CodeGenere *fenetreCode = new CodeGenere(code1, this);
    fenetreCode->exec();
}
