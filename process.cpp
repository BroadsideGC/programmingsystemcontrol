#include "matrix.cpp"
#include <string>
#include "plant.h"

#include <blocks/integrator.h>

class Process {
public:

    void setVar(std::string var) {
        this->var = var;

        std::cout<<var;

        plant.setCMatrix(mat.c);
        plant.setBMatrix(mat.b_5);
        if (var == "Cont") {
            plant.setAMatrix(&mat.a_cont[0][0]);
            plant.setBMatrix(mat.b_5);
        } else if (var == "Discr_5") {
            plant.setAMatrix(&mat.a_5[0][0]);
            plant.setBMatrix(mat.b_5);
        } else if (var == "Discr_50") {
            plant.setAMatrix(&mat.a_50[0][0]);
            plant.setBMatrix(mat.b_50);
        } else if (var == "Discr_100") {
            plant.setAMatrix(&mat.a_100[0][0]);
            plant.setBMatrix(mat.b_100);
        } else if (var == "Cos1_5") {
            plant.setAMatrix((double*)&mat.cos1_5[0][0]);
            plant.setCMatrix(mat.cos1Y);
            flag = 0;
         } else if (var == "Cos2_5") {
            plant.setAMatrix(&mat.cos2_5[0][0]);
            plant.setCMatrix(mat.cos2Y);
            flag = 0;
        } else if (var == "Cos1_50") {
            plant.setAMatrix(&mat.cos1_50[0][0]);
            plant.setCMatrix(mat.cos1Y);
            flag = 0;
        } else if (var == "Cos2_50") {
            plant.setAMatrix(&mat.cos2_50[0][0]);
            plant.setCMatrix(mat.cos2Y);
            flag = 0;
       }
        else if (var == "Cos1_100") {
            plant.setAMatrix(&mat.cos1_100[0][0]);
            plant.setCMatrix(mat.cos1Y);
            flag = 0;
        } else if (var == "Cos2_100") {
            plant.setAMatrix(&mat.cos2_100[0][0]);
            plant.setCMatrix(mat.cos2Y);
            flag = 0;
        }
        if (!flag) {
            plant.setState();
        }
    }

    double update(double dt) {
        plant.update(dt, flag);
        if (var == "Cont") {
            plant.x1 = int1.update(plant.xdiff1, dt);
            plant.x2 = int2.update(plant.xdiff2, dt);
            plant.x3 = int3.update(plant.xdiff3, dt);

        } else {
            plant.x1 = plant.xdiff1;
            plant.x2 = plant.xdiff2;
            plant.x3 = plant.xdiff3;
        }
        return plant.getState();
    }

    double getState() {
        return plant.getState();
    }

private:
    integrator int1 = integrator(0);
    integrator int2 = integrator(0);
    integrator int3 = integrator(0);
    std::string var;
    bool flag = 1;
    Matrix mat = Matrix();
    Plant plant = Plant();
};
