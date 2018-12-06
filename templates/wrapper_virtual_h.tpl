#ifndef VIRTUALWRAPPER{$imitator}_H
#define VIRTUALWRAPPER{$imitator}_H
#include "../../../include/ivirtualwrapper.h"

class _{$imitator}VirtualWrapper : public IVirtualWrapper
{


public:
    _{$imitator}VirtualWrapper(QString panelname);
    void processParam(QString name, QVariant value);
};
#endif
