#include <QApplication>
#include "FenetreGenerator.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FenetreGenerator maFenetre;
    maFenetre.show();

    return app.exec();
}
