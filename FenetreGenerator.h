#ifndef FENETREGENERATOR_H
#define FENETREGENERATOR_H
#include <QtWidgets>

class FenetreGenerator : public QWidget
{

    Q_OBJECT
    public slots:
        void creerCode();
    public:
        FenetreGenerator();
    private:
        QLineEdit *nom;
        QLineEdit *classeMere;
        QCheckBox *checkbox1;
        QCheckBox *checkbox2;
        QCheckBox *checkbox3;
        QGroupBox *groupbox3;
        QLineEdit *auteur;
        QDateEdit *dateDeCreation;
        QTextEdit *roleClasse;
        QDialogButtonBox *buttonBox;
};

#endif // FENETREGENERATOR_H
