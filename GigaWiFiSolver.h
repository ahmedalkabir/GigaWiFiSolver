#ifndef GIGA_WIFI_SOLVER_H_
#define GIGA_WIFI_SOLVER_H_

// #include <mbed.h>
// #include <Arduino.h>
#include <BlockDevice.h>
#include "QSPIFBlockDeviceAsas.h"
#include <utility>

static QSPIFBlockDeviceAsas _qspi_block(QSPI_SO0, QSPI_SO1, QSPI_SO2, QSPI_SO3,  QSPI_SCK, QSPI_CS, A_QSPIF_POLARITY_MODE_1, 40000000);

class GigaWiFiSolver {
    public:
        GigaWiFiSolver(){
            _root = &_qspi_block;
        }

        mbed::BlockDevice *get_device(){
            return _root;
        }

    private:
        QSPIFBlockDeviceAsas *_root;
};


GigaWiFiSolver r1;

mbed::BlockDevice *mbed::BlockDevice::get_default_instance() {
  return r1.get_device();
}

#endif
