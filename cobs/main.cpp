#include <QCoreApplication>
#include "cobs_res.cpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    float f = 3;
    uint8_t res[8];
    cobs_res(f, res);
    for (int i = 0; i < 8; i++) {
        std::cerr << (int) res[i] << " ";
    }
    return a.exec();
}
