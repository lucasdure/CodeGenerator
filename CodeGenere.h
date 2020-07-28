#ifndef CODEGENERE_H
#define CODEGENERE_H
#include <QtWidgets>

class CodeGenere : public QDialog
{
    public:
        CodeGenere(QString &code, QWidget *parent);

    private:
        QTextEdit *codeGenere;
        QPushButton *fermer;
};

#endif // CODEGENERE_H
