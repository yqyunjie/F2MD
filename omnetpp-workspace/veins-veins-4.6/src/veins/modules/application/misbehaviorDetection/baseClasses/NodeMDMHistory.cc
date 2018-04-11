#include <veins/modules/application/misbehaviorDetection/baseClasses/NodeMDMHistory.h>


MDMHistory::MDMHistory() {
    nodeId = 0;
    BSMNum = 0;
}

MDMHistory::MDMHistory(int id) {
    nodeId = id;
    BSMNum = 0;
}

BsmCheck MDMHistory::getBsmCheck(int index) {
    return bsmCheckList[index];
}

void MDMHistory::setBsmCheck(int index, BsmCheck bsmCheck) {
    bsmCheckList[index] = bsmCheck;
}

void MDMHistory::addBsmCheck(BsmCheck bsmCheck) {
    if (BSMNum < MAXMDMLENGTH) {
        BSMNum++;
    }
    for (int var = BSMNum - 1; var > 0; --var) {
        bsmCheckList[var] = bsmCheckList[var - 1];
    }
    bsmCheckList[0] = bsmCheck;
}