#ifndef GIGA_WIFI_SOLVER_H_
#define GIGA_WIFI_SOLVER_H_

#include <BlockDevice.h>
#include "QSPIFBlockDeviceAsas.h"
#include <utility>

// Don't touch it 
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


// As the defual block device has some defects that can't 
// works well, so I need to override with the modified implementation
// of QSPIFBlockDevice instance.

GigaWiFiSolver r1;

mbed::BlockDevice *mbed::BlockDevice::get_default_instance() {
  return r1.get_device();
}

#endif
